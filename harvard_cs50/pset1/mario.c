#include <stdio.h>
#include <cs50.h>

const int MIN_HEIGHT = 0;
const int MAX_HEIGHT = 23;
const string WHITESPACE_ROW_SEGMENT = " ";
const string PYRAMID_ROW_SEGMENT = "$";

int main(void)
{
    int height;
    do {
        printf("Height: ");
        height = GetInt();
    } while ( height < MIN_HEIGHT || height > MAX_HEIGHT );

    const int row_length = height + 1;
    int whitespace_buffer_length = row_length - 2;
    while (height)
    {
        for (int i = 0; i < whitespace_buffer_length; i++)
        {
            printf("%s", WHITESPACE_ROW_SEGMENT);
        }

        for (int i = whitespace_buffer_length; i < row_length; i++)
        {
            printf("%s", PYRAMID_ROW_SEGMENT);
        }

        printf("\n");
        whitespace_buffer_length--;
        height--;
    }
}

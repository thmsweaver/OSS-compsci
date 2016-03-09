#include <stdio.h>
#include <string.h>
#include <cs50.h>

const char WHITESPACE_CODE_POINT = (int) ' ';
const int MIN_LOWERCASE_CODE_POINT = (int) 'a';
const int MAX_LOWERCASE_CODE_POINT = (int) 'z';
const int LOWER_TO_UPPER_CODE_POINT_DISTANCE = 32;

char toUpper(char initial)
{
    int code_point = (int) initial;

    if (code_point >= MIN_LOWERCASE_CODE_POINT &&
        code_point <= MAX_LOWERCASE_CODE_POINT)
    {
        code_point -= LOWER_TO_UPPER_CODE_POINT_DISTANCE;
    }

    return (char) code_point;
}

int main ()
{
    string name = GetString();
    printf("%c", toUpper(name[0]));

    int name_length = strlen(name);
    for (int i = 1; i < name_length; i++)
    {

        int current_code_point = (int) name[i];
        char next_char = name[i + 1];
        int next_code_point = (int) next_char;

        if (current_code_point == WHITESPACE_CODE_POINT) {
            // account for accidental double-spacing
            if (next_code_point != WHITESPACE_CODE_POINT) {
                printf("%c", toUpper(name[i + 1]));
            }
        }
    }

    printf("\n");
}

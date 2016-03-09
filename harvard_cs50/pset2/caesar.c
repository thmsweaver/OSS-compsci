#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    int shift;
    if (argc > 1 && argc < 3) {
        shift = atoi(argv[1]);
    } else {
        printf("Caesar Cipher requires integer command-line argument\n");
        return 1;
    }

    printf("Enter plaintext: ");
    string plaintext = GetString();

    int string_length = strlen(plaintext);
    for (int i = 0; i < string_length; i++) {
        int code_point = (int) plaintext[i];

        int normalize;
        if (code_point >= 97 && code_point <= 122) {
            normalize = 97;
        } else {
            normalize = 65;
        }

        int shifted_code_point = ((code_point - normalize + shift) % 26) + normalize;
        printf("%c\n", (char) shifted_code_point);
    }
}

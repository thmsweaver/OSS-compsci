#include <stdio.h>
#include <string.h>
#include <cs50.h>

const int _a_CODEPOINT = 'a';
const int _z_CODEPOINT = 'z';
const int _A_CODEPOINT = 'A';
const int _Z_CODEPOINT = 'Z';

int is_alpha_string(string characters);
int is_alpha_lowercase(char letter);
int is_alpha_uppercase(char letter);
char get_enciphered_char(char character, int shift);

int main(int argc, string argv[])
{
    string cipher_key = argv[1];

    if ((argc > 1 && argc < 3) &&
        is_alpha_string(cipher_key)) {
    } else {
        printf("Vignere Cipher requires one alphabet string CLI argument\n");
        return 1;
    }

    string plaintext = GetString();

    int cipher_length = strlen(cipher_key);
    int cipher_key_code_points[cipher_length];
    for (int i = 0; i < cipher_length; i++) {
        cipher_key_code_points[i] = (int) cipher_key[i];
    }

    int next_cipher_index = 0;
    int plaintext_length = strlen(plaintext);
    for (int i = 0; i < plaintext_length; i++) {
        char current_char = plaintext[i];

        if (is_alpha_lowercase(current_char) ||  is_alpha_uppercase(current_char)) {
            int cipher_index = next_cipher_index % cipher_length;
            int shift = cipher_key_code_points[cipher_index];
            char enciphered_char = get_enciphered_char(current_char, shift);
            printf("%c", enciphered_char);

            next_cipher_index++;
        } else {
            printf("%c", current_char);
        }
    }

    printf("\n");
}

int is_alpha_lowercase(char letter) {
    if (letter >= _a_CODEPOINT &&
        letter <= _z_CODEPOINT) {
        return 1;
    } else {
        return 0;
    }
}

int is_alpha_uppercase(char letter) {
    if (letter >= _A_CODEPOINT &&
        letter <= _Z_CODEPOINT) {
        return 1;
    } else {
        return 0;
    }
}

int is_alpha_string(string characters) {

    int characters_length = strlen(characters);
    for (int i = 0; i < characters_length; i++) {
        char current_char = characters[i];

        if (is_alpha_lowercase(current_char) ||
            is_alpha_uppercase(current_char)) {
            continue;
        } else {
            return 0;
        }
    }

    return 1;
}

char get_enciphered_char(char character, int shift) {
    int normalize;
    if (is_alpha_lowercase(character)) {
        normalize = 97;
    } else {
        normalize = 65;
    }

    int shifted = (int) character - normalize + shift;
    int enciphered_code_point = (shifted % 26) + normalize;
    return (char) enciphered_code_point;
}

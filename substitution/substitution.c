#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("./substitution key\n");
        return 1;
    }
    int length = strlen(argv[1]);
    if (length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    char lower_string[26];
    for (int i = 0; i< length; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain 26 characters.");
            return 1;
        }
        lower_string[i] = tolower(argv[1][i]);
    }
    for (int i = 0; i < length; i++)
    {
        {
            for (int j = 25; j > i; j--)
            {
                if (lower_string[i] == lower_string[j])
                {
                    printf("Key must not contain repeated characters.");
                    return 1;
                }
            }
        }
    }
    string plaintext = get_string("plaintext: ");
    int plain_length = strlen(plaintext);
    char ciphertext[plain_length];
    int plain_index;
    for (int i = 0; i < plain_length; i++)
    {
        if (isupper(plaintext[i]))
        {
            plain_index = plaintext[i] - 65;
            ciphertext[i] = toupper(argv[1][plain_index]);
        }
        else if (islower(plaintext[i]))
        {
            plain_index = plaintext[i] - 97;
            ciphertext[i] = tolower(argv[1][plain_index]);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[plain_length] = '\0';
    printf("ciphertext: %s\n", ciphertext);
}
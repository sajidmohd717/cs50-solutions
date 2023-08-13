// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string input_string);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }
    printf("%s\n", replace(argv[1]));

}

string replace(string input_string)
{
    int length = strlen(input_string);
    for (int i = 0; i < length; i++)
    {
        switch (input_string[i])
        {
            case 'a':
                input_string[i] = 54; // ascii value of 6
                break;
            case 'e':
                input_string[i] = 51; // ascii value of 3
                break;
            case 'i':
                input_string[i] = 49; // ascii value of 1
                break;
            case 'o':
                input_string[i] = 48; // ascii value of 0
                break;
        }
    }
    return input_string;
}
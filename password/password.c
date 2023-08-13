// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool upper_req = false, lower_req = false, number_req = false, symbol_req = false;
    int length = strlen(password);
    for (int i = 0; i< length; i++)
    {
        if (upper_req == false)
        {
            upper_req = isupper(password[i]); //will become true, if isupper returns non 0
        }
        if (lower_req == false)
        {
            lower_req = islower(password[i]);
        }
        if (number_req == false)
        {
            number_req = isdigit(password[i]);
        }
        if (symbol_req == false)
        {
            symbol_req = !(isalnum(password[i]));
        }
    }
    if (upper_req == true && lower_req == true && number_req == true && symbol_req == true)
    {
        return true;
    }
    return false;
}

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{

    char ch;


// Ensure that a key is entered that must not be negative, alphabet, empty or digit contains a letter

    if (argc != 2)
    {
        printf(" Usage: ./caesar key\n");
        return 1;  // or return (-1): This removes the segmentation fault error message
    }


    else if (argv[1] <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;

    }

//Loop over each character to check valid digit and avoid program timeout
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            return 1;
        }
    }


    int key = atoi(argv[1]);



//Get user text
    string text = get_string("plaintext: ");


//Loop over each character to check for upper or lower cases and digits

    for (int i = 0; text[i] != '\0'; ++i)
    {
        ch = text[i];

        if (isalnum(ch))
        {
            if (islower(ch))
            {
                ch = (ch - 'a' + key) % 26 + 'a';
            }

            if (isupper(ch))
            {
                ch = (ch - 'A' + key) % 26 + 'A';
            }

            if (isdigit(ch))
            {
                ch = (ch - '0' + key) % 1 - + '0';
            }
        }

        text[i] = ch;
    }

    printf(" ciphertext:  %s\n", text);

    return 0;
}




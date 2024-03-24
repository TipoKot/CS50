#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes
bool only_digits(string argv);
char rotate(char c, int number);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc == 2) // index 0 in argv is always the program name
    {
        // Make sure every character in argv[1] is a digit
        if (only_digits(argv[1]))
        {
            // Convert argv[1] from a `string` to an `int`
            int number = atoi(argv[1]);

            // Prompt user for plaintext
            string text = get_string("Text: ");

            // For each character in the plaintext:
            // Rotate the character if it's a letter
            // Implemented as a function at the end of the program

            // Print the ciphertext by character
            printf("ciphertext: ");
            for (int i = 0, len = strlen(text); i < len; i++)
            {
                printf("%c", rotate(text[i], number));
            }
            printf("\n");
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool only_digits(string argv)
{
    for (int i = 0, len = strlen(argv); i < len; i++)
        if (!isdigit(argv[i]))
        {
            return false;
        }
    return true;
}

char rotate(char c, int number)
{
    char cipherchar = 0;
    if (isupper(c))
    {
        cipherchar = (((c - 'A') + number) % 26) + 'A'; // % остаток от деления
    }
    else if (islower(c))
    {
        cipherchar = (((c - 'a') + number) % 26) + 'a'; // % остаток от деления
    }
    else
    {
        return c;
    }
    return cipherchar;
}

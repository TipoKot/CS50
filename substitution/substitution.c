#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool only_alpha(string argv);
bool not_repeat(string argv);
char cipher(char c, string argv);

int main(int argc, string argv[])
{
    if (argc == 2) // index 0 in argv is always the program name
    {
        // validate key
        // check key length
        if (strlen(argv[1]) == 26)
        {
            // check for non-alpha chars
            if (only_alpha(argv[1]))
            {
                // check for repeated chars
                if (not_repeat(argv[1]))
                {
                    // promt user for a plain text
                    string text = get_string("Text: ");

                    printf("ciphertext: ");
                    for (int i = 0, len = strlen(text); i < len; i++)
                    {
                        printf("%c", cipher(text[i], argv[1]));
                    }
                    printf("\n");
                    return 0;
                }
                else
                {
                    printf("Usage: characters in the key must not repeat\n");
                    return 1;
                }
            }
            else
            {
                printf("Usage: key must be only alphabetical characters\n");
                return 1;
            }
        }
        else
        {
            printf("Usage: ./substitution 26s characters key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
}

// function checks that every char in a string is alphabetical
bool only_alpha(string argv)
{
    for (int i = 0, len = strlen(argv); i < len; i++)
        if (!isalpha(argv[i]))
        {
            return false;
        }
    return true;
}

bool not_repeat(string argv)
{
    char key[26];
    for (int count = 0, len = strlen(argv); count < len; count++)
    {
        bool found = false;
        for (int j = 0; j < count; j++)
        {
            if (tolower(key[j]) == tolower(argv[count]))
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            return false;
        }
        if (!found)
        {
            key[count] = argv[count];
        }
    }
    return true;
}

char cipher(char c, string argv)
{
    char cipherchar = 0;
    if (isupper(c))
    {
        cipherchar = toupper(argv[c - 'A']);
    }
    else if (islower(c))
    {
        cipherchar = tolower(argv[c - 'a']);
    }
    else
    {
        return c;
    }
    return cipherchar;
}

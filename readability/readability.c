#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // debug printf("Letters:%i\n", letters);
    // debug printf("Words:%i\n", words);
    // debug printf("Sentences:%i\n", sentences);

    // Compute the Coleman-Liau index
    float index = (0.0588 * (((float) letters / (float) words) * 100) -
                   (0.296 * (((float) sentences / (float) words) * 100)) - 15.8);
    // debug printf("%.2f\n", (float)index);

    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 10)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int count_letters(string text)
{
    // Return the number of letters in text
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    // Return the number of words in text
    int words = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            words = words + 0;
        }
        else if (isblank(text[i]))
        {
            if (ispunct(text[i - 1]))
            {
                words = words + 0;
            }
            else
            {
                words++;
            }
        }
        else if (ispunct(text[i]))
        {
            if (isalpha(text[i + 1]))
            {
                words = words + 0;
            }
            else if (ispunct(text[i + 1]))
            {
                words = words + 0;
            }
            else
            {
                words++;
            }
        }
    }
    return words;
}

int count_sentences(string text)
{
    // Return the number of sentences in text
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (ispunct(text[i]))
        {
            if (text[i] == 33)
            {
                sentences++;
            }
            else if (text[i] == 46)
            {
                sentences++;
            }
            else if (text[i] == 63)
            {
                sentences++;
            }
            else
            {
                sentences = sentences + 0;
            }
        }
    }
    return sentences;
}

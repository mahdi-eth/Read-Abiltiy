#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, string argv[])
{
    string text = get_string("Text: ");
    int words = 1, nl = 0, ns = 0;



    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ' && text[i - 1] != ' ') //white space condition
        {
            words++;
        }
    }

    //Counts each character
    for (int j = 0, len = strlen(text); j < len; j++)
    {
        if ((text[j] >= (int) 'A' && text[j] <= (int) 'Z') || (text[j] >= (int) 'a' && text[j] <= (int) 'z'))
        {
            nl++;
        }

        if (text[j] == '.' || text[j] == '!' || text[j] == '?')
        {
            ns++;
        }
    }

    // calculating l & s
    float l = ((float) nl / (float) words) * 100;
    // l is the average number of letters per 100 words

    float s = ((float) ns / (float) words) * 100;
    // s is the average number of sentences per 100 words

    // the Coleman-Liau index formula
    int index = round(0.0588 * l - 0.296 * s - 15.8);

    if (index >= 1 && index <= 16)
    {
        printf("Grade %d\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}
#include <cs50.h>
#include <stdio.h>

int count_letters(char text[]);
int count_words(char text[]);
int count_sentences(char text[]);

int main(void)
{
    // get string from user
    // char text[] = "death death to the idf";
    string text = get_string("Text: ");

    // count letter
    int lets = count_letters(text);
    // printf("%i letter\n", lets);

    // count words
    int words = count_words(text);
    // printf("%i word\n",words);

    // count sent
    int sens = count_sentences(text);
    // printf("%i sentence\n",sens);

    // do formula index = 0.0588 * L - 0.296 * S - 15.8
    double countlets = ((double) lets / words) * 100;
    double contsen = ((double) sens / words) * 100;
    double index = (0.0588 * countlets) - (0.296 * contsen) - 15.8;
    // printf("%f\n\n", index);

    // print grade
    if (index < 0)
        printf("Before Grade 1\n");
    else if (index > 17)
        printf("Grade 16+\n");
    else
        printf("Grade %.0f\n", index);
}





int count_letters(char text[])
{
    int i = 0;
    int lets = 0;
    while (text[i] != '\0')
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            lets++;
        }
        i++;
    }
    return lets;
}

int count_words(char text[])
{
    int j = 0;
    int words = 1;
    while (text[j] != '\0')
    {
        if (text[j] == 32)
        {
            words++;
        }
        j++;
    }
    return words;
}

int count_sentences(char text[])
{
    int k = 0;
    int sens = 0;
    while (text[k] != '\0')
    {
        if ((text[k] == '.' || text[k] == '?' || text[k] == '!'))
        {
            sens++;
        }
        k++;
    }
    return sens;
}
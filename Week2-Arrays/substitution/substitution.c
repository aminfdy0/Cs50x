#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int ft_len(char *s);
int check_repeatition(char *str);
int check_letter(char *src);

int main(int argc, char *argv[])
{
    int i = 0;
    int len = 0;
    if (argc == 2)
    {
        len = ft_len(argv[1]);
        if (len != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else if (check_repeatition(argv[1]) == 1)
        {
            printf("ket must not contain repeated characters\n");
            return 1;
        }
        else if (check_letter(argv[1]) == 1)
        {
            printf("ket must not contain alphabetic characters\n");
            return 1;
        }
        string text = get_string("plaintext: ");

        while (text[i])
        {
            if (text[i] >= 'A' && text[i] <= 'Z')
            {
                text[i] = toupper(argv[1][text[i] - 'A']);
            }
            else if (text[i] >= 'a' && text[i] <= 'z')
            {
                text[i] = tolower(argv[1][text[i] - 'a']);
            }
            i++;
        }
        printf("ciphertext: %s\n", text);
        return 0;
    }
    else
        printf("Usage: ./substitution key\n");
    return 1;
}

int ft_len(char *s)
{
    int i = 1;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

int check_repeatition(char *str)
{
    int i = 0;
    int j;
    while (str[i] != '\0')
    {
        j = i + 1;
        while (str[j])
        {
            if (str[i] == str[j] 
                || str[i] >= 'A' && str[i] <= 'Z' && str[i] + 32 == str[j]
                || str[i] >= 'A' && str[i] <= 'Z' && str[i] - 32 == str[j])
            {
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}

int check_letter(char *src)
{
    int i = 0;
    while (src[i])
    {
        if ((src[i] >= 33 && src[i] <= 64) || (src[i] >= 91 && src[i] <= 96))
        {
            return 1;
        }
        i++;
    }
    return 0;
}
#include <cs50.h>
#include <ctype.h> // for use isdigit func
#include <stdio.h>
#include <stdlib.h> // for use atoi func

int main(int argc, char *argv[])
{
    int i = 0;
    if (argc == 2) 
    {
        // this while for check the argc 2 is number 
        while (argv[1][i] != '\0')
        {
            if (!(isdigit(argv[1][i])))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            i++;
        }
        string text = get_string("plaintext: ");
        i = 0;
        while (text[i] != '\0')
        {
            if (text[i] >= 'A' && text[i] <= 'Z')
            {
                text[i] = ((text[i] - 'A' + atoi(argv[1])) % 26) + 'A';
            }
            else if (text[i] >= 'a' && text[i] <= 'z')
            {
                text[i] = ((text[i] - 'a' + atoi(argv[1])) % 26) + 'a';
            }
            i++;
        }
        printf("ciphertext: %s\n", text);
        return 0;
    }
    else
        printf("Usage: ./caesar key\n");
    return 1;
}
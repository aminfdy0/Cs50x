// check the sytle by using style50 filename.c

#include <cs50.h>
#include <stdio.h>

// this func for switch in letter lowercase to uppercase
// code of this func in line 47
char    *uppercase(char *str);

// this func for handling letters and give every letter number
// code in this func in line 63
int     count_letters(char *po);



int main(void)
{
    // get string from player 1 and 2;
    // char po[] = "AMIN";
    // char pt[] = "FDY";
    string po = get_string("Player 1: ");
    string pt = get_string("Player 2: ");

    // if i find any letter lowercase in string make it uppercase
    uppercase(po);
    uppercase(pt);

    //Handele letters & count
    int sum_po = count_letters(po);
    int sum_pt = count_letters(pt);
    // printf("%i\n%i\n", sum_po, sum_pt);

    //Compare
    if (sum_po > sum_pt)
    printf("Player 1 wins!\n");
    else if (sum_pt > sum_po)
    printf("Player 2 wins!\n");
    else
    printf("Tie!\n");
}






char    *uppercase(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
    return str;
}





int count_letters(char *str)
{
     int i = 0;
    int one = 0, two = 0, three = 0, four = 0, five = 0, eight = 0, ten = 0;
     while(str[i] != '\0')
    {
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'N' || str[i] == 'O' ||
        str[i] == 'U' || str[i] == 'T' || str[i] == 'S' || str[i] == 'R' || str[i] == 'L')
            one = one + 1;

        else if(str[i] == 'D' || str[i] == 'G')
            two = two + 2;

        else if (str[i] == 'B' || str[i] == 'C' || str[i] == 'M' || str[i] == 'P' )
            three = three + 3;

        else if (str[i] == 'Y' || str[i] == 'W' || str[i] == 'V' || str[i] == 'H' || str[i] == 'F')
            four = four + 4;

        else if (str[i] == 'K')
            five = five + 5;

        else if(str[i] == 'J' || str[i] == 'X')
            eight = eight + 8;

        else if(str[i] == 'Q' || str[i] == 'Z')
            ten = ten + 10;

        i++;
    }
    int total = one + two + three + four + five + eight + ten;
    return total;
}
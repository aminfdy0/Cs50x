#include <cs50.h>
#include <stdio.h>

int  quarter(int nb);
int penny(int nb);
int nickel(int nb);

int main(void)
{
    int change, result;
    do{
        change = get_int("change owed: ");
    }
    while (change < 0);
    
    int Qcoins = quarter(change);
    change = change - (Qcoins*25);

    int Pcoins = penny(change);
    change = change - (Pcoins*10);

    int Ncoins = nickel(change);
    change = change - (Ncoins*5);

    result = Qcoins + Pcoins + Ncoins + change;

    printf("%i\n", result);
}

int  quarter(int nb)
{
    return nb/25;
}
int penny(int nb)
{
    return nb/10;
}
int nickel(int nb)
{
    return nb/5;
}
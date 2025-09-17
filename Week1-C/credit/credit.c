#include <cs50.h>
#include <stdio.h>

// define func for using
int number_len(long long nb);

int main(void)
{
     // get card number from user
     do
     {
          int number = get_long_long("Number: ");
     } while (number < 0);

     long long copy_card = number;

     // function for count len of number
     int len = number_len(copy_card);

     int total = 0;
     int pos = 0; 
     
     // Luhn’s Algorithm
     while (copy_card > 0)
     {
          int digit = copy_card % 10;
          if (pos % 2 == 0) 
          {
               total += digit;
          }
          else
          {
               int doubled = digit * 2;
               total += (doubled / 10) + (doubled % 10);
          }
          copy_card /= 10;
          pos++;
     }

     // the last digit in that sum (exmple: 20) is a 0, so Dcard is legit!
     if (total % 10 != 0)
     {
          printf("INVALID\n");
          return 0;
     }

     // check len of card number
     if (len != 13 && len != 15 && len != 16)
     {
          printf("INVALID\n");
          return 0;
     }

     // for take first two digits from number
     copy_card = number;
     while (copy_card >= 100)
     {
          copy_card /= 10;
     }
     int firsttwo = copy_card;


     // the time for checking
     if ((len == 16) && (firsttwo >= 51 && firsttwo <= 55))
          printf("MASTERCARD\n");
     else if (((len == 13) || (len == 16)) && ((firsttwo / 10 == 4) || (firsttwo == 4)))
          printf("VISA\n");
     else if ((len == 15) && (firsttwo == 34 || firsttwo == 37))
          printf("AMEX\n");
     else
          printf("INVALID\n");
}

int number_len(long long nb)
{
     int i = 0;
     while (nb > 0)
     {
          i++;
          nb /= 10;
     }
     return i;
}


// that my first try without inderstanding Luhn’s Algorithm well but after searching and asking and got the idea 
// u can see the result above

/*#include <cs50.c>
#include <stdio.h>

int number_len(long long nb);

int main(void)
{
     long long number;
     do
     {
          number = get_long_long("Number: ");
     } while (number < 0);


     long long copy_card = number;
     int len =  number_len(copy_card);
     //printf("len of number = %i\n", len);


     copy_card = number;
     int sum1 = 0;
     int mod1 = 0;

     int sum2 = 0;
     int mod2 = 0;
     int moddev = 0;

     if (len != 13 && len != 15 && len != 16)
     {
          printf("INVALID");
          return 0;
     }
     else 
     {
          while (copy_card > 0)
          {
               mod1 = copy_card % 10;
               sum1 = sum1 + mod1;
               copy_card /= 10;
               copy_card /= 10;
          }
          //printf("%i\n", sum1);
     }


          copy_card = number;
          while (copy_card > 0)
          {
               copy_card /= 10;
               mod2 = copy_card % 10;
               sum2 = (2 * mod2);
               moddev += (sum2 / 10) + (sum2 % 10);
               copy_card /= 10;
          }
          //printf("%i\n", moddev);
     

     int total = 0;
     total = moddev + sum1;
     copy_card = number;

     //printf("total: %i\n",total);

     while (copy_card > 100)
     {
          copy_card /= 10;
     }
     int firsttwo = copy_card;
     //printf("first two digit: %i\n", firsttwo);

     // if (!(firsttwo % 10 == 0)) 
     // {
     // printf("IVALID2\n");
     // }

     if  ((len == 16 ) && (firsttwo >= 51 && firsttwo <= 55))
     printf("MasterCard\n");
     else if (((len == 13) || (len == 16)) && (firsttwo / 10 == 4) || (firsttwo == 4))
     printf("Visa\n");
     else if ((firsttwo == 34 || firsttwo == 37))
     printf("AMEX\n");
     else
     printf("IVALID3");
}

int number_len(long long nb)
{
     int i = 0;
     while (nb > 0)
     {
          i++;
          nb /= 10;
     }
     return i;
}*/
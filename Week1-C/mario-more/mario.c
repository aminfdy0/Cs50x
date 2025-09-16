//to understad this code will u should be see and understand the code of mario-less

#include <stdio.h>   // For use printf funtion
#include <cs50.c>    // For use get_int funtion

// Prints a row of hashes ('#')
void print_hashes(int count)
{   
    for (int i = 0; i <= count; i++)
    {                               
         printf("#");                   
    }                                   
}                                               

int main(void)
{
    int height, row, space;

    // Ask the user for the pyramid height (the number should be between (1 - 8))
    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8); // that is the condition that control the number

    // Loop over each row of the pyramid
    for (row = 0; row < height; row++)
    {
        // Print the leading spaces (to right-align the left pyramid)
        for (space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }

        // Print the left half of the pyramid
        print_hashes(row);

        // Print the space between the two pyramids
        printf(" ");

        // Print the right half of the pyramid
        print_hashes(row);

        // Move to the next row
        printf("\n");
    }
}
/*
Example
height: 8
       # #
      ## ##
     ### ###
    #### ####
   ##### #####
  ###### ######
 ####### #######
######## ########
*/
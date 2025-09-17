#include <cs50.h>   // For get_int
#include <stdio.h>  // For printf

int main(void)
{
    int height;

    // Ask the user for the pyramid height (the number should be between (1 - 8))
    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    // Build the pyramid row by row
    for (int row = 0; row < height; row++)
    {
        // Print spaces to right-align the pyramid
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }

        // Print hashes for the current row
        for (int hash = 0; hash <= row; hash++)
        {
            printf("#");
        }

        // Move to the next row
        printf("\n");
    }
}

/*
Example
height: 5;
    #
   ##
  ###
 ####
#####
*/
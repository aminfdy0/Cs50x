#include <cs50.h> //for use get_string function
#include <stdio.h> // for use printf function

int main(void)
{
    // ask the user for enter the name
    string name = get_string("what's your name? ");
    // printf "hello" + (name of user)
    printf("hello, %s\n", name);
}
/*\
Exmple of output
what's your name? AminFdy
hello AminFdy (followd by new line)
*/
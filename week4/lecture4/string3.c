// Capitalizes a string

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get a string
    char* s = get_string("s: ");

    // Copy string's address
    //it’s a copy of the pointer “s” not copy of the text and (s & t) in this case can access the same string variable and any operation on (s & t) will applied on the same string variable.
    // this occurs because “s” is just address, like creating pointer in other data type and save address to it.
    char* t = s;

    //use if to be sure that there are at least one character in “t” before change it to avoid errors.
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

/*
    // Capitalize first letter in string
    t[0] = toupper(t[0]);
*/

    // Print string twice
    printf("s: %s\n", s); // Capitalizes a string
    printf("t: %s\n", t); // Capitalizes a string
}

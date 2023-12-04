// Capitalizes a copy of a string

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> //malloc, free
#include <string.h>

int main(void)
{
    // Get a string
    char *s = get_string("s: ");

    // Allocate memory for another string
    //creates a block of memory that equal the length of the string “s” plus one.
    // This allows for the inclusion of the null “\0” character in our final, copied string.
    char *t = malloc(strlen(s) + 1); //(malloc(x)) function create a space in heap memory (not in static) with size “x” bytes and return it’s address.
    // if (malloc) can’t find the target memory size it returns “NULL”, to be sure that work correctly we check it by if statement.
    if (t == NULL)
    {
	    return 1;
    }

    // Copy string into memory, including '\0'
    char v[6]; // another solution to copy string but this work in static memory.

    // create the variable (n) will make the loop more fast because the (strlen) fun. run only one time rather than run every time in the loop.
    for (int i = 0, n = strlen(s) + 1; i < n; i++)
    {
        t[i] = s[i]; // copy every byte from “s” to “t” arrays
    }

    // Capitalize copy
    //in this case the address of “s” and “t” are different and located in different location of memory.
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    // Print strings
    printf("s: %s\n", s); // not capitalized string
    printf("t: %s\n", t); // Capitalizes a string
    // Free memory
    //must use free fun. when using malloc fun. to  avoid memory errors (memory leak).
    free(t);
}

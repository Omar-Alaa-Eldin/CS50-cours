// Compares two strings' addresses

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // the name of any array it just a pointer to the first element only and must input the size of it at declaring step.
    // Get two strings

    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // Compare strings' addresses
    //produce different always because it compare (*s) with (*t) in hexadecimal format and they have different value.
    //from that we can’t use (==) to compare string data or any array, but it can work with char data.
    printf("%p\n%p\n", s, t); //prove that “s” has different value of “t”.
    if (s == t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}

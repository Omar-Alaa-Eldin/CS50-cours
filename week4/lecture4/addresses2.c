// Stores and prints an integer's address

#include <stdio.h>

//define a data type to the pointer we will use.
typedef int* pointer;


int main(void)
{
    // (&) provides the address of something stored in memory.
    // (*) instructs the compiler to go to a location in memory.
    //save the address of integer in a pointer “p”.
    int n = 50;
    int *p = &n;
    // or we can define the pointer with pointer data type rather than use “*”.
    pointer s = &n;
    printf("%p\n%p\n", p, s);
    //print the integer of the pointer.
    printf("%i\n", *p);
    //printf("%i\n", (int) p); //format specifies type 'int' but the argument has type 'int *' [-Werror,-Wformat]
    printf("%p\n",  p);
}


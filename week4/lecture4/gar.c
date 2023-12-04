//garbage values is a remnants data in the memory can be confused with our data if we take any memory without assign it to values.
// for that it’s not recommended to declare empty variable or pointer of take any pieces of memory without assign it.

#include <stdio.h>

int main(void)
{
    int arr[5000]; //declare empty array
    for (int i =0; i < 5000; i++)
    {
	    printf("%i\n", arr[i]);
    }
}


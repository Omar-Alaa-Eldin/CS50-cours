// Demonstrates memory errors via valgrind

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //the memory errors not appear when compile the programme but it occurs inside the ram.
    int *x = malloc(3 * sizeof(int));
    //the index must start from “0” in the memory.
    x[1] = 72;
    x[2] = 73;
    //there are no index “3” for this array in the memory.
    //x[3] = 33;
    //must use free fun. when using malloc fun. after finish the memory to avoid memory crash.
    free(x);
}

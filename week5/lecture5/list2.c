#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // this algorithem take more time to expand the array put it use less memory.
    //creat list using (malloc) fun.
    int* list = malloc(3*sizeof(int));
    if (!list)
    {
        return 1;
    }

    *list = 1;
    *(list+1) = 2;
    *(list+2) = 3;

//creat a new memory to add more elements by using (realloc(<old buffer>, <new size>)) function.
    int* temp = realloc( list, 4 *sizeof(int) );
    // this function give me new buffer of memory with the new size i want and copy the old memory to it.
    if (!temp)
    {
        free(list);
        return 1;
    }
    list = temp;
    //add nem element
    list[3] = 4;

    // Print list
    for (int i = 0; i < 4; i++)
    {
        //printf("%i\n", list[i]);
        printf("%i\n", list[i]);
    }
    free(list);
    return 0;
}
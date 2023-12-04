#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //creat list using (malloc) fun.
    int* list = malloc(3*sizeof(int));
    if (!list)
    {
        return 1;
    }

    *list = 1;
    *(list+1) = 2;
    *(list+2) = 3;

//creat a new memory to add more elements
    int* temp = malloc( 4 *sizeof(int) );
    if (!temp)
    {
        free(list);
        return 1;
    }
//copy the old array.
    for (int i = 0; i < 3; i++)
    {
        temp[i] = list[i];
    }
    //add nem element
    temp[3] = 4;
    //free the old memory
    free(list);
    //rereferencing the old pointer to the new pointer
    list = temp;

    /*
    // List of size 3
    int list[3];

    // Initialize list with numbers
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;
    //this list has costant size, i can't add new elements to it.
    */


    // Print list
    for (int i = 0; i < 4; i++)
    {
        //printf("%i\n", list[i]);
        printf("%i\n", *(list + i));
    }
    free(list);
    return 0;
}
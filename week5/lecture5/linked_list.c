#include <stdio.h>
#include <stdlib.h>

typedef struct node //we must to name the struct at the first to use it's name inside it.
{
    int number;
    struct node *next; //pointer to another node.
}
node;


// this algorithem take less time to expand the array but it use twice the memory of the array.
// the linked arraies don't have index, because it's not continous.
//to access any element in the liked array we use binary search.
int main(int argc, char* argv[])
{
    node* list = NULL;

    for (int i =1; i < argc; i++)
    {
        int number = atoi(argv[i]);
        node* n = malloc(sizeof(node));
        if (!n)
        {
            return 1;
        }
        n -> number = number;
        n -> next = NULL;

        n -> next = list;
        list = n;
    }
//pinting to each pices of the linked node.

    for (node* ptr = list; ptr ; ptr = ptr->next)
    { // using for loop.
        printf("%i\n", ptr->number);
    }
/*
    node* ptr = list;
    while (ptr)
    { // using while loop.
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
*/

//free the memory i used
   node*  ptr = list; // reset the pointer to the last of the linked array to free the memory.
    while (ptr)
    {
        node* temp = ptr->next; //save the next postion
        free(ptr); // free the memory.
        ptr = temp; // step to the next postion i saved earler.
    }
    return 0;
}
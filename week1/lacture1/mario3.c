#include <stdio.h>
#include <cs50.h>
// define my function before the "main" fun. to can be used inside it
int get_size(void);
void print_grid(int size);


int main(void)
{
    //Get size of grid
    int n = get_size();


    //Print grid of bricks
    // calling the fun. by it's name and pass a variable as an argoment
    print_grid(n);
}




























// define a function returning an output nad dosent take input
// "int" mean that the fun. reaturn output and the argument "void" mean that the fun. dosen't take any input
int get_size(void)
{
    // we can define the variabel without give it any value put choose it's data type.
    int n;
    do
    {
        // use the varialble after define it
        n = get_int("Size: ");
    }
    while (n < 1);
    return n;
}

// define a function with an input argoment and dosen't return any output
// "void" mean no out put, "int size" it define the input argoment by it's type and name
void print_grid(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j ++)
        {
            printf("#");
        }
        printf("\n");
    }
}
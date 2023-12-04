#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int array[] = {3,7,9,5,1,0,4};
    for (int i = 0; i < 7; i++)
    {
        printf("%i", array[i]);
    }
    printf("\n");
    for (int i =0; i < 6; i++)
    {
        int x = array[i];
        int n = 0;
        for (int j = i+1; j< 7; j++)
        {
            if (array[j] < x)
            {
                x = array[j];
                n = j;
            }
        }
        array[n] = array[i];
        array[i] = x;
    }
    for (int i = 0; i < 7; i++)
    {
        printf("%i", array[i]);
    }
    printf("\n");
}
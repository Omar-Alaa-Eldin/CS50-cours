#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("start number: ");
    }
    while (n < 0);

    int m;
    do
    {
        m = get_int("end number: ");
    }
    while (m < 0);

    int i = 0;
    while (n < m)
    {
        n = n + (n/3) - (n/4);
        i++;
    }
    printf("the number of years is %i.\n", i);

}
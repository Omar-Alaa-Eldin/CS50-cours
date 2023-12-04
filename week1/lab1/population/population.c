#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // take the start population
    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);

    // take the end population
    int m;
    do
    {
        m = get_int("End number: ");
    }
    while (m < n);

    // calc. the years required
    int i = 0;
    while (n < m)
    {
        n = n + (n / 3) - (n / 4);
        i++;
    }
    // print the result
    printf("Years: %i.\n", i);
}

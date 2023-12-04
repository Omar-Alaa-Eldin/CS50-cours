#include <cs50.h>
#include <stdio.h>

long factorial(long number);

int main(void)
{
    long n = get_long("Type a number: ");
    printf("%li\n",  factorial(n));
}

long factorial(long number)
{
    // Base case: 1! = 1
    if (number == 1)
    {
        return  1;
    }

    // Recursive call: n! = n * (n - 1)!
    return number * factorial(number -  1);
}
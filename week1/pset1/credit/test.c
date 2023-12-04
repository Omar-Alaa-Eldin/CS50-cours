#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long x = 4006300000000014;
    printf("%lo\n", x % 10);
    x = 4006300000000010;
    printf("%lo\n", x % 10);
    printf("%lo\n", x % 20);

}
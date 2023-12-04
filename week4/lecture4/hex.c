#include <stdio.h>

int main(void)
{
    int x = 0x5D;
    int y = 0x9;
    printf("%i\n", x);
    printf("%x\n", x);
    printf("%x\n", (x+y));
    printf("%i\n", y);
    printf("%x\n", (x-y));
    printf("%x\n", (x*y));
    printf("%i\n", (x*y));
}
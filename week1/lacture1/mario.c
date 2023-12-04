#include <stdio.h>

int main(void)
{
   for (int i = 0; i < 4; i++)
   {
    printf("?");
   }
   printf("\n");
   for (int i = 0; i < 3; i++)
   {
    printf("#\n");
   }
   // "const" make the variable constant and it can't chang in the code
   const int n = 5;
   for (int i = 0; i < n; i++)
   {
    for (int j = 0; j < n; j++)
    {
        printf("#");
    }
    printf("\n");
   }
}
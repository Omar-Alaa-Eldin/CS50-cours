#include <stdio.h>


void swap(int a, int b);
void swap2(int* a, int* b);
void swap1(void);
/*
int x = 50;
int  y = 75;
*/

int x=50, y=75; //intioalizing more thane one variable inthe same line
int main(void)
{
    int n =10;
    int m = 25;
    swap(n, m);
    printf("n: %i\nm: %i\n", n,m); // not swapped
    // the value not changed in this case because when pass variables to the function the fun. make a copy of this variables and work on it so any change in this variables not change the main variables.

    //solution to that problem is to create {x, y} as global variables so the (swap) fun cane access it and work with it.
    swap1();
    printf("x: %i\ny: %i\n", x,y); // will swapped
    // another solution is to use pointers.
    swap2(&x, &y);
    printf("x: %i\ny: %i\n", x,y); // will swapped
}



void swap(int a, int b) // local variables pass by values.
{
	int temp = b;
	b = a;
	a = temp;
}

void swap1(void) // work with global variables.
{
	int temp = y;
	y = x;
	x = temp;
}

void swap2(int* a, int* b) // address variables pass by references.
{
	int temp = *b;
	*a = *a;
	*b = temp;
}

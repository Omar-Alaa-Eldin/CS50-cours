// Prints an integer's address

#include <stdio.h>

int main(void)
{
	//print the address of something stored in memory in Hexadecimal format.
    int n = 50;  // initialization of the variable “n”
    // (int*) : “*” refer to data type pointer, and “int” refer to the size of the variable in which this address, in this case int = 4 bytes.
    int* p = &n; // initialization of the pointer “p” and save the address of variable “n” .
    //this mean the pointer “p” refer to the address of the first byte of variable “n” which equal to (4) bytes because it’s contain integer data.
    printf("%i\n", n);
    // “&n” can be literally translated as the address of “n”.
    // “%p” represent a pointer.
    printf("%p\n", &n); // print the address of the variable “n”, which is represent the address of the first byte from the variable’s bytes.
    //”&” return the address of a variable.
    printf("%i\n", *&n); //print the value of the address
    //”*” before the address return the value of this address refer.
    printf("%p\n", p); // print the variable “p” which contain a pointer of variable “n”.
    //pointer data type consist of (8) bytes.
    //declare empty pointer. (not recommended)
    int* m; //declare pointer variable
    m = &n; //assign address for the pointer
    // int x, y, z; this way declaring more than one empty variable with the same data type in one step. (not recommended)
    // <int *x, *y, *z,> for declaring many empty pointers in one step with the same size.  (not recommended)  <int* x, y, z> declare only one pointer “*x” and tow variable “y, z”.
    // “*” this symbol represent the pointer data type and in the same time it is part of the pointer name..
    //beast way to declare empty pointer assign it to a (Null) value.
    int* c = NULL; // avoid garbage value.
    printf("%p\n", c); //out put (nil).
}

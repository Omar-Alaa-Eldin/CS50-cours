// Declares a string without CS50 Library
#include <stdio.h>

int main(void)
{
    //basic way to create string in C.
    //it’s a special case for the string data when create pointer (char*) we don’t need to assign an address to it but we write the string directly and the pointer declare an array from this character and save the address of the first character.
    int n = 50; //declare variable “n”, and assign value “50” to it.
    int* p = &n; //assign the address of the variable “n” to the pointer “p”.
    //<int* p = 50;> // not allowed to assign a value to a pointer rather than address.

    char c = 'a';
    char* b = &c; //in this case (char*) it’s just a pointer save the address of the variable “c” with size one byte because it’s store a char data type. (not string = array of char )

    char *s = "HI!"; // allowed to assign a string value to this pointer only.
    // in these case the (char*) represent a string = (array of char) and “s” save the address of the first character in the array and has no definite size it take memory until the last character which equal automatically “NULL = \0”.

    printf("%s\n", s); // print the all array of the characters starting from the address of “s” pointer which is the first charachter. (by identifier “%s”)
    printf("%s\n", s+1);
    printf("%s\n\n", s+2);

    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n\n", s[2]);

    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));
    printf("%c\n\n", *(s+3));
    //printf("%c\n\n", *(s+50000)); //Segmentation fault (core dumped)

    printf("%p\n", s);
    //printf("%p\n", s[0]);//produce error, s[0] = (*s) so that it represent the value of the char byte not the address of it.

    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}

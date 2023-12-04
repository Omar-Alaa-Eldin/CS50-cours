// Prints a string's address as well the addresses of its chars

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //C/C++ language not has data type (string), it created by array of character.
    //string type take any number of bytes every byte separate from other and contain one character like array of characters (char arr[]).
    //in the (string s) actually “s” is pointer for the first character of the string variable equivalent to (char* s) and has size (1) byte, so actually “s” return an address.
    //(string s) equivalent to (char *s)
    string s = "HI!";
    printf("%s\n", s); //print the variable string value.
    // “s” act like a pointer for the first character of the string.
    printf("%p\n", s); // print the address of the first character
    printf("%c\n", s[0]); // print the value of the first character
    printf("%p\n", &s[0]); // print the address of the first character (other way)
    printf("%p\n%p\n", s, &s[0]); // prove that (s = &s[0]).
    printf("%p\n", &s[1]); // print the address of the second character
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
    printf("%c\n", *&s[1]);
    printf("%c\n", *&s[2]);
    printf("%c\n", *&s[3]);//the "NULL" vlaue
    printf("%c\n", *&s[4]);//out of the range of the string, out put garpag value.

}

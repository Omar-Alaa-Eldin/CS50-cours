#include <stdio.h>

typedef char* string; //create the string data type manually.
// replace the cs50 library to can use string data type without it.

int main(void)
{
    string s =  "HI!";
    printf("%s\n", s);
    string m = "omar";
    for (int i = 0; i < 4;  i++, printf("\n"))
    {
	    printf("%c", m[i]); //print the value of every character in the characters array
        printf("%c", *m); // print the value of the address “s”, which equal to the first character
        printf("%c", *m + i); // print the value of the address “s”, which equal to the first character, then adding the value of “I” so we get chain aphetically start from first character and go throw in the aphetically order.
        printf("%c", *(m + i)); // in this case we adding the value “I” to the address before print it so we can print all the array of char character by character.
    }
}
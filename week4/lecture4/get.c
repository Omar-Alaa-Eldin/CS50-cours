//(scanf) function, work without (get) functions.
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x; //initialize the variable automatically but (char*) must initialized manually.
    char* s = NULL; //in this case “s” has no address value (empty).
    char* t = malloc( sizeof(char) * 6); //not work correctly because the string need to open space to save whate ever we write.
    //if the user writes more than 6 byte string the programme will crash.
    // this problem not solved in this way???
    // (sizeof) function return the size of a specified data type, in this chase (char) return (1) byte.
    if ( t == NULL)
    {
	return 1;
    }


    printf("X: ");
    scanf("%i", &x);
    // take the input from the user and return this value to the address “&x” of the variable “x”.
    printf("S: ");
    scanf("%s", s); // not use “&s” because “s” itself is address.
    printf("T: ");
    scanf("%s", t);


    printf("X: %i\n", x);
    printf("S: %s\n", s);
    printf("t: %s\n", t);

    free(t);
}
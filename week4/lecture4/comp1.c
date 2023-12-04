// Compares two strings using strcmp

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get two strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // Compare strings
    // the fun. (strcmp) compare the character itself not the pointers.
    if (strcmp(s, t) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
    //compare first and second character only and can compare all word manually like this
	if (*s == *t  && *(s+1) == *(t+1))
    	{
       		printf("Same\n");
    	}
    	else
    	{
     		printf("Different\n");
    	}

}

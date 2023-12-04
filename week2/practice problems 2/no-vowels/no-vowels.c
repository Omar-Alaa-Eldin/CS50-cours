// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

void check(string t);

typedef struct
{
    char a;
    char e;
    char i;
    char o;
} vowels;

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word");
        return 1;
    }
    string txt = argv[1];
    check(txt);
    printf("%s\n", txt);
}

void check(string t)
{
    vowels v;
    v.a = '6';
    v.e = '3';
    v.i = '1';
    v.o = '0';
    for (int i = 0, l = strlen(t); i < l; i++)
    {
        // if (t[i] == 'a' )
        //{
        //     t[i] = v.a;
        // }
        switch (t[i])
        {
            case 'a':
                t[i] = v.a;
                break;
            case 'e':
                t[i] = v.e;
                break;
            case 'i':
                t[i] = v.i;
                break;
            case 'o':
                t[i] = v.o;
                break;
        }
    }
}
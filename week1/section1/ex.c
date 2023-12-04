// header files are the liberaries that i want to use in my file, it's contain the functions i will call in my code.
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("what's your name? ");
    int age = get_int("what's your age? ");
    string number = get_string("what's your phone number? ");

    printf("Age is %i. Name is %s. Phone number is %s.\n", age, name, number);
}
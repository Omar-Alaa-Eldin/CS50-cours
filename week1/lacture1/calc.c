#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // define log integer it make the code use 64 bit of RAM to acess larger number
    long x = get_long("x: ");
    long y = get_long("y: ");
    // define a float variable to store a decimal piont
    // we need to chang the type of 'x' & 'y' to float to make right process and produce the numbers after the decimal point
    // float z = (float) x / (float) y;  // result 0.33333334326744079590

    // "double" like 'long' using 64 bit not 32 bit, it make the calculation more accurate
    double z = (double) x / (double) y; // result 0.33333333333333331483

    // "%li" represent long integer rather than "%i" normal integer
    // printf("%li\n", x + y);
    // "%f" repesent a float variable with decimal point
    //'.20' decide the number of digits after the decimal point
    printf("%.20f\n", z);
}
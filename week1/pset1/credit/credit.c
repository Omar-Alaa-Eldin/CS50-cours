#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // Ask user for credit card number
    long store;
    do
    {
        store = get_long("Number: ");
    }
    while (store < 0);

    // calculating the amount of digits
    long cnumber = store;
    int digits;

    for (digits = 0; cnumber > 0; digits++)
    {
        cnumber /= 10;
    }

    // calculating the checksum
    long checkcredit = store;
    int sum = 0;
    int s2 = 0;
    for (int duo = 0; checkcredit > 0; duo++, checkcredit /= 10)
    {
        if (duo % 2 == 0)
        {
            sum += (checkcredit % 10);
        }
        else
        {
            if ((checkcredit % 10) * 2 >= 10)
            {
                s2 += 1 + (checkcredit % 10) * 2 - 10;
            }
            else
            {
                s2 += (checkcredit % 10) * 2;
            }
        }
    }
    sum += s2;
    // printf("%i ", sum1);
    sum = sum % 10;

    // conditions for varification of the card
    if (sum == 0)
    {
        if (digits != 13 && digits != 15 && digits != 16)
        {
            printf("INVALID\n");
        }
        else if (digits == 16 || digits == 13)
        {
            if (digits == 16 && (store >= 51e14 && store < 56e14))
            {
                printf("MASTERCARD\n");
            }
            else if ((digits == 13 || digits == 16) && ((store <= 4e13 && store < 5e13) || (store >= 4e15 && store < 5e15)))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (digits == 15)
        {
            if ((store >= 34e13 && store < 35e13) || (store >= 37e13 && store < 38e13))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

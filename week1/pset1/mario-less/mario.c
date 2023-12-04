#include <cs50.h>
#include <stdio.h>

int get_height(void);
void draw_lader(int height);


int main(void)
{
    //Get Height of pyramid
    int h = get_height();

    //draw the pyramid
    draw_lader(h);
}








int get_height(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    return h;
}

void draw_lader(int height)
{
    for (int i = 0; i < height; i++)
    {
        //print spaces
        for (int j = i + 1; j < height; j++)
        {
            printf(" ");
        }
        //print first pyramed
        for (int x = i + 1; x > 0; x--)
        {
            printf("#");
        }
        printf("\n");
    }
}
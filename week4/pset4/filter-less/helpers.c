#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef uint8_t BYTE;

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float G = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            // round automatically value.
            G = rint(G);
            image[i][j].rgbtRed = G;
            image[i][j].rgbtGreen = G;
            image[i][j].rgbtBlue = G;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int R = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int G = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int B = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            if (R > 255)
            {
                R = 255;
            }
            if (G > 255)
            {
                G = 255;
            }
            if (B > 255)
            {
                B = 255;
            }
            image[i][j].rgbtRed = R;
            image[i][j].rgbtGreen = G;
            image[i][j].rgbtBlue = B;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // round to the lowest value.
        int c = round(width / 2.0);
        for (int j = 0; j < c; j++)
        {
            int k = width - j - 1;
            if (k == j)
            {
                break;
            }
            BYTE red = image[i][j].rgbtRed;
            BYTE green = image[i][j].rgbtGreen;
            BYTE blue = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = image[i][k].rgbtRed;
            image[i][j].rgbtGreen = image[i][k].rgbtGreen;
            image[i][j].rgbtBlue = image[i][k].rgbtBlue;
            image[i][k].rgbtRed = red;
            image[i][k].rgbtGreen = green;
            image[i][k].rgbtBlue = blue;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // make another copy of the imag
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float R, G, B;
            if (i == 0 && j == 0) // topleft
            {
                R = round((copy[0][0].rgbtRed + copy[0][1].rgbtRed + copy[1][1].rgbtRed + copy[1][0].rgbtRed) / 4.0);
                G = round((copy[0][0].rgbtGreen + copy[0][1].rgbtGreen + copy[1][1].rgbtGreen + copy[1][0].rgbtGreen) / 4.0);
                B = round((copy[0][0].rgbtBlue + copy[0][1].rgbtBlue + copy[1][1].rgbtBlue + copy[1][0].rgbtBlue) / 4.0);
                image[0][0].rgbtRed = R;
                image[0][0].rgbtGreen = G;
                image[0][0].rgbtBlue = B;
            }
            else if (i == 0 && j == width - 1) // topright
            {
                R = round((copy[0][width - 1].rgbtRed + copy[0][width - 2].rgbtRed + copy[1][width - 2].rgbtRed +
                           copy[1][width - 1].rgbtRed) /
                          4.0);
                G = round((copy[0][width - 1].rgbtGreen + copy[0][width - 2].rgbtGreen + copy[1][width - 2].rgbtGreen +
                           copy[1][width - 1].rgbtGreen) /
                          4.0);
                B = round((copy[0][width - 1].rgbtBlue + copy[0][width - 2].rgbtBlue + copy[1][width - 2].rgbtBlue +
                           copy[1][width - 1].rgbtBlue) /
                          4.0);
                image[0][width - 1].rgbtRed = R;
                image[0][width - 1].rgbtGreen = G;
                image[0][width - 1].rgbtBlue = B;
            }
            else if (i == height - 1 && j == 0) // bottomleft
            {
                R = round((copy[height - 1][0].rgbtRed + copy[height - 2][0].rgbtRed + copy[height - 2][1].rgbtRed +
                           copy[height - 1][1].rgbtRed) /
                          4.0);
                G = round((copy[height - 1][0].rgbtGreen + copy[height - 2][0].rgbtGreen + copy[height - 2][1].rgbtGreen +
                           copy[height - 1][1].rgbtGreen) /
                          4.0);
                B = round((copy[height - 1][0].rgbtBlue + copy[height - 2][0].rgbtBlue + copy[height - 2][1].rgbtBlue +
                           copy[height - 1][1].rgbtBlue) /
                          4.0);
                image[height - 1][0].rgbtRed = R;
                image[height - 1][0].rgbtGreen = G;
                image[height - 1][0].rgbtBlue = B;
            }
            else if (i == height - 1 && j == width - 1) // bottomright
            {
                R = round((copy[height - 1][width - 1].rgbtRed + copy[height - 2][width - 1].rgbtRed +
                           copy[height - 2][width - 2].rgbtRed + copy[height - 1][width - 2].rgbtRed) /
                          4.0);
                G = round((copy[height - 1][width - 1].rgbtGreen + copy[height - 2][width - 1].rgbtGreen +
                           copy[height - 2][width - 2].rgbtGreen + copy[height - 1][width - 2].rgbtGreen) /
                          4.0);
                B = round((copy[height - 1][width - 1].rgbtBlue + copy[height - 2][width - 1].rgbtBlue +
                           copy[height - 2][width - 2].rgbtBlue + copy[height - 1][width - 2].rgbtBlue) /
                          4.0);
                image[height - 1][width - 1].rgbtRed = R;
                image[height - 1][width - 1].rgbtGreen = G;
                image[height - 1][width - 1].rgbtBlue = B;
            }
            else if (i == 0 && j != 0 && j != width - 1) // top
            {
                R = round((copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed +
                           copy[i + 1][j + 1].rgbtRed + copy[i][j + 1].rgbtRed) /
                          6.0);
                G = round((copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen +
                           copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen + copy[i][j + 1].rgbtGreen) /
                          6.0);
                B = round((copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue +
                           copy[i + 1][j + 1].rgbtBlue + copy[i][j + 1].rgbtBlue) /
                          6.0);
                image[i][j].rgbtRed = R;
                image[i][j].rgbtGreen = G;
                image[i][j].rgbtBlue = B;
            }
            else if (i != 0 && i != height - 1 && j == 0) // left
            {
                R = round((copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j + 1].rgbtRed +
                           copy[i + 1][j + 1].rgbtRed + copy[i + 1][j].rgbtRed) /
                          6.0);
                G = round((copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen +
                           copy[i][j + 1].rgbtGreen + copy[i + 1][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen) /
                          6.0);
                B = round((copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j + 1].rgbtBlue +
                           copy[i + 1][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue) /
                          6.0);
                image[i][j].rgbtRed = R;
                image[i][j].rgbtGreen = G;
                image[i][j].rgbtBlue = B;
            }
            else if (i != 0 && i != height - 1 && j == width - 1) // right
            {
                R = round((copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i][j - 1].rgbtRed +
                           copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed) /
                          6.0);
                G = round((copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                           copy[i][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen) /
                          6.0);
                B = round((copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i][j - 1].rgbtBlue +
                           copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue) /
                          6.0);
                image[i][j].rgbtRed = R;
                image[i][j].rgbtGreen = G;
                image[i][j].rgbtBlue = B;
            }
            else if (i == height - 1 && j != 0 && j != width - 1) // bottom
            {
                R = round((copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed +
                           copy[i - 1][j + 1].rgbtRed + copy[i][j + 1].rgbtRed) /
                          6.0);
                G = round((copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                           copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j + 1].rgbtGreen) /
                          6.0);
                B = round((copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue +
                           copy[i - 1][j + 1].rgbtBlue + copy[i][j + 1].rgbtBlue) /
                          6.0);
                image[i][j].rgbtRed = R;
                image[i][j].rgbtGreen = G;
                image[i][j].rgbtBlue = B;
            }
            else
            {
                R = round((copy[i][j].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed +
                           copy[i][j - 1].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed +
                           copy[i + 1][j + 1].rgbtRed) /
                          9.0);
                G = round((copy[i][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen +
                           copy[i - 1][j + 1].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i][j + 1].rgbtGreen +
                           copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) /
                          9.0);
                B = round((copy[i][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue +
                           copy[i - 1][j + 1].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i][j + 1].rgbtBlue +
                           copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) /
                          9.0);
                image[i][j].rgbtRed = R;
                image[i][j].rgbtGreen = G;
                image[i][j].rgbtBlue = B;
            }
        }
    }
    return;
}

#include "helpers.h"
#include <math.h>

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
            int n = 0;
            int iline[] = {i - 1, i, i + 1};
            int jline[] = {j - 1, j, j + 1};
            float R = 0, G = 0, B = 0;

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int x = iline[r];
                    int y = jline[c];

                    if (x >= 0 && x < height && y >= 0 && y < width)
                    {
                        RGBTRIPLE p = image[x][y];
                        R += image[x][y].rgbtRed;
                        G += image[x][y].rgbtGreen;
                        B += image[x][y].rgbtBlue;
                        n++;
                    }
                }
            }
            copy[i][j].rgbtRed = round(R / n);
            copy[i][j].rgbtGreen = round(G / n);
            copy[i][j].rgbtBlue = round(B / n);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // make copy of image
    RGBTRIPLE copy[height][width];
    // apply the edge detection algorithm
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int iline[] = {i - 1, i, i + 1};
            int jline[] = {j - 1, j, j + 1};
            float Gx_R = 0, Gx_G = 0, Gx_B = 0;
            float Gy_R = 0, Gy_G = 0, Gy_B = 0;

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int x = iline[r];
                    int y = jline[c];
                    if (x >= 0 && x < height && y >= 0 && y < width)
                    {
                        RGBTRIPLE p = image[x][y];
                        Gx_R += Gx[r][c] * p.rgbtRed;
                        Gx_G += Gx[r][c] * p.rgbtGreen;
                        Gx_B += Gx[r][c] * p.rgbtBlue;

                        Gy_R += Gy[r][c] * p.rgbtRed;
                        Gy_G += Gy[r][c] * p.rgbtGreen;
                        Gy_B += Gy[r][c] * p.rgbtBlue;
                    }
                }
            }
            // apply the sqrt fun to the Gx and Gy
            int fr = round(sqrt(pow(Gx_R, 2) + pow(Gy_R, 2)));
            int fb = round(sqrt(pow(Gx_B, 2) + pow(Gy_B, 2)));
            int fg = round(sqrt(pow(Gx_G, 2) + pow(Gy_G, 2)));

            copy[i][j].rgbtRed = fr > 255 ? 255 : fr;
            copy[i][j].rgbtGreen = fg > 255 ? 255 : fg;
            copy[i][j].rgbtBlue = fb > 255 ? 255 : fb;
        }
    }

    // copy the result to final image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}

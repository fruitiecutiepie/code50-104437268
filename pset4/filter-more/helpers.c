#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - j];
            image[i][width - j] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_copy[height][width];

    // Copy each original pixel values of image to image_copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_copy[i][j] = image[i][j];
        }
    }

    // Blur each pixel according to the average RGB values of its adjacent pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize the average of each RGB values & each addition of value
            int avgRed = 0, avgGreen = 0, avgBlue = 0, counter = 0;

            // Initialize boundaries of corresponding pixel
            int rmin = -1, rmax = 1, cmin = -1, cmax = 1;

            if image_copy[i ]

            // Calculate the sum of each RGB values within 1 row and column of the original pixel
            for (int r = rmin; r <= rmax; r++)
            {
                for (int c = cmin; c <= cmax; c++)
                {
                    avgRed += image_copy[i + r][j + c].rgbtRed;
                    avgGreen += image_copy[i + r][j + c].rgbtGreen;
                    avgBlue += image_copy[i + r][j + c].rgbtBlue;
                    counter++;
                }
            }

            // Calculate the average of each RGB values within 1 row and column of the original pixel
            avgRed = round(avgRed / counter);
            avgGreen = round(avgGreen / counter);
            avgBlue = round(avgBlue / counter);

            // Assign each new RGB values to the original pixel
            image[i][j].rgbtRed = avgRed;
            image[i][j].rgbtGreen = avgGreen;
            image[i][j].rgbtBlue = avgBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

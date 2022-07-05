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
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize variables for the average of RGB values respectively & changes counter
            int avgRed = 0, avgGreen = 0, avgBlue = 0, counter = 0;

            // Calculate the sum of RGB values within 1 row and column of the original pixel respectively
            while (true)
            {
                for (int r = -1; r <= 1; r++)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        avgRed += image[i + r][j + c].rgbtRed;
                        avgGreen += image[i + r][j + c].rgbtGreen;
                        avgBlue += image[i + r][j + c].rgbtBlue;
                        counter++;
                    }
                }
            }

            // Calculate the average of RGB values within 1 row and column of the original pixel respectively
            avgRed /= counter;
            avgGreen /= counter;
            avgBlue /= counter;

            // Assign new RGB values to the original pixel respectively
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

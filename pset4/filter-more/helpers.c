#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            image[i][j].rgbtRed = round(avg);
            image[i][j].rgbtGreen = round(avg);
            image[i][j].rgbtBlue = round(avg);
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
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;
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
            int avgRed = 0, avgGreen = 0, avgBlue = 0;
            float counter = 0;

            // Initialize boundaries of the corresponding pixel
            int rmin = -1, rmax = 1, cmin = -1, cmax = 1;

            // Determine if the corresponding pixel is at the very top of the image
            if (i == 0)
            {
                rmin = 0;
            }

            // Determine if the corresponding pixel is at the very bottom of the image
            if (i == height - 1)
            {
                rmax = 0;
            }

            // Determine if the corresponding pixel is a the very left of the image
            if (j == 0)
            {
                cmin = 0;
            }

            // Determine if the corresponding pixel is at the very right of the image
            if (j == width - 1)
            {
                cmax = 0;
            }

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

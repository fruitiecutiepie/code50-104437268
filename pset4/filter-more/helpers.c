#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // For each pixel:
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate average RGB value and assign it to each pixel
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
    // For each pixel:
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap each pixel value with 
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
    RGBTRIPLE copy[height][width];

    // Copy each original pixel values of image to image_copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // For each pixel: blur according to the average RGB values of its adjacent pixels
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
                    avgRed += copy[i + r][j + c].rgbtRed;
                    avgGreen += copy[i + r][j + c].rgbtGreen;
                    avgBlue += copy[i + r][j + c].rgbtBlue;
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
    RGBTRIPLE copy[height][width];

    // Copy each original pixel values of image to image_copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // For each pixel: blur according to the average RGB values of its adjacent pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize the average of each RGB values & each addition of value
            int GxRed = 0, GxGreen = 0, GxBlue = 0;
            int GyRed = 0, GyGreen = 0, GyBlue = 0;
            float counter = 0;

            // Initialize boundaries of the corresponding pixel
            int rmin = -1, rmax = 1, cmin = -1, cmax = 1;

            // Define Gx matrix
            int Gx[3][3] = {
                {-1, 0, 1},
                {-2, 0, 2},
                {-1, 0, 1},
            };

            // Define Gy matrix
            int Gy[3][3] = {
                {-1, -2, -1},
                {0, 0, 0},
                {1, 2, 1},
            };

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
                    GxRed += copy[i + r][j + c].rgbtRed;
                    GxGreen += copy[i + r][j + c].rgbtGreen;
                    GxBlue += copy[i + r][j + c].rgbtBlue;
                    counter++;
                }
            }

            // Calculate the average of each RGB values within 1 row and column of the original pixel
            int Red = round(sqrt(GxRed) + sqrt(GyRed));
            int Green = round(sqrt(GxGreen) + sqrt(GyGreen));
            int Blue = round(sqrt(GxBlue) + sqrt(GyBlue));

            // // Assign each new RGB values to the original pixel
            image[i][j].rgbtRed = Red;
            image[i][j].rgbtGreen = Green;
            image[i][j].rgbtBlue = Blue;
        }
    }
    return;
}

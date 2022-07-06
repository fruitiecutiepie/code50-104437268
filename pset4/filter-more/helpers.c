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
            // Swap the value of each pixel with that of its equivalent when reflected
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

            // Initialize boundaries of each pixel
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

            // Determine if the corresponding pixel is at the very left of the image
            if (j == 0)
            {
                cmin = 0;
            }

            // Determine if the corresponding pixel is at the very right of the image
            if (j == width - 1)
            {
                cmax = 0;
            }

            // For each pixel that is within 1 row and column of the original pixel:
            for (int r = rmin; r <= rmax; r++)
            {
                for (int c = cmin; c <= cmax; c++)
                {
                    // Calculate the sum of each RGB values within 1 row and column of the original pixel
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

    // For each pixel: highlight edges by applying the Sobel operator
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize boundaries of each pixel & Gx and Gy matrix
            int rmin = -1, rmax = 1, cmin = -1, cmax = 1;

            // Define Gx matrix
            int Gx[3][3] =
            {
                {-1, 0, 1},
                {-2, 0, 2},
                {-1, 0, 1},
            };

            // Define Gy matrix
            int Gy[3][3] =
            {
                {-1, -2, -1},
                {0, 0, 0},
                {1, 2, 1},
            };

            // Determine if the corresponding pixel is at the very top of the image
            if (i == 0)
            {
                rmin++;
            }

            // Determine if the corresponding pixel is at the very bottom of the image
            if (i == height - 1)
            {
                rmax--;
            }

            // Determine if the corresponding pixel is at the very left of the image
            if (j == 0)
            {
                cmin++;
            }

            // Determine if the corresponding pixel is at the very right of the image
            if (j == width - 1)
            {
                cmax--;
            }

            // Initialize the sum of each RGB's Gx and Gy values
            int GxRed = 0, GxGreen = 0, GxBlue = 0;
            int GyRed = 0, GyGreen = 0, GyBlue = 0;

            // For each pixel that is within 1 row and column of the original pixel:
            for (int r = rmin; r <= rmax; r++)
            {
                for (int c = cmin; c <= cmax; c++)
                {
                    // Calculate the sum of each RGB's Gx value within 1 row and column of the original pixel
                    GxRed += copy[i + r][j + c].rgbtRed * Gx[r + 1][c + 1];
                    GxGreen += copy[i + r][j + c].rgbtGreen * Gx[r + 1][c + 1];
                    GxBlue += copy[i + r][j + c].rgbtBlue * Gx[r + 1][c + 1];

                    // Calculate the sum of each RGB's Gy value within 1 row and column of the original pixel
                    GyRed += copy[i + r][j + c].rgbtRed * Gy[r + 1][c + 1];
                    GyGreen += copy[i + r][j + c].rgbtGreen * Gy[r + 1][c + 1];
                    GyBlue += copy[i + r][j + c].rgbtBlue * Gy[r + 1][c + 1];
                }
            }

            // Combine Gx and Gy into a final value
            int Red = round(sqrt(pow(GxRed, 2) + pow(GyRed, 2)));
            int Green = round(sqrt(pow(GxGreen, 2) + pow(GyGreen, 2)));
            int Blue = round(sqrt(pow(GxBlue, 2) + pow(GyBlue, 2)));

            // Limit each RGB final value to 255
            if (Red > 255)
            {
                Red = 255;
            }
            if (Green > 255)
            {
                Green = 255;
            }
            if (Blue > 255)
            {
                Blue = 255;
            }

            // // Assign each new RGB value to the original pixel
            image[i][j].rgbtRed = Red;
            image[i][j].rgbtGreen = Green;
            image[i][j].rgbtBlue = Blue;
        }
    }
    return;
}

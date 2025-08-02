#include "helpers.h"

/*
typedef uint8_t  BYTE;
reminder of RGBTRIPLE
typedef struct
{
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;
*/

// how am I going to compute neibourghs?
// Convert image to grayscale
/*
Same values for rgb (as they approach to 0) we get clearer greys until blck,
mayb we can do the avg per pixel and cast to int
*/
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gray_tone =
                (int) (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;
            image[i][j].rgbtRed = gray_tone;
            image[i][j].rgbtGreen = gray_tone;
            image[i][j].rgbtBlue = gray_tone;
        }
    }
    return;
}

// Reflect image horizontally
/*
Uhm for every row invert order of the indexes
*/
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE original_value = image[i][j];
            image[i][j] = image[i][width - j - 1]; // we then put the current position its opposite
                                                   // (e.g for 0 we put 7 (if we assume width is 8))
            image[i][width - j - 1] =
                original_value; // we do the second swap, before we assigned to the first position
                                // the last, now we go to the lastand assign the
                                // first(original_value)
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red_sum = 0;
            int blue_sum = 0;
            int green_sum = 0;
            int cter = 0; // to compute avg

            // now for every pixel we are we want to get neighbours and we can do such as
            // from current x,y "scan" from (-1, -1) (top lef corner) to (1,1) (top right corner)
            // skipping myself so we probably need another double loop?
            for (int coord_x = -1; coord_x <= 1; coord_x++)
            {
                for (int coord_y = -1; coord_y <= 1; coord_y++)
                {
                    int new_i = i + coord_x; // calculate new i
                    int new_j = j + coord_y; // calculate new j

                    // we also check if it's a valid neighbour if it's inside height & width of img
                    // using indx
                    if (new_i >= 0 && new_i < height && new_j >= 0 && new_j < width &&
                        (coord_x != 0 || coord_y != 0))
                    {
                        red_sum += image[new_i][new_j].rgbtRed;
                        blue_sum += image[new_i][new_j].rgbtBlue;
                        green_sum += image[new_i][new_j].rgbtGreen;
                        cter++;
                    }
                }
            }

            // here we have completed an entire pixel and its neighs
            if (cter > 0)
            {
                tmp[i][j].rgbtRed = red_sum / cter;
                tmp[i][j].rgbtBlue = blue_sum / cter;
                tmp[i][j].rgbtGreen = green_sum / cter;
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tmp[i][j];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

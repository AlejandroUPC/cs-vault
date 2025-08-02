// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    // we declare here a fix array to just copye the bytes
    BYTE wav_header[HEADER_SIZE];
    fread(wav_header, HEADER_SIZE, 1, input);
    fwrite(wav_header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file
    // uhm
    int16_t buffer; //only one per sample, no need array
    // ** KINDA STRUGGLED HERE, WHEN READING/WRITTING
    // the HEADER the pointer of the file updates in place
    // SO WE WONT READ/WRITE those bytes agian FCK **

    while(fread(&buffer, sizeof(int16_t), 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }


    // Close files
    fclose(input);
    fclose(output);
}


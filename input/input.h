/* input.h */

#ifndef INPUT_H
#define INPUT_H

#include <stdint.h>
#include <stdbool.h>

// Define the Input and DataType structures

typedef struct {
    int width;
    int height;
    int channels;
} Dimensions;

// Define the data types supported by the library
typedef enum {
    Int,
    FLOAT32
} DataType;

typedef union {
        int ***int_data;
        float ***float32_data;
} InputData;

typedef enum {
    JPEG,
    JPG,
    PNG,
    GIF,
    TGA,
    BMP,
    PSD,
    HDR,
    PIC
    // Add support for other formats here
} ImageFormat;

// Load an image from file and store it in an InputData struct
InputData* load_input_data_from_image(const char *filename, const Dimensions *input_dimensions, DataType data_type);

// Load an image from disk with a specified format
InputData *load_image_data_with_format(const char *filename, const Dimensions *input_dimensions, DataType data_type, ImageFormat format);

// Load an JPEG image from disk as a float array
float*** loadFloatJPEG(const char* jpegFileName, int* width, int* height);

// Load an JPEG image from disk as a int array
int*** loadIntJPEG(const char* jpegFileName, int* width, int* height);

// Load a PNG image from disk as a float array
float*** loadFloatPNG(const char* pngFileName, int* width, int* height);

// Load a PNG image from disk as a int array
int*** loadIntPNG(const char* pngFileName, int* width, int* height);

// Load an image from disk as a float array
float*** loadFloatImage(const char* fileName, int* width, int* height, int* channels);

// Load an image from disk as a int array
int*** loadIntImage(const char* fileName, int* width, int* height, int* channels);

// Create an empty image
InputData* create_empty_input_data(int width, int height, int channels, DataType data_type, int fill_value);

// Resize an image
void resize_image(InputData **image_data_ptr, const Dimensions original_dimensions, Dimensions new_dimensions, DataType data_type);

// Free the memory associated with an image
void free_image_data(InputData *image_data, Dimensions dimensions, DataType data_type);

#endif /* Input_H */

#ifndef _MY_IMAGE_H_
#define _MY_IMAGE_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>

/** @brief Type definition for pixel data. */
typedef uint8_t pixelData;

/** @brief Structure representing a pixel point with x and y coordinates. */
typedef struct pixelPoint
{
    unsigned x;
    unsigned y;
} pixelPointT;

/** @brief Structure representing an image. */
struct image
{
    unsigned width, height;
    pixelData *data;
};

typedef struct image imageT, *imageP;

/**
 * @brief Create a new image with the specified width and height.
 * @param width Width of the image.
 * @param height Height of the image.
 * @return Pointer to the created image.
 */
imageP createImage(unsigned width, unsigned height);

/**
 * @brief Fill the image with random pixel data.
 * @param image Pointer to the image structure.
 */
void fillRandom(imageP image);

/**
 * @brief Fill the image with a specified color.
 * @param image Pointer to the image structure.
 * @param color Color value.
 */
void fillColor(imageP image, pixelData color);

/**
 * @brief Free the memory allocated for the image.
 * @param image Pointer to the image structure.
 */
void freeImage(imageP image);

/**
 * @brief Save the image in PGM format to a file.
 * @param image Pointer to the image structure.
 * @param filename Name of the file to save the image to.
 */
int savePgm(imageP image, const char *filename);

/**
 * @brief Get a pointer to the pixel at the specified coordinates.
 * @param image Pointer to the image structure.
 * @param x X-coordinate of the pixel.
 * @param y Y-coordinate of the pixel.
 * @return Pointer to the specified pixel.
 */
pixelData *getPixel(imageP image, unsigned x, unsigned y);

/**
 * @brief Set the color of the pixel at the specified coordinates.
 * @param image Pointer to the image structure.
 * @param x X-coordinate of the pixel.
 * @param y Y-coordinate of the pixel.
 * @param color Color value.
 */
void setPixel(imageP image, unsigned x, unsigned y, unsigned color);

/**
 * @brief Draw a line on the image between two specified points.
 * @param image Pointer to the image structure.
 * @param startPoint Starting point of the line.
 * @param endPoint Ending point of the line.
 * @param color Color value.
 */
void drawLine(imageP image, pixelPointT startPoint, pixelPointT endPoint, unsigned color);

#endif // _MY_IMAGE_H_

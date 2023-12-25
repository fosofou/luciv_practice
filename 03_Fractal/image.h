#ifndef _MY_IMAGE_H_
#define _MY_IMAGE_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>

typedef uint8_t pixelData;

typedef struct pixelPoint
{
    unsigned x;
    unsigned y;
} pixelPointT;

struct image
{
    unsigned width, height;
    pixelData *data;
};

typedef struct image imageT, *imageP;

imageP createImage(unsigned width, unsigned height);

void fillRandom(imageP image);

void fillColor(imageP image, pixelData color);

void freeImage(imageP image);

int savePgm(imageP image, const char *filename);

pixelData *getPixel(imageP image, unsigned x, unsigned y);

void setPixel(imageP image, unsigned x, unsigned y, unsigned color);

void drawLine(imageP image, pixelPointT startPoint, pixelPointT endPoint, unsigned color);

#endif // _MY_IMAGE_H_
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <math.h>

#include "image.h"

imageP createImage(unsigned width, unsigned height) {
    assert(width > 0 && height > 0 && "invalid dimensions");

    imageP newImage = (imageP)malloc(sizeof(imageT));
    newImage->width = width;
    newImage->height = height;
    newImage->data = (pixelData*)malloc(width * height * sizeof(pixelData));
    fillColor(newImage, 0);
    return newImage;
}

void fillRandom(imageP img) {
    assert(img != NULL);
    srand(time(NULL));
    for (unsigned y = 0; y < img->height; ++y) {
        for (unsigned x = 0; x < img->width; ++x) {
            setPixel(img, x, y, rand() % 256);
        }
    }
}

void fillColor(imageP img, pixelData color) {
    assert(color >= 0 && color < 256 && "invalid color");

    for (unsigned y = 0; y < img->height; ++y) {
        for (unsigned x = 0; x < img->width; ++x) {
            setPixel(img, x, y, color);
        }
    }
}

void freeImage(imageP img) {
    free(img->data);
    free(img);
}

int savePgm(imageP img, const char *filename) {
    FILE *to = fopen(filename, "w");
    fprintf(to, "P2\n%u %u\n255\n", img->width, img->height);

    pixelData *p = img->data;
    for(unsigned y = 0; y < img->height; ++y)
        for(unsigned x = 0; x < img->width; ++x)
            fprintf(to, "%u%c", *(p++), x == img->width - 1 ? '\n' : ' ');

    fclose(to);
    return 0;
}

pixelData *getPixel(imageP img, unsigned x, unsigned y) {
    assert(y < img->height && x < img->width && "out of range");
    return &img->data[y * img->width + x];
}

void setPixel(imageP img, unsigned x, unsigned y, unsigned color) {
    assert(y < img->height && x < img->width && "out of range");
    assert(color >= 0 && color < 256 && "invalid color");
    *getPixel(img, x, y) = color;
}

void drawLine(imageP img, pixelPointT p1, pixelPointT p2, unsigned color) {
    assert(color >= 0 && color < 256 && "invalid color");

    int dx = (int)p2.x - (int)p1.x;
    int dy = (int)p2.y - (int)p1.y;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    double x_inc = (double)dx / (double)steps;
    double y_inc = (double)dy / (double)steps;

    double x = (double)p1.x;
    double y = (double)p1.y;

    for (int i = 0; i <= steps; i++) {
        assert(round(x) < img->width && round(y) < img->height && "out of range");

        setPixel(img, round(x), round(y), color);
        x += x_inc;
        y += y_inc;
    }
}
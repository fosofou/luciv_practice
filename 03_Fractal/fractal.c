#include "fractal.h"

void drawMandelbrot(imageP img, float left, float top, float xSide, float ySide) {
    // Maximum number of iterations to determine if a point belongs to the set
    int maxIterations = 1000;

    assert(img != NULL && "img is NULL");
    assert(xSide > 0 && ySide > 0 && "Invalid xSide or ySide");

    double zx, zy, cx, cy, temp;

    for (int y = 0; y < img->height; ++y) {
        for (int x = 0; x < img->width; ++x) {
            zx = zy = 0;
            cx = x * xSide / img->width + left;
            cy = y * ySide / img->height + top;
            int iterations = 0;

            while (zx * zx + zy * zy < 4 && iterations < maxIterations) {
                temp = zx * zx - zy * zy + cx;
                zy = 2 * zx * zy + cy;
                zx = temp;
                ++iterations;
            }

            // color selection depending on the number of iterations
            pixelData color = (iterations == maxIterations) ? 0 : (iterations % 256);
            setPixel(img, x, y, color);
        }
    }
}

void drawSierpinskiTriangle(imageP img, int x1, int y1, int x2, int y2, int x3, int y3, int depth) {
    assert(depth >= 0 && "invalid depth");
    assert(img != NULL && "img is NULL");
    if (depth == 0) {
        drawLine(img, (pixelPointT){x1, y1}, (pixelPointT){x2, y2}, 255);
        drawLine(img, (pixelPointT){x2, y2}, (pixelPointT){x3, y3}, 255);
        drawLine(img, (pixelPointT){x3, y3}, (pixelPointT){x1, y1}, 255);
    } else {
        // Find the midpoints of the sides of the triangle
        int mx1 = (x1 + x2) / 2;
        int my1 = (y1 + y2) / 2;
        int mx2 = (x2 + x3) / 2;
        int my2 = (y2 + y3) / 2;
        int mx3 = (x3 + x1) / 2;
        int my3 = (y3 + y1) / 2;

        // Recursively call the function for each of the new triangles
        drawSierpinskiTriangle(img, x1, y1, mx1, my1, mx3, my3, depth - 1);
        drawSierpinskiTriangle(img, mx1, my1, x2, y2, mx2, my2, depth - 1);
        drawSierpinskiTriangle(img, mx3, my3, mx2, my2, x3, y3, depth - 1);
    }
}
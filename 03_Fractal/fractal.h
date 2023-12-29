#ifndef _FRACTAL_H_
#define _FRACTAL_H_

#include "image.h"
#include <assert.h>

/**
 * @brief Draw the Mandelbrot set
 *
 * @param img Pointer to the image structure.
 * @param left Left boundary of the complex plane.
 * @param top Top boundary of the complex plane.
 * @param xside Width of the complex plane.
 * @param yside Height of the complex plane.
 */
void drawMandelbrot(imageP img, float left, float top, float xside, float yside);

/**
 * @brief Draw a Sierpinski triangle
 *
 * @param img Pointer to the image structure.
 * @param x1 X-coordinate of the first vertex.
 * @param y1 Y-coordinate of the first vertex.
 * @param x2 X-coordinate of the second vertex.
 * @param y2 Y-coordinate of the second vertex.
 * @param x3 X-coordinate of the third vertex.
 * @param y3 Y-coordinate of the third vertex.
 * @param depth Recursion depth for generating the triangle.
 */
void drawSierpinskiTriangle(imageP img, int x1, int y1, int x2, int y2, int x3, int y3, int depth);

#endif // _FRACTAL_H_

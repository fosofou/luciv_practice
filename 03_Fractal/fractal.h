#ifndef _FRACTAL_H_
#define _FRACTAL_H_

#include "image.h"
#include <assert.h>

/**
 * ... text ...
 */
void drawMandelbrot(imageP img, float left, float top, float xside, float yside);

void drawSierpinskiTriangle(imageP img, int x1, int y1, int x2, int y2, int x3, int y3, int depth);

#endif // _FRACTAL_H_

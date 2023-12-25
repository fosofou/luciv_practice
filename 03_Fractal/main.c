#include "image.h"
#include "fractal.h"


int main()
{
    int width = 800;
    int height = 800;

    imageP fractal1 = createImage(width, height);
    
    // Mandelbrot fractal boundaries 
    float left = -2.0;
    float top = -1.5;
    float xSide = 3.0;
    float ySide = 3.0;

    drawMandelbrot(fractal1, left, top, xSide, ySide);
    savePgm(fractal1, "mandelbrot_fractal.pgm");
    freeImage(fractal1);

    imageP fractal2 = createImage(width, height);

    // initial parameters for the Sierpinski triangle
    int x1 = 50, y1 = 550;
    int x2 = 750, y2 = 550;
    int x3 = 400, y3 = 50;
    int depth = 10;

    drawSierpinskiTriangle(fractal2, x1, y1, x2, y2, x3, y3, depth);
    savePgm(fractal2, "sierpinski_triangle_fractal.pgm");
    freeImage(fractal2);

    return 0;
}



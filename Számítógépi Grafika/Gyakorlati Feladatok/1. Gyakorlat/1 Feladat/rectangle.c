#include "rectangle.h"

void setRectangleSize(Rectangle* rectangle, double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return;
    } 
    rectangle->a = a;
    rectangle->b = b;
    rectangle->c = c;
}

double calcRectangleVolume(Rectangle* rectangle) {
    return rectangle->a * rectangle->b * rectangle->c;
}

double calcRectangleSurface(Rectangle* rectangle) {
    return 2 * (rectangle->a * rectangle->b + rectangle->a * rectangle->c + rectangle->b * rectangle->c);
}

bool isSquare(Rectangle* rectangle) {
    if (rectangle->a == rectangle->b || rectangle->a == rectangle->c || rectangle->b == rectangle->c) {
        return true;
    }
    return false;
}
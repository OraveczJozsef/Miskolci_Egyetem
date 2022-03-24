#include <stdio.h>

#include "rectangle.h"

int main(int argc, char** args) {
    Rectangle rectangle;
    double rectangleVolume;
    double rectangleSurface;
    bool rectangleSquare;

    setRectangleSize(&rectangle, 12.1, 13.7, 12.1);

    rectangleVolume = calcRectangleVolume(&rectangle);
    rectangleSurface = calcRectangleSurface(&rectangle);
    rectangleSquare = isSquare(&rectangle);

    printf("Volume: %lf\nSurface: %lf\nSquare: %s\n", rectangleVolume, rectangleSurface, (rectangleSquare ? "Yes" : "No"));

    return 0;
}
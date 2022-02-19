#ifndef RectangleDefine
    #include <math.h>
    #include <stdbool.h>

    #define RectangleDefine

    typedef struct Rectangle {
        double a;
        double b;
        double c;
    } Rectangle;
    
    void setRectangleSize(Rectangle* rectangle, double a, double b, double c);

    double getRectangleVolume(Rectangle rectangle);
    double getRectangleSurface(Rectangle rectangle);

    bool isSquare(Rectangle rectangle);
#endif
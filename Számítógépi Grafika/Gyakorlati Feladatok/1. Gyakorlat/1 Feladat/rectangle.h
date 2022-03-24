#ifndef RectangleDefine
    #define RectangleDefine

    #include <math.h>
    #include <stdbool.h>

    typedef struct Rectangle {
        double a;
        double b;
        double c;
    } Rectangle;
    
    void setRectangleSize(Rectangle* rectangle, double a, double b, double c);

    double calcRectangleVolume(Rectangle* rectangle);
    double calcRectangleSurface(Rectangle* rectangle);

    bool isSquare(Rectangle* rectangle);
#endif
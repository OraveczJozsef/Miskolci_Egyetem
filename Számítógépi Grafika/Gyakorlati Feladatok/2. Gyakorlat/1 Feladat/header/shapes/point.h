#ifndef POINT_HEADER
    #define POINT_HEADER

    typedef struct Point {
        int x;
        int y;
    } Point;

    void addPoint(Point* point, int x, int y);
#endif
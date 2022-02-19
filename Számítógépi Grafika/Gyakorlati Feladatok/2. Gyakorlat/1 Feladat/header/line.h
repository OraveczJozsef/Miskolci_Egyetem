#ifndef LineDefine
    #include "color.h"

    #define LineDefine

    typedef struct Line {
        int startX;
        int startY;

        int endX;
        int endY;

        Color color;
    } Line;
#endif
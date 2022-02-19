#ifndef RectangleDefine
    #include <SDL2/SDL.h>

    #include <stdbool.h>
    
    #include "color.h"
        
    #define RectangleDefine

    typedef struct Rectangle {
        SDL_Rect rectangle;
        Color color;
    } Rectangle;
    
    void makeRectangle(Rectangle* rectangle, int x, int y, int w, int h, int r, int g, int b, int a);
    bool isInSlot(int x, int y, int w, int h, int cx, int cy);
#endif
#ifndef RECTANGLE_HEADER
    #define RECTANGLE_HEADER

    #include <stdio.h>
    #include <stdbool.h>

    #include <SDL2/SDL.h>

    #include "point.h"
    #include "../utils/color.h"
    #include "../utils/util.h"

    #define MAX_RECTANGLE_COUNT 5
    #define COLOR_RECTANGLE_COUNT 5
    
    typedef struct Rectangle {
        SDL_Rect rectangle;

        RGB rgb;

        bool is_draw;
    } Rectangle;

    typedef struct Rectangles {
        Rectangle rectangles[MAX_RECTANGLE_COUNT];

        int index;
        int count;
    } Rectangles;

    void init_rectangle(Rectangles* rectangles);
    void init_rectangle_color(Rectangles* rectangles);

    bool is_in_slot(int x, int y, int w, int h, int cursor_x, int cursor_y);
#endif
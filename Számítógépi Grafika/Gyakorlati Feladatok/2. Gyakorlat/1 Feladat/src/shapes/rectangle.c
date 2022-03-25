#include "../../header/shapes/rectangle.h"

void init_rectangle(Rectangles* rectangles) {
    rectangles->count = 0;
    rectangles->index = 0;
}

void init_rectangle_color(Rectangles* rectangles) {
    int i = 0;

    for (i = 0; i < COLOR_RECTANGLE_COUNT; i++) {
        SDL_Rect rec;
        
        rec.x = 5 + (i*35);
        rec.y = 5;
        rec.w = 30;
        rec.h = 30;

        set_color(&rectangles->rectangles[i].rgb, randomInteger(0, 255), randomInteger(0, 255), randomInteger(0, 255));

        rectangles->rectangles[i].rectangle = rec;
        rectangles->rectangles[i].is_draw = true;
    }
}

bool is_in_slot(int x, int y, int w, int h, int cursor_x, int cursor_y) {
    if ((x <= cursor_x) && (y <= cursor_y) && (x + w >= cursor_x) && (y + h >= cursor_y)) {
        return true;
    }

    return false;
}
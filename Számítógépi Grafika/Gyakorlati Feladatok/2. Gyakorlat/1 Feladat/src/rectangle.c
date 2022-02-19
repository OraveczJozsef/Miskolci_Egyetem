#include "../header/rectangle.h"

void makeRectangle(Rectangle* rectangle, int x, int y, int w, int h, int r, int g, int b, int a) {
    SDL_Rect rec;
    rec.x = x;
    rec.y = y;
    rec.w = w;
    rec.h = h;

    Color color;
    setColor(&color, r, g, b, a);
    
    rectangle->rectangle = rec;
    rectangle->color = color;
}

bool isInSlot(int x, int y, int w, int h, int cx, int cy) {
    if (x <= cx && (x + w) >= cx && y <= cy && (y + h) >= cy) {
        return true;
    }
    return false;
}
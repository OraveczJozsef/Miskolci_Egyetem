#ifndef COLOR_HEADER
    #define COLOR_HEADER

    typedef struct RGB {
        int r; // Red
        int g; // Green
        int b; // Blue
    } RGB;

    typedef struct RGBA {
        RGB rgb; // RGB

        int a; // Alpha
    } RGBA;

    void set_color(RGB* rgb, int r, int g, int b);
#endif
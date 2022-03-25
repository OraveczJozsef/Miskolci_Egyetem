#ifndef APP_HEADER
    #define APP_HEADER

    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <time.h>

    #include <SDL2/SDL.h>

    #include "shapes/line.h"
    #include "shapes/rectangle.h"

    #define SCREEN_WIDTH 800
    #define SCREEN_HEIGHT 640

    typedef struct App {
        SDL_Window* win; // Window
        SDL_Renderer* render; // Renderer

        bool is_running; // App Running

        bool is_line_draw; // Line Draw | Rec Draw
        int click_count; // 

        // User Element
        Lines lines;
        Rectangles rectangles;

        // App Element
        Rectangles rectangles_color;
        int select_color;
    } App;

    void init_app(App* app, int width, int height);
    void destroy_app(App* app);

    void app_event(App* app);
    void app_render(App* app);
#endif
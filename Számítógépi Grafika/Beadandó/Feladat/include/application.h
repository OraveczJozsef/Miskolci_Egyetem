#ifndef APPLICATION_HEADER
    #define APPLICATION_HEADER

    #include <stdbool.h>

    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>

    #include "camera.h"
    
    #define VIEWPORT_RATIO (4.0 / 3.0)
    #define VIEWPORT_ASPECT 50.0

    typedef struct Application {
        SDL_Window* window;
        SDL_GLContext context;

        bool running;
    } Application;
    
    void init_application(Application* application, int screen_width, int screen_height);
    void init_opengl();
    void reshape(GLsizei screen_width, GLsizei screen_height);
#endif
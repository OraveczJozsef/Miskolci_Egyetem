#include "../include/application.h"

void init_application(Application* application, int screen_width, int screen_height) {
    int error_code;
    int inited_loaders;

    application->running = false;

    error_code = SDL_Init(SDL_INIT_EVERYTHING);
    if (error_code != 0) {
        printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
        return;
    }

    application->window = SDL_CreateWindow("Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_OPENGL);
    if (application->window == NULL) {
        printf("[ERROR] Unable to create the application window!\n");
        return;
    }

    inited_loaders = IMG_Init(IMG_INIT_PNG);
    if (inited_loaders == 0) {
        printf("[ERROR] IMG initialization error: %s\n", IMG_GetError());
        return;
    }

    application->context = SDL_GL_CreateContext(application->window);
    if (application->context == NULL) {
        printf("[ERROR] Unable to create the OpenGL context!\n");
        return;
    }

    init_opengl();
    reshape(screen_width, screen_height);

    // init

    application->running = true;
}

void init_opengl() {
    // 
}

void reshape(GLsizei screen_width, GLsizei screen_height) {
    int x, y, w, h;
    double ratio;

    ratio = (double) screen_width / screen_height;

    if (ratio > VIEWPORT_RATIO) {
        w = (int)((double) screen_height * VIEWPORT_RATIO);
        h = screen_height;
        x = (screen_width - w) / 2;
        y = 0;
    } else {
        w = screen_width;
        h = (int)((double) screen_width / VIEWPORT_RATIO);
        x = 0;
        y = (screen_height - h) / 2;
    }

    glViewport(x, y, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.08, 0.08, -0.06, 0.06, 0.1, 10);
}
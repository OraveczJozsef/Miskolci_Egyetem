#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdbool.h>

#include "header/color.h"
#include "header/line.h"
#include "header/rectangle.h"

// Define Settings
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 640

#define COLOR_RECTANGLE_COUNT 5
#define DRAW_TYPE 2

#define MAX_LINE_COUNT 5
#define MAX_RECTANGLE_COUNT 5

int main(int argc, char** args) {
    // Sdl Settings
    int error_code;
    bool need_run = true;
    
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    // For
    int i;

    // Draw Settings
    int clickCount = 0;
    bool isDraw = false;
    int selectColor = 0;
    bool isLine = true;
    bool isRectangle = false;

    // Line Settings
    Line lines[MAX_LINE_COUNT];
    Line newLine;
    int lineIndex = 0;
    int lineCount = 0;

    // Rectangle Settings
    Rectangle rectangles[MAX_RECTANGLE_COUNT];
    Rectangle newRectangle;
    int rectangleIndex = 0;
    int rectangleCount = 0;

    // Color & Draw Type Settings
    Rectangle colorRec[COLOR_RECTANGLE_COUNT];
    Rectangle typeRec[DRAW_TYPE];
    SDL_Rect recType;

    // Color
    int randomColor[COLOR_RECTANGLE_COUNT][3] = {{36, 129, 115}, {207, 223, 141}, {156, 31, 103}, {47, 199, 216}, {180, 80, 80}};

    // Color & Draw Type make Rectangle
    for (i = 0; i < COLOR_RECTANGLE_COUNT; i++) {
        makeRectangle(&colorRec[i], 5 + (i*35), 5, 30, 30, randomColor[i][0], randomColor[i][1], randomColor[i][2], 255);
    }
    for (i = 0; i < DRAW_TYPE; i++) {
        makeRectangle(&typeRec[i], SCREEN_WIDTH - (i+1)*35, 5, 30, 30, 180, 90, 50, 255);
    }

    recType.x = SCREEN_WIDTH-70+5;
    recType.y = 10;
    recType.w = 20;
    recType.h = 20;

    // SDL Init
    error_code = SDL_Init(SDL_INIT_EVERYTHING);
    if (error_code != 0) {
        printf("[Error] SDL initialization error: %s\n", SDL_GetError());
        return error_code;
    }

    // Window
    window = SDL_CreateWindow("1.Gyakorlat/1.Feladat", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    // Render
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //SDL_RenderClear(renderer);

    // Prog Run
    while (need_run) {
        // Event
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    if (event.button.type == SDL_KEYDOWN) {
                        if (event.key.keysym.sym == SDLK_ESCAPE) {
                            need_run = false;
                        }
                    }
                    break;
                case SDL_QUIT:
                    need_run = false;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        if (event.button.y >= 40) {
                            if (isLine) {
                                if (clickCount % 2 == 0) {
                                    newLine.startX = event.button.x;
                                    newLine.startY = event.button.y;
                                } else {
                                    newLine.endX = event.button.x;
                                    newLine.endY = event.button.y;

                                    isDraw = true;
                                }

                                clickCount++;
                            } else if (isRectangle) {
                                if (clickCount % 2 == 0) {
                                    newRectangle.rectangle.x = event.button.x;
                                    newRectangle.rectangle.y = event.button.y;
                                } else {
                                    if (newRectangle.rectangle.x > event.button.x) {
                                        newRectangle.rectangle.w = event.button.x - newRectangle.rectangle.x;
                                    } else {
                                        newRectangle.rectangle.w = -(newRectangle.rectangle.x - event.button.x);
                                    }
                                    
                                    if (newRectangle.rectangle.y > event.button.y) {
                                        newRectangle.rectangle.h = event.button.y - newRectangle.rectangle.y;
                                    } else {
                                        newRectangle.rectangle.h = -(newRectangle.rectangle.y - event.button.y);
                                    }
                                    
                                    isDraw = true;
                                }

                                clickCount++;
                            }
                        } else {
                            for (i = 0; i < COLOR_RECTANGLE_COUNT; i++) {
                                if (isInSlot(colorRec[i].rectangle.x, colorRec[i].rectangle.y, colorRec[i].rectangle.w, colorRec[i].rectangle.h, event.button.x, event.button.y)) {
                                    selectColor = i;
                                    break;
                                }
                            }

                            for (i = 0; i < DRAW_TYPE; i++) {
                                if (isInSlot(typeRec[i].rectangle.x, typeRec[i].rectangle.y, typeRec[i].rectangle.w, typeRec[i].rectangle.h, event.button.x, event.button.y)) {
                                    if (i == 0) {
                                        isLine = true;
                                        isRectangle = false;
                                    } else {
                                        isLine = false;
                                        isRectangle = true;
                                    }

                                    isDraw = false;
                                    clickCount = 0;
                                }
                            }
                        }
                    } else if (event.button.button == SDL_BUTTON_RIGHT) {
                        if (event.button.state == SDL_PRESSED) {
                            printf("Mouse Position: [X: %d, Y: %d]\n", event.button.x, event.button.y);
                        }
                    }
                    break;
            }
        }

        /* Draw */
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        // Color
        for (i = 0; i < COLOR_RECTANGLE_COUNT; i++) {
            SDL_SetRenderDrawColor(renderer, colorRec[i].color.r, colorRec[i].color.g, colorRec[i].color.b, colorRec[i].color.a);
            SDL_RenderFillRect(renderer, &colorRec[i].rectangle);
        }

        // Draw Type
        for (i = 0; i < DRAW_TYPE; i++) {
            SDL_SetRenderDrawColor(renderer, typeRec[i].color.r, typeRec[i].color.g, typeRec[i].color.b, typeRec[i].color.a);
            SDL_RenderFillRect(renderer, &typeRec[i].rectangle);

            if (i == 0) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawLine(renderer, typeRec[i].rectangle.x+15, typeRec[i].rectangle.y+5, typeRec[i].rectangle.x+15, typeRec[i].rectangle.y+20);
            } else {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                SDL_RenderFillRect(renderer, &recType);
            }
        }

        // Add new Element
        if (isDraw) {
            if (isLine) {
                if (lineIndex >= MAX_LINE_COUNT) {
                    lineIndex = 0;
                }

                lines[lineIndex].startX = newLine.startX;
                lines[lineIndex].startY = newLine.startY;
                lines[lineIndex].endX = newLine.endX;
                lines[lineIndex].endY = newLine.endY;
                setColor(&lines[lineIndex].color, colorRec[selectColor].color.r, colorRec[selectColor].color.g, colorRec[selectColor].color.b, colorRec[selectColor].color.a);
                
                if (lineCount != MAX_LINE_COUNT) {
                    lineCount++;
                }
                lineIndex++;
            } else if (isRectangle) {
                if (rectangleIndex >= MAX_RECTANGLE_COUNT) {
                    rectangleIndex = 0;
                }

                rectangles[rectangleIndex].rectangle.x = newRectangle.rectangle.x;
                rectangles[rectangleIndex].rectangle.y = newRectangle.rectangle.y;
                rectangles[rectangleIndex].rectangle.w = newRectangle.rectangle.w;
                rectangles[rectangleIndex].rectangle.h = newRectangle.rectangle.h;

                setColor(&rectangles[rectangleIndex].color, colorRec[selectColor].color.r, colorRec[selectColor].color.g, colorRec[selectColor].color.b, colorRec[selectColor].color.a);

                if (rectangleCount != MAX_RECTANGLE_COUNT) {
                    rectangleCount++;
                }
                rectangleIndex++;
            }

            isDraw = false;
        }

        // Draw Element
        for (i = 0; i < lineCount; i++) {
            SDL_SetRenderDrawColor(renderer, lines[i].color.r, lines[i].color.g, lines[i].color.b, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawLine(renderer, lines[i].startX, lines[i].startY, lines[i].endX, lines[i].endY);
        }
        for (i = 0; i < rectangleCount; i++) {
            SDL_SetRenderDrawColor(renderer, rectangles[i].color.r, rectangles[i].color.g, rectangles[i].color.b, rectangles[i].color.a);
            SDL_RenderFillRect(renderer, &rectangles[i].rectangle);
        }

        // Render
        SDL_RenderPresent(renderer);
    }

    // Prog Exit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
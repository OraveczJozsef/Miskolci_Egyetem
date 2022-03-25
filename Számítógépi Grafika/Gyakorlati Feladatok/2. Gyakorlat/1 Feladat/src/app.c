#include "../header/app.h"

void init_app(App* app, int width, int height) {
    int error_code;

    app->is_running = false;

    error_code = SDL_Init(SDL_INIT_EVERYTHING);
    if (error_code != 0) {
        printf("[Error] SDL initialization error: %s\n", SDL_GetError());
        return;
    }

    // Window
    app->win = SDL_CreateWindow("1.Gyakorlat/1.Feladat", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    // Render
    app->render = SDL_CreateRenderer(app->win, -1, SDL_RENDERER_ACCELERATED);

    app->is_line_draw = true;
    app->click_count = 0;

    init_lines(&(app->lines));
    init_rectangle(&(app->rectangles));

    init_rectangle_color(&(app->rectangles_color));
    app->select_color = 0;

    app->is_running = true;
}
void destroy_app(App* app) {
    SDL_DestroyRenderer(app->render);
    SDL_DestroyWindow(app->win);
    SDL_Quit();
}

void app_event(App* app) {
    SDL_Event event;
    int i = 0;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_ESCAPE:
                        app->is_running = false;
                        break;
                    default:
                        break;
                }
                break;
            case SDL_QUIT:
                app->is_running = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button) {
                    case SDL_BUTTON_LEFT:
                        if (event.button.y >= 40) {
                            if (app->is_line_draw) {
                                if (app->lines.index >= MAX_LINE_COUNT) {
                                    app->lines.index = 0;
                                }

                                if (app->lines.lines[app->lines.index].is_draw) {
                                    app->lines.lines[app->lines.index].is_draw = false;
                                }

                                if (app->click_count % 2 == 0) {
                                    app->lines.lines[app->lines.index].start.x = event.button.x;
                                    app->lines.lines[app->lines.index].start.y = event.button.y;
                                } else {
                                    app->lines.lines[app->lines.index].end.x = event.button.x;
                                    app->lines.lines[app->lines.index].end.y = event.button.y;

                                    set_color(&app->lines.lines[app->lines.index].rgb, app->rectangles_color.rectangles[app->select_color].rgb.r, app->rectangles_color.rectangles[app->select_color].rgb.g, app->rectangles_color.rectangles[app->select_color].rgb.b);

                                    app->lines.lines[app->lines.index].is_draw = true;

                                    app->lines.index++;

                                    if (app->lines.count != MAX_LINE_COUNT) {
                                        app->lines.count++;
                                    }
                                }

                                app->click_count++;
                            } else {
                                if (app->rectangles.index >= MAX_RECTANGLE_COUNT) {
                                    app->rectangles.index = 0;
                                }

                                if (app->rectangles.rectangles[app->rectangles.index].is_draw) {
                                    app->rectangles.rectangles[app->rectangles.index].is_draw = false;
                                }

                                if (app->click_count % 2 == 0) {
                                    app->rectangles.rectangles[app->rectangles.index].rectangle.x = event.button.x;
                                    app->rectangles.rectangles[app->rectangles.index].rectangle.y = event.button.y;
                                } else {
                                    if (app->rectangles.rectangles[app->rectangles.index].rectangle.x > event.button.x) {
                                        app->rectangles.rectangles[app->rectangles.index].rectangle.w = event.button.x - app->rectangles.rectangles[app->rectangles.index].rectangle.x;
                                    } else {
                                        app->rectangles.rectangles[app->rectangles.index].rectangle.w = -(app->rectangles.rectangles[app->rectangles.index].rectangle.x - event.button.x);
                                    }
                                    
                                    if (app->rectangles.rectangles[app->rectangles.index].rectangle.y > event.button.y) {
                                        app->rectangles.rectangles[app->rectangles.index].rectangle.h = event.button.y - app->rectangles.rectangles[app->rectangles.index].rectangle.y;
                                    } else {
                                        app->rectangles.rectangles[app->rectangles.index].rectangle.h = -(app->rectangles.rectangles[app->rectangles.index].rectangle.y - event.button.y);
                                    }
                                    
                                    set_color(&app->rectangles.rectangles[app->rectangles.index].rgb, app->rectangles_color.rectangles[app->select_color].rgb.r, app->rectangles_color.rectangles[app->select_color].rgb.g, app->rectangles_color.rectangles[app->select_color].rgb.b);

                                    app->rectangles.rectangles[app->rectangles.index].is_draw = true;

                                    app->rectangles.index++;

                                    if (app->rectangles.count != MAX_LINE_COUNT) {
                                        app->rectangles.count++;
                                    }
                                }

                                app->click_count++;
                            }
                        } else {
                            if (event.button.x <= 180) {
                                for (i = 0; i < COLOR_RECTANGLE_COUNT; i++) {
                                    if (is_in_slot(app->rectangles_color.rectangles[i].rectangle.x, app->rectangles_color.rectangles[i].rectangle.y, app->rectangles_color.rectangles[i].rectangle.w, app->rectangles_color.rectangles[i].rectangle.h, event.button.x, event.button.y)) {
                                        app->select_color = i;
                                        break;
                                    }
                                }
                            } else {
                                if (is_in_slot(SCREEN_WIDTH - 35, 5, 30, 30, event.button.x, event.button.y)) {
                                    app->is_line_draw = !app->is_line_draw;
                                    app->click_count = 0;
                                }
                            }
                        }
                        break;
                    case SDL_BUTTON_RIGHT:
                        if (event.button.state == SDL_PRESSED) {
                            printf("Mouse Position: [X: %d, Y: %d]\n", event.button.x, event.button.y);
                        }
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
    }
}
void app_render(App* app) {
    int i = 0;
    SDL_Rect rec;
    int r = 255, g = 255, b = 255;

    SDL_SetRenderDrawColor(app->render, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(app->render);

    // Line
    for (i = 0; i < app->lines.count; i++) {
        if (app->lines.lines[i].is_draw) {
            SDL_SetRenderDrawColor(app->render, app->lines.lines[i].rgb.r, app->lines.lines[i].rgb.g, app->lines.lines[i].rgb.b, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawLine(app->render, app->lines.lines[i].start.x, app->lines.lines[i].start.y, app->lines.lines[i].end.x, app->lines.lines[i].end.y);
        }
    }

    // Rectangle
    for (i = 0; i < app->rectangles.count; i++) {
        if (app->rectangles.rectangles[i].is_draw) {
            SDL_SetRenderDrawColor(app->render, app->rectangles.rectangles[i].rgb.r, app->rectangles.rectangles[i].rgb.g, app->rectangles.rectangles[i].rgb.b, SDL_ALPHA_OPAQUE);
            SDL_RenderFillRect(app->render, &app->rectangles.rectangles[i].rectangle);
        }
    }

    // Draw Type
    if (!app->is_line_draw) {
        r = 180;
        g = 80;
        b = 80;
    }
    SDL_SetRenderDrawColor(app->render, 100, 100, 100, SDL_ALPHA_OPAQUE);
    rec.x = SCREEN_WIDTH - 35;
    rec.y = 5;
    rec.w = 30;
    rec.h = 30;
    SDL_RenderFillRect(app->render, &rec);
    SDL_SetRenderDrawColor(app->render, r, g, b, SDL_ALPHA_OPAQUE);
    
    rec.x = SCREEN_WIDTH - 30;
    rec.y = 10;
    rec.w = 20;
    rec.h = 20;
    SDL_RenderDrawRect(app->render, &rec);
    rec.x = SCREEN_WIDTH - 29;
    rec.y = 11;
    rec.w = 18;
    rec.h = 18;
    SDL_RenderFillRect(app->render, &rec);


    // Color
    for (i = 0; i < COLOR_RECTANGLE_COUNT; i++) {
        SDL_SetRenderDrawColor(app->render, app->rectangles_color.rectangles[i].rgb.r, app->rectangles_color.rectangles[i].rgb.g, app->rectangles_color.rectangles[i].rgb.b, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(app->render, &app->rectangles_color.rectangles[i].rectangle);
    }

    SDL_RenderPresent(app->render);
}
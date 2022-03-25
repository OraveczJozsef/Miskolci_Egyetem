#include "../header/app.h"

int main(int argc, char** args) {
    App app;

    srand(time(NULL));
    init_app(&app, SCREEN_WIDTH, SCREEN_HEIGHT);

    while (app.is_running) {
        app_event(&app);
        app_render(&app);
    }

    destroy_app(&app);

    return 0;
}
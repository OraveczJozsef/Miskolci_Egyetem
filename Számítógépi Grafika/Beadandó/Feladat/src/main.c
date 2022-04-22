#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "app.h"

/**
 * Main function
 */
int main(int argc, char* argv[]) {
    int i;
    App app;

    srand(time(NULL));

    init_app(&app, 1024, 768);
    
    if (argc > 1) {
        for (i = 0; i < argc; i++) {
            if (strcmp(argv[i], "-dev") == 0) {
                app.dev_mode = true;
            } else if (strcmp(argv[i], "-debug") == 0) {
                app.debug_mode = true;
            }
        }
    }

    if (app.dev_mode) {
        printf("[App Dev] Enable!\n");
        app.scene.dev_mode = true;
        app.camera.dev_mode = true;
    } else {
        printf("[App Dev] Disable!\n");
    }

    if (app.debug_mode) {
        printf("[App Debug] Enable!\n");
        app.scene.debug_mode = true;
        app.camera.debug_mode = true;
    } else {
        printf("[App Debug] Disable!\n");
    }

    while (app.is_running) {
        handle_app_events(&app);
        update_app(&app);
        render_app(&app);
    }
    destroy_app(&app);

    return 0;
}

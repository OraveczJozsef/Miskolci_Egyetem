#include "app.h"

#include <stdio.h>

/**
 * Main function
 */
int main(int argc, char* argv[]) {
    App app;
    int i;

    init_app(&app, 1024, 768);
    app.is_dev_mode = false;

    if (argc > 1) {
        for (i = 0; i < argc; i++) {
            if (strcmp(argv[i], "-dev")) {
                app.is_dev_mode = true;
            }
        }
    }

    while (app.is_running) {
        handle_app_events(&app);
        update_app(&app);
        render_app(&app);
    }
    
    destroy_app(&app);

    return 0;
}

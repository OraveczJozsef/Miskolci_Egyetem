#ifndef FIRE_HEADER
    #define FIRE_HEADER

    #include <stdlib.h>

    #include <obj/model.h>
    #include <obj/load.h>
    #include <obj/draw.h>

    #include "texture.h"
    #include "utils.h"

    typedef struct Fire {
        Model model;

        GLuint* textures;
        int texture_size;
        int texture_used;
        
        int texture_actual;
        float time;

        vec3 position;
        vec3 rotation;
    } Fire;

    /**
     * Initialize the fire.
     */
    void init_fire(Fire* fire);

    /**
     * Inserts the fire texture into an array.
     */
    void add_texture(Fire* fire, char* src);

    /**
     * Update the fire.
     */
    void update_fire(Fire* fire, double time);

    /**
     * Render the fire.
     */
    void render_fire(const Fire* fire);
#endif
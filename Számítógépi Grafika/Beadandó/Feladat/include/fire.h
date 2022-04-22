#ifndef FIRE_HEADER
    #define FIRE_HEADER

    #include <stdlib.h>
    #include <stdbool.h>

    #include <obj/model.h>
    #include <obj/load.h>
    #include <obj/draw.h>

    #include "texture.h"
    #include "utils.h"

    typedef struct FireData {
        int texture_actual;
        float time;
        float radius;

        vec3 position;
        vec3 rotation;
    } FireData;

    typedef struct Fire {
        Model model;

        GLuint* textures;
        int texture_size;
        int texture_used;
        
        FireData* fire_data;
        int fire_data_size;
        int fire_data_used;

        bool fire_effect;
        ColorA fire_effect_rgba;
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
     * Inserts the fire data into an array.
     */
    void add_fire(Fire* fire, int texture_actual, float time, float radius, vec3 position, vec3 rotation);

    /**
     * Update the fire.
     */
    void update_fire(Fire* fire, double time);

    /**
     * Render the fire.
     */
    void render_fire(const Fire* fire);
#endif
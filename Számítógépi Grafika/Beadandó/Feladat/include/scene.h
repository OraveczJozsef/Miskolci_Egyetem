#ifndef SCENE_H
    #define SCENE_H

    #include <stdlib.h>
    #include <stdbool.h>

    #include <obj/model.h>
    #include <obj/load.h>
    #include <obj/draw.h>

    #include "camera.h"
    #include "texture.h"

    #include "fire.h"

    #define LIGHT_ALPHA_MINIMUM 0.2f // Light animation alpha minimum value.
    #define LIGHT_ALPHA_MAXIMUM 0.8f // Light animation alpha maximum value.

    /**
     * Model and associated texture.
     */
    typedef struct Object {
        Model model;
        GLuint texture;
    } Object;

    /**
     * Characteristics of light sources.
     */
    typedef struct Light {
        float ambient[4];
        float diffuse[4];
        float specular[4];
        float position[4];

        float speed;
    } Light;

    typedef struct Scene {
        bool dev_mode;
        bool debug_mode;

        Object* objects;
        int object_used;
        int object_size;

        Fire fire;

        Light* lights;
        int light_used;
        int light_size;

        Material material;

        bool is_show_help;
        GLuint help_texture;
    } Scene;

    /**
     * Initialize the scene.
     */
    void init_scene(Scene* scene);

    /**
     * Initialize the model and texture.
     */
    void init_objects(Scene* scene);

    /**
     * Initialize the lights
     */
    void init_lights(Scene* scene);

    /**
     * Loads and puts the model on the array.
     */
    void add_model(Scene* scene, char* model_src, char* texture_src);
    
    /**
     * Inserts the light data into an array.
     */
    void add_light(Scene* scene, float ambient[4], float diffuse[4], float specular[4], float position[4]);
    
    /**
     * Adjusts the animation speed of that light.
     */
    void set_light_speed(Light* light, float speed);

    /**
     * Selects the appropriate texture and draws the model.
     */
    void draw_object(const Object object);

    /**
     * Displays/draws the lights.
     */
    void draw_light(const Scene* scene);

    /**
     * Set the current material.
     */
    void set_material(const Material* material);

    /**
     * Sets the is_show_help changed, which if true is visible otherwise not visible
     */
    void set_show_help(Scene* scene, bool state);

    /**
     * Update the scene.
     */
    void update_scene(Scene* scene, double time);

    void update_fire(Scene* scene, vec3 camera_position);

    /**
     * Render the scene objects.
     */
    void render_scene(const Scene* scene);

    /**
     * Draw the origin of the world coordinate system.
     */
    void draw_origin();

    /**
     * Draw the Help panel.
     */
    void draw_help(const GLuint texture);

    /**
     * 
     */
    void draw_fire_effect(const Scene* scene);

#endif /* SCENE_H */

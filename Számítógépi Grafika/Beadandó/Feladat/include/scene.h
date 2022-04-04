#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

#include <stdlib.h>

/**
 * 
 */
typedef struct Models {
    Model model;
    GLuint texture;
    Material material;
} Models;

/**
 * 
 */
typedef struct Scene {
    //Model cube;
    //GLuint cube_texture_id;

    Models* models;
    int models_size;
    int models_used;

    Light* lights;
    int light_size;
    int light_used;

    bool is_dev_mode;
} Scene;

/**
 * 
 */
void add_model(Scene* scene, char* model_src, char* texture_src);

/**
 *
 */
void set_model_material(Models* models, double ambient_red, double ambient_green, double ambient_blue, double diffuse_red, double diffuse_green, double diffuse_blue, double specular_red, double specular_green, double specular_blue, double shininess);

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
//void set_lighting();
void set_lighting(Light* light, int index);

void add_light(Scene* scene, RGBA ambient, RGBA diffuse, RGBA specular, vec4 position);

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * 
 */
void draw_texture_model(Models model);

/**
 * Update the scene.
 */
void update_scene(Scene* scene, double time);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

/**
 * 
 */
void set_light_speed(Light* light, double speed);

#endif /* SCENE_H */

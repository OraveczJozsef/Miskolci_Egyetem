#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene) {
    RGBA ambient;
    RGBA diffuse;
    RGBA specular;
    vec4 position;

    scene->models_size = 1;
    scene->models_used = 0;
    scene->models = malloc(scene->models_size * sizeof(Models));

    scene->light_size = 1;
    scene->light_used = 0;
    scene->lights = malloc(scene->models_size * sizeof(Light));

    // Model
    // 0 id -> Room
    add_model(scene, "assets/models/room.obj", "assets/textures/room.jpg");
    set_model_material(&scene->models[0], 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0);

    // 2 id -> fireplace
    add_model(scene, "assets/models/fireplace.obj", "assets/textures/fireplace.jpg");
    set_model_material(&scene->models[1], 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0);

    // Light
    ambient.red = 1.0;
    ambient.green = 1.0;
    ambient.blue = 1.0;
    ambient.alpha = 1.0;
    
    diffuse.red = 1.0;
    diffuse.green = 1.0;
    diffuse.blue = 1.0;
    diffuse.alpha = 1.0;
    
    specular.red = 0.0;
    specular.green = 0.0;
    specular.blue = 0.0;
    specular.alpha = 1.0;

    position.x = 0.0f;
    position.y = 10.0f;
    position.z = 10.0f;
    position.w = 0.0f;

    // 0
    add_light(scene, ambient, diffuse, specular, position);
    
    position.x = -7.8f;
    position.y = -6.6f;
    position.z = 1.5f;
    position.w = 1.0f;

    // 1
    add_light(scene, ambient, diffuse, specular, position);

    position.x = 0.0f;
    position.y = 0.0f;
    position.z = 1.5f;
    position.w = 1.0f;

    // 2
    add_light(scene, ambient, diffuse, specular, position);
}

/* Model */
void add_model(Scene* scene, char* model_src, char* texture_src) {
    if (scene->models_used == scene->models_size) {
        scene->models_size += 1;
        scene->models = realloc(scene->models, scene->models_size * sizeof(Models));
    }

    load_model(&(scene->models[scene->models_used].model), model_src);
    scene->models[scene->models_used].texture = load_texture(texture_src);

    scene->models_used++;
}

/* Model Material */
void set_model_material(Models* models, double ambient_red, double ambient_green, double ambient_blue, double diffuse_red, double diffuse_green, double diffuse_blue, double specular_red, double specular_green, double specular_blue, double shininess) {
    models->material.ambient.red = ambient_red;
    models->material.ambient.green = ambient_green;
    models->material.ambient.blue = ambient_blue;
    
    models->material.diffuse.red = diffuse_red;
    models->material.diffuse.green = diffuse_green;
    models->material.diffuse.blue = diffuse_blue;

    models->material.specular.red = specular_red;
    models->material.specular.green = specular_green;
    models->material.specular.blue = specular_blue;
    
    models->material.shininess = shininess;
}

/* Render Material */
void set_material(const Material* material) {
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

/* Light */
void add_light(Scene* scene, RGBA ambient, RGBA diffuse, RGBA specular, vec4 position) {
    if (scene->light_used == scene->light_size) {
        scene->light_size += 1;
        scene->lights = realloc(scene->lights, scene->light_size * sizeof(Light));
    }

    scene->lights[scene->light_used].ambient = ambient;
    scene->lights[scene->light_used].diffuse = diffuse;
    scene->lights[scene->light_used].specular = specular;
    scene->lights[scene->light_used].position = position;

    scene->lights[scene->light_used].speed = 0.0;

    scene->light_used++;
}

/* Render Light */
void set_lighting(Light* light, int index) {
    float ambient_light[] = {
        light->ambient.red,
        light->ambient.green,
        light->ambient.blue,
        light->ambient.alpha
    };

    float diffuse_light[] = {
        light->diffuse.red,
        light->diffuse.green,
        light->diffuse.blue,
        light->diffuse.alpha
    };

    float specular_light[] = {
        light->specular.red,
        light->specular.green,
        light->specular.blue,
        light->specular.alpha
    };

    float position[] = {
        light->position.x,
        light->position.y,
        light->position.z,
        light->position.w
    };

    if (index == 0) {
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
        glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
        glLightfv(GL_LIGHT0, GL_POSITION, position);
    } else if (index == 1) {
        glLightfv(GL_LIGHT1, GL_AMBIENT, ambient_light);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse_light);
        glLightfv(GL_LIGHT1, GL_SPECULAR, specular_light);
        glLightfv(GL_LIGHT1, GL_POSITION, position);
    } else if (index == 2) {
        glLightfv(GL_LIGHT2, GL_AMBIENT, ambient_light);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse_light);
        glLightfv(GL_LIGHT2, GL_SPECULAR, specular_light);
        glLightfv(GL_LIGHT2, GL_POSITION, position);
    } else if (index == 3) {
        glLightfv(GL_LIGHT3, GL_AMBIENT, ambient_light);
        glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuse_light);
        glLightfv(GL_LIGHT3, GL_SPECULAR, specular_light);
        glLightfv(GL_LIGHT3, GL_POSITION, position);
    } else if (index == 4) {
        glLightfv(GL_LIGHT4, GL_AMBIENT, ambient_light);
        glLightfv(GL_LIGHT4, GL_DIFFUSE, diffuse_light);
        glLightfv(GL_LIGHT4, GL_SPECULAR, specular_light);
        glLightfv(GL_LIGHT4, GL_POSITION, position);
    } else if (index == 5) {
        glLightfv(GL_LIGHT5, GL_AMBIENT, ambient_light);
        glLightfv(GL_LIGHT5, GL_DIFFUSE, diffuse_light);
        glLightfv(GL_LIGHT5, GL_SPECULAR, specular_light);
        glLightfv(GL_LIGHT5, GL_POSITION, position);
    } else if (index == 6) {
        glLightfv(GL_LIGHT6, GL_AMBIENT, ambient_light);
        glLightfv(GL_LIGHT6, GL_DIFFUSE, diffuse_light);
        glLightfv(GL_LIGHT6, GL_SPECULAR, specular_light);
        glLightfv(GL_LIGHT6, GL_POSITION, position);
    } else if (index == 7) {
        glLightfv(GL_LIGHT7, GL_AMBIENT, ambient_light);
        glLightfv(GL_LIGHT7, GL_DIFFUSE, diffuse_light);
        glLightfv(GL_LIGHT7, GL_SPECULAR, specular_light);
        glLightfv(GL_LIGHT7, GL_POSITION, position);
    }
}

void set_light_speed(Light* light, double speed) {
    light->speed = speed;
}

void update_scene(Scene* scene, double time) {
    int i;
    float value;

    for (i = 0; i < scene->light_size; i++) {
        value = scene->lights[i].speed * time;

        if (
            ((scene->lights[i].ambient.alpha + value) > 0.2) &&
            ((scene->lights[i].diffuse.alpha + value) > 0.2) &&
            ((scene->lights[i].specular.alpha + value) > 0.2)
        ) {
            scene->lights[i].ambient.red += value;
            scene->lights[i].ambient.green += value;
            scene->lights[i].ambient.blue += value;
            scene->lights[i].ambient.alpha += value;

            scene->lights[i].diffuse.red += value;
            scene->lights[i].diffuse.green += value;
            scene->lights[i].diffuse.blue += value;
            scene->lights[i].diffuse.alpha += value;
            
            scene->lights[i].specular.red += value;
            scene->lights[i].specular.green += value;
            scene->lights[i].specular.blue += value;
            scene->lights[i].specular.alpha += value;
        }
    }
}

void render_scene(const Scene* scene) {
    int i;
    
    set_material(&(scene->models[0].material));

    for (i = 0; i < scene->light_used; i++) {
        set_lighting(&(scene->lights[i]), i);
    }

    if (scene->is_dev_mode) {
        draw_origin();
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Room
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.0f);
        glRotatef(90, 1.0f, 0.0f, 0.0f);

        draw_texture_model(scene->models[0]);
    glPopMatrix();
    
    // FirePlace
    glPushMatrix();
        glTranslatef(6.05f, 0.0f, 1.0f);
        glRotatef(90, 1.0f, 0.0f, 0.0f);
        glRotatef(270, 0.0f, 1.0f, 0.0f);

        draw_texture_model(scene->models[1]);
    glPopMatrix();
}

void draw_origin() {
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}

void draw_texture_model(Models model) {
    glBindTexture(GL_TEXTURE_2D, model.texture);
    draw_model(&model.model);
}
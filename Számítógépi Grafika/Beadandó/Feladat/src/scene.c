#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>
#include <stdlib.h>
#include <time.h>

void init_scene(Scene* scene) {
    srand(time(NULL));

    scene->dev_mode = false;
    scene->debug_mode = false;

    /* Model */
    init_objects(scene);
    /* Model */

    /* Light */
    init_lights(scene);
    /* Light */

    scene->material.ambient.red = 0.0;
    scene->material.ambient.green = 0.0;
    scene->material.ambient.blue = 0.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;

    scene->material.shininess = 0.0;
}

void init_objects(Scene* scene) {
    scene->object_size = 1;
    scene->object_used = 0;
    scene->objects = malloc(scene->object_size * sizeof(Object));

    add_model(scene, "assets/models/room.obj", "assets/textures/room.jpg");
    add_model(scene, "assets/models/fireplace.obj", "assets/textures/fireplace.jpg");
    add_model(scene, "assets/models/lamp_1.obj", "assets/textures/lamp_1.jpg");
    add_model(scene, "assets/models/lamp_2.obj", "assets/textures/lamp_2.jpg");

    add_model(scene, "assets/models/ter.obj", "assets/textures/ter.jpg");
}

void init_lights(Scene* scene) {
    float ambient_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position[] = { 0.0f, 10.0f, 10.0f, 0.0f };

    scene->light_size = 1;
    scene->light_used = 0;
    scene->lights = malloc(scene->light_size * sizeof(Light));

    add_light(scene, ambient_light, diffuse_light, specular_light, position);
    
    ambient_light[3] = 0.8f;
    diffuse_light[3] = 0.8f;
    specular_light[3] = 0.8f;
    
    position[0] = 0.0f;
    position[1] = 0.0f;
    position[2] = 3.8f;
    position[3] = 1.0f;
    add_light(scene, ambient_light, diffuse_light, specular_light, position);
    
    position[0] = -8.119684f;
    position[1] = -5.633071f;
    position[2] = 3.8f;
    position[3] = 1.0f;
    add_light(scene, ambient_light, diffuse_light, specular_light, position);
}



void add_model(Scene* scene, char* model_src, char* texture_src) {
    if (scene->object_used == scene->object_size) {
        scene->object_size++;
        scene->objects = realloc(scene->objects, scene->object_size * sizeof(Object));
    }

    load_model(&(scene->objects[scene->object_used].model), model_src);
    scene->objects[scene->object_used].texture = load_texture(texture_src);

    scene->object_used++;
}

void add_light(Scene* scene, float ambient[4], float diffuse[4], float specular[4], float position[4]) {
    int i;
    
    if (scene->light_used == scene->light_size) {
        scene->light_size++;
        scene->lights = realloc(scene->lights, scene->light_size * sizeof(Light));
    }

    for (i = 0; i < 4; i++) {
        scene->lights[scene->light_used].ambient[i] = ambient[i];
        scene->lights[scene->light_used].diffuse[i] = diffuse[i];
        scene->lights[scene->light_used].specular[i] = specular[i];
        scene->lights[scene->light_used].position[i] = position[i];
    }

    scene->lights[scene->light_used].speed = 0.0f;

    scene->light_used++;
}



void set_light_speed(Light* light, float speed) {
    light->speed = speed;
}

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



void update_scene(Scene* scene, double time) {
    int i, j;
    float ambient_new, diffuse_new, specular_new;

    for (i = 0; i < scene->light_used; i++) {
        ambient_new = scene->lights[i].ambient[3] + scene->lights[i].speed * time;
        diffuse_new = scene->lights[i].diffuse[3] + scene->lights[i].speed * time;
        specular_new = scene->lights[i].specular[3] + scene->lights[i].speed * time;

        if ((ambient_new > LIGHT_ALPHA_MINIMUM && diffuse_new > LIGHT_ALPHA_MINIMUM && specular_new > LIGHT_ALPHA_MINIMUM) && (ambient_new < LIGHT_ALPHA_MAXIMUM && diffuse_new < LIGHT_ALPHA_MAXIMUM && specular_new < LIGHT_ALPHA_MAXIMUM)) {
            for (j = 0; j < 4; j++) {
                scene->lights[i].ambient[j] += scene->lights[i].speed * time;
                scene->lights[i].diffuse[j] += scene->lights[i].speed * time;
                scene->lights[i].specular[j] += scene->lights[i].speed * time;
            }
        }
    }

}

void render_scene(const Scene* scene) {
    if (scene->dev_mode) {
        draw_origin();
    }

    set_material(&(scene->material));
    draw_light(scene);

    // room
    glPushMatrix();
        glRotatef(90, 1.0f, 0.0f, 0.0f);

        draw_object(scene->objects[0]);
    glPopMatrix();
    
    // fireplace
    glPushMatrix();
        glTranslatef(6.05f, 0.0f, 1.0f);
        glRotatef(90, 1.0f, 0.0f, 0.0f);
        glRotatef(270, 0.0f, 1.0f, 0.0f);

        draw_object(scene->objects[1]);
    glPopMatrix();

    // lamp 1
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, 4.2f);
        glRotatef(-90, 1.0f, 0.0f, 0.0f);

        draw_object(scene->objects[2]);
        draw_object(scene->objects[3]);
    glPopMatrix();

    // Lamp 2
    glPushMatrix();
        glTranslatef(-8.119684f, -5.633071f, 4.2f);
        glRotatef(-90, 1.0f, 0.0f, 0.0f);

        draw_object(scene->objects[2]);
        draw_object(scene->objects[3]);
    glPopMatrix();
    
    // ter
    glPushMatrix();
        glTranslatef(-1.0f, -150.0f, -20.0f);
        glRotatef(90, 1.0f, 0.0f, 0.0f);
        glRotatef(45, 0.0f, 1.0f, 0.0f);

        draw_object(scene->objects[4]);
    glPopMatrix();
    

    // Window
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glEnable(GL_COLOR_MATERIAL);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);

    glBegin(GL_QUADS);
        glColor4f(0.0f, 0.5f, 1.0f, 0.25f);
        
        glNormal3f(1, 1, 1);

        glVertex3f(-3.8f, 6.0f, 0.0f);
        glVertex3f(3.8f, 6.0f, 0.0f);
        glVertex3f(3.8f, 6.0f, 2.5f);
        glVertex3f(-3.8f, 6.0f, 2.5f);
    glEnd();

    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
}



void draw_origin() {
    glBegin(GL_LINES);
        glColor3f(1, 0, 0);
        glNormal3f(0, 0, 1);
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

void draw_object(Object object) {
    glBindTexture(GL_TEXTURE_2D, object.texture);
    draw_model(&object.model);
}

void draw_light(const Scene* scene) {
    int i;

    for (i = 0; i < scene->light_used; i++) {
        if (i == 0) {
            glLightfv(GL_LIGHT0, GL_AMBIENT, scene->lights[i].ambient);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, scene->lights[i].diffuse);
            glLightfv(GL_LIGHT0, GL_SPECULAR, scene->lights[i].specular);
            glLightfv(GL_LIGHT0, GL_POSITION, scene->lights[i].position);
        } else if (i == 1) {
            glLightfv(GL_LIGHT1, GL_AMBIENT, scene->lights[i].ambient);
            glLightfv(GL_LIGHT1, GL_DIFFUSE, scene->lights[i].diffuse);
            glLightfv(GL_LIGHT1, GL_SPECULAR, scene->lights[i].specular);
            glLightfv(GL_LIGHT1, GL_POSITION, scene->lights[i].position);
        } else if (i == 2) {
            glLightfv(GL_LIGHT2, GL_AMBIENT, scene->lights[i].ambient);
            glLightfv(GL_LIGHT2, GL_DIFFUSE, scene->lights[i].diffuse);
            glLightfv(GL_LIGHT2, GL_SPECULAR, scene->lights[i].specular);
            glLightfv(GL_LIGHT2, GL_POSITION, scene->lights[i].position);
        }

        /*if (scene->debug_mode) {
            printf("[Light Index]: %d\n", i);
            printf("[Light Ambient]: %f, %f, %f, %f\n", scene->lights[i].ambient[0], scene->lights[i].ambient[1], scene->lights[i].ambient[2], scene->lights[i].ambient[3]);
            printf("[Light Diffuse]: %f, %f, %f, %f\n", scene->lights[i].diffuse[0], scene->lights[i].diffuse[1], scene->lights[i].diffuse[2], scene->lights[i].diffuse[3]);
            printf("[Light Specular]: %f, %f, %f, %f\n", scene->lights[i].specular[0], scene->lights[i].specular[1], scene->lights[i].specular[2], scene->lights[i].specular[3]);
            printf("[Light Position]: %f, %f, %f, %f\n", scene->lights[i].position[0], scene->lights[i].position[1], scene->lights[i].position[2], scene->lights[i].position[3]);
            printf("[Light Speed]: %f\n", scene->lights[i].speed);
        }*/
    }
}

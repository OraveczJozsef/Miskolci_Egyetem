#include "scene.h"

void init_scene(Scene* scene) {

    scene->dev_mode = false;
    scene->debug_mode = false;

    /* Help */
    scene->is_show_help = false;
    scene->help_texture = load_texture("assets/textures/help.jpg");
    /* Help */

    /* Model */
    init_objects(scene);
    /* Model */

    /* Light */
    init_lights(scene);
    /* Light */

    /* Fire */
    init_fire(&(scene->fire));
    /* Fire */

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
    float position[] = { 0.0f, 0.0f, 1.0f, 0.0f };

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

    diffuse_light[0] = 1.0f;
    diffuse_light[1] = 0.35f;
    diffuse_light[2] = 0.0f;
    diffuse_light[3] = 0.5f;
    position[0] = 5.8f;
    position[1] = -0.03;
    position[2] = 0.55f;
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

void set_show_help(Scene* scene, bool state) {
    scene->is_show_help = state;
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

    /* Fire Texture */
    update_fire(&(scene->fire), time);
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
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
    glDisable(GL_LIGHT3);
    glPushMatrix();
        glTranslatef(-1.0f, -150.0f, -20.0f);
        glRotatef(90, 1.0f, 0.0f, 0.0f);
        glRotatef(45, 0.0f, 1.0f, 0.0f);

        draw_object(scene->objects[4]);
    glPopMatrix();
    glEnable(GL_LIGHT3);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT1);

    // Fire
    render_fire(&(scene->fire));    

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

    glEnable(GL_TEXTURE_2D);
    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_BLEND);
    
    // Help panel
    if (scene->is_show_help) {
        draw_help(scene->help_texture);
    }
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

void draw_object(const Object object) {
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
        } else if (i == 3) {
            glLightfv(GL_LIGHT3, GL_AMBIENT, scene->lights[i].ambient);
            glLightfv(GL_LIGHT3, GL_DIFFUSE, scene->lights[i].diffuse);
            glLightfv(GL_LIGHT3, GL_SPECULAR, scene->lights[i].specular);
            glLightfv(GL_LIGHT3, GL_POSITION, scene->lights[i].position);
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

void draw_help(const GLuint texture) {
    // Benjámin Bettes
    glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor4f(0.75f, 0.75f, 0.75f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);
        glVertex3d(-2, 1.5, -3);

        glTexCoord2f(1, 0);
        glVertex3d(2, 1.5, -3);

        glTexCoord2f(1, 1);
        glVertex3d(2, -1.5, -3);
        
        glTexCoord2f(0, 1);
        glVertex3d(-2, -1.5, -3);
    glEnd();
    

    glDisable(GL_BLEND);
    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    // -------------
}
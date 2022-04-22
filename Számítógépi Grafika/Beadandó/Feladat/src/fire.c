#include "fire.h"

void init_fire(Fire* fire) {
    vec3 position;
    vec3 rotation;

    fire->texture_size = 1;
    fire->texture_used = 0;
    fire->textures = malloc(fire->texture_size * sizeof(Fire));

    fire->fire_effect = false;
    fire->fire_effect_rgba.red = 0;
    fire->fire_effect_rgba.blue = 0;
    fire->fire_effect_rgba.green = 0;
    fire->fire_effect_rgba.alpha = 0;

    load_model(&(fire->model), "assets/models/fire.obj");

    add_texture(fire, "assets/textures/fire/1.png");
    add_texture(fire, "assets/textures/fire/2.png");
    add_texture(fire, "assets/textures/fire/3.png");
    add_texture(fire, "assets/textures/fire/4.png");
    add_texture(fire, "assets/textures/fire/5.png");
    add_texture(fire, "assets/textures/fire/6.png");
    add_texture(fire, "assets/textures/fire/7.png");
    add_texture(fire, "assets/textures/fire/8.png");

    fire->fire_data_size = 1;
    fire->fire_data_used = 0;
    fire->fire_data = malloc(fire->fire_data_size * sizeof(FireData));

    position.x = 5.8f;
    position.y = -0.03f;
    position.z = 0.4f;
    
    rotation.x = 90.0f;
    rotation.y = 0.0f;
    rotation.z = 0.0f;

    add_fire(fire, 0, 0.0f, 2.0f, position, rotation);
    
    position.x = -1.861721f;
    position.y = -1.509007f;
    position.z = 0.3f;

    add_fire(fire, 0, 0.0f, 2.0f, position, rotation);
}

void add_texture(Fire* fire, char* src) {
    if (fire->texture_size == fire->texture_used) {
        fire->texture_size++;
        fire->textures = realloc(fire->textures, fire->texture_size * sizeof(Fire));
    }

    fire->textures[fire->texture_used] = load_texture_rgba(src);
    fire->texture_used++;
}

void add_fire(Fire* fire, int texture_actual, float time, float radius, vec3 position, vec3 rotation) {
    if (fire->fire_data_size == fire->fire_data_used) {
        fire->fire_data_size++;
        fire->fire_data = realloc(fire->fire_data, fire->fire_data_size * sizeof(FireData));
    }

    fire->fire_data[fire->fire_data_used].texture_actual = texture_actual;
    fire->fire_data[fire->fire_data_used].time = time;
    fire->fire_data[fire->fire_data_used].radius = radius;

    fire->fire_data[fire->fire_data_used].position = position;
    fire->fire_data[fire->fire_data_used].rotation = rotation;

    fire->fire_data_used++;
}

void update_fire(Fire* fire, double time) {
    int i;

    for (i = 0; i < fire->fire_data_used; i++) {
        fire->fire_data[i].time += 5 * time;

        if (fire->fire_data[i].time >= 1.0f) {
            fire->fire_data[i].texture_actual = rand() % fire->texture_used;
            fire->fire_data[i].time = 0.0f;
        }
    }
}


void render_fire(const Fire* fire) {
    int i;

    glDisable(GL_LIGHTING);
    glEnable(GL_BLEND);
    glEnable(GL_COLOR_MATERIAL);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        for (i = 0; i < fire->fire_data_used; i++) {
            glPushMatrix();
                glTranslatef(fire->fire_data[i].position.x, fire->fire_data[i].position.y, fire->fire_data[i].position.z);
                glRotatef(fire->fire_data[i].rotation.x, 1.0f, 0.0f, 0.0f);
                glRotatef(fire->fire_data[i].rotation.y, 0.0f, 1.0f, 0.0f);
                glRotatef(fire->fire_data[i].rotation.z, 0.0f, 0.0f, 1.0f);

                glNormal3f(1.0f, 1.0f, 1.0f);
                glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
                
                    
                glBindTexture(GL_TEXTURE_2D, fire->textures[fire->fire_data[i].texture_actual]);
                draw_model(&fire->model);

            glPopMatrix();
        }
    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_BLEND);
    glEnable(GL_LIGHTING);
}
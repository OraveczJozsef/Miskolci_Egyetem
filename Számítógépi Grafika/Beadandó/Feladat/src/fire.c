#include "fire.h"

void init_fire(Fire* fire) {
    fire->texture_size = 1;
    fire->texture_used = 0;
    fire->textures = malloc(fire->texture_size * sizeof(Fire));

    load_model(&(fire->model), "assets/models/fire.obj");

    add_texture(fire, "assets/textures/fire/1.png");
    add_texture(fire, "assets/textures/fire/2.png");
    add_texture(fire, "assets/textures/fire/3.png");
    add_texture(fire, "assets/textures/fire/4.png");
    add_texture(fire, "assets/textures/fire/5.png");
    add_texture(fire, "assets/textures/fire/6.png");
    add_texture(fire, "assets/textures/fire/7.png");
    add_texture(fire, "assets/textures/fire/8.png");

    fire->texture_actual = 0;
    fire->time = 0.0f;

    fire->position.x = 5.8f;
    fire->position.y = -0.03f;
    fire->position.z = 0.5f;
    
    fire->rotation.x = 90.0f;
    fire->rotation.y = 270.0f;
    fire->rotation.z = 0.0f;
}

void add_texture(Fire* fire, char* src) {
    if (fire->texture_size == fire->texture_used) {
        fire->texture_size++;
        fire->textures = realloc(fire->textures, fire->texture_size * sizeof(Fire));
    }

    fire->textures[fire->texture_used] = load_texture_rgba(src);
    fire->texture_used++;
}

void update_fire(Fire* fire, double time) {
    fire->time += 20 * time;
    if (fire->time >= 1.0f) {
        if (fire->texture_actual < (fire->texture_used - 1)) {
            fire->texture_actual++;
        } else {
            fire->texture_actual = 0;
        }

        fire->time = 0.0f;
    }
}

void render_fire(const Fire* fire) {
    glDisable(GL_LIGHTING);
    glPushMatrix();
        glTranslatef(fire->position.x, fire->position.y, fire->position.z);
        glRotatef(fire->rotation.x, 1.0f, 0.0f, 0.0f);
        glRotatef(fire->rotation.y, 0.0f, 1.0f, 0.0f);
        glRotatef(fire->rotation.z, 0.0f, 0.0f, 1.0f);

        glNormal3f(1.0f, 1.0f, 1.0f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        
        glEnable(GL_BLEND);
        glEnable(GL_COLOR_MATERIAL);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            
            glBindTexture(GL_TEXTURE_2D, fire->textures[fire->texture_actual]);
            draw_model(&fire->model);

        glDisable(GL_COLOR_MATERIAL);
        glDisable(GL_BLEND);
    glPopMatrix();
    glEnable(GL_LIGHTING);
}
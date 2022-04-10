#include "camera.h"

#include <GL/gl.h>
#include <math.h>

void init_camera(Camera* camera) {
    camera->dev_mode = false;
    camera->debug_mode = false;

    /* Collisions */
    init_collision(camera);
    /* Collisions */

    camera->position.x = -8.0;
    camera->position.y = -10.5;
    camera->position.z = 1.0;

    camera->rotation.x = 0.0;
    camera->rotation.y = 0.0;
    camera->rotation.z = 90.0;

    camera->speed.x = 0.0;
    camera->speed.y = 0.0;
    camera->speed.z = 0.0;

    camera->multiplier = 1.5f;

    camera->is_preview_visible = false;
}

void init_collision(Camera* camera) {
    camera->collisions_size = 1;
    camera->collisions_used = 0;
    camera->collisions = malloc(camera->collisions_size * sizeof(Collision));

    add_collision(camera, -9.876704, -10.873814, 3.76719, 10.736569);
    add_collision(camera, -8.310473, -3.054345, 4.747963, 2.307802);
    add_collision(camera, -5.862918, -3.862672, 11.753636, 7.744962);
    add_collision(camera, -3.865237, -5.870737, 7.72909, 11.748135);
}


void add_collision(Camera* camera, float x, float y, float w, float h) {
    if (camera->collisions_used == camera->collisions_size) {
        camera->collisions_size++;
        camera->collisions = realloc(camera->collisions, camera->collisions_size * sizeof(Collision));
    }

    camera->collisions[camera->collisions_used].x = x;
    camera->collisions[camera->collisions_used].y = y;
    camera->collisions[camera->collisions_used].w = w;
    camera->collisions[camera->collisions_used].h = h;

    camera->collisions_used++;
}


void set_view(const Camera* camera) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-(camera->rotation.x + 90), 1.0, 0, 0);
    glRotatef(-(camera->rotation.z - 90), 0, 0, 1.0);
    glTranslatef(-camera->position.x, -camera->position.y, -camera->position.z);
}

void set_camera_speed(Camera* camera, double speed) {
    camera->speed.y = speed;
}

void set_camera_side_speed(Camera* camera, double speed) {
    camera->speed.x = speed;
}

void set_camera_multiplier(Camera* camera, float multiplier) {
    camera->multiplier = multiplier;
}


void update_camera(Camera* camera, double time) {
    double angle;
    double side_angle;

    int i;
    bool is_collision = false;
    float new_x, new_y;

    angle = degree_to_radian(camera->rotation.z);
    side_angle = degree_to_radian(camera->rotation.z + 90.0);

    new_x = camera->position.x + (cos(angle) * camera->speed.y + cos(side_angle) * camera->speed.x) * time * camera->multiplier;
    new_y = camera->position.y + (sin(angle) * camera->speed.y + sin(side_angle) * camera->speed.x) * time * camera->multiplier;

    for (i = 0; i < camera->collisions_used; i++) {
        if (in_collision(new_x, new_y, camera->collisions[i]) || camera->dev_mode) {
            is_collision = true;
            break;
        }
    }

    if (is_collision) {
        camera->position.x += ((cos(angle) * camera->speed.y) + (cos(side_angle) * camera->speed.x)) * time * camera->multiplier;
        camera->position.y += ((sin(angle) * camera->speed.y) + (sin(side_angle) * camera->speed.x)) * time * camera->multiplier;
    }
}

void rotate_camera(Camera* camera, double horizontal, double vertical) {
    camera->rotation.z += horizontal;
    camera->rotation.x += vertical;

    if (camera->rotation.z < 0) {
        camera->rotation.z += 360.0;
    }

    if (camera->rotation.z > 360.0) {
        camera->rotation.z -= 360.0;
    }

    if (camera->rotation.x < 0) {
        camera->rotation.x += 360.0;
    }

    if (camera->rotation.x > 360.0) {
        camera->rotation.x -= 360.0;
    }
}


bool in_collision(float new_position_x, float new_position_y, Collision collision) {
    if (
        ((collision.x + COLLISION_PADDING) < new_position_x) &&
        ((collision.y + COLLISION_PADDING) < new_position_y) &&
        ((collision.x + collision.w - COLLISION_PADDING * 2) > new_position_x) &&
        ((collision.y + collision.h - COLLISION_PADDING * 2) > new_position_y)
    ) {
        return true;
    }
    return false;
}


void show_texture_preview()
{
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-1, 1, -3);
    glTexCoord2f(1, 0);
    glVertex3f(1, 1, -3);
    glTexCoord2f(1, 1);
    glVertex3f(1, -1, -3);
    glTexCoord2f(0, 1);
    glVertex3f(-1, -1, -3);
    glEnd();

    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}

#include "camera.h"

#include <GL/gl.h>

#include <math.h>


void init_camera(Camera* camera) {
    init_collision(camera);

    camera->position.x = -8.0;
    camera->position.y = -10.0;
    camera->position.z = 1.0;

    camera->rotation.x = 0.0;
    camera->rotation.y = 0.0;
    camera->rotation.z = 90.0;

    camera->speed.x = 0.0;
    camera->speed.y = 0.0;
    camera->speed.z = 0.0;

    camera->multiplier = 1;

    camera->is_preview_visible = false;
}

void init_collision(Camera* camera) {
    camera->collisions[0].x = -9.876704;
    camera->collisions[0].y = -10.873814;
    camera->collisions[0].w = 3.76719;
    camera->collisions[0].h = 10.736569;
    
    camera->collisions[1].x = -8.310473;
    camera->collisions[1].y = -3.054345;
    camera->collisions[1].w = 4.747963;
    camera->collisions[1].h = 2.307802;

    camera->collisions[2].x = -5.862918;
    camera->collisions[2].y = -3.862672;
    camera->collisions[2].w = 11.753636;
    camera->collisions[2].h = 7.744962;

    camera->collisions[3].x = -3.865237;
    camera->collisions[3].y = -5.870737;
    camera->collisions[3].w = 7.72909;
    camera->collisions[3].h = 11.748135;
}

void update_camera(Camera* camera, double time) {
    double angle;
    double side_angle;
    float new_x, new_y;

    angle = degree_to_radian(camera->rotation.z);
    side_angle = degree_to_radian(camera->rotation.z + 90.0);

    new_x = camera->position.x + (cos(angle) * camera->speed.y + cos(side_angle) * camera->speed.x) * time * camera->multiplier;
    new_y = camera->position.y + (sin(angle) * camera->speed.y + sin(side_angle) * camera->speed.x) * time * camera->multiplier;

    if (
        !is_coolision(new_x, new_y, camera->collisions[0].x, camera->collisions[0].y, camera->collisions[0].w, camera->collisions[0].h) &&
        !is_coolision(new_x, new_y, camera->collisions[1].x, camera->collisions[1].y, camera->collisions[1].w, camera->collisions[1].h) && 
        !is_coolision(new_x, new_y, camera->collisions[2].x, camera->collisions[2].y, camera->collisions[2].w, camera->collisions[2].h) && 
        !is_coolision(new_x, new_y, camera->collisions[3].x, camera->collisions[3].y, camera->collisions[3].w, camera->collisions[3].h)
    ) {
        return;
    }

    camera->position.x += (cos(angle) * camera->speed.y + cos(side_angle) * camera->speed.x) * time * camera->multiplier;
    camera->position.y += (sin(angle) * camera->speed.y + sin(side_angle) * camera->speed.x) * time * camera->multiplier;
}

void set_view(const Camera* camera)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-(camera->rotation.x + 90), 1.0, 0, 0);
    glRotatef(-(camera->rotation.z - 90), 0, 0, 1.0);
    glTranslatef(-camera->position.x, -camera->position.y, -camera->position.z);
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

void set_camera_speed(Camera* camera, double speed) {
    camera->speed.y = speed;
}

void set_camera_side_speed(Camera* camera, double speed) {
    camera->speed.x = speed;
}

void show_texture_preview() {
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

void set_camera_multiplier(Camera* camera, double multiplier) {
    camera->multiplier = multiplier;
}
#include "scene.h"

#include <GL/gl.h>

void init_scene(Scene* scene)
{
}

void update_scene(Scene* scene)
{
}

void render_scene(const Scene* scene)
{
    draw_origin();

    //draw_triangles();

    draw_circle(0.5f, 0.5f, 0.5f, 0.4f, 100);
}

void draw_origin()
{
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

void draw_triangles() {
    glBegin(GL_TRIANGLES);

    glColor3f(1, 1, 0);
    glVertex3f(0, 0, 0); // Center

    glColor3f(0, 1, 1);
    glVertex3f(0, 1, 0); // 

    glColor3f(1, 0, 1);
    glVertex3f(1, 0, 0);

    glEnd();
}

void draw_circle(float center_x, float center_y, float center_z, float radius, int segments) {
    int i;
    //float cx = 0.5;
    //float cy = 0.5;
    //float cz = 0.5;

    glBegin(GL_LINE_LOOP);

    for (i = 0; i < segments; i++) {
        float theta = 2.0f * 3.1415926f * i / segments;
        
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        
        glVertex3f(x + center_x, y + center_y, center_z);
    }
    glEnd();
}
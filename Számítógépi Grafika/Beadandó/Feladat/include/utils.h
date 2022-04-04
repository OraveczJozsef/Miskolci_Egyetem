#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

#define COLLISION_P 0.25
/**
 * GLSL-like three dimensional vector
 */
typedef struct vec2 {
    float x;
    float y;
} vec2;

typedef struct vec3 {
    float x;
    float y;
    float z;
} vec3;

typedef struct vec4 {
    float x;
    float y;
    float z;
    float w;
} vec4;

/**
 * Color with RGB components
 */
typedef struct Color {
    float red;
    float green;
    float blue;
} Color;

typedef struct RGBA {
    float red;
    float green;
    float blue;
    float alpha;
} RGBA;
/**
 * Material
 */
typedef struct Material {
    struct Color ambient;
    struct Color diffuse;
    struct Color specular;
    float shininess;
} Material;

    
typedef struct Light {
    struct RGBA ambient;
    struct RGBA diffuse;
    struct RGBA specular;
    struct vec4 position;

    double speed;
} Light;


typedef struct Collisions {
    float x;
    float y;
    float w;
    float h;
} Collisions;

/**
 * Calculates radian from degree.
 */
double degree_to_radian(double degree);


/**
 * 
 */
bool is_coolision(float camera_x, float camera_y, float collision_x, float collision_y, float collision_w, float collision_h);
#endif /* UTILS_H */

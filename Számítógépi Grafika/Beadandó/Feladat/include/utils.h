#ifndef UTILS_H
    #define UTILS_H

    #include <math.h>

    /**
     * GLSL-like three dimensional vector
     */
    typedef struct vec3 {
        float x;
        float y;
        float z;
    } vec3;

    typedef struct vec2 {
        float x;
        float y;
    } vec2;

    /**
     * Color with RGB components
     */
    typedef struct Color {
        float red;
        float green;
        float blue;
    } Color;
    
    typedef struct ColorA {
        float red;
        float green;
        float blue;
        float alpha;
    } ColorA;

    /**
     * Material
     */
    typedef struct Material {
        struct Color ambient;
        struct Color diffuse;
        struct Color specular;

        float shininess;
    } Material;

    /**
     * Collision
     */
    typedef struct Collision {
        float x;
        float y;
        float w;
        float h;
    } Collision;


    /**
     * Calculates radian from degree.
     */
    double degree_to_radian(double degree);


    vec2 normalize_vec2(const vec2 vec);

#endif /* UTILS_H */

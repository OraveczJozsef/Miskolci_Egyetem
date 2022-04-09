#ifndef CAMERA_H
    #define CAMERA_H

    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>

    #include "utils.h"

    #define COLLISION_PADDING 0.25

    /**
     * Camera, as a moving point with direction
     */
    typedef struct Camera {
        vec3 position;
        vec3 rotation;
        vec3 speed;

        float multiplier;

        bool is_preview_visible;
        
        bool dev_mode;
        bool debug_mode;

        Collision* collisions;
        int collisions_size;
        int collisions_used;
    } Camera;

    /**
     * Initialize the camera to the start position.
     */
    void init_camera(Camera* camera);

    /**
     * Initializes the collision.
     */
    void init_collision(Camera* camera);

    /**
     * Add a new collision to the array.
     */
    void add_collision(Camera* camera, float x, float y, float w, float h);

    /**
     * Update the position of the camera.
     */
    void update_camera(Camera* camera, double time);

    /**
     * Apply the camera settings to the view transformation.
     */
    void set_view(const Camera* camera);

    /**
     * Set the horizontal and vertical rotation of the view angle.
     */
    void rotate_camera(Camera* camera, double horizontal, double vertical);

    /**
     * Set the speed of forward and backward motion.
     */
    void set_camera_speed(Camera* camera, double speed);

    /**
     * Set the speed of left and right side steps.
     */
    void set_camera_side_speed(Camera* camera, double speed);

    /**
     * Speed multiplier (walking, stealth, running).
     */
    void set_camera_multiplier(Camera* camera, float multiplier);

    /**
     * The given coordinate (x, y) is included in this collision.
     */
    bool in_collision(float new_position_x, float new_position_y, Collision collision);

    /**
     * 
     */
    void show_texture_preview();

#endif /* CAMERA_H */

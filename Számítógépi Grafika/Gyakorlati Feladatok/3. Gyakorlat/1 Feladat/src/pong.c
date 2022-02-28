#include "../include/pong.h"
#include <stdio.h>

void init_pong(Pong* pong, int width, int height)
{
    pong->width = width;
    pong->height = height;

    init_pad(&(pong->left_pad), 0, height, RED_THEME);
    init_pad(&(pong->right_pad), width - 50, height, GREEN_THEME);

    init_ball(&(pong->ball), width / 2, height / 2);

    init_players(&(pong->players));
}

void update_pong(Pong* pong, double time)
{
    update_pad(&(pong->left_pad), time);
    update_pad(&(pong->right_pad), time);
    update_ball(&(pong->ball), time);
    bounce_ball(pong);
}

void render_pong(Pong* pong)
{
    render_pad(&(pong->left_pad));
    render_pad(&(pong->right_pad));
    render_ball(&(pong->ball));
}

void set_left_pad_position(Pong* pong, float position)
{
    set_pad_position(&(pong->left_pad), position);
}

void set_left_pad_speed(Pong* pong, float speed)
{
    set_pad_speed(&(pong->left_pad), speed);
}

void set_right_pad_position(Pong* pong, float position)
{
    set_pad_position(&(pong->right_pad), position);
}

void set_right_pad_speed(Pong* pong, float speed)
{
    set_pad_speed(&(pong->right_pad), speed);
}

void bounce_ball(Pong* pong)
{
    if (pong->left_pad.y <= pong->ball.y && (pong->left_pad.y + pong->left_pad.height) >= pong->ball.y) {
        if (pong->ball.x > pong->left_pad.x) {
            if (pong->ball.x - pong->ball.radius < 50) {
                pong->ball.x = pong->ball.radius + 50;

                pong->ball.speed_x *= -1;

                pong->ball.rotate_speed *= -1;

                add_player_left_point(&(pong->players), 1);

                printf("Left: %d\nRight: %d\n\n", get_player_left_point(&(pong->players)), get_player_right_point(&(pong->players)));
            }
        }
    }
    if (pong->right_pad.y <= pong->ball.y && (pong->right_pad.y + pong->right_pad.height) >= pong->ball.y) {
        if (pong->ball.x < pong->right_pad.x) {
            if (pong->ball.x + pong->ball.radius > pong->width - 50) {
                pong->ball.x = pong->width - pong->ball.radius - 50;

                pong->ball.speed_x *= -1;

                pong->ball.rotate_speed *= -1;

                add_player_right_point(&(pong->players), 1);
                
                printf("Left: %d\nRight: %d\n\n", get_player_left_point(&(pong->players)), get_player_right_point(&(pong->players)));
            }
        }
    }
    if (pong->ball.y - pong->ball.radius < 0) {
        pong->ball.y = pong->ball.radius;
        pong->ball.speed_y *= -1;
    }
    if (pong->ball.y + pong->ball.radius > pong->height) {
        pong->ball.y = pong->height - pong->ball.radius;
        pong->ball.speed_y *= -1;
    }
}

#include "utils.h"

#include <math.h>

double degree_to_radian(double degree)
{
	return degree * M_PI / 180.0;
}

bool is_coolision(float camera_x, float camera_y, float collision_x, float collision_y, float collision_w, float collision_h) {
	if (((collision_x + COLLISION_P) < camera_x) && ((collision_y + COLLISION_P) < camera_y) && ((collision_x + collision_w - COLLISION_P * 2) > camera_x) && ((collision_y + collision_h - COLLISION_P * 2) > camera_y)) {
		return true;
	}
	return false;
}
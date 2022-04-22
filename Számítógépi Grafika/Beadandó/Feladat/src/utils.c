#include "utils.h"

double degree_to_radian(double degree)
{
	return degree * M_PI / 180.0;
}

vec2 normalize_vec2(const vec2 vec) {
	vec2 return_value;
	float length = sqrtf((vec.x * vec.x) + (vec.y * vec.y));
	
	return_value.x = vec.x / length;
	return_value.y = vec.y / length;

	return return_value;
}
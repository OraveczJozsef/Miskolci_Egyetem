#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/gl.h>

typedef GLubyte Pixel[3];
typedef GLubyte PixelA[4];

/**
 * Load texture from file and returns with the texture name.
 */
GLuint load_texture(char* filename);

/**
 * 
 */
GLuint load_texture_rgba(char* texture_src);

#endif /* TEXTURE_H */

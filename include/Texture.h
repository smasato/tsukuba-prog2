//
// include/Texture.h
//

#ifndef __INCLUDE_TEXTURE_H__
#define __INCLUDE_TEXTURE_H__

#include <png.h>

typedef struct {
    unsigned int width, height;
    unsigned int texID;
} Texture;

typedef struct {
    unsigned int width, height, channels;
    unsigned char *data;
    png_structp png;
    png_infop info;
    png_bytepp p;
    png_byte type;
    png_byte header[8];
} Png;

int loadPng(Png *png, char *filename);

int getTexture(Texture *texture, Png *png);

int loadPngAndGetTexture(Texture *texture, char *filename);

void drawTexture(Texture *texture, int xi, int yi, unsigned int w, unsigned int h);

#endif // __INCLUDE_TEXTURE_H__

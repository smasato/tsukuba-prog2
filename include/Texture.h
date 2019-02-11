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

int LoadPng(Png *png, char *filename);

int GetTexture(Texture *texture, Png *png);

int LoadPngAndGetTexture(Texture *texture, char *filename);

void DrawTexture(Texture *texture, int xi, int yi, unsigned int w, unsigned int h);

#endif //__INCLUDE_TEXTURE_H__

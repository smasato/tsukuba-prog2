//
// lib/Texture.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Texture.h"

#ifdef __APPLE__

#include <GLUT/glut.h>

#endif

#ifdef __linux

#include <GL/glut.h>

#endif

#define glError() { \
    GLenum err = glGetError(); \
    while (err != GL_NO_ERROR) { \
        fprintf(stderr, "glError: %s caught at %s:%u\n", (char *)gluErrorString(err), __FILE__, __LINE__); \
        err = glGetError(); \
    } \
}

int LoadPng(Png *png, char *filename) {
    FILE *fp;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file: %s\n", filename);
        return 0;
    }

    unsigned int readSize = (unsigned int) fread(png->header, 1, 8, fp);

    if (png_sig_cmp(png->header, 0, 8)) {
        fprintf(stderr, "Error: png_sig_cmp error!\n");
        return 0;
    }

    png->png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (png->png == NULL) {
        fprintf(stderr, "Error: png_create_read_struct error!\n");
        return 0;
    }

    png->info = png_create_info_struct(png->png);
    if (png->info == NULL) {
        fprintf(stderr, "Error: png_crete_info_struct error!\n");
        return 0;
    }

    png_init_io(png->png, fp);
    png_set_sig_bytes(png->png, readSize);
    png_read_png(png->png, png->info, PNG_TRANSFORM_PACKING | PNG_TRANSFORM_STRIP_16, NULL);

    png->width = (unsigned int) png_get_image_width(png->png, png->info);
    png->height = (unsigned int) png_get_image_height(png->png, png->info);

    png->p = png_get_rows(png->png, png->info);

    png->type = png_get_color_type(png->png, png->info);
    if (png->type == PNG_COLOR_TYPE_RGB) {
        png->channels = 3;
    } else if (png->type == PNG_COLOR_TYPE_RGBA) {
        png->channels = 4;
    }

    png->data = (unsigned char *) malloc(
            sizeof(unsigned char) * png->width * png->height * png->channels);
    if (png->data == NULL) {
        fprintf(stderr, "Error: data malloc error!\n");
        return 0;
    }

    for (int i = 0; i < (int) png->height; i++) {
        memcpy(png->data + i * png->width * png->channels, png->p[i], png->width * png->channels);
    }

    png_destroy_read_struct(&png->png, &png->info, NULL);
    fclose(fp);

    return 1;
}

int GetTexture(Texture *texture, Png *png) {
    if (png->channels != 1 && png->channels != 3 && png->channels != 4) {
        fprintf(stderr, "Error: invalid channels: %d\n", png->channels);
        return 0;
    }

    glError();

    glGenTextures(1, &texture->texID);

    if (texture->texID == 0) {
        fprintf(stderr, "Error: texture cannot be created\n");
        return 0;
    }

    texture->width = png->width;
    texture->height = png->height;

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);


    glBindTexture(GL_TEXTURE_2D, texture->texID);
    if (png->channels == 1)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, png->width, png->height, 0,
                     GL_LUMINANCE, GL_UNSIGNED_BYTE, png->data);
    else if (png->channels == 3)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, png->width, png->height, 0,
                     GL_RGB, GL_UNSIGNED_BYTE, png->data);
    else if (png->channels == 4)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, png->width, png->height, 0,
                     GL_RGBA, GL_UNSIGNED_BYTE, png->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);

    glError();

    return 1;
}

int LoadPngAndGetTexture(Texture *texture, char *filename) {
    Png png;

    if (LoadPng(&png, filename)) {
        GetTexture(texture, &png);

        return 1;
    }

    return 0;
}

void DrawTexture(Texture *texture, int xi, int yi, unsigned int w, unsigned int h) {
    glError();

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_ALPHA_TEST);

    glBindTexture(GL_TEXTURE_2D, texture->texID);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex2i(xi, yi);
    glTexCoord2f(1, 0);
    glVertex2i(xi + w, yi);
    glTexCoord2f(1, 1);
    glVertex2i(xi + w, yi + h);
    glTexCoord2f(0, 1);
    glVertex2i(xi, yi + h);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);

    glDisable(GL_ALPHA_TEST);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);

    glError();
}

//
// lib/Text.c
//

#ifdef __APPLE__

#include <GLUT/glut.h>

#endif

#ifdef __linux

#include <GL/glut.h>

#endif

#include "Text.h"

void RenderText(char *text, int x, int y) {
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);

    glRasterPos2i(x, y);
    for (int i = 0; text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}

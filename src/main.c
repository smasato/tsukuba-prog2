#include <stdlib.h>
#include "Texture.h"
#include "Ranking.h"

#ifdef __APPLE__

#include <GLUT/glut.h>

#endif

#ifdef __linux

#include <GL/glut.h>

#endif

#define TITLE 0
#define GAME 1
#define RANKING_INPUT 2
#define RANKING 3

int g_Page = 0;

int g_WindowWidth = 512;
int g_WindowHeight = 512;

Texture g_Tex[5];
Ranking ranking;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glOrtho(0, g_WindowWidth, g_WindowHeight, 0, -1, 1);
    LoadPngAndGetTexture(&g_Tex[TITLE], "src/png/title.png");
    LoadPngAndGetTexture(&g_Tex[GAME], "src/png/game.png");
    LoadPngAndGetTexture(&g_Tex[RANKING], "src/png/ranking.png");

    LoadPngAndGetTexture(&g_Molar_Tex[MOLAR_G], "src/png/game/game_g.png");
    LoadPngAndGetTexture(&g_Molar_Tex[MOLAR_H], "src/png/game/game_h.png");
    LoadPngAndGetTexture(&g_Molar_Tex[MOLAR_V], "src/png/game/game_v.png");
    LoadPngAndGetTexture(&g_Molar_Tex[MOLAR_B], "src/png/game/game_b.png");
    LoadPngAndGetTexture(&g_Molar_Tex[MOLAR_N], "src/png/game/game_n.png");
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    switch (g_Page) {
        case TITLE:
            DrawTexture(&g_Tex[TITLE], 0, 0, g_Tex[TITLE].width, g_Tex[TITLE].width);
            break;
        case GAME:
            break;
        case RANKING_INPUT:
            break;
        case RANKING:
            DrawTexture(&g_Tex[RANKING], 0, 0, g_Tex[RANKING].width, g_Tex[RANKING].width);
            RenderRanking(&ranking);
            break;
        default:
            break;
    }

    glutSwapBuffers();
}

void idle(void) {
    glutPostRedisplay();
}

void keyboard(unsigned char key, unsigned int x, unsigned int y) {
    switch (key) {
        case 'q':
        case 'Q':
        case '\033':
            exit(0);
        case 's':
        case 'S':
            switch (g_Page) {
                case TITLE:
                    g_Page = GAME;
                    break;
            }
        case 'r':
        case 'R':
            switch (g_Page) {
                case TITLE:
                    g_Page = RANKING;
                    break;
            }
            break;
        case 't':
        case 'T':
            switch (g_Page) {
                case TITLE:
                    break;
                case RANKING:
                    g_Page = TITLE;
                    break;
            }
            break;
    }

    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(g_WindowWidth, g_WindowHeight);
    glutCreateWindow("prog2");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();

    return 0;
}

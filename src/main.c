#include <stdlib.h>
#include "Texture.h"
#include "Ranking.h"
#include "Timer.h"

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

#define MOLAR_G 0
#define MOLAR_H 1
#define MOLAR_V 2
#define MOLAR_B 3
#define MOLAR_N 4

int g_Page = 0;

int g_WindowWidth = 512;
int g_WindowHeight = 512;

unsigned char g_Key = 255;

int g_Molar;

double g_prevTime = 0, g_rapTime = 0;

Texture g_Tex[5];
Texture g_Molar_Tex[5];
Ranking g_ranking;

void keyboardHandlerInGame(unsigned char key) {
    switch (key) {
        case 'g':
        case 'G':
            g_Key = 0;
            break;
        case 'h':
        case 'H':
            g_Key = 1;
            break;
        case 'v':
        case 'V':
            g_Key = 2;
            break;
        case 'b':
        case 'B':
            g_Key = 3;
            break;
        case 'n':
        case 'N':
            g_Key = 4;
            break;
        default:
            g_Key = 255;
            break;
    }
}

void game(void) {
    if (g_rapTime == 0) {
        StartTimer();
        DrawTexture(&g_Tex[GAME], 0, 0, g_Tex[GAME].width, g_Tex[GAME].width);
    }
    g_prevTime = GetTime();

    if (g_rapTime > 60) exit(0);

    if (g_Molar == g_Key)g_Molar = rand() % 5;

    DrawTexture(&g_Molar_Tex[g_Molar], 0, 0, g_Molar_Tex[g_Molar].width, g_Molar_Tex[g_Molar].height);

    g_rapTime = GetRapTime(g_prevTime);
}

void init(void) {
    srand((unsigned) time(NULL));

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
            game();
            break;
        case RANKING_INPUT:
            break;
        case RANKING:
            DrawTexture(&g_Tex[RANKING], 0, 0, g_Tex[RANKING].width, g_Tex[RANKING].width);
            RenderRanking(&g_ranking);
            break;
        default:
            break;
    }

    glutSwapBuffers();
}

void idle(void) {
    display();
}

void keyboard(unsigned char key, unsigned int x, unsigned int y) {
    if (g_Page == GAME) {
        keyboardHandlerInGame(key);
    } else {
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
                break;
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

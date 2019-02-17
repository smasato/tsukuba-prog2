#include <stdlib.h>
#include <string.h>
#include "Texture.h"
#include "Ranking.h"
#include "Timer.h"
#include "Text.h"

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
int g_Start = 0;
int g_Score = 0;
char g_Name[10] = {'\0'};

int g_WindowWidth = 512;
int g_WindowHeight = 512;

unsigned char g_Key = 255;

int g_Molar;

time_t g_startTime = 0, g_rapTime = 0;

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

void keyboardHandlerInRankingInput(unsigned char key) {
    int len = (int) strlen(g_Name);
    switch (key) {
        case 13: // enter
            g_Page = RANKING;
            AddToRanking(&g_ranking, g_Score, g_Name);
            g_Score = 0;
            g_Name[0] = '\0';
            g_Start = 0;
            g_rapTime = 0;
            break;
        case 127: // del
            if (strlen(g_Name) > 0) {
                g_Name[len - 1] = '\0';
            }
            break;
        default:
            if (strlen(g_Name) < 9) {
                g_Name[len] = key;
                g_Name[len + 1] = '\0';
            }
            break;
    }
}

void game(void) {
    if (g_Start == 0) {
        g_startTime = GetTime();
        DrawTexture(&g_Tex[GAME], 0, 0, g_Tex[GAME].width, g_Tex[GAME].width);
        g_Start = 1;
    }

    if (g_rapTime > (time_t) 30) {
        g_Page = RANKING_INPUT;
        return;
    }

    if (g_Molar == g_Key) {
        g_Score++;
        g_Molar = rand() % 5;
    }

    DrawTexture(&g_Molar_Tex[g_Molar], 0, 0, g_Molar_Tex[g_Molar].width, g_Molar_Tex[g_Molar].height);

    char time[256];
    sprintf(time, "remaining time: %2d:%02d", (int) (30 - g_rapTime) / 60, (int) (30 - g_rapTime) % 60);
    RenderText(time, 80, 480);

    char score[256];
    sprintf(score, "score: %d", g_Score);
    RenderText(score, 300, 480);

    g_rapTime = GetRapTime(g_startTime);
}

void rankingInput(void) {
    if (CanRankIn(&g_ranking, g_Score) > -1) {
        char *rankingText = "Input your name.";
        RenderText(rankingText, 180, 300);
        RenderText(g_Name, 135, 320);
    } else {
        char score[256];
        sprintf(score, "total score: %d", g_Score);
        RenderText(score, 220, 300);
    }

}

void init(void) {
    srand((unsigned) time(NULL));

    glClearColor(0.0, 0.0, 0.0, 1.0);

    glOrtho(0, g_WindowWidth, g_WindowHeight, 0, -1, 1);
    LoadPngAndGetTexture(&g_Tex[TITLE], "src/png/title.png");
    LoadPngAndGetTexture(&g_Tex[GAME], "src/png/game.png");
    LoadPngAndGetTexture(&g_Tex[RANKING_INPUT], "src/png/ranking_input.png");
    LoadPngAndGetTexture(&g_Tex[RANKING], "src/png/ranking.png");

    LoadPngAndGetTexture(&g_Molar_Tex[MOLAR_G], "src/png/game/game_g.png");
    LoadPngAndGetTexture(&g_Molar_Tex[MOLAR_H], "src/png/game/game_h.png");
    LoadPngAndGetTexture(&g_Molar_Tex[MOLAR_V], "src/png/game/game_v.png");
    LoadPngAndGetTexture(&g_Molar_Tex[MOLAR_B], "src/png/game/game_b.png");
    LoadPngAndGetTexture(&g_Molar_Tex[MOLAR_N], "src/png/game/game_n.png");

    LoadRankingFile("data/ranking_data.csv", &g_ranking);
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
            DrawTexture(&g_Tex[RANKING_INPUT], 0, 0, g_Tex[RANKING_INPUT].width, g_Tex[RANKING_INPUT].width);
            rankingInput();
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

void keyboard(unsigned char key, __attribute__((unused)) int _x, __attribute__((unused)) int _y) {
    if (g_Page == GAME) {
        keyboardHandlerInGame(key);
    } else if (g_Page == RANKING_INPUT) {
        keyboardHandlerInRankingInput(key);
    } else {
        switch (key) {
            case 'q':
            case 'Q':
            case '\033':
                SaveRankingFile("data/ranking_data.csv", &g_ranking);
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

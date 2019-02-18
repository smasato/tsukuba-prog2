//
// src/main.c
//

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

int gPage = 0;
int gStart = 0;
int gScore = 0;
char gName[10] = {'\0'};

int gWindowWidth = 512;
int gWindowHeight = 512;

unsigned char gKey = 255;

int gMolar;

time_t gStartTime = 0, gRapTime = 0;

Texture gTex[5];
Texture gMolarTex[5];
Ranking gRanking;

void keyboardHandlerInGame(unsigned char key) {
    switch (key) {
        case 'g':
        case 'G':
            gKey = 0;
            break;
        case 'h':
        case 'H':
            gKey = 1;
            break;
        case 'v':
        case 'V':
            gKey = 2;
            break;
        case 'b':
        case 'B':
            gKey = 3;
            break;
        case 'n':
        case 'N':
            gKey = 4;
            break;
        default:
            gKey = 255;
            break;
    }
}

void keyboardHandlerInRankingInput(unsigned char key) {
    int len = (int) strlen(gName);
    switch (key) {
        case 13: // enter
            gPage = RANKING;
            addToRanking(&gRanking, gScore, gName);
            gScore = 0;
            gName[0] = '\0';
            gStart = 0;
            gRapTime = 0;
            break;
        case 127: // del
            if (strlen(gName) > 0) {
                gName[len - 1] = '\0';
            }
            break;
        default:
            if (strlen(gName) < 9) {
                gName[len] = key;
                gName[len + 1] = '\0';
            }
            break;
    }
}

void game(void) {
    if (gStart == 0) {
        gStartTime = getTime();
        drawTexture(&gTex[GAME], 0, 0, gTex[GAME].width, gTex[GAME].width);
        gStart = 1;
    }

    if (gRapTime > (time_t) 30) {
        gPage = RANKING_INPUT;
        return;
    }

    if (gMolar == gKey) {
        gScore++;
        gMolar = rand() % 5;
    }

    drawTexture(&gMolarTex[gMolar], 0, 0, gMolarTex[gMolar].width, gMolarTex[gMolar].height);

    char time[256];
    sprintf(time, "remaining time: %2d:%02d", (int) (30 - gRapTime) / 60, (int) (30 - gRapTime) % 60);
    renderText(time, 80, 480);

    char score[256];
    sprintf(score, "score: %d", gScore);
    renderText(score, 300, 480);

    gRapTime = getRapTime(gStartTime);
}

void rankingInput(void) {
    if (canRankIn(&gRanking, gScore) > -1) {
        char *rankingText = "Input your name.";
        renderText(rankingText, 180, 300);
        renderText(gName, 135, 320);
    } else {
        char score[256];
        sprintf(score, "total score: %d", gScore);
        renderText(score, 220, 300);
    }

}

void init(void) {
    srand((unsigned) time(NULL));

    glClearColor(0.0, 0.0, 0.0, 1.0);

    glOrtho(0, gWindowWidth, gWindowHeight, 0, -1, 1);
    loadPngAndGetTexture(&gTex[TITLE], "src/png/title.png");
    loadPngAndGetTexture(&gTex[GAME], "src/png/game.png");
    loadPngAndGetTexture(&gTex[RANKING_INPUT], "src/png/ranking_input.png");
    loadPngAndGetTexture(&gTex[RANKING], "src/png/ranking.png");

    loadPngAndGetTexture(&gMolarTex[MOLAR_G], "src/png/game/game_g.png");
    loadPngAndGetTexture(&gMolarTex[MOLAR_H], "src/png/game/game_h.png");
    loadPngAndGetTexture(&gMolarTex[MOLAR_V], "src/png/game/game_v.png");
    loadPngAndGetTexture(&gMolarTex[MOLAR_B], "src/png/game/game_b.png");
    loadPngAndGetTexture(&gMolarTex[MOLAR_N], "src/png/game/game_n.png");

    loadRankingFile("data/ranking_data.csv", &gRanking);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    switch (gPage) {
        case TITLE:
            drawTexture(&gTex[TITLE], 0, 0, gTex[TITLE].width, gTex[TITLE].width);
            break;
        case GAME:
            game();
            break;
        case RANKING_INPUT:
            drawTexture(&gTex[RANKING_INPUT], 0, 0, gTex[RANKING_INPUT].width, gTex[RANKING_INPUT].width);
            rankingInput();
            break;
        case RANKING:
            drawTexture(&gTex[RANKING], 0, 0, gTex[RANKING].width, gTex[RANKING].width);
            renderRanking(&gRanking);
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
    if (gPage == GAME) {
        keyboardHandlerInGame(key);
    } else if (gPage == RANKING_INPUT) {
        keyboardHandlerInRankingInput(key);
    } else {
        switch (key) {
            case 'q':
            case 'Q':
            case '\033':
                saveRankingFile("data/ranking_data.csv", &gRanking);
                exit(0);
            case 's':
            case 'S':
                switch (gPage) {
                    case TITLE:
                        gPage = GAME;
                        break;
                }
                break;
            case 'r':
            case 'R':
                switch (gPage) {
                    case TITLE:
                        gPage = RANKING;
                        break;
                }
                break;
            case 't':
            case 'T':
                switch (gPage) {
                    case TITLE:
                        break;
                    case RANKING:
                        gPage = TITLE;
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
    glutInitWindowSize(gWindowWidth, gWindowHeight);
    glutCreateWindow("prog2");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();

    return 0;
}

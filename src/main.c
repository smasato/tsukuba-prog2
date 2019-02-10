#include <stdlib.h>

#ifdef __APPLE__

#include <GLUT/glut.h>

#endif

#ifdef __linux

#include <GL/glut.h>

#endif

#include "GenericTimer.h"

int g_WindowWidth = 512;
int g_WindowHeight = 512;

int g_AnimationDuration = 10;

double g_PrevTime = 0.0;

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    StartTimer();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void idle(void) {
    if (GetRapTime(g_PrevTime) >= g_AnimationDuration) {
        g_PrevTime = GetTime();
    }
    display();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'q':
        case 'Q':
        case '\033':
            exit(0);
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int _y) {
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
    glutMouseFunc(mouse);
    init();
    glutMainLoop();

    return 0;
}

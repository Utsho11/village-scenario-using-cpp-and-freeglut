#include <GL/glut.h>

void drawSky() {
    // ── Sky ───────────────────────────────────
    glBegin(GL_QUADS);
        glColor3f(0.53f, 0.81f, 0.98f);  // light blue (top)
        glVertex2f(-1.0f,  1.0f);         // top-left
        glVertex2f( 1.0f,  1.0f);         // top-right

        glColor3f(0.8f, 0.93f, 1.0f);    // pale blue (bottom of sky)
        glVertex2f( 1.0f,  0.0f);         // bottom-right
        glVertex2f(-1.0f,  0.0f);         // bottom-left
    glEnd();

    // ── Ground (Grass) ────────────────────────
    glBegin(GL_QUADS);
        glColor3f(0.24f, 0.60f, 0.17f);  // dark green (top of ground)
        glVertex2f(-1.0f,  0.0f);         // top-left
        glVertex2f( 1.0f,  0.0f);         // top-right

        glColor3f(0.13f, 0.37f, 0.08f);  // deeper green (bottom)
        glVertex2f( 1.0f, -1.0f);         // bottom-right
        glVertex2f(-1.0f, -1.0f);         // bottom-left
    glEnd();
}

void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // sky blue background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);     // 2D world space
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);           // clear screen

    // drawing functions

     drawSky();

    glutSwapBuffers();                      // show the frame
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 27) exit(0);                // ESC to quit
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Village Scene");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}

#include <GL/glut.h>

// ──────────────────────────────────────────
//  Window Settings
// ──────────────────────────────────────────
const int WIDTH  = 800;
const int HEIGHT = 600;
const char* TITLE = "CG Practice";

// ──────────────────────────────────────────
//  Display — put your drawing code here
// ──────────────────────────────────────────
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // TODO: draw your shapes here
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0); glVertex2f( 0.0f,  0.5f);
        glColor3f(0, 1, 0); glVertex2f(-0.5f, -0.5f);
        glColor3f(0, 0, 1); glVertex2f( 0.5f, -0.5f);
    glEnd();

    glutSwapBuffers();
}

// ──────────────────────────────────────────
//  Keyboard — ESC to quit
// ──────────────────────────────────────────
void keyboard(unsigned char key, int x, int y) {
    if (key == 27) exit(0);
}

// ──────────────────────────────────────────
//  Init — one-time OpenGL settings
// ──────────────────────────────────────────
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);     // 2D coordinate space
}

// ──────────────────────────────────────────
//  Main
// ──────────────────────────────────────────
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(TITLE);

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}

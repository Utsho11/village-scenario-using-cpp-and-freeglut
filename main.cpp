#include <GL/glut.h>
// ───────────────── hills ─────────────────
//
// ── Reusable: draws a filled triangle ─────────────────
void drawTriangle(float x1, float y1,
                  float x2, float y2,
                  float x3, float y3) {
    glBegin(GL_TRIANGLES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    glEnd();
}

void drawHills() {
    // ── Layer 1: Farthest hills (lightest) ────────────
    glColor3f(0.45f, 0.72f, 0.35f);
    drawTriangle(-1.0f, 0.0f,  -0.7f, 0.55f,  -0.3f, 0.0f);
    drawTriangle( 0.2f, 0.0f,   0.6f, 0.50f,   1.0f, 0.0f);

    // snow caps — layer 1
    glColor3f(1.0f, 1.0f, 1.0f);
    drawTriangle(-0.77f, 0.43f,  -0.7f, 0.55f,  -0.61f, 0.43f);
    drawTriangle( 0.48f, 0.38f,   0.6f, 0.50f,   0.70f, 0.38f);

    // ── Layer 2: Mid hills (medium green) ─────────────
    glColor3f(0.30f, 0.58f, 0.20f);
    drawTriangle(-1.0f, 0.0f,  -0.5f, 0.38f,   0.1f, 0.0f);
    drawTriangle( 0.0f, 0.0f,   0.5f, 0.42f,   1.0f, 0.0f);

    // snow caps — layer 2
    glColor3f(1.0f, 1.0f, 1.0f);
    drawTriangle(-0.65f, 0.26f,  -0.5f, 0.38f,  -0.30f, 0.26f);
    drawTriangle( 0.35f, 0.30f,   0.5f, 0.42f,   0.65f, 0.30f);

    // ── Layer 3: Near hills (darkest) ─────────────────
    glColor3f(0.18f, 0.45f, 0.10f);
    drawTriangle(-1.0f, 0.0f,  -0.6f, 0.22f,  -0.1f, 0.0f);
    drawTriangle(-0.2f, 0.0f,   0.2f, 0.30f,   0.6f, 0.0f);
    drawTriangle( 0.5f, 0.0f,   0.8f, 0.20f,   1.0f, 0.0f);

    // snow caps — layer 3
    glColor3f(1.0f, 1.0f, 1.0f);
    drawTriangle(-0.78f, 0.12f,  -0.6f, 0.22f,  -0.38f, 0.12f);
    drawTriangle( 0.07f, 0.20f,   0.2f, 0.30f,   0.33f, 0.20f);
    drawTriangle( 0.65f, 0.10f,   0.8f, 0.20f,   0.90f, 0.10f);
}

// ───────────────── Sky ─────────────────
void drawSky() {

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
     drawHills();

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

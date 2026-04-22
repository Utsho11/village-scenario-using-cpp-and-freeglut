#include <GL/glut.h>
#include <math.h>
#define pi 3.1416

float p,dx=0.1;
float pos[4]   = {-200, -100, -400, -300};
float speed[4] = {0.03, 0.028, 0.02, 0.025};
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

void drawQuad(float x1, float y1,
              float x2, float y2,
              float x3, float y3,
              float x4, float y4) {
    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
    glEnd();
}

void drawCircle(float r,float x, float y,float d=360){

    for(float i=0;i<=d;i+=0.5){
        float theta = i * pi / 180;
        float x1 = x + r*cos(theta);
        float y1 = y + r*sin(theta);

        glVertex2f(x1,y1);
    }
}

//------------------clouds------------------
void drawClouds() {
    glColor3f(1, 1, 1); // white cloud

    // ===== Cloud 1 =====
glBegin(GL_POLYGON);
    drawCircle(30, 560 + pos[2], 500);
    drawCircle(25, 520 + pos[2], 510);
    drawCircle(25, 600 + pos[2], 510);
    drawCircle(20, 560 + pos[2], 530);
    drawCircle(22, 580 + pos[2], 485);
glEnd();

    // ===== Cloud 2 =====
glBegin(GL_POLYGON);
    drawCircle(30, 660 + pos[3], 560);
    drawCircle(22, 630 + pos[3], 570);
    drawCircle(26, 700 + pos[3], 565);
    drawCircle(18, 660 + pos[3], 590);
    drawCircle(20, 680 + pos[3], 535);
glEnd();

    // ===== Cloud 3 =====
glBegin(GL_POLYGON);
    drawCircle(30, 660 + pos[1], 540);
    drawCircle(22, 630 + pos[1], 550);
    drawCircle(26, 700 + pos[1], 555);
    drawCircle(18, 660 + pos[1], 570);
    drawCircle(20, 680 + pos[1], 515);
glEnd();


    // ===== Cloud 4 =====
glBegin(GL_POLYGON);
    drawCircle(28, 920 + pos[0], 540);
    drawCircle(24, 880 + pos[0], 550);
    drawCircle(24, 960 + pos[0], 550);
    drawCircle(20, 920 + pos[0], 570);
    drawCircle(22, 940 + pos[0], 520);
glEnd();

    // ---------- movement update ----------
    int r[4] = {0,1,2,3};
    for (int i = 0; i < 4; i++) {
        pos[i] += speed[r[i]];

        if (pos[i] > 1000){
            pos[i] = -1000;
            r[i] = rand() % 4;
        }

    }


}


// ───────────────── hills ─────────────────

void drawHills() {
    // 1st hill

    glColor3f(0.3,0.5,0.7);
    drawTriangle(80,400,170,400,125,450);
    glColor3f(0.13f, 0.37f, 0.08f);
    drawQuad(0,300,250,300,170,400,80,400);

    for(int x=125;x<=750;x+=250){
    glColor3f(0.9,0.9,0.9);
        drawTriangle(80+x,400,170+x,400,125+x,450);
    glColor3f(0.13f, 0.37f, 0.08f);
        drawQuad(0+x,300,250+x,300,170+x,400,80+x,400);
    }

    for(int x=0;x<=1000;x+=250){
    glColor3f(0.9,0.9,0.9);
        drawTriangle(80+x,400,170+x,400,125+x,450);
   glColor3f(0.24f, 0.60f, 0.17f);
        drawQuad(0+x,300,250+x,300,170+x,400,80+x,400);
    }



}

// ───────────────── sky ─────────────────
void drawSkyGround() {

    glBegin(GL_QUADS);
        glColor3f(0.45f, 0.75f, 0.95f);  // light blue (top)
        glVertex2f(0,  600);         // top-left
        glVertex2f( 1000,  600);         // top-right

        glColor3f(0.75f, 0.9f, 1.0f);    // pale blue (bottom of sky)
        glVertex2f( 1000,  300);         // bottom-right
        glVertex2f(0,  300);         // bottom-left
    glEnd();

    // ── Ground (Grass) ────────────────────────
    glBegin(GL_QUADS);
        glColor3f(0.24f, 0.60f, 0.17f);  // dark green (top of ground)
        glVertex2f(0,  0);         // top-left
        glVertex2f( 0,  300);         // top-right

        glColor3f(0.13f, 0.37f, 0.08f);  // deeper green (bottom)
        glVertex2f( 1000, 300);         // bottom-right
        glVertex2f( 1000, 0);         // bottom-left
    glEnd();
}

// ───────────────── river ─────────────────
void drawRiver() {
    // River body
    glColor3f(0.0f, 0.7f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(1000, 200);
        glVertex2f(1000, 300);
    glColor3f(0.0f, 0.55f, 0.9f);
        glVertex2f(750, 300);
        glVertex2f(650, 200);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.85f);
    glBegin(GL_QUADS);
        glVertex2f(730, 200);
        glVertex2f(1000, 200);
        glVertex2f(1000, 0);
        glVertex2f(600, 0);
    glEnd();
}

// ───────────────── boat ─────────────────

void drawBoat(){

    p+=dx;

    if (p > 100) {
    dx = -0.1;
    }

    if (p < -100) {
    dx = 0.1;
    }


    glColor3f(0.55f, 0.27f, 0.07f); // dark brown
    drawQuad(700+p,100,900+p,100,850+p,50,750+p,50);
    glBegin(GL_POLYGON);

    glColor3f(0.70f, 0.50f, 0.23f);
    for(float i=0;i<=180;i+=0.5){
        float theta = i * pi / 180;
        float x1 = p+800 + 60*cos(theta);
        float y1 = 100 + 40*sin(theta);

        glVertex2f(x1,y1);
    }
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0,0,0);

    for(int x=0;x<=40;x+=5){
        glVertex2f(705+x+p,95-x);
        glVertex2f(895-x+p,95-x);
    }


    glColor3f(1,1,1);

     for(int x=0;x<=20;x+=10){
        glVertex2f(760-x+p,130-x);
        glVertex2f(840+x+p,130-x);
    }

     glVertex2f(770+p,100);
     glVertex2f(770+p,133);
     glVertex2f(780+p,100);
     glVertex2f(780+p,137);
     glVertex2f(790+p,100);
     glVertex2f(790+p,139);
     glVertex2f(800+p,100);
     glVertex2f(800+p,140);
     glVertex2f(810+p,100);
     glVertex2f(810+p,140);
     glVertex2f(820+p,100);
     glVertex2f(820+p,138);
     glVertex2f(830+p,100);
     glVertex2f(830+p,135);

    glEnd();

    glutPostRedisplay();

}

// ───────────────── sun ─────────────────
void drawSun(){
    glColor3f(1.0f, 0.9f, 0.3f);
    glBegin(GL_POLYGON);
    drawCircle(50,850,550);
    glEnd();
}

// ───────────────── hay ─────────────────
void drawHay(){
    glColor3f(0.3,0,0);
    drawQuad(190,390,210,390,210,350,190,350);
    glBegin(GL_POLYGON);
    glColor3f(0.85f, 0.75f, 0.35f);
    drawCircle(60,200,300);
    glEnd();
    drawQuad(140,300,260,300,270,200,130,200);
}

//-----------------house-----------------
void drawHouse() {

    // ----- body -----
    glColor3f(0.85f, 0.65f, 0.45f);
    drawQuad(250, 150, 450, 150, 450, 300, 250, 300);

    // ----- roof -----
    glColor3f(0.5f, 0.15f, 0.15f);
    drawTriangle(230, 300, 470, 300, 350, 400);

    // ----- door -----
    glColor3f(0.35f, 0.18f, 0.08f);
    drawQuad(320, 150, 380, 150, 380, 230, 320, 230);

    // ----- windows -----
    glColor3f(0.7f, 0.9f, 1.0f);
    drawQuad(270, 210, 310, 210, 310, 250, 270, 250);
    drawQuad(390, 210, 430, 210, 430, 250, 390, 250);
}

//-----------------tree-----------------
void drawTree() {


    // ----- trunk -----
    glColor3f(0.4f, 0.2f, 0.1f);

    drawQuad(460, 200, 500, 200, 500, 380, 460, 380);

    glBegin(GL_POLYGON);
    // ----- leaves -----
   glColor3f(0.4f, 0.8f, 0.2f);

    drawCircle(70, 480, 420);
    drawCircle(60, 440, 400);
    drawCircle(60, 520, 400);
    drawCircle(55, 480, 470);


    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);           // clear screen

    // drawing functions
     drawSkyGround();
     drawSun();
     drawRiver();
     drawHills();
     drawClouds();
     drawBoat();
     drawHay();
     drawTree();
     drawHouse();



    glutSwapBuffers();                      // show the frame
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("Lab");
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 1000, 0, 600);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

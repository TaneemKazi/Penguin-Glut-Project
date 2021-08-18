#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>

void init()
{
    glClearColor(1.0f ,1.0f ,1.0f, 0.0f);
    gluOrtho2D  (0, 1000, 0, 650);
}

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);

    for(int i=0; i<=100; i++)
    {
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x+cx), (y+cy));
    }
    glEnd();
}


void lineDrawing(int x1, int x2, int y1, int y2)
{
    float step;

    glColor3ub (238, 246, 12);
    int dx = abs(x2-x1);
    int dy = abs(y2-y1);

    if(abs(dx) > abs(dy) )
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }

    float ix = dx/step;
    float iy = dy/step;

    float x=x1, y=y1;

    glBegin(GL_POINTS);
    glVertex2i (abs(x), abs(y));

    int i;
    for (i = 0; i<step; i++)
    {
        x = x + ix;
        y = y + iy;
        glVertex2i (abs(x), abs(y));
    }

    glEnd();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);



    glColor3ub (0, 0, 0);
    circle     (150, 170, 600, 400);

    glColor3ub (146, 140, 100);
    circle     (105,50,600,490);

    glColor3ub (209, 222, 201);
    circle     (140,105,600,350);

    glColor3ub (255, 255, 255);
    circle     (35,35,565,480);

    glColor3ub (255, 255, 255);
    circle     (35,28,635,480);

    glColor3ub (0, 0, 0);
    circle     (10,10,590,480);

    glColor3ub (255, 255, 255);
    circle     (3,3,587,480);

    glColor3ub (0, 0, 0);
    circle     (8,8,608,480);

    glColor3ub (255, 255, 255);
    circle     (2,2,606,480);


    glColor3ub (165, 145, 15);
    glBegin    (GL_POLYGON);
    glVertex2d (620, 400);
    glVertex2d (640, 460);
    glVertex2d (555, 460);
    glEnd();

    glColor3ub (165, 145, 15);
    circle     (75,30,520,250);

    glColor3ub (165, 145, 15);
    circle     (75,30,700,250);

    glColor3ub (0, 0, 0);
    glBegin    (GL_POLYGON);
    glVertex2d (400, 380);
    glVertex2d (455, 380);
    glVertex2d (460, 440);
    glEnd();

    glColor3ub (0, 0, 0);
    glBegin    (GL_POLYGON);
    glVertex2d (760, 380);
    glVertex2d (805, 380);
    glVertex2d (730, 440);
    glEnd();


    glFlush();
}


int main()
{

    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowPosition(600,180);
    glutInitWindowSize(800,700);
    glutCreateWindow("Penguin");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

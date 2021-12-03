#include <windows.h>
#include <stdio.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static int slices = 16;
static int stacks = 16;

float x_position = 0.0, inc = 10;
int state = 1;

/* GLUT callback Handlers */
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glRotatef(1, 0.0, 1.0, 0.0 );

    glLoadIdentity();
    glTranslatef(x_position, 0.0, 0.0);

    //glClear(GL_COLOR_BUFFER_BIT);


    /// body
    glColor3f(0.4,0.3,0.1);
    glBegin(GL_POLYGON);
    glVertex2i(250, 400);
    glVertex2i(500, 230);
    glVertex2i(1000, 230);
    glVertex2i(1250, 400);
    glEnd();

    /// flag
    glColor3f(065, 0.49, 0.12);
    glBegin(GL_POLYGON);
    glVertex2i(250, 600);
    glVertex2i(250, 400);
    glVertex2i(275, 400);
    glVertex2i(275, 600);
    glEnd();


    /// first deck
    glColor3f(0.3, 0.31, 0.2);
    glBegin(GL_POLYGON);
    glVertex2i(420,550);
    glVertex2i(420,400);
    glVertex2i(1080,400);
    glVertex2i(1080,550);
    glEnd();

    /// 178, 172, 10
    /// first window
    glColor3f(0.60, 0.68, 0.04);
    glBegin(GL_POLYGON);
    glVertex2i(485,520);
    glVertex2i(485,430);
    glVertex2i(585,430);
    glVertex2i(585,520);
    glEnd();

    /// second window
    glColor3f(0.60, 0.68, 0.04);
    glBegin(GL_POLYGON);
    glVertex2i(635,520);
    glVertex2i(635,430);
    glVertex2i(735,430);
    glVertex2i(735,520);
    glEnd();

    /// third window
    glColor3f(0.60, 0.68, 0.04);
    glBegin(GL_POLYGON);
    glVertex2i(785,520);
    glVertex2i(785,430);
    glVertex2i(885,430);
    glVertex2i(885,520);
    glEnd();

    /// forth window
    glColor3f(0.60, 0.68, 0.04);
    glBegin(GL_POLYGON);
    glVertex2i(935,520);
    glVertex2i(935,430);
    glVertex2i(1035,430);
    glVertex2i(1035,520);
    glEnd();

    /// second deck
    glColor3f(0.3, 0.51, 0.92);
    glBegin(GL_POLYGON);
    glVertex2i(470,680);
    glVertex2i(470,550);
    glVertex2i(1030,550);
    glVertex2i(1030,680);
    glEnd();

    /// 5th window
    glColor3f(0.60, 0.68, 0.04);
    glBegin(GL_POLYGON);
    glVertex2i(550,650);
    glVertex2i(550,580);
    glVertex2i(650,580);
    glVertex2i(650,650);
    glEnd();

    /// 6th window
    glColor3f(0.60, 0.68, 0.04);
    glBegin(GL_POLYGON);
    glVertex2i(690,650);
    glVertex2i(690,580);
    glVertex2i(790,580);
    glVertex2i(790,650);
    glEnd();
    /// 7th window
    glColor3f(0.60, 0.68, 0.04);
    glBegin(GL_POLYGON);
    glVertex2i(830,650);
    glVertex2i(830,580);
    glVertex2i(930,580);
    glVertex2i(930,650);
    glEnd();


    glLoadIdentity();
    /// water
    /// 19, 76, 198
    glColor3f(0.07,0.31,0.77);
    glBegin(GL_POLYGON);
    glVertex2i(0, 230);
    glVertex2i(0, 0);
    glVertex2i(1440, 0);
    glVertex2i(1440, 230);
    glEnd();

    glutSwapBuffers();
}
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0.0, 1440, 0.0, 1020);
    glMatrixMode(GL_MODELVIEW);
}


void initOpenGL()
{
    glClearColor(0.35, 0.51, 0.72, .0);
    //glClearColor(1.0, 1.0, 1.0, 1.0);
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
    if(x_position>=1250) x_position=-1250;
    // if(x_position>=1250 || x_position<=-1250) inc=-inc;
    x_position += inc;
    //printf("%lf %lf\n", x_position, inc);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("workshop window");

    initOpenGL();



    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    ///void glutTimerFunc(unsigned int numMilliseconds, functionCallback, value);
    glutMainLoop();
    return 0;
}

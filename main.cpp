#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <windows.h>
#include <math.h>

void myInit(void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
}

const GLfloat DEG2RAD = 3.14159/180;

void drawflower(void)
{
GLint i;
GLfloat xradius=3.5;
GLfloat yradius=2;



glColor3f(1.0 ,0.0 ,0.5);

glBegin(GL_POLYGON); //to draw the ellipse in a filled color

for (i=0; i < 360; i++)
{
//convert degrees into radians
float degInRad = i*DEG2RAD;
glVertex2f ( cos (degInRad) *xradius, sin (degInRad) *yradius);
}

glEnd();
}




void drawBorder(void) //to draw the ellipse with just its border
{
GLint i;
GLfloat xradius=3.5;
GLfloat yradius=2;

glColor3f(0.0 ,0.0 ,0.0);

glBegin(GL_LINE_LOOP);

for (i=0; i < 360; i++)
{
//convert degrees into radians
float degInRad = i*DEG2RAD;
glVertex2f ( cos (degInRad) *xradius, sin (degInRad) *yradius);
}

glEnd();
}





void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);

glColor3f(0.0 , 1.0 ,0.6);
glLineWidth(5.0);
glBegin(GL_LINES);
glVertex2f(5.0,6.0);
glVertex2f(5.0,17.0);
glEnd();


//center petal
glPushMatrix() ;
glTranslatef(5,5,0) ;
glRotatef(90,0,0,1) ;
drawflower() ;
drawBorder();
glPopMatrix() ;

//right petal
glPushMatrix() ;
glTranslatef(3.7, 6.6,0);

glRotatef(20,0,0,1) ;
drawflower() ;
drawBorder();
glPopMatrix() ;

//left petal
glPushMatrix() ;
glTranslatef(6.4, 6.6,0) ;

glRotatef(160,0,0,1) ;
drawflower() ;
drawBorder();
glPopMatrix() ;

glFlush();
}

int main(int argc,char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutCreateWindow("flower");
myInit();
glutDisplayFunc(display);
gluOrtho2D (17.0, 0.0, 17.0, 0.0);
glutMainLoop();
}

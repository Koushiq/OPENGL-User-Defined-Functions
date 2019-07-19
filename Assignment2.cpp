#include<windows.h>

#include<GL/glut.h>
#include <GL/gl.h>

#include<bits/stdc++.h>

#define PI 2*acos(0.0)

using namespace std;


void display();

void idle();

void drawGrid();

void drawQuad(GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat);

void drawLine(GLfloat , GLfloat , GLfloat , GLfloat);

void drawTriangle(GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat);

void drawHalfCircle(GLfloat,GLfloat,GLfloat);
void drawCircle(GLfloat,GLfloat,GLfloat);

void drawElipse(GLfloat x,GLfloat y,GLfloat radius,GLfloat xx,GLfloat yy,int start);

void drawShip();
void update2(int value);
void drawBitmapText(char *str,float x,float y,float z);
void drawDigits();
void drawRefelction();
void update();
void handleKeypress(unsigned char , int , int );
void drawClouds();
void handleMouse(int button, int state, int x, int y);

GLfloat position = 0.0f;
//GLfloat position2 = 0.0f;
GLfloat speed = 0.01f;

GLfloat cloudPosition=0.0f;
GLfloat cloudSpeed=0.02f;


void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
	    cloudSpeed+=0.005;
	}
	if(button==GLUT_RIGHT_BUTTON)
    {
        cloudSpeed-=0.005;

    }

    glutPostRedisplay();
}




void handleKeypress(unsigned char key, int x, int y)
{
	switch (key) {
case 'a':
     speed+=0.01;//
    break;
case 'd':
     speed-=0.01;
    break;
glutPostRedisplay();
}}


void drawClouds()
{
    glLoadIdentity();
glPushMatrix();
glTranslatef(cloudPosition,0.0, 0.0f);
    glColor3ub(255,255,255);
    drawCircle(0.4,0.7,0.15);
    drawCircle(0.4,0.58,0.07);
    drawCircle(0.25,0.7,0.07);
    drawCircle(0.28,0.59,0.08);
    drawCircle(0.4+0.1,0.58,0.07);
    drawCircle(0.25+0.1,0.7,0.07);
    drawCircle(0.28+0.11,0.59,0.08);
    drawCircle(0.28+0.26,0.69,0.08);
    glPopMatrix();

}

void update2(int value)
{
    if(cloudPosition<-1.71)
    {
        cloudPosition=1.30f;
    }
    if(cloudPosition>1.31)
       {
           cloudPosition=-1.71;
       }

        cloudPosition -= cloudSpeed;


	glutPostRedisplay();


	glutTimerFunc(25, update2, 0);
}

void update(int value)
{

       if(position < -1.71)
       {
         position = 1.30f;
       }

       if(position>1.31)
       {
           position=-1.71;
       }

        position -= speed;


	glutPostRedisplay();


	glutTimerFunc(25, update, 0);
}

void drawRefelction()
{
     glLoadIdentity();
glPushMatrix();
glTranslatef(position,0.0, 0.0f);
    glColor3ub(252,40,72);
    drawElipse(0.4,-0.206,0.028,0.32,0.0,50);
   /* glColor3ub(255,255,255);
    drawElipse(0.4,-0.240,0.035,0.38,0.0,50);
    */ glPopMatrix();
}

void drawShip()
{


 glLoadIdentity();
glPushMatrix();
glTranslatef(position,0.0, 0.0f);


    //middle
    glColor3ub(240,240,240);
    drawQuad(0.65,0.12, 0.22,0.12, 0.17,0.0, 0.70,0.0);

    //bottom
    glColor3ub(240, 240, 240);
    drawQuad(0.78,0.0, 0.0,0.0, 0.2,-0.4, 0.6,-0.4);

    //bottom red
    glColor3ub(252,40,72);
    drawQuad(0.70,-0.18, 0.088,-0.18, 0.14,-0.25, 0.650,-0.25);

    //window
    glColor3ub(204, 225, 235);
    drawCircle(0.2,-0.07,0.04);
    drawCircle(0.30,-0.07,0.04);
    drawCircle(0.40,-0.07,0.04);

    //square window
    glColor3ub(204, 225, 235);

    drawQuad(0.35,0.08, 0.24,0.08, 0.24,0.055, 0.35,0.055);

    drawQuad(0.5,0.08, 0.46,0.08, 0.46,0.055, 0.5,0.055);
    drawQuad(0.55,0.08, 0.51,0.08, 0.51,0.055, 0.55,0.055);
    drawQuad(0.60,0.08, 0.56,0.08, 0.56,0.055, 0.60,0.055);

    drawQuad(0.5,0.08-0.05, 0.46,0.08-0.05, 0.46,0.055-0.05, 0.5,0.055-0.05);
    drawQuad(0.55,0.08-0.05, 0.51,0.08-0.05, 0.51,0.055-0.05, 0.55,0.055-0.05);
    drawQuad(0.60,0.08-0.05, 0.56,0.08-0.05, 0.56,0.055-0.05, 0.60,0.055-0.05);

    //chimney
    glColor3ub(240, 240, 240);
    drawQuad(0.47,0.28, 0.4,0.28, 0.4,0.1, 0.47,0.1);

    glColor3ub(240, 240, 240);
    drawQuad(0.57,0.28, 0.5,0.28, 0.5,0.1, 0.57,0.1);\

    //chimney layer
    glColor3ub(109, 150, 171);
    drawQuad(0.57,0.22, 0.5,0.22, 0.5,0.18, 0.57,0.18);
    drawQuad(0.47,0.22, 0.4,0.22, 0.4,0.18, 0.47,0.18);




    glPopMatrix();

}


void idle()
{
    glutPostRedisplay();
}

void drawBitmapText(char *str,float x,float y,float z)
{
	char *c;
	glRasterPos3f(x, y,z);

	for (c=str ; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
	}
}

void drawDigits()
{
    glColor3ub(0,0,0);
    /*for(double i=-1.0;i<=1.0;i+=0.1)
    {
            string strr=to_string(i);
            char digit[4];
            strcpy(digit,strr.c_str());
            drawBitmapText(digit,i,0.0,0.0);
    }*/
    float x=-1.0,y=1.0,z=0.0;
    char arr[11][5]={"-1.0","-0.8","-0.6","-0.4","-0.2","0.2","0.4","0.6","0.8","1.0"};

   //top
    for(int i=0;i<11;i++)
    {
        drawBitmapText(arr[i],x+0.05,y-0.18,z);
        x+=0.2;
    }
    //left
    x=-1.0,y=1.0,z=0.0;
    for(int i=0;i<11;i++)
    {
        drawBitmapText(arr[i],x+0.05,y-0.18,z);
        y-=0.2;
    }


    //right
    x=1.0,y=-1.0,z=0.0;

    for(int i=0;i<=11;i++)
    {
        drawBitmapText(arr[i],x-0.15,y+0.02,z);
        y+=0.2;
    }

    glEnd();
}
void drawCircle(GLfloat x,GLfloat y,GLfloat radius)
{
	int i;
	int lineAmount = 100;
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x,y);
	//glColor3ub(255, 0, 191);
		for(i = 0; i <= lineAmount;i++)
        {
			glVertex2f(x + (radius * cos(i *  twicePi / lineAmount)),y + (radius* sin(i * twicePi / lineAmount)));

		}
	glEnd();
}


void drawElipse(GLfloat x,GLfloat y,GLfloat radius,GLfloat xx,GLfloat yy,int start)
{
	int i;
	int lineAmount = 100;
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x,y);
	glColor3ub(141, 173, 194);
		for(i = start; i <= lineAmount;i++)
        {
			glVertex2f(x + ( (radius-xx) * cos(i *  twicePi / lineAmount)),y + ( (radius-yy )* sin(i * twicePi / lineAmount)));

		}
	glEnd();
}



void drawHalfCircle(GLfloat x,GLfloat y,GLfloat radius)
{
	int i;
	int lineAmount = 100;
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x,y);
	//glColor3ub(255, 0, 191);
		for(i = 50; i <= lineAmount;i++)
        {
			glVertex2f(x + (radius * cos(i *  twicePi / lineAmount)),y + (radius* sin(i * twicePi / lineAmount)));

		}
	glEnd();
}

void drawGrid()
{
    glColor3ub(128,128,128);
	glBegin(GL_LINES);
	for(double i=1.0;i>=-1.0;i-=0.2)
    {
        glVertex2f(1.0,(i));glLoadIdentity();
glPushMatrix();
glTranslatef(position,0.0, 0.0f);
        glVertex2f(-1.0,(i));
    }
    for(double i=1.0;i>=-1.0;i-=0.2)
    {
        glVertex2f((i),1.0);
        glVertex2f((i),-1.0);
    }
    glColor3ub(0, 102, 255);
    glVertex2f(1.0,0.0);
    glVertex2f(-1.0,0.0);
    glVertex2f(0.0,1.0);
    glVertex2f(0.0,-1.0);
	glEnd();
}

void drawQuad(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3)
{
    glBegin(GL_QUADS);

    glVertex2f(x0,y0);

    glVertex2f(x1,y1);

    glVertex2f(x2,y2);

    glVertex2f(x3,y3);

    glEnd();
}


void drawLine(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1)
{
    glBegin(GL_LINES);

    glVertex2f(x0,y0);

    glVertex2f(x1,y1);

    glEnd();
}

void drawTriangle(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
    glBegin(GL_TRIANGLES);

    glVertex2f(x0,y0);

    glVertex2f(x1,y1);

    glVertex2f(x2,y2);

    glEnd();
}

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT);


	//sky
	glColor3ub(204, 225, 235);
	drawQuad(1.0,1.0,-1.0,1.0,-1.0,-0.2,1.0,-0.2);


    drawShip();



	//water
	glColor3ub(140, 170, 194);
    drawQuad(1.0,-0.2,-1.0,-0.2,-1.0,-1.0,1.0,-1.0);


    drawRefelction();

    drawClouds();

    //drawGrid();
    //drawDigits();

	glFlush();
	glutSwapBuffers();

}


int main(int argc,char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE);

    glutInitWindowSize(620, 620);

    glutInitWindowPosition(1920/2 - 310,1080/2 - 310);

    glutCreateWindow("Test");

    glutDisplayFunc(display);

    glutIdleFunc(idle);
    glutMouseFunc(handleMouse);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(25, update, 0);
    glutTimerFunc(25,update2,0);
    glutMainLoop();
    return 0;

}

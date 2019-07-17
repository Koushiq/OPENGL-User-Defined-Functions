#include<windows.h>

#include<GL/glut.h>

#include<bits/stdc++.h>

#define PI 2*acos(0.0)

using namespace std;


void display();

void idle();

void drawGrid();

void drawQuad(GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat);

void drawLine(GLfloat , GLfloat , GLfloat , GLfloat);

void drawTriangle(GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat);

void drawCircle(GLfloat,GLfloat,GLfloat);

void drawBitmapText(char *str,float x,float y,float z);
void drawDigits();

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

    // down
    x=-1.0,y=-1.0,z=0.0;
    for(int i=11;i>=0;i--)
    {
        drawBitmapText(arr[i],x-0.35,y+0.02,z);
        x+=0.2;
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

void drawGrid()
{
    glColor3ub(128,128,128);
	glBegin(GL_LINES);
	for(double i=1.0;i>=-1.0;i-=0.2)
    {
        glVertex2f(1.0,(i));
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

	drawGrid();
	drawDigits();

	glFlush();

	glutSwapBuffers();

}


int main(int argc,char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE);

    glutInitWindowSize(420, 420);

    glutInitWindowPosition(1920/2 - 210,1080/2 - 210);

    glutCreateWindow("Test");

    glutDisplayFunc(display);

    glutIdleFunc(idle);

    glutMainLoop();

    return 0;

}

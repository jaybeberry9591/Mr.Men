#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>

const float DEG2RAD = 3.14159/180;
const float PI=3.1416;
static int handstate=0;
void beeTimer(int);
void myHappy();
void myPain();
void DrawCircle(float,float,float,int);
void tree();

void init()
{
    glClearColor(191.0/255.0, 239.0/255.0, 255.0/255.0,0.0f);
}

void myReshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}

double x_position=8.0;
int beeState=1;

void circle(float x, float y,float radius_x, float radius_y)
{
	int i=0;
	float angle = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 50; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex2f (x+cos(angle) * radius_x, y+sin(angle) * radius_y);
		}

	glEnd();
}

void Outlinercircle(float x, float y,float radius_x, float radius_y)
{
	int i=0;
	float angle = 0.0;

	glBegin(GL_LINE_STRIP);

		for(i = 0; i < 50; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex2f (x+cos(angle) * radius_x, y+sin(angle) * radius_y);
		}

	glEnd();
}

void drawEllipse(float x,float y,float xradius, float yradius)
{
	glBegin(GL_POLYGON);

	for(int i=0; i < 360; i++)
	{
		 //convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(x+cos(degInRad)*xradius,y+sin(degInRad)*yradius);
	}
	glEnd();
}


void OutlinerdrawEllipse(float x,float y,float xradius, float yradius)
{
	glBegin(GL_LINE_STRIP);

	for(int i=0; i < 360; i++)
	{
		 //convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(x+cos(degInRad)*xradius,y+sin(degInRad)*yradius);
	}
	glEnd();
}

void DrawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);

	for(int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}

void OutlinerDrawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_LINE_STRIP);

	for(int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}


void mybee()
{
    //body
    glColor3f(1.0,1.0,0.0);
    drawEllipse(x_position+1,8.50,0.65,0.7);
    glColor3d(0.0,0.0,0.0);
    OutlinerdrawEllipse(x_position+1,8.50,0.65,0.7);
    glFlush();

    //head
    glColor3f(0.0,0.0,0.0);
    DrawCircle(x_position+1,9.24,0.35,80);
    glFlush();


    //strips
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
    glVertex2d(x_position+0.225,8.5);
    glVertex2d(x_position+1.88,8.5);
    glEnd();
    glFlush();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
    glVertex2d(x_position+0.2,8.78);
    glVertex2d(x_position+1.65,8.78);
    glEnd();
    glFlush();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
    glVertex2d(x_position+0.225,8.2);
    glVertex2d(x_position+1.65,8.2);
    glEnd();
    glFlush();

    //wings
    glColor3d(211.0/255.0, 211.0/255.0, 211.0/255.0);
    drawEllipse(x_position+0.2,8.50,0.55,0.7);
    drawEllipse(x_position+1.85,8.50,0.55,0.7);
    glColor3d(0.0,0.0,0.0);
    OutlinerdrawEllipse(x_position+0.2,8.50,0.55,0.7);
    OutlinerdrawEllipse(x_position+1.85,8.50,0.55,0.7);

}




void tree()
{


      glColor3d(0.0,0.0,0.0);
      Outlinercircle(-8.0,4.325,2.0,2.0);
      Outlinercircle(-4.5,4.325,2.5,2.5);
      Outlinercircle(0.0,4.325,2.5,2.0);
      Outlinercircle(3.5,4.325,2.5,1.5);
      Outlinercircle(7.5,4.325,2.5,2.5);

      glColor3f(46.0/255.0,139.0/255.0,87.0/255.0);
      circle(-8.0,4.3,2.0,2.0);
      circle(-4.5,4.3,2.5,2.5);
      glColor3d(60.0/255.0,179.0/255.0,113.0/255.0);
      circle(0.0,4.3,2.5,2.0);
      circle(3.5,4.3,2.5,1.5);
      circle(7.5,4.3,2.5,2.5);



}

double x_sandwitch=0.0;
double y_sandwitch=0.0;
double x_ball=0.0;
double y_ball=0.0;

void myHappy()
{
    //face
    glColor3d(1.0,1.0,0.0);
    DrawCircle(5.0,-5.0,2.5,80);
    glColor3d(0.0,0.0,0.0);
    OutlinerDrawCircle(5.0,-5.0,2.5,80);

    //eyes
    glColor3d(0.0,0.0,0.0);
    DrawCircle(4.5,-4.5,0.25,80);
    glColor3d(0.0,0.0,0.0);
    DrawCircle(5.5,-4.5,0.25,80);

    //smile
    glColor3d(0.0, 0.0,0.0);
    Outlinercircle(5.0,-5.65,1.0,-0.95);

    //Right hand
    glColor3d(1.0,1.0,0.0);
    glBegin(GL_QUADS);
    glVertex2d(7.3,y_ball+-5.8);
    glVertex2d(6.8,y_ball+-6.8);
    glVertex2d(8.3,y_ball+-6.8);
    glVertex2d(8.3,y_ball+-5.8);
    glEnd();
    glFlush();

    glColor3d(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(7.3,y_ball+-5.8);
    glVertex2d(6.8,y_ball+-6.8);
    glVertex2d(8.3,y_ball+-6.8);
    glVertex2d(8.3,y_ball+-5.8);
    glVertex2d(7.3,y_ball+-5.8);
    glVertex2d(8.0,y_ball+-5.8);
    glEnd();
    glFlush();


    //Right palm
    glColor3d(1.0,1.0,0.0);
    DrawCircle(8.5,y_ball+-6.3,0.65,80);
    glColor3d(0.0,0.0,0.0);
    OutlinerDrawCircle(8.5,y_ball+-6.3,0.65,80);

     //left hand
    glColor3d(1.0,1.0,0.0);
    glBegin(GL_QUADS);
    glVertex2d(1.9,y_ball+-5.8);
    glVertex2d(1.9,y_ball+-6.8);
    glVertex2d(3.2,y_ball+-6.8);
    glVertex2d(2.7,y_ball+-5.8);
    glEnd();
    glFlush();

    glColor3d(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(1.9,y_ball+-5.8);
    glVertex2d(1.9,y_ball+-6.8);
    glVertex2d(3.2,y_ball+-6.8);
    glVertex2d(2.7,y_ball+-5.8);
    glVertex2d(1.9,y_ball+-5.8);
    glVertex2d(2.7,y_ball+-5.8);
    glEnd();
    glFlush();


    //left palm
    glColor3d(1.0,1.0,0.0);
    DrawCircle(1.5,y_ball+-6.3,0.65,80);
    glColor3d(0.0,0.0,0.0);
    OutlinerDrawCircle(1.5,y_ball+-6.3,0.65,80);


    //ball
    glColor3d(1.0,0.0,0.0);
    DrawCircle(x_ball+1.4,y_ball+-6.2,0.55,80);

    glColor3d(0.0,0.0,0.0);
    OutlinerDrawCircle(x_ball+1.4,y_ball+-6.2,0.55,80);

    //leg
    glColor3d(1.0,1.0,0.0);
    drawEllipse(4.5,-7.6,0.45,0.65);

    glColor3d(1.0,1.0,0.0);
    drawEllipse(5.5,-7.6,0.45,0.65);

    glColor3d(0.0,0.0,0.0);
    OutlinerdrawEllipse(4.5,-7.6,0.45,0.65);
    OutlinerdrawEllipse(5.5,-7.6,0.45,0.65);

  //plate
    glColor3d(0.0/255.0, 206.0/255.0, 209.0/255.0);
    drawEllipse(3.5,-8.5,2.5,0.78);
    glColor3d(0.0,0.0,0.0);
    OutlinerdrawEllipse(3.5,-8.5,2.5,0.78);
    OutlinerdrawEllipse(3.5,-8.5,1.5,0.28);

    //sandwitch
    glColor3d(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(x_sandwitch+3.5,y_sandwitch+-7.5);
    glVertex2d(x_sandwitch+2.5,y_sandwitch+-8.2);
    glVertex2d(x_sandwitch+4.5,y_sandwitch+-8.2);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glVertex2d(x_sandwitch+2.5,y_sandwitch+-8.2);
    glVertex2d(x_sandwitch+2.5,y_sandwitch+-8.8);
    glVertex2d(x_sandwitch+4.5,y_sandwitch+-8.8);
    glVertex2d(x_sandwitch+4.5,y_sandwitch+-8.2);
    glEnd();
    glFlush();

    glColor3d(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(x_sandwitch+3.5,y_sandwitch+-7.5);
    glVertex2d(x_sandwitch+2.5,y_sandwitch+-8.2);
    glVertex2d(x_sandwitch+4.5,y_sandwitch+-8.2);
    glEnd();
    glFlush();

    glColor3d(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(x_sandwitch+3.5,y_sandwitch+-7.5);
    glVertex2d(x_sandwitch+4.5,y_sandwitch+-8.2);
    glEnd();
    glFlush();

    glColor3d(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(x_sandwitch+2.5,y_sandwitch+-8.2);
    glVertex2d(x_sandwitch+2.5,y_sandwitch+-8.8);
    glVertex2d(x_sandwitch+4.5,y_sandwitch+-8.8);
    glVertex2d(x_sandwitch+4.5,y_sandwitch+-8.2);
    glEnd();
    glFlush();

    //sauce and leaf details
    glColor3d(0.0,1.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(x_sandwitch+2.5,y_sandwitch+-8.4);
    glVertex2d(x_sandwitch+4.5,y_sandwitch+-8.4);
    glEnd();
    glFlush();

    glColor3d(1.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(x_sandwitch+2.5,y_sandwitch+-8.5);
    glVertex2d(x_sandwitch+4.5,y_sandwitch+-8.5);
    glEnd();
    glFlush();

    glColor3d(1.0,1.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(x_sandwitch+2.5,y_sandwitch+-8.5);
    glVertex2d(x_sandwitch+4.5,y_sandwitch+-8.5);
    glEnd();
    glFlush();

    glColor3d(1.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(x_sandwitch+2.5,y_sandwitch+-8.6);
    glVertex2d(x_sandwitch+4.5,y_sandwitch+-8.6);
    glEnd();
    glFlush();

    glColor3d(0.0,1.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(x_sandwitch+2.5,y_sandwitch+-8.7);
    glVertex2d(x_sandwitch+4.5,y_sandwitch+-8.7);
    glEnd();
    glFlush();




}



float y_pain=0.0;

void myPain()
{
    //body
    glColor3d(99.0/255.0,184.0/255.0,255.0/255.0);
    drawEllipse(-7.0,-7.0,3.0,5.0);
    glColor3d(0.0,0.0,0.0);
    OutlinerdrawEllipse(-7.0,-7.0,3.0,5.0);
    //eyes
    glColor3d(0.0,0.0,0.0);
    DrawCircle(-7.5,-6.0,0.25,80);
    glColor3d(0.0,0.0,0.0);
    DrawCircle(-6.0,-6.0,0.25,80);

    //Upper bandage
    glColor3d(1.0,1.0,1.0);
    circle(-7.0,-5.0,2.75,3.5);
    glColor3d(0.0,0.0,0.0);
    Outlinercircle(-7.0,-5.0,2.75,3.5);

    //bandage strip
    glBegin(GL_LINE_STRIP);
    glVertex2d(-9.0,-2.5);
    glVertex2d(-5.0,-2.5);
    glEnd();
    glFlush();

    glBegin(GL_LINE_STRIP);
    glVertex2d(-9.5,-3.5);
    glVertex2d(-4.5,-3.5);
    glEnd();
    glFlush();

    glBegin(GL_LINE_STRIP);
    glVertex2d(-9.8,-4.5);
    glVertex2d(-4.2,-4.5);
    glEnd();
    glFlush();


    //smile
    glColor3d(0.0, 0.0,0.0);
    Outlinercircle(-7.0,-7.0,1.5,-1.95);

    //hand
    glColor3d(99.0/255.0,184.0/255.0,255.0/255.0);
    glBegin(GL_QUADS);
    glVertex2d(-4.2,y_pain+-6.5);
    glVertex2d(-4.2,y_pain+-7.5);
    glVertex2d(-2.5,y_pain+-7.5);
    glVertex2d(-2.7,y_pain+-6.5);
    glEnd();
    glFlush();

    glColor3d(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(-4.2,y_pain+-6.5);
    glVertex2d(-4.2,y_pain+-7.5);
    glVertex2d(-2.5,y_pain+-7.5);
    glVertex2d(-2.7,y_pain+-6.5);
    glVertex2d(-4.2,y_pain+-6.5);
    glVertex2d(-2.7,y_pain+-6.5);
    glEnd();
    glFlush();

    //palm
    glColor3d(99.0/255.0,184.0/255.0,255.0/255.0);
    DrawCircle(-2.0,y_pain+-7.0,0.8,80);
    glColor3d(0.0,0.0,0.0);
    OutlinerDrawCircle(-2.0,y_pain+-7.0,0.8,80);

    //Lower bandage
    glColor3d(1.0,1.0,1.0);
    circle(-7.0,-8.35,2.85,-3.5);
    glColor3d(0.0,0.0,0.0);
    Outlinercircle(-7.0,-8.35,2.85,-3.5);

    //lower bandage strip
    glBegin(GL_LINE_STRIP);
    glVertex2d(-9.8,-8.7);
    glVertex2d(-4.1,-8.7);
    glEnd();
    glFlush();

    glBegin(GL_LINE_STRIP);
    glVertex2d(-9.7,-9.5);
    glVertex2d(-4.3,-9.5);
    glEnd();
    glFlush();

}

double x_boat=0.0;

void MyManMyMissMyBoat()
{

    //Miss
    glColor3d(1.0,1.0,0.0);
    DrawCircle(x_boat+1.5,1.2,1.5,80);
    glColor3d(0.0,0.0,0.0);
    OutlinerDrawCircle(x_boat+1.5,1.2,1.5,80);

    //bow
    glColor3d(255.0/255.0,105.0/255.0,180.0/255.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(x_boat+1.0,3.2);
    glVertex2d(x_boat+1.0,2.7);
    glVertex2d(x_boat+1.5,2.7);
    glEnd();
    glFlush();

    glColor3d(255.0/255.0,105.0/255.0,180.0/255.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(x_boat+2.0,3.2);
    glVertex2d(x_boat+2.0,2.7);
    glVertex2d(x_boat+1.5,2.7);
    glEnd();
    glFlush();


   //eyes
    glColor3d(0.0,0.0,0.0);
    DrawCircle(x_boat+1.0,1.5,0.25,80);
    glColor3d(0.0,0.0,0.0);
    DrawCircle(x_boat+2.0,1.5,0.25,80);

    //smile
    glColor3d(0.0, 0.0,0.0);
    Outlinercircle(x_boat+1.5,0.9,0.80,-0.65);


    //MR.MEN
    glColor3f(238.0/255.0,44.0/255.0,44.0/255.0);
    glBegin(GL_QUADS);
    glVertex2d(x_boat+-3.0,3.0);
    glVertex2d(x_boat+-3.0,0.5);
    glVertex2d(x_boat+-0.7,0.3);
    glVertex2d(x_boat+-0.7,3.0);
    glEnd();
    glFlush();

    glColor3d(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(x_boat+-3.0,3.0);
    glVertex2d(x_boat+-3.0,0.5);
    glVertex2d(x_boat+-0.7,0.3);
    glVertex2d(x_boat+-0.7,3.0);
    glVertex2d(x_boat+-3.0,3.0);
    glVertex2d(x_boat+-0.7,3.0);
    glEnd();
    glFlush();

    //eyes
    glColor3d(0.0,0.0,0.0);
    DrawCircle(x_boat+-1.5,2.0,0.25,80);
    glColor3d(0.0,0.0,0.0);
    DrawCircle(x_boat+-2.3,2.0,0.25,80);

    //hat
    glColor3d(125.0/255.0,255.0/255.0,0.0/255.0);
    glRectd(x_boat+-1.0,3.25,x_boat+-2.8,3.0);
    circle(x_boat+-1.8,3.15,0.65,1.2);
    glColor3d(0.0,0.0,0.0);
    Outlinercircle(x_boat+-1.8,3.15,0.65,1.2);

    //smile
    glColor3d(0.0, 0.0,0.0);
    Outlinercircle(x_boat+-1.9,1.5,0.60,-0.75);


    //BOAT
    glBegin(GL_QUADS);
    glColor3f(255.0/255.0,165.0/255.0,79.0/255.0);
    glVertex2d(x_boat+-4.0,0.7);
    glVertex2d(x_boat+-3.0,-2.0);
    glColor3f(205.0/255.0,102.0/255.0,29.0/255.0);
    glVertex2d(x_boat+3.0,-2.0);
    glVertex2d(x_boat+4.0,0.0);
    glEnd();
    glFlush();

    glColor3d(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(x_boat+-4.0,0.7);
    glVertex2d(x_boat+-3.0,-2.0);
    glVertex2d(x_boat+3.0,-2.0);
    glVertex2d(x_boat+4.0,0.0);
    glEnd();
    glFlush();

    //boat strip
    glColor3d(0.0,191.0/255.0,1.0);
    glBegin(GL_QUADS);
    glVertex2d(x_boat+-4.0,0.7);
    glVertex2d(x_boat+-3.88,0.2);
    glVertex2d(x_boat+3.88,-0.5);
    glVertex2d(x_boat+4.0,0.0);
    glEnd();
    glFlush();

    glColor3d(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(x_boat+-4.0,0.7);
    glVertex2d(x_boat+-3.88,0.2);
    glVertex2d(x_boat+3.88,-0.5);
    glVertex2d(x_boat+4.0,0.0);
    glVertex2d(x_boat+-4.0,0.7);
    glVertex2d(x_boat+4.0,0.0);
    glEnd();
    glFlush();


   // glColor3d(1.0,1.0,1.0);

}

static double y_position=0.0;
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


    //sun
    glColor3d(255.0/255.0, 165.0/255.0, 0.0);
    DrawCircle(-2.5,y_position,2.5,120);

    glColor3d(0.0,0.0,0.0);
    OutlinerDrawCircle(-2.5,y_position,2.5,120);



    // tree
    tree();

    //upper ground
    glColor3f(139.0/255.0,87.0/255.0,66.0/255.0);
    glBegin(GL_QUADS);
    glVertex2d(-10.0,4.5);
    glVertex2d(-10.0,4.0);
    glVertex2d(10.0,4.0);
    glVertex2d(10.0,4.5);
    glEnd();
    glFlush();

    glColor3d(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(-10.0,4.5);
    glVertex2d(-10.0,4.0);
    glVertex2d(10.0,4.0);
    glVertex2d(10.0,4.5);
    glVertex2d(-10.0,4.5);
    glVertex2d(10.0,4.5);
    glEnd();
    glFlush();

//lower grass first half
    glColor3f(0.439216,0.858824,0.576471);
    glBegin(GL_QUADS);
    glVertex2d(-10.0,-6.0);
    glVertex2d(-10.0,-10.0);
    glVertex2d(0.0,-10.0);
    glVertex2d(0.0,-4.0);
    glEnd();
    glFlush();


 //lower grass second half
    glColor3f(0.439216,0.858824,0.576471);
    glBegin(GL_QUADS);
    glVertex2d(0.0,-4.0);
    glVertex2d(0.0,-10.0);
    glColor3f (0.137255,0.556863,0.137255);
    glVertex2d(10.0,-10.0);
    glVertex2d(10.0,-2.0);
    glEnd();
    glFlush();

  //water
    glBegin(GL_QUADS);
    glColor3d(0.196078,0.6,0.8);
    glVertex2d(-10.0,4.0);
    glVertex2d(-10.0,-6.0);
    glColor3d (0.258824,0.258824,0.435294);
    glVertex2d(10.0,-2.0);
    glVertex2d(10.0,4.0);
    glEnd();
    glFlush();

 //blanket
    glBegin(GL_QUADS);
    glColor3d(0.89,0.47,0.20);
    glVertex2d(0.0,-6.0);
    glColor3d(0.55,0.09,0.09);
    glVertex2d(2.0,-9.0);
    glColor3d (0.73,0.16,0.96);
    glVertex2d(10.0,-8.5);
    glColor3d (0.309804, 0.184314,0.309804);
    glVertex2d(10.0,-5.1);
    glEnd();
    glFlush();

    glColor3d(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2d(0.0,-6.0);
    glVertex2d(2.0,-9.0);
    glVertex2d(10.0,-8.5);
    glVertex2d(10.0,-5.1);
    glVertex2d(0.0,-6.0);
    glVertex2d(10.0,-5.1);
    glEnd();
    glFlush();


    glPushMatrix();
    MyManMyMissMyBoat();
    glPopMatrix();
    mybee();
    myHappy();

    glPushMatrix();
    myPain();
    glPopMatrix();

    glutSwapBuffers();

}

void move_painhand()
{

    if(handstate==0){
        y_pain+=1.5;
        handstate=1;
        glutPostRedisplay();
        PlaySound("Bye Bye -SoundBible.com-1483442951.wav", NULL, SND_FILENAME| SND_ASYNC);
    }
    else if(handstate==1){
        y_pain=0;
        handstate=-1;
        glutPostRedisplay();
        PlaySound("Bye Bye -SoundBible.com-1483442951.wav", NULL, SND_FILENAME| SND_ASYNC);
    }
    else if(handstate==-1){
        y_pain-=1.5;
        handstate=0;
        glutPostRedisplay();
        PlaySound("Bye Bye -SoundBible.com-1483442951.wav", NULL, SND_FILENAME| SND_ASYNC);
    }

}

static int boatstate=0;
void move_boatforward()
{
    if(x_boat>=-8.0){
        x_boat-=0.07;
        glutPostRedisplay();
        PlaySound("Rowing A Boat-SoundBible.com-2108783030.wav", NULL, SND_FILENAME| SND_ASYNC);

    }
}

void move_boatbackward()
{
    if(x_boat<=8.0){
        x_boat+=0.07;
        glutPostRedisplay();
        PlaySound("Rowing A Boat-SoundBible.com-2108783030.wav", NULL, SND_FILENAME| SND_ASYNC);

    }
}

static int ballstate=0;//ball left hand

void play_ball()
{
    if(ballstate==0){
        x_ball+=7.1;
        ballstate=1;
        glutPostRedisplay();
    }
    else if(ballstate==1) //ball right hand
    {
        x_ball-=7.1;
        ballstate=0;
        glutPostRedisplay();
    }
}

static int happystate=0;//intital position;
void move_happyhand()
{
       if(happystate==0){
        y_ball+=0.5;
        happystate=1;
        glutPostRedisplay();
        PlaySound("Hello Baby Girl-SoundBible.com-879828213.wav", NULL, SND_FILENAME| SND_ASYNC);
       }

       else if(happystate==1){
        y_ball-=0.5;
        happystate=0;
        glutPostRedisplay();
        PlaySound("Hello Baby Girl-SoundBible.com-879828213.wav", NULL, SND_FILENAME| SND_ASYNC);
       }


}


void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 'b':
			move_painhand();
			break;

		case 'p':
			play_ball();
			break;

		case 'h':
			 move_happyhand();
			 break;

	  default:
			break;
	}
}

void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(move_boatforward);
         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
			glutIdleFunc(move_boatbackward);
          //glutIdleFunc(NULL); // make idle function inactive
         break;
      default:
         break;
   }
}

int main()
{
    PlaySound("Mr Men.wav", NULL, SND_FILENAME| SND_ASYNC);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(250,250);
    glutCreateWindow("Mr Men in Park");
    init();
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myReshape);
    glutKeyboardFunc(my_keyboard);
	glutMouseFunc(my_mouse);
    glutTimerFunc(1000,beeTimer,0);
    glutMainLoop();

    return 0;
}

void beeTimer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,beeTimer,0);
    switch (beeState){
    case 1:
        if(x_position>-10.0)
            x_position-=0.10;
        else
             beeState=-1;
             break;

    case -1:
        if(x_position<8.0)
            x_position+=0.10;
        else
            beeState=1;
            break;
        }
        if(y_position<6.0){
            y_position+=0.01;
        }

}

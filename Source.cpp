//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...



#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include <fstream>
#include <time.h>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) // making the size of the canvas --> background image
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


float* taxiColor = colors[DARK_GRAY];  // 
int score = 0;

int xI = 40, yI = 920; // global variable

//TAXIII
void drawCar()
{
	DrawSquare(xI, yI, 30, taxiColor); // Taxi
	DrawCircle(xI, yI, 6, colors[WHEAT]); // to make the left wheel of the taxi
	DrawCircle(xI + 22, yI + 1, 6, colors[WHEAT]);// to make the right wheel of the taxi
	glutPostRedisplay();
}
bool flag = true;
void moveCar()
{
	if (xI > 10 && flag)
	{
		xI -= 19;
		cout << "going left";
		if (xI < 100)

			flag = false;
	}
	else if (xI < 1010 && !flag)
	{
		cout << "go right";
		xI += 19;
		if (xI > 900)
			flag = true;
	}
}
// Random Cars
// 1st Random Car
int a = 40, b = 520;
void drawRandomCar1()
{
	DrawSquare(a, b, 30, colors[MIDNIGHT_BLUE]);
	DrawCircle(a, b, 6, colors[WHEAT]);
	DrawCircle(a + 22, b + 1, 6, colors[WHEAT]);
	glutPostRedisplay();
}
bool flag1 = true;
void moveRandomCar1()
{
	if (a > 10 && flag1)
	{
		a -= 18;
		//cout << "going left";
		if (a < 100)

			flag1 = false;
	}
	else if (a < 1010 && !flag1)
	{
		//cout << "go right";
		a += 18;
		if (a > 900)
			flag1 = true;
	}
}
//2nd Random car
int c = 40, d = 840;
void drawRandomCar2()  // draws a second random car in middle 
{
	DrawSquare(c, d, 30, colors[MIDNIGHT_BLUE]);
	DrawCircle(c, d, 6, colors[WHEAT]);  // to make the left wheels of the car
	DrawCircle(c + 22, d + 1, 6, colors[WHEAT]); // to make the right wheel of the car
	glutPostRedisplay();
}

bool flag2 = true;
void moveRandomCar2() // to move the second random car in the middle right y axis upwards
{
	if (c > 10 && flag2)
	{
		c -= 18;
		//cout << "going left";
		if (c < 100)

			flag2 = false;
	}
	else if (c < 1010 && !flag2)
	{
		//cout << "go right";
		c += 18;
		if (c > 900)
			flag2 = true;
	}
}

//3rd Random Car
int f = 600, e = 40;
void drawRandomCar3() // draws a third random car in middle 
{
	DrawSquare(f, e, 30, colors[MIDNIGHT_BLUE]);
	DrawCircle(f, e, 6, colors[WHEAT]); // to make the left wheels of the car
	DrawCircle(f + 22, e + 1, 6, colors[WHEAT]); // to make the right wheel of the car
	glutPostRedisplay();
}

bool flag3 = true;
void moveRandomCar3() // to move the third random car in the middle right y axis upwards
{
	if (e > 10 && flag3)
	{
		e -= 18;
		//cout << "going left";
		if (e < 100)

			flag3 = false;
	}
	else if (e < 1010 && !flag3)
	{
		//cout << "go right";
		e += 18;
		if (e > 900)
			flag3 = true;
	}
}

//4th random car
int g = 980, h = 840;
void drawRandomCar4() // draw a random car in the extreme right y axis 
{
	DrawSquare(g, h, 30, colors[MIDNIGHT_BLUE]);
	DrawCircle(g, h, 6, colors[WHEAT]);  // to make the left wheels of the car
	DrawCircle(g + 22, h + 1, 6, colors[WHEAT]); // to make the right wheel of the car
	glutPostRedisplay();
}

bool flag4 = true;
void moveRandomCar4() // to move the fourth random car in extreme right y axis downwards
{
	if (h > 10 && flag4)
	{
		h -= 18;
		//cout << "going left";
		if (h < 100)

			flag4 = false;
	}
	else if (h < 1010 && !flag4)
	{
		//cout << "go right";
		h += 18;
		if (h > 900)
			flag4 = true;
	}
}
int passenger1X = 810, passenger1Y1 = 940, passenger1Y2 = 970, head1x = 810, head1y = 975;
int passenger2X = 400, passenger2Y1 = 320, passenger2Y2 = 360, head2x = 400, head2y = 370;
int passenger3X = 880, passenger3Y2 = 170, passenger3Y1 = 120, head3x = 880, head3y = 175;
int sizeP1 = 7, sizeP2 = 7, sizeP3 = 7, sizeC1 = 5, sizeC2 = 5, sizeC3 = 5;
void drawPassanger()  // is drawing the  first passenger and is further used to call the passanger randomly
{
	// Passenger1
	DrawLine(passenger1X, passenger1Y1, passenger1X, passenger1Y2, sizeP1, colors[MISTY_ROSE]);
	DrawCircle(head1x, head1y, sizeC1, colors[RED]);

	// Passenger2
	DrawLine(passenger2X, passenger2Y1, passenger2X, passenger2Y2, sizeP2, colors[MISTY_ROSE]);
	DrawCircle(head2x, head2y, sizeC2, colors[RED]);

	//Passenger3
	DrawLine(passenger3X, passenger3Y1, passenger3X, passenger3Y2, sizeP3, colors[MISTY_ROSE]);
	DrawCircle(head3x, head3y, sizeC3, colors[RED]);

	glutPostRedisplay();
}
void dropOff()  // Not Working Properly
{
	//Green Square drop off location
	int squareX = 250, squareY = 250, squareSize = 20;
	DrawSquare(squareX, squareY, squareSize, colors[GREEN]); //DROP off location
	int key;
	if (key == '32' && (xI == 250 && yI == 250))
	{
		squareX = 0;
		squareY = 0;
		squareSize = 0;
		DrawLine(250, 200, 250, 240, 10, colors[AQUA_MARINE]);
		DrawCircle(250, 250, 5, colors[AQUA_MARINE]);
	}
}

void dropOffLocation() // Not Working Properly
{
	int x = xI;
	x = 800;
	int sX = xI;
	sX = 1000;
	int generate;
	int yd;

	srand((time(0)));
	generate = rand() % 1000 + 800;
	//yd = rand() % 320 + 40;

	DrawCircle(generate, 320, 10, colors[VIOLET]);

	glutPostRedisplay();
}


/*Main Canvas drawing function.*/

void GameDisplay()/**/
{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors




	//Display Score, and name
	DrawString(40, 980, "Score = " + to_string(score), colors[DARK_TURQUOISE]);
	DrawString(360, 980, "Mahareeb Fatima 21i-1564", colors[DARK_TURQUOISE]);
	//DrawString( 960, 980, "Timer ", colors[MISTY_ROSE]);

	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[VIOLET] ); 



	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	



	for (int i = 120; i <= 280; i += 40) // first building
	{
		DrawSquare(i, 880, 40, colors[MISTY_ROSE]);
	}
	for (int i = 600; i <= 1020; i += 40) // second building
	{
		DrawSquare(i, 880, 40, colors[MISTY_ROSE]);
	}
	for (int i = 240; i < 360; i += 40) // third building
	{
		DrawSquare(i, 760, 40, colors[MISTY_ROSE]);
	}
	for (int i = 640; i < 760; i += 40) // fourth building
	{
		DrawSquare(320, i, 40, colors[MISTY_ROSE]);
	}
	for (int i = 160; i < 440; i += 40) // fifth building
	{
		DrawSquare(320, i, 40, colors[MISTY_ROSE]);
	}
	for (int i = 160; i < 320; i += 40) // sixth building
	{
		DrawSquare(120, i, 80, colors[MISTY_ROSE]);
	}
	for (int i = 0; i < 160; i += 40) // seventh building
	{
		DrawSquare(480, i, 40, colors[MISTY_ROSE]);
	}
	for (int i = 160; i < 280; i += 40) // eigth building
	{
		DrawSquare(640, i, 80, colors[MISTY_ROSE]);
	}
	for (int i = 840; i < 960; i += 40) // ninth building
	{
		DrawSquare(i, 80, 40, colors[MISTY_ROSE]);
	}
	for (int i = 640; i < 800; i += 40) // tenth building
	{
		DrawSquare(800, i, 40, colors[MISTY_ROSE]);
	}
	for (int i = 360; i < 520; i += 40) // 11 building
	{
		DrawSquare(680, i, 40, colors[MISTY_ROSE]);
	}
	for (int i = 720; i < 880; i += 40) // 12 building
	{
		DrawSquare(i, 480, 40, colors[MISTY_ROSE]);
	}
	for (int i = 480; i < 600; i += 40) // 13 building
	{
		DrawSquare(i, 680, 40, colors[MISTY_ROSE]);
	}
	for (int i = 560; i < 720; i += 40) // 14 building
	{
		DrawSquare(520, i, 40, colors[MISTY_ROSE]);
	}

	//DRAWING BORDERS
	DrawLine(1020, 0, 1020, 1020, 10, colors[MISTY_ROSE]); // right border
	DrawLine(0, 1020, 1020, 1020, 10, colors[MISTY_ROSE]);// upper border
	DrawLine(0, 0, 0, 1020, 10, colors[MISTY_ROSE]); // Left Border
	DrawLine(0, 0, 1020, 0, 10, colors[MISTY_ROSE]); // lower border

	// Obstacles -  Speed Brakers
	DrawSquare(800, 400, 30, colors[CHOCOLATE]); // obstacle 1
	DrawSquare(400, 80, 30, colors[CHOCOLATE]);  // obstacle 2
	DrawSquare(880, 720, 30, colors[CHOCOLATE]);  // obstacle 3
	DrawSquare(200, 360, 30, colors[CHOCOLATE]);  // obstacle 4
	DrawSquare(160, 680, 30, colors[CHOCOLATE]);  // obstacle 5
	DrawSquare(600, 760, 30, colors[CHOCOLATE]);  // obstacle 6


	//Random Cars Placement;
	drawRandomCar1(); // car obstacle 1 moving in x axis rightwards
	drawRandomCar2(); // car obstacle 2 moving in x axis rightwards
	drawRandomCar3(); // car obstacle 3 moving in y axis upwards
	drawRandomCar4(); // car obstacle 4 moving in y axis downwards

	//Passaengers
	drawPassanger();
	dropOffLocation();
	dropOff();

	drawCar();//TAXI
	glutSwapBuffers(); // do not modify this line..
}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void obstacle()  // Check for Obstacles and subtract pints if the car hits the obstcle
{
	//ObStacle Checking
	//Right Key Car coming from the left
	if (((xI == 130 && (yI >= 620 && yI <= 710)) || (xI == 170 && (yI >= 340 && yI <= 390))
		|| (xI == 360 && (yI >= 60 && yI <= 110)) || (xI == 770 && (yI >= 380 && yI <= 430))
		|| (xI == 850 && (yI >= 700 && yI <= 750)) || (xI == 570 && (yI >= 740 && yI <= 790))
		))
	{
		/* If the Taxi hits an obstacle and it's Colour is Red it will subtract 2 from the score and
		if the taxi colour is yellow it will subtract 4 from the score*/
		if (taxiColor == colors[ORANGE])
		{
			score -= 4;
		}
		else if (taxiColor == colors[RED])
		{
			score -= 2;
		}
	}
	//Left Key Car coming from the right
	else if (((xI == 190 && (yI >= 620 && yI <= 710)) || (xI == 200 && (yI >= 340 && yI <= 390))
		|| (xI == 380 && (yI >= 60 && yI <= 110)) || (xI == 830 && (yI >= 380 && yI <= 430))
		|| (xI == 920 && (yI >= 700 && yI <= 750)) || (xI == 610 && (yI >= 740 && yI <= 790))
		))
	{
		/* If the Taxi hits an obstacle and it's Colour is Red it will subtract 2 from the score and
		if the taxi colour is yellow it will subtract 4 from the score*/
		if (taxiColor == colors[ORANGE])
		{
			score -= 4;
		}
		else if (taxiColor == colors[RED])
		{
			score -= 2;
		}
	}
	//Key Up Car coming from down
	else if (((yI == 680 && (xI >= 160 && xI <= 200)) || (yI == 360 && (xI >= 200 && xI <= 240))
		|| (yI == 80 && (xI >= 400 && xI <= 440)) || (yI == 400 && (xI >= 800 && xI <= 840))
		|| (yI == 720 && (xI >= 840 && xI <= 880)) || (yI == 760 && (xI >= 600 && xI <= 640))
		))
	{
		/* If the Taxi hits an obstacle and it's Colour is Red it will subtract 2 from the score and
		if the taxi colour is yellow it will subtract 4 from the score*/
		if (taxiColor == colors[ORANGE])
		{
			score -= 4;
		}
		else if (taxiColor == colors[RED])
		{
			score -= 2;
		}
	}
	//Key down Car coming from up
	else if (((yI == 710 && (xI >= 160 && xI <= 200)) || (yI == 390 && (xI >= 200 && xI <= 240))
		|| (yI == 110 && (xI >= 400 && xI <= 440)) || (yI == 430 && (xI >= 800 && xI <= 840))
		|| (yI == 750 && (xI >= 840 && xI <= 880)) || (yI == 790 && (xI >= 600 && xI <= 640))
		))
	{
		/* If the Taxi hits an obstacle and it's Colour is Red it will subtract 2 from the score and
		if the taxi colour is yellow it will subtract 4 from the score*/
		if (taxiColor == colors[ORANGE])
		{
			score -= 4;
		}
		else if (taxiColor == colors[RED])
		{
			score -= 2;
		}
	}
}


void NonPrintableKeys(int key, int x, int y)
{
	//COLLISION WITH BUILDINGS
	if (key == GLUT_KEY_RIGHT && ((xI == 90 && (yI >= 860 && yI <= 920)) || (xI == 570 && (yI >= 860 && yI <= 920))
		|| (xI == 210 && (yI >= 720 && yI <= 780)) || (xI == 290 && (yI >= 640 && yI <= 730)) || (xI == 450 && (yI >= 660 && yI <= 720))
		|| (xI == 490 && (yI >= 540 && yI <= 700)) || (xI == 770 && (yI >= 620 && yI <= 800)) || (xI == 90 && (yI >= 140 && yI <= 350))
		|| (xI == 290 && (yI >= 140 && yI <= 440)) || (xI == 450 && (yI >= 0 && yI <= 160)) || (xI == 610 && (yI >= 140 && yI <= 310))
		|| (xI == 810 && (yI >= 60 && yI <= 140)) || (xI == 650 && (yI >= 340 && yI <= 530))
		))
	{
		xI += 0;
	}
	else if (key == GLUT_KEY_LEFT && ((xI == 320 && (yI >= 860 && yI <= 920)) || (xI == 0 && (yI >= 860 && yI <= 920))
		|| (xI == 360 && (yI >= 720 && yI <= 780)) || (xI == 360 && (yI >= 620 && yI <= 780)) || (xI == 600 && (yI >= 660 && yI <= 720))
		|| (xI == 560 && (yI >= 540 && yI <= 700)) || (xI == 840 && (yI >= 620 && yI <= 800)) || (xI == 200 && (yI >= 140 && yI <= 350))
		|| (xI == 360 && (yI >= 140 && yI <= 440)) || (xI == 520 && (yI >= 0 && yI <= 160)) || (xI == 720 && (yI >= 140 && yI <= 310))
		|| (xI == 960 && (yI >= 60 && yI <= 110)) || (xI == 720 && (yI >= 340 && yI <= 490)) || (xI == 880 && (yI >= 450 && yI <= 500))
		))
	{
		xI -= 0;
	}
	else if (key == GLUT_KEY_UP && ((yI == 850 && (xI >= 90 && xI <= 310)) || (yI == 850 && (xI >= 570 && xI <= 1000))
		|| (yI == 730 && (xI >= 210 && xI <= 290)) || (yI == 610 && (xI >= 290 && xI <= 360)) || (yI == 130 && (xI >= 90 && xI <= 200))
		|| (yI == 130 && (xI >= 290 && xI <= 360)) || (yI == 50 && (xI >= 810 && xI <= 960)) || (yI == 130 && (xI >= 610 && xI <= 710))
		|| (yI == 610 && (xI >= 770 && xI <= 830)) || (yI == 530 && (xI >= 490 && xI <= 560)) || (yI == 650 && (xI >= 450 && xI <= 520))
		|| (yI == 650 && (xI >= 530 && xI <= 600)) || (yI == 330 && (xI >= 640 && xI <= 720)) || (yI == 450 && (xI >= 720 && xI <= 880))
		))
	{
		yI += 0;
	}
	else if (key == GLUT_KEY_DOWN && ((yI == 920 && (xI >= 90 && xI <= 310)) || (yI == 920 && (xI >= 570 && xI <= 1000))
		|| (yI == 800 && (xI >= 210 && xI <= 350)) || (yI == 360 && (xI >= 100 && xI <= 200)) || (yI == 450 && (xI >= 290 && xI <= 360))
		|| (yI == 160 && (xI >= 460 && xI <= 520)) || (yI == 120 && (xI >= 810 && xI <= 960)) || (yI == 320 && (xI >= 620 && xI <= 720))
		|| (yI == 720 && (xI >= 470 && xI <= 600)) || (yI == 520 && (xI >= 650 && xI <= 880)) || (yI == 800 && (xI >= 730 && xI <= 840))
		))
	{
		yI -= 0;
	}

	// Checking For Obstacles and subtracting points
	else if (key == GLUT_KEY_RIGHT)
	{
		// what to do when right key is pressed...
		obstacle();
		xI += 10;
	}
	else if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/)
	{
		// what to do when left key is pressed...
		obstacle();
		xI -= 10;
	}
	else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/)
	{
		obstacle();
		yI += 10;
	}

	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/)
	{
		obstacle();
		yI -= 10;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y)
{
	if (key == 27/* Escape key ASCII*/)
	{
		exit(1); // exit the program when escape key is pressed.
	}
	//Picking up the passangers
	// 32 is the ASCII of spacebar
	if (key == 32 && ((xI >= 760 && xI <= 840) && (yI >= 900 && yI <= 970)))
	{
		passenger1X = 0;
		passenger1Y1 = 0;
		passenger1Y2 = 0;
		head1x = 0;
		head1y = 0;
		sizeP1 = 0;
		sizeC1 = 0;

		score += 10; // 10 points for picking the passenger
	}
	// Picking passenge 2
	if (key == 32 && ((xI >= 360 && xI <= 410) && (yI >= 300 && yI <= 410)))
	{
		// what to do when right key is pressed...
		passenger2X = 0;
		passenger2Y1 = 0;
		passenger2Y2 = 0;
		head2x = 0;
		head2y = 0;
		sizeP2 = 0;
		sizeC2 = 0;

		score += 10; // 10 points for picking the passenger
	}
	//Picking Passenger3
	if (key == 32 && ((xI >= 840 && xI <= 900) && (yI >= 120 && yI <= 160)))
	{
		// what to do when right key is pressed...
		passenger3X = 0;
		passenger3Y1 = 0;
		passenger3Y2 = 0;
		head3x = 0;
		head3y = 0;
		sizeP3 = 0;
		sizeC3 = 0;

		score += 10; // 10 points for picking the passenger
	}
	glutPostRedisplay();
}
/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m)
{
	// implement your functionality here
	//moveCar();
	moveRandomCar1();
	moveRandomCar2();
	moveRandomCar3();
	moveRandomCar4();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y)
{
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y)
{
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
		cout << "Right Button Pressed" << endl;

	}
	glutPostRedisplay();
}
void inputScoreBoard()
{
	string name[10];
	int score[10];
	int i = 0;
	cout << "Plase Enter your Name:   ";
	cin >> name[i];

	fstream file;
	file.open("highScores.txt", ios::out | ios::app | ios::ate);
	{
		file << name[i] << "    " << score[i] << endl;
	}
	file.close();
}
void displayScoreBoard()
{
	inputScoreBoard();
	string line; // to read the file line by line
	fstream file;
	ifstream("highScores.txt");
	while (file.eof() == 0)
	{
		getline(file, line);
		cout << line << endl;
	}

}
void menu()
{
	char choice, choice1, colour;


	cout << "Do you want to play Rush hour game...?\n";
	cout << "'Y' =  Yes\n'N =  No'     ";
	cin >> choice;
	if (choice == 'Y' || choice == 'y')
	{
		cout << "Do you want to view the LeaderBoard...?\n";
		cout << "'Y' =  Yes\n'N =  No'     ";
		cin >> choice1;
		if (choice1 == 'Y' || choice1 == 'y')
		{
			displayScoreBoard();
		}
		cout << "Select the colour of the taxi\n";
		cout << "'R' = RED\n'Y' = YELLOW...\t";
		cin >> colour;
		if (colour == 'R' || colour == 'r')
		{
			taxiColor = colors[RED]; // dynamic array is storing the address of colour red
		}
		else if (colour == 'Y' || colour == 'y')
		{
			taxiColor = colors[ORANGE];
		}
		else
		{
			cout << "INVALID COLOR ENTERED.\n";
			cout << "Now you can only play with the original color.\n";
		}
	}


}
int main(int argc, char* argv[])
{
	menu();

	int width = 1020, height = 1020; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Mahareeb Fatima"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...



	//checkObstacles();

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
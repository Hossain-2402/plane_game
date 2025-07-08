#include "iGraphics.h"

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://


int vh = 9;
int vw = 16;



unsigned int game_background_image_down;
unsigned int game_background_image_up;

unsigned int tower_image;
unsigned int tower_image_reverse;

unsigned int plane_image;

double background_left = 0;
double left = 40;
int plane_y = 45;

void make_background(){
	for (int i = 0; i < 50; i++){
		int dist = i * 100;
		iShowImage((background_left + dist) * vw, 0, 100 * vw, 51 * vh, game_background_image_down);


		iShowImage((background_left + dist) * vw, 49 * vh, 100 * vw, 51 * vh, game_background_image_up);



	}
}

void move_background(){
	background_left -= 0.005;
}


void make_buildings(){
	int random_number = rand() % 60;
	int add = (random_number < 30) ? random_number + 30 : random_number;
	for (int i = 0; i < 50; i++){
		int tower_image_x = 50;
		int tower_image_reverse_x = 50;

		iShowImage((left + (i * 50)) * vw, 12.5 * vh, 15 * vw, 55 * vh, tower_image);

		iShowImage(((left + 25) + (i * 50))* vw, 32.5 * vh, 15 * vw, 55 * vh, tower_image_reverse);
	}
}

void move_buildings(){
	left -= 0.005;
}

void make_plane(){

	iShowImage(5 * vw, plane_y * vh, 15 * vw, 15 * vh, plane_image);
}


void iDraw()
{
	iClear();



	make_background();
	move_background();

	make_plane();

	make_buildings();
	move_buildings();



}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == 'w')
	{
		plane_y++;
	}
	if (key == 's')
	{
		if (plane_y > 10) plane_y--;
	}
	
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
				
	}
	if (key == GLUT_KEY_LEFT)
	{
		
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
}


int main()
{
	iInitialize(100*vw, 100*vh, "Project Title");


	game_background_image_down = iLoadImage("background_2.jpg");
	game_background_image_up = iLoadImage("reverse_background_2.jpg");

	tower_image = iLoadImage("tower_image.png");
	tower_image_reverse = iLoadImage("tower_image_reverse.png");

	plane_image = iLoadImage("plane_image_2.png");


	iStart();
	return 0;
}

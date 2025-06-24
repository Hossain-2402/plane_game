#include "iGraphics.h"

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://



const float vh = 9;
const int vw = 16;

char images[4][100] = { "ball_1.png", "ball_2.png", "ball_3.png", "ball_4.png" };
int index = 0;

int play_button_clicked = 0;

int car_x = -20;

float plane_y = 45;





void rotate_ball(){
	index++;

	if (index > 3) index = 0;

}

void move_car(){
	car_x ++;

	if (car_x > 100){
		car_x = -19;
	}

}


int bottom_tower = 20;
int up_tower = 40;

int left = 20;

void make_buildings(){
	int random_number = rand() % 60;
	int add = (random_number < 30) ? random_number + 30 : random_number;
	for (int i = 0; i < 10; i++){
		int tower_image_x = 50 ;
		int tower_image_reverse_x = 50 ;

		unsigned int tower_image = iLoadImage("tower_image.png");
		iShowImage((left + tower_image_x + (i*50)) * vw, 12.5 * vh, 15 * vw, 55 * vh, tower_image);

		unsigned int tower_image_reverse = iLoadImage("tower_image_reverse.png");
		iShowImage((left+35+tower_image_reverse_x + + (i*50))* vw, 32.5 * vh, 15 * vw, 55 * vh, tower_image_reverse);
	}
}

int background_left = 0;
void make_background(){
	for (int i = 0; i < 10; i++){
		int dist = i * 100;
		unsigned int game_background_image_down = iLoadImage("background_2.jpg");
		iShowImage((background_left + dist) * vw, 0, 100 * vw, 51 * vh, game_background_image_down);


		unsigned int game_background_image_up = iLoadImage("reverse_background_2.jpg");
		iShowImage((background_left + dist) * vw, 49 * vh, 100 * vw, 51 * vh, game_background_image_up);


		
	}
}

void move_buildings(){
	left -= 10;
}


void move_background(){
	background_left -= 10;
}


void play_screen(){


	make_background();
	move_background();



	unsigned int back_button = iLoadImage("back_button_image.png");
	iShowImage(-2.5 * vw, 90 * vh, 15 * vw, 7 * vh, back_button);


	unsigned int plane_image = iLoadImage("plane_image_2.png");
	iShowImage(5*vw, plane_y * vh, 15 * vw, 15 * vh, plane_image);


//	unsigned int tower_image = iLoadImage("tower_image.png");
//	iShowImage(20 * vw, 12.5 * vh, 15 * vw, 45 * vh, tower_image);

//	unsigned int tower_image_reverse = iLoadImage("tower_image_reverse.png");
//	iShowImage(40 * vw, 43.5 * vh, 15 * vw, 45 * vh, tower_image_reverse);


	make_buildings();
	move_buildings();
	
}

void iDraw()
{
	
	
	
	iClear();





	unsigned int image = iLoadImage("wallpaper.jpg");
	iShowImage(0, 0, 100 * vw, 100 * vh, image);

	iSetColor(0, 255, 0);
	iFilledRectangle(30 * vw, 80 * vh, 40 * vw, 10 * vh);
	iSetColor(0,0,0);
	iText(48 * vw, 84 * vh, "Play", GLUT_BITMAP_HELVETICA_18);


	iSetColor(245, 245, 220);
	iFilledRectangle(30 * vw, 60 * vh, 40 * vw, 10 * vh);
	iSetColor(0, 0, 0);
	iText(47 * vw, 64 * vh, "History", GLUT_BITMAP_HELVETICA_18);

	iSetColor(173, 216, 230);
	iFilledRectangle(30 * vw, 40 * vh, 40 * vw, 10 * vh);
	iSetColor(0,0,0);
	iText(47 * vw, 44 * vh, "Settings", GLUT_BITMAP_HELVETICA_18);

	iSetColor(255, 0, 0);
	iFilledRectangle(30 * vw, 20 * vh, 40 * vw, 10 * vh);
	iSetColor(255,255,255);
	iText(48 * vw, 24 * vh, "Quit", GLUT_BITMAP_HELVETICA_18);


	if (play_button_clicked) play_screen();



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
	/*


	*/
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if ((mx >= 30 * vw && mx <= 70 * vw) && (my >= 80 * vh && my <= 90 * vh)) play_button_clicked = 1;

		if ((mx >= 2.5 * vw && mx <= 12.5 * vw) && (my >= 90 * vh && my <= 95 * vh)) play_button_clicked = 0;
		
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

void iTimer() {
	move_car();
}

int main()
{
	///srand((unsigned)time(NULL));

	iInitialize(100*vw, 100*vh, "First game");
	///updated see the documentations
	iStart();
	return 0;
}
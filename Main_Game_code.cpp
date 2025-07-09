#include "iGraphics.h"

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://


int vh = 4;
int vw = 6;



int landing_page_background_image;
int button_image;

int play_button_clicked = 0;
int levels_button_clicked = 0;
int quit_button_clicked = 0;


void show_play_screen(){
	iSetColor(255, 255, 255);
	iFilledRectangle(0,0,100*vw,100*vh);

	iSetColor(0, 0, 0); 
	iText(0,80*vh,"Play Screen");
}

void show_levels_screen(){
	iSetColor(255, 255, 255);
	iFilledRectangle(0, 0, 100 * vw, 100 * vh);

	iSetColor(0, 0, 0);
	iText(0, 80 * vh, "Levels Screen");
}

void create_landing_page(){
	
	iShowImage(0,0,100*vw,100*vh,landing_page_background_image);

	iShowImage(30*vw,50*vh,40*vw,40*vh,button_image);
	iSetColor(0,0,0);
	iText(47.5 * vw, 70 * vh, "Play", GLUT_BITMAP_8_BY_13);
	
	iShowImage(30 * vw, 30 * vh, 40 * vw, 40 * vh, button_image);
	iSetColor(0, 0, 0);
	iText(46 * vw, 50 * vh, "Levels");

	iShowImage(30 * vw, 10 * vh, 40 * vw, 40 * vh, button_image);
	iSetColor(0, 0, 0);
	iText(47.5 * vw, 30 * vh, "Quit");

	if (play_button_clicked == 1) show_play_screen();
	if (levels_button_clicked == 1) show_levels_screen();
	if (quit_button_clicked == 1) exit(0);


}


void iDraw()
{
	iClear();

	create_landing_page();

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
		if ((mx >= 30 * vw && mx <= 70 * vw) && (my >= 50 * vh && my <= 90 * vh)) play_button_clicked = 1;

		if ((mx >= 30 * vw && mx <= 70 * vw) && (my >= 30 * vh && my <= 70 * vh)) levels_button_clicked = 1;

		if ((mx >= 30 * vw && mx <= 70 * vw) && (my >= 10 * vh && my <= 50 * vh)) quit_button_clicked = 1;
		
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
	if (key == '\r')
	{
		
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
	///srand((unsigned)time(NULL));
	iInitialize(100*vw, 100*vh, "Project Title");

	
	landing_page_background_image = iLoadImage("2.png");
	button_image = iLoadImage("button_image.png");

	///updated see the documentations
	iStart();
	return 0;
}

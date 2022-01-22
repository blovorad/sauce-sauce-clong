#include "prototype.h"

Mouse mouse;													//creation de la souris

void initMouse(void)
{
	SDL_GetMouseState(&mouse.x, &mouse.y);						//init des valeurs de la souris
	mouse.rightButton = SDL_FALSE;								//...
	mouse.leftButton = SDL_FALSE;								//...
	mouse.oldRightButton = SDL_FALSE;							//...
	mouse.oldLeftButton = SDL_FALSE;							//Fin init des valeurs de la souris
}

void getMousePos(void)
{
	SDL_GetMouseState(&mouse.x, &mouse.y);						//actualisation de la position de la souris
}	

void actualiseRightButton(int n)
{
	if(n == 1)													//actualisation du bouton droite de la souris
	{
		mouse.oldRightButton = mouse.rightButton;				//..
		mouse.rightButton = SDL_TRUE;							//..
	}
	else if(n == 2)												//actualisation du bouton droite de la souris
	{
		mouse.oldRightButton = mouse.rightButton;				//..
		mouse.rightButton = SDL_FALSE;							//..
	}	
}

void actualiseLeftButton(int n)
{
	if(n == 1)													//actualisation du bouton gauche de la souris
	{
		mouse.oldLeftButton = mouse.leftButton;					//..
		mouse.leftButton = SDL_TRUE;							//..
	}
	else if(n == 2)												//actualisation du bouton gauche de la souris
	{
		mouse.oldLeftButton = mouse.leftButton;					//..
		mouse.leftButton = SDL_FALSE;							//..
	}
}

void actualiseOldLeftButton(void)
{
	mouse.oldLeftButton = mouse.leftButton;						//utile pour le gui / bouton
}

void actualiseOldRightButton(void)
{
	mouse.oldRightButton = mouse.rightButton;					//utile pour le gui / bouton
}

SDL_bool getStateOfRightButton(void)
{
	return mouse.rightButton;									//si le bouton droit est enfoncer
}

SDL_bool getStateOfOldRightButton(void)
{
	return mouse.oldRightButton;								//si le bouton gauche est enfoncer
}

SDL_bool getStateOfLeftButton(void)
{
	return mouse.leftButton;									//si le bouton gauche a été enfoncer
}

SDL_bool getStateOfOldLeftButton(void)
{
	return mouse.oldLeftButton;									//si le bouton droit a été enfoncer
}

int getMouseX(void)
{
	return mouse.x;												//récuperation de la valeur X de la souris pour utilisation
}

int getMouseY(void)
{
	return mouse.y;												//récuperation de la valeur Y de la souris pour utilisation
}


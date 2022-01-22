#include "prototype.h"

void draw(void)
{
	if(SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 255) != 0)									//permet de mettre une couleur de fond								
	{
		SDL_Log("IMPOSSIBLE DE METTRE EN NOIR FOND ECRAN : %s",SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_RenderClear(getRenderer());																	//applique cette couleur, nettoie l'écran 

	if(isActiveMainMenu())
	{
		drawMainMenu();
	}
	if(isActiveOption())
	{
		drawOption();
	}
	if(isActiveGame())
	{
		drawMap();
		drawRessourceTEAM1();
		drawGameGui();
	}
	
	SDL_RenderPresent(getRenderer());																//affichage de tout les renderCopy

	SDL_Delay(1);																					//soulage le processeur												
}

void drawLine(int *x1, int *y1, int *x2, int *y2, SDL_Color *couleur)
{
	setRenderColor(couleur);																		//applique la couleur sur la ligne

	if(SDL_RenderDrawLine(getRenderer(), *x1, *y1, *x2, *y2) != 0)									//dessine la ligne
	{
		SDL_Log("IMPOSSIBLE DE DRAW LINE  :%s",SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void drawPoint(int *x, int *y, SDL_Color *couleur)
{
	setRenderColor(couleur);																		//applique la couleur sur le point

	if(SDL_RenderDrawPoint(getRenderer(), *x, *y) != 0)												//dessine le point
	{
		SDL_Log("IMPOSSIBLE DE DRAW POINT :%s",SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void drawRect(SDL_Rect *r, SDL_bool *fill, SDL_Color *couleur)
{
	setRenderColor(couleur);																		//applique la couleur sur le rectangle

	if(*fill)																						//si on remplis le rectangle
	{
		SDL_RenderFillRect(getRenderer(), r);														//on le dessine
	}
	else																							//sinon on dessine que son contours
	{
		SDL_RenderDrawRect(getRenderer(), r);														//on le dessine														
	}
}

void drawTexture(SDL_Texture *texture, SDL_Rect *dst, SDL_Rect *src)
{
	if(SDL_RenderCopy(getRenderer(), texture, src, dst) != 0)										//dessin d'une texture, sans rotation
	{
		printf("IMPOSSIBLE D'AFFICHER LA TEXTURE :%s",SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void drawTextureEx(SDL_Texture *texture, SDL_Rect *dst, SDL_Rect *src, SDL_Point *center, int angle, SDL_RendererFlip flip)
{
	if(SDL_RenderCopyEx(getRenderer(), texture, src, dst, angle, center, flip) != 0)				//dessin d'une texture, avec rotation
	{
		SDL_Log("IMPOSSIBLE D'AFFICHER LA TEXTUREEX :%s",SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void setRenderColor(SDL_Color *couleur)
{
	if(SDL_SetRenderDrawColor(getRenderer(),couleur->r, couleur->g, couleur->b, couleur->a) != 0)	//application de la couleur envoyer
	{
		SDL_Log("IMPOSSIBLE DE METTRE LA COULEUR :%s",SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

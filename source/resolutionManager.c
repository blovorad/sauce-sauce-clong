#include "prototype.h"

static SDL_Window *screen;
static SDL_Renderer *renderer;
static SDL_bool fullscreen;
static int screenWidth;
static int screenHeight;
static int currentResolution;
static float scaleX;
static float scaleY;

static int oldCurrentResolution;
static SDL_bool oldFullscreen;

/*
RESOLUTION
0 : 800x600
1 : 1024x768
2 : 1360x768
3 : 1600x900
4 : 1920x1080
*/

void initWindowAndRenderer(void)
{
	int trucFullscreen;

	FILE *fichier = fopen("source/fichier/config.txt", "r");
	if(fichier == NULL)
	{
		fprintf(stderr, "FILE OPEN: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	fscanf(fichier, "%d", &trucFullscreen);

	if(trucFullscreen == 0)
	{
		fullscreen = SDL_FALSE;
		oldFullscreen = SDL_FALSE;
	}
	else
	{
		fullscreen = SDL_TRUE;
		oldFullscreen = SDL_TRUE;
	}

	fseek(fichier, 5, SEEK_SET);

	fscanf(fichier, "%d", &currentResolution);
	oldCurrentResolution = currentResolution;

	if(getCurrentResolution() == 0)
	{
		screenWidth = 800;
		screenHeight = 600;
	}
	else if(getCurrentResolution() == 1)
	{
		screenWidth = 1024;
		screenHeight = 768;
	}
	else if(getCurrentResolution() == 2)
	{
		screenWidth = 1360;
		screenHeight = 768;
	}
	else if(getCurrentResolution() == 3)
	{
		screenWidth = 1600;
		screenHeight = 900;
	}
	else if(getCurrentResolution() == 4)
	{
		screenWidth = 1920;
		screenHeight = 1080;
	}

	if(fullscreen == SDL_FALSE)
	{
		screen = SDL_CreateWindow("SAUCE SAUCE CLONG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	}
	else
	{
		screen = SDL_CreateWindow("SAUCE SAUCE CLONG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_FULLSCREEN);
	}

	renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);

	if(screen == NULL || renderer == NULL)
	{
		SDL_Log("IMPOSSIBLE CREATION FENETRE OU RENDERER : %s",SDL_GetError());
		exit(EXIT_FAILURE);
	}

	setScale();

	fclose(fichier);
	fichier = NULL;
}

void setScale(void)
{
	scaleX = (float)screenWidth / (float)BASE_SCREENWIDTH;
	scaleY = (float)screenHeight / (float)BASE_SCREENHEIGHT;
}

void setResolution(void)
{
	currentResolution++;
	if(currentResolution > 4)
	{
		currentResolution = 0;
	}
}

void setFullscreen(SDL_bool active)
{
	fullscreen = active;
	changeBoutonFullscreen();
}

void resetResolution(int reset)
{
	currentResolution = reset;
}

void changeResolution(int w, int h)
{
	cleanOption();
	SDL_SetWindowSize(screen, w, h);

	screenWidth = w;
	screenHeight = h;

	if(fullscreen == SDL_TRUE)
	{
		if(SDL_SetWindowFullscreen(screen, SDL_WINDOW_FULLSCREEN) != 0)
		{
			SDL_Log("ECHEC FULLSCREEN :%s", SDL_GetError());
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if(SDL_SetWindowFullscreen(screen, 0) != 0)
		{
			SDL_Log("ECHEC FULLSCREEN :%s", SDL_GetError());
			exit(EXIT_FAILURE);
		}
	}
 
	setScale();

	SDL_SetWindowPosition(screen, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

	oldFullscreen = fullscreen;
	oldCurrentResolution = currentResolution;

	FILE *fichier = fopen("source/fichier/config.txt", "w");
	if(fichier == NULL)
	{
		fprintf(stderr, "FILE OPEN: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	if(fullscreen == SDL_FALSE)
	{
		fputs("0 ", fichier);
	}
	else if(fullscreen == SDL_TRUE)
	{
		fputs("1 ", fichier);
	}

	char fx[2];
	char musique[2];
	char espace[5] = " ";

	sprintf(fx, "%d", getVolumeFx());
	sprintf(musique, "%d", getVolumeMusic());

	fputs(musique, fichier);

	strcat(espace, fx);

	fputs(espace, fichier);

	if(currentResolution == 0)
	{
		fputs(" 0", fichier);
	}
	else if(currentResolution == 1)
	{
		fputs(" 1", fichier);
	}
	else if(currentResolution == 2)
	{	
		fputs(" 2", fichier);
	}
	else if(currentResolution == 3)
	{
		fputs(" 3", fichier);
	}
	else if(currentResolution == 4)
	{
		fputs(" 4", fichier);
	}

	fclose(fichier);
	fichier = NULL;

	initOption();
}
//FONCTION DE RECUPERATION

SDL_Renderer *getRenderer(void)
{
	return renderer;
}

SDL_Window *getWindow(void)
{
	return screen;
}

SDL_bool getFullscreen(void)
{
	return fullscreen;
}

SDL_bool getOldFullscreen(void)
{
	return oldFullscreen;
}

int getCurrentResolution(void)
{
	return currentResolution;
}

int getOldCurrentResolution(void)
{
	return oldCurrentResolution;
}

int getWidth(void)
{
	return screenWidth;
}

int getHeight(void)
{
	return screenHeight;
}

float getScaleX(void)
{
	return scaleX;
}

float getScaleY(void)
{
	return scaleY;
}

void cleanWindowAndRenderer(void)
{
	if(renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
	}
	if(screen != NULL)
	{
		SDL_DestroyWindow(screen);
		screen = NULL;
	}
}
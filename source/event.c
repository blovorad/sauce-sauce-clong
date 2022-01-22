#include "prototype.h"

static void (*liste_event[DIM_EVENT])(void);

void initEvent(void)
{
	liste_event[0] = &quitGame;
	liste_event[1] = &startGame;
	liste_event[2] = &goToOption;
	liste_event[3] = &goToMenu;
	liste_event[4] = &backToMenu;
	liste_event[5] = &addVolumeFx;
	liste_event[6] = &removeVolumeFx;
	liste_event[7] = &addVolumeMusique;
	liste_event[8] = &removeVolumeMusique;
	liste_event[9] = &goToConstruction;
	liste_event[10] = &returnToGame;
	liste_event[11] = &buyForge;
	liste_event[12] = &buyFerme;
	liste_event[13] = &goToOptionGame;
	liste_event[14] = &returnToGameplay;
	liste_event[15] = &applyChange;
	liste_event[16] = &setFullscreenOption;
	liste_event[17] = &setResolutionEvent;
}

void quitGame(void)
{
	playFx(1);
	FILE *fichier = fopen("source/fichier/config.txt", "w");
	if(fichier == NULL)
	{
		fprintf(stderr, "FILE OPEN: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	if(getFullscreen() == SDL_FALSE)
	{
		fputs("0 ", fichier);
	}
	else if(getFullscreen() == SDL_TRUE)
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

	if(getCurrentResolution() == 0)
	{
		fputs(" 0", fichier);
	}
	else if(getCurrentResolution() == 1)
	{
		fputs(" 1", fichier);
	}
	else if(getCurrentResolution() == 2)
	{	
		fputs(" 2", fichier);
	}
	else if(getCurrentResolution() == 3)
	{
		fputs(" 3", fichier);
	}
	else if(getCurrentResolution() == 4)
	{
		fputs(" 4", fichier);
	}

	fclose(fichier);
	fichier = NULL;

	setGo(SDL_FALSE);
}

void startGame(void)
{
	playFx(1);
	cleanMainMenu();
	initMap();
	startMusic(2, SDL_FALSE);
}

void addVolumeMusique(void)
{
	playFx(1);
	upVolumeMusic();
}

void removeVolumeMusique(void)
{
	playFx(1);
	downVolumeMusic();
}	

void addVolumeFx(void)
{
	playFx(1);
	upVolumeFx();
}

void removeVolumeFx(void)
{
	playFx(1);
	downVolumeFx();
}

void goToOption(void)
{
	playFx(1);
	cleanMainMenu();
	initOption();
}

void goToMenu(void)
{
	playFx(1);
	if(getOldFullscreen() != getFullscreen())
	{
		setFullscreen(getOldFullscreen());
	}
	if(getOldCurrentResolution() != getCurrentResolution())
	{
		resetResolution(getOldCurrentResolution());
	}

	cleanOption();
	initMainMenu();
}

void backToMenu(void)
{
	playFx(1);
	setPrintConstruction(SDL_FALSE);
	setPrintGameOption(SDL_FALSE);
	cleanMap();
	initMainMenu();
	startMusic(0, SDL_FALSE);
}

void goToConstruction(void)
{
	playFx(1);
	setPrintConstruction(SDL_TRUE);
	setSelection(-1);
}

void returnToGame(void)
{
	playFx(1);
	setPrintConstruction(SDL_FALSE);
}

void buyForge(void)
{
	playFx(1);
	if(getGoldTEAM1() >= 100)
	{
		changeGoldTEAM1(-100);
		setSelection(9);
		setPrintConstruction(SDL_FALSE);
	}
	else
	{

	}
}

void buyFerme(void)
{
	playFx(1);
	if(getGoldTEAM1() >= 250)
	{
		changeGoldTEAM1(-250);
		setSelection(10);
		setPrintConstruction(SDL_FALSE);
	}
	else
	{

	}
}

void goToOptionGame(void)
{
	playFx(1);
	setPrintGameOption(SDL_TRUE);
}

void returnToGameplay(void)
{
	playFx(1);
	setPrintGameOption(SDL_FALSE);
}

void applyChange(void)
{
	playFx(1);
	if(getCurrentResolution() == 0)
	{
		changeResolution(800, 600);
	}
	else if(getCurrentResolution() == 1)
	{
		changeResolution(1024, 768);
	}
	else if(getCurrentResolution() == 2)
	{
		changeResolution(1360, 768);
	}
	else if(getCurrentResolution() == 3)
	{
		changeResolution(1600, 900);
	}
	else if(getCurrentResolution() == 4)
	{
		changeResolution(1920, 1080);
	}
}

void setFullscreenOption(void)
{
	playFx(1);
	if(getFullscreen() == SDL_FALSE)
	{
		setFullscreen(SDL_TRUE);
	}
	else
	{
		setFullscreen(SDL_FALSE);
	}
}

void setResolutionEvent(void)
{
	playFx(1);
	setResolution();
	changeBoutonResolution();
}


void playEvent(int event)
{
	if(event > -1 && event < DIM_EVENT)
	{
		(*liste_event[event])();
	}
}
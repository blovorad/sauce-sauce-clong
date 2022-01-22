#include "prototype.h"

static GroupeGui menu;

void initOption(void)
{
	setPrintOption(SDL_TRUE);

	menu.liste_bouton = NULL;
	menu.liste_panel = NULL;
	menu.liste_texte = NULL;

	menu.nbTexte = 3;
	menu.nbBouton = 8;
	menu.nbPanel = 1;
	menu.nbBarre = 2;

	menu.visible = SDL_TRUE;

	menu.liste_bouton = malloc(sizeof(Bouton) * menu.nbBouton);
	menu.liste_panel = malloc(sizeof(Panel) * menu.nbPanel);
	menu.liste_texte = malloc(sizeof(Texte) * menu.nbTexte);
	menu.liste_barre = malloc(sizeof(Barre) * menu.nbBarre);

	if(menu.liste_bouton == NULL || menu.liste_panel == NULL || menu.liste_texte == NULL || menu.liste_barre == NULL)
	{
		fprintf(stderr, "malloc: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	menu.liste_bouton[0] = createBouton(300, 500, 200, 50, ORIGINAL, getNoir(255), "MENU PRINCIPAL", getNoir(255), getFont1(), SDL_FALSE, 3);
	menu.liste_bouton[1] = createBouton(150, 200, 100, 50, ORIGINAL, getGris(255), "MOINS", getNoir(255), getFont1(), SDL_FALSE, 8);
	menu.liste_bouton[2] = createBouton(550, 200, 100, 50, ORIGINAL, getGris(255), "PLUS", getNoir(255), getFont1(), SDL_FALSE, 7);
	menu.liste_bouton[3] = createBouton(150, 350, 100, 50, ORIGINAL, getGris(255), "MOINS", getNoir(255), getFont1(), SDL_FALSE, 6);
	menu.liste_bouton[4] = createBouton(550, 350, 100, 50, ORIGINAL, getGris(255), "PLUS", getNoir(255), getFont1(), SDL_FALSE, 5);
	menu.liste_bouton[5] = createBouton(300, 425, 200, 50, ORIGINAL, getGris(255), "APPLIQUER", getNoir(255), getFont1(), SDL_FALSE, 15);
	if(getFullscreen() == SDL_TRUE)
	{
		menu.liste_bouton[6] = createBouton(290, 70, 210, 50, ORIGINAL, getGris(255), "FULLSCREEN ON", getNoir(255), getFont1(), SDL_FALSE, 16);
	}
	else
	{
		menu.liste_bouton[6] = createBouton(290, 70, 210, 50, ORIGINAL, getGris(255), "FULLSCREEN OFF", getNoir(255), getFont1(), SDL_FALSE, 16);
	}
	if(getCurrentResolution() == 0)
	{
		menu.liste_bouton[7] = createBouton(300, 10, 200, 50, ORIGINAL, getGris(255), "800x600", getNoir(255), getFont1(), SDL_FALSE, 17);
	}
	else if(getCurrentResolution() == 1)
	{
		menu.liste_bouton[7] = createBouton(300, 10, 200, 50, ORIGINAL, getGris(255), "1024x768", getNoir(255), getFont1(), SDL_FALSE, 17);
	}
	else if(getCurrentResolution() == 2)
	{
		menu.liste_bouton[7] = createBouton(300, 10, 200, 50, ORIGINAL, getGris(255), "1360x768", getNoir(255), getFont1(), SDL_FALSE, 17);
	}
	else if(getCurrentResolution() == 3)
	{
		menu.liste_bouton[7] = createBouton(300, 10, 200, 50, ORIGINAL, getGris(255), "1600x900", getNoir(255), getFont1(), SDL_FALSE, 17);
	}
	else if(getCurrentResolution() == 4)
	{
		menu.liste_bouton[7] = createBouton(300, 10, 200, 50, ORIGINAL, getGris(255), "1920x1080", getNoir(255), getFont1(), SDL_FALSE, 17);
	}

	/*
RESOLUTION
0 : 800x600
1 : 1024x768
2 : 1360x768
3 : 1600x900
4 : 1920x1080
*/

	menu.liste_panel[0] = createPanel(0, 0, 800, 600, 11, getNoir(255), SDL_FALSE);

	menu.liste_texte[0] = createTexte(350, 550, 100, 50, "JEU CREER PAR BLOVORAD", getBlanc(255), getFont1());
	menu.liste_texte[1] = createTexte(300, 150, 200, 50, "VOLUME MUSIQUES", getBlanc(255), getFont1());
	menu.liste_texte[2] = createTexte(300, 300, 200, 50, "VOLUME EFFETS", getBlanc(255), getFont1());

	menu.liste_barre[0] = createBarre(275 * getScaleX(), 200 * getScaleY(), 250 * getScaleX(), 50 * getScaleY(), getBlanc(255));
	menu.liste_barre[1] = createBarre(275 * getScaleX(), 350 * getScaleY(), 250 * getScaleX(), 50 * getScaleY(), getBlanc(255));
}	
//int x, int y, int w, int h, SDL_Color color
void updateOption(void)
{
	menu.liste_barre[0].sprite.dimension.w = (getVolumeMusic() * menu.liste_barre[0].tailleReel.w) / 10;
	menu.liste_barre[1].sprite.dimension.w = (getVolumeFx() * menu.liste_barre[1].tailleReel.w) / 10;

	updateGroupeGui(&menu);
}

void drawOption(void)
{
	drawGroupeGui(&menu);
}

void cleanOption(void)
{
	SDL_Log("CLEAN OPTION EN COURS\n");
	setPrintOption(SDL_FALSE);

	cleanGroupeGui(&menu);
	SDL_Log("CLEAN OPTION TERMINER\n");
}

void changeBoutonFullscreen(void)
{
	if(menu.liste_bouton[6].texte.sprite.texture != NULL)
	{
		SDL_DestroyTexture(menu.liste_bouton[6].texte.sprite.texture);
		menu.liste_bouton[6].texte.sprite.texture = NULL;
	}

	if(getFullscreen() == SDL_TRUE)
	{
		menu.liste_bouton[6] = createBouton(290, 70, 210, 50, ORIGINAL, getGris(255), "FULLSCREEN ON", getNoir(255), getFont1(), SDL_FALSE, 16);
	}
	else
	{
		menu.liste_bouton[6] = createBouton(290, 70, 210, 50, ORIGINAL, getGris(255), "FULLSCREEN OFF", getNoir(255), getFont1(), SDL_FALSE, 16);
	}
}

void changeBoutonResolution(void)
{
	if(menu.liste_bouton[7].texte.sprite.texture != NULL)
	{
		SDL_DestroyTexture(menu.liste_bouton[7].texte.sprite.texture);
		menu.liste_bouton[7].texte.sprite.texture = NULL;
	}

	if(getCurrentResolution() == 0)
	{
		menu.liste_bouton[7] = createBouton(300, 10, 200, 50, ORIGINAL, getGris(255), "800x600", getNoir(255), getFont1(), SDL_FALSE, 17);
	}
	else if(getCurrentResolution() == 1)
	{
		menu.liste_bouton[7] = createBouton(300, 10, 200, 50, ORIGINAL, getGris(255), "1024x768", getNoir(255), getFont1(), SDL_FALSE, 17);
	}
	else if(getCurrentResolution() == 2)
	{
		menu.liste_bouton[7] = createBouton(300, 10, 200, 50, ORIGINAL, getGris(255), "1360x768", getNoir(255), getFont1(), SDL_FALSE, 17);
	}
	else if(getCurrentResolution() == 3)
	{
		menu.liste_bouton[7] = createBouton(300, 10, 200, 50, ORIGINAL, getGris(255), "1600x900", getNoir(255), getFont1(), SDL_FALSE, 17);
	}
	else if(getCurrentResolution() == 4)
	{
		menu.liste_bouton[7] = createBouton(300, 10, 200, 50, ORIGINAL, getGris(255), "1920x1080", getNoir(255), getFont1(), SDL_FALSE, 17);
	}
}
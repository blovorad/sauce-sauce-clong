#include "prototype.h"

static GroupeGui menu;

void initMainMenu(void)
{
	setPrintMainMenu(SDL_TRUE);

	menu.liste_bouton = NULL;
	menu.liste_panel = NULL;
	menu.liste_texte = NULL;
	menu.liste_barre = NULL;

	menu.nbTexte = 2;
	menu.nbBouton = 3;
	menu.nbPanel = 2;
	menu.nbBarre = 0;

	menu.visible = SDL_TRUE;

	menu.liste_bouton = malloc(sizeof(Bouton) * menu.nbBouton);
	menu.liste_panel = malloc(sizeof(Panel) * menu.nbPanel);
	menu.liste_texte = malloc(sizeof(Texte) * menu.nbTexte);

	if(menu.liste_bouton == NULL || menu.liste_panel == NULL || menu.liste_texte == NULL)
	{
		fprintf(stderr, "malloc: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	menu.liste_bouton[0] = createBouton(300, 150, 200, 50, ORIGINAL, getNoir(255), "COMMENCEZ", getNoir(255), getFont1(), SDL_FALSE, 1);
	menu.liste_bouton[1] = createBouton(300, 250, 200, 50, ORIGINAL, getNoir(255), "OPTION", getNoir(255), getFont1(), SDL_FALSE, 2);
	menu.liste_bouton[2] = createBouton(300, 350, 200, 50, ORIGINAL, getNoir(255), "QUITTER", getNoir(255), getFont1(), SDL_FALSE, 0);

	menu.liste_panel[0] = createPanel(0, 0, 800, 600, 11, getNoir(255), SDL_FALSE);
	menu.liste_panel[1] = createPanel(180, 50, 440, 50, ORIGINAL, getNoir(255), SDL_FALSE);

	menu.liste_texte[0] = createTexte(350, 550, 100, 50, "JEU CREER PAR BLOVORAD", getBlanc(255), getFont1());
	menu.liste_texte[1] = createTexte(300, 50, 200, 50, "BIENVENU DANS SAUCE SAUCE CLONG", getVertFoncer(255), getFont1());
}

void updateMainMenu(void)
{
	updateGroupeGui(&menu);
}

void drawMainMenu(void)
{
	drawGroupeGui(&menu);
}

void cleanMainMenu(void)
{	
	SDL_Log("CLEAN MAIN MENU EN COURS\n");
	setPrintMainMenu(SDL_FALSE);

	cleanGroupeGui(&menu);
	SDL_Log("CLEAN MAIN MENU TERMINER\n");
}
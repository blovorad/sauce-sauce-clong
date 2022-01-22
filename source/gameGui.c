#include "prototype.h"

static HumanGui element[3];
static int nbElement;
static int selection;

static GroupeGui other;
static GroupeGui constructionGui;
static GroupeGui menu;
static GroupeGui endMenu;

static Panel buildingPanel;

void initGameGui(void)
{
	selection = -1;
	nbElement = 3;

	constructionGui.liste_bouton = NULL;
	constructionGui.liste_texte = NULL;
	constructionGui.liste_panel = NULL;
	constructionGui.liste_barre = NULL;

	menu.liste_bouton = NULL;
	menu.liste_texte = NULL;
	menu.liste_panel = NULL;
	menu.liste_barre = NULL;

	other.liste_bouton = NULL;
	other.liste_texte = NULL;
	other.liste_panel = NULL;
	other.liste_barre = NULL;

	menu.nbTexte = 2;
	menu.nbBouton = 6;
	menu.nbPanel = 1;
	menu.nbBarre = 2;

	menu.liste_panel = malloc(sizeof(Panel) * menu.nbPanel);
	menu.liste_bouton = malloc(sizeof(Bouton) * menu.nbBouton);
	menu.liste_barre = malloc(sizeof(Barre) * menu.nbBarre);
	menu.liste_texte = malloc(sizeof(Texte) * menu.nbTexte);
	if(menu.liste_panel == NULL || menu.liste_bouton == NULL || menu.liste_barre == NULL || menu.liste_texte == NULL)
	{
		fprintf(stderr, "malloc: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	menu.liste_panel[0] = createPanel(140, 50 + 10, 520, 400, 8, getGris(255), SDL_TRUE);

	menu.liste_texte[0] = createTexte(300, 150, 200, 50, "VOLUME MUSIQUES", getBlanc(255), getFont1());
	menu.liste_texte[1] = createTexte(300, 300, 200, 50, "VOLUME EFFETS", getBlanc(255), getFont1());

	menu.liste_bouton[0] = createBouton(325, 415, 150, 25, ORIGINAL, getGris(255), "RETOUR", getNoir(255), getFont1(), SDL_FALSE, 14);
	menu.liste_bouton[1] = createBouton(275, 80, 250, 25, ORIGINAL, getGris(255), "MENU PRINCIPAL", getNoir(255), getFont1(), SDL_FALSE, 4);
	menu.liste_bouton[2] = createBouton(150, 200, 100, 50, ORIGINAL, getGris(255), "MOINS", getNoir(255), getFont1(), SDL_FALSE, 8);
	menu.liste_bouton[3] = createBouton(550, 200, 100, 50, ORIGINAL, getGris(255), "PLUS", getNoir(255), getFont1(), SDL_FALSE, 7);
	menu.liste_bouton[4] = createBouton(150, 350, 100, 50, ORIGINAL, getGris(255), "MOINS", getNoir(255), getFont1(), SDL_FALSE, 6);
	menu.liste_bouton[5] = createBouton(550, 350, 100, 50, ORIGINAL, getGris(255), "PLUS", getNoir(255), getFont1(), SDL_FALSE, 5);

	menu.liste_barre[0] = createBarre(275 * getScaleX(), 200 * getScaleY(), 250 * getScaleX(), 50 * getScaleY(), getBlanc(255));
	menu.liste_barre[1] = createBarre(275 * getScaleX(), 350 * getScaleY(), 250 * getScaleX(), 50 * getScaleY(), getBlanc(255));
	//int x, int y, int w, int h, SDL_Color panelColor, char *ptexte, SDL_Color texteColor, TTF_Font *font, SDL_bool pFill, int event
	//menu.liste_bouton[0] = createBouton(20, -10, 64, 64, 12, getVert(255), " ", getRouge(255), getFont1(), SDL_FALSE, -1);
	menu.visible = SDL_TRUE;

	SDL_Rect r20 = {0, 0, 128, 128};

	buildingPanel.dimension = r20;
	buildingPanel.texture = 0;
	buildingPanel.fill = SDL_FALSE;
	buildingPanel.couleur = getNoir(255);

	constructionGui.nbBouton = 3;
	constructionGui.nbPanel = 3;
	constructionGui.nbTexte = 6;
	constructionGui.nbBarre = 0;

	constructionGui.visible = SDL_TRUE;

	constructionGui.liste_bouton = malloc(sizeof(Bouton) * constructionGui.nbBouton);
	constructionGui.liste_panel = malloc(sizeof(Panel) * constructionGui.nbPanel);
	constructionGui.liste_texte = malloc(sizeof(Texte) * constructionGui.nbTexte);
	if(constructionGui.liste_bouton == NULL || constructionGui.liste_panel == NULL || constructionGui.liste_texte == NULL)
	{
		fprintf(stderr, "malloc: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	constructionGui.liste_panel[0] = createPanel(200, 50 + 10, 400, 400, 11, getGris(255), SDL_TRUE);
	constructionGui.liste_panel[1] = createPanel(250, 50 + 50, 128, 128, 9, getGris(255), SDL_TRUE);
	constructionGui.liste_panel[2] = createPanel(250, 250 + 20, 128, 128, 10, getGris(255), SDL_TRUE);

	constructionGui.liste_bouton[0] = createBouton(325, 415, 150, 25, ORIGINAL, getGris(255), "RETOUR", getNoir(255), getFont1(), SDL_FALSE, 10);
	constructionGui.liste_bouton[1] = createBouton(400, 50 + 50, 100, 25, ORIGINAL, getGris(255), "FORGE", getNoir(255), getFont1(), SDL_FALSE, 11);
	constructionGui.liste_bouton[2] = createBouton(400, 250 + 20, 100, 25, ORIGINAL, getGris(255), "FERME", getNoir(255), getFont1(), SDL_FALSE, 12);

	constructionGui.liste_texte[0] = createTexte(400, 70 + 50, 100, 50, "GENERE DE", getBlanc(255), getFont1());
	constructionGui.liste_texte[5] = createTexte(405, 100 + 50, 100, 50, "L'OR (+50)", getBlanc(255), getFont1());
	constructionGui.liste_texte[3] = createTexte(400, 130 + 50, 100, 50, "COUT: 100", getBlanc(255), getFont1());
	constructionGui.liste_texte[1] = createTexte(400, 270 + 20, 100, 50, "GENERE DU", getBlanc(255), getFont1());
	constructionGui.liste_texte[2] = createTexte(410, 300 + 20, 100, 50, "MANGER (+20)", getBlanc(255), getFont1());
	constructionGui.liste_texte[4] = createTexte(400, 330 + 20, 100, 50, "COUT: 250", getBlanc(255), getFont1());

	other.nbBouton = 2;
	other.nbPanel = 0;
	other.nbTexte = 0;
	other.nbBarre = 0;

	other.visible = SDL_TRUE;

	other.liste_bouton = malloc(sizeof(Bouton) * other.nbBouton);
	if(other.liste_bouton == NULL)
	{
		fprintf(stderr, "malloc: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	other.liste_bouton[0] = createBouton(300, 5, 200, 25, ORIGINAL, getGris(255), "CONSTRUCTION", getNoir(255), getFont1(), SDL_FALSE, 9);
	other.liste_bouton[1] = createBouton(700, -2, 44, 44, 12, getVert(255), " ", getRouge(255), getFont1(), SDL_FALSE, 13);

	//ELEMENT WARRIOR
	element[0].time.currentTime = 0; 
	element[0].time.previousTime = SDL_GetTicks();
	element[0].time.ms = 200;

	element[0].currentAnimation = 0;

	element[0].texture = WARRIOR;

	for(int i = 0; i < 4; i++)
	{
		element[0].animation[0][i].x = i * 512;
		element[0].animation[0][i].y = 0;
		element[0].animation[0][i].w = 512;
		element[0].animation[0][i].h = 512;
	}

	SDL_Rect r1 = {235, 530, 64, 64};

	element[0].dimension.x = r1.x * getScaleX();
	element[0].dimension.y = r1.y * getScaleY();
	element[0].dimension.w = r1.w * getScaleX();
	element[0].dimension.h = r1.h * getScaleY();

	element[0].selfCollide.couleur = getVert(255);
	element[0].selfCollide.fill = SDL_FALSE;
	element[0].selfCollide.dimension.x = element[0].dimension.x + 17 * getScaleX();
	element[0].selfCollide.dimension.y = element[0].dimension.y + 5 * getScaleY();
	element[0].selfCollide.dimension.w = element[0].dimension.w - 28 * getScaleX();
	element[0].selfCollide.dimension.h = element[0].dimension.h - 14 * getScaleY();

	element[0].id = WARRIOR;
	element[0].selected = SDL_FALSE;

	element[0].panelSelect = createPanel(r1.x, r1.y, r1.w, r1.h , SELECT, getBlanc(255), SDL_FALSE);
	element[0].panelOriginal = createPanel(r1.x, r1.y, r1.w, r1.h, ORIGINAL, getBlanc(255), SDL_FALSE);

	//ELEMENT KNIGHT
	element[1].time.currentTime = 0; 
	element[1].time.previousTime = SDL_GetTicks();
	element[1].time.ms = 200;

	element[1].currentAnimation = 0;

	element[1].texture = KNIGHT;

	for(int i = 0; i < 4; i++)
	{
		element[1].animation[0][i].x = i * 512;
		element[1].animation[0][i].y = 0;
		element[1].animation[0][i].w = 512;
		element[1].animation[0][i].h = 512;
	}

	SDL_Rect r2 = {r1.x + r1.w * 2, 530, 64, 64};

	element[1].dimension.x = r2.x * getScaleX();
	element[1].dimension.y = r2.y * getScaleY();
	element[1].dimension.w = r2.w * getScaleX();
	element[1].dimension.h = r2.h * getScaleY();

	element[1].selfCollide.couleur = getVert(255);
	element[1].selfCollide.fill = SDL_FALSE;
	element[1].selfCollide.dimension.x = element[1].dimension.x + 17 * getScaleX();
	element[1].selfCollide.dimension.y = element[1].dimension.y + 5 * getScaleY();
	element[1].selfCollide.dimension.w = element[1].dimension.w - 28 * getScaleX();
	element[1].selfCollide.dimension.h = element[1].dimension.h - 14 * getScaleY();

	element[1].id = KNIGHT;
	element[1].selected = SDL_FALSE;

	element[1].panelSelect = createPanel(r2.x, r2.y, r2.w, r2.h, SELECT, getBlanc(255), SDL_FALSE);
	element[1].panelOriginal = createPanel(r2.x, r2.y, r2.w, r2.h, ORIGINAL, getBlanc(255), SDL_FALSE);

	//ELEMENT ARCHER
	element[2].time.currentTime = 0; 
	element[2].time.previousTime = SDL_GetTicks();
	element[2].time.ms = 200;

	element[2].currentAnimation = 0;

	element[2].texture = ARCHER;

	for(int i = 0; i < 4; i++)
	{
		element[2].animation[0][i].x = i * 512;
		element[2].animation[0][i].y = 0;
		element[2].animation[0][i].w = 512;
		element[2].animation[0][i].h = 512;
	}

	SDL_Rect r3 = {r2.x + r2.w * 2, 530, 64, 64};

	element[2].dimension.x = r3.x * getScaleX();
	element[2].dimension.y = r3.y * getScaleY();
	element[2].dimension.w = r3.w * getScaleX();
	element[2].dimension.h = r3.h * getScaleY();

	element[2].selfCollide.couleur = getVert(255);
	element[2].selfCollide.fill = SDL_FALSE;
	element[2].selfCollide.dimension.x = element[2].dimension.x + 17 * getScaleX();
	element[2].selfCollide.dimension.y = element[2].dimension.y + 5 * getScaleY();
	element[2].selfCollide.dimension.w = element[2].dimension.w - 28 * getScaleX();
	element[2].selfCollide.dimension.h = element[2].dimension.h - 14 * getScaleY();

	element[2].id = ARCHER;
	element[2].selected = SDL_FALSE;

	element[2].panelSelect = createPanel(r3.x, r3.y, r3.w, r3.h, SELECT, getBlanc(255), SDL_FALSE);
	element[2].panelOriginal = createPanel(r3.x, r3.y, r3.w, r3.h, ORIGINAL, getBlanc(255), SDL_FALSE);
}

void updateGameGui(void)
{
	for(int i = 0; i < nbElement; i++)
	{
		element[i].time.currentTime = SDL_GetTicks();

		if(element[i].time.currentTime >= element[i].time.previousTime + element[i].time.ms)
		{
			element[i].currentAnimation++;
			if(element[i].currentAnimation >= 4)
			{
				element[i].currentAnimation = 0;
			}

			element[i].time.previousTime = element[i].time.currentTime;
		}
		if(isActiveEndGame() == SDL_FALSE)
		{
			int mX = getMouseX();
			int mY = getMouseY();
			if(mX > element[i].selfCollide.dimension.x && mX < element[i].selfCollide.dimension.x + element[i].selfCollide.dimension.w &&
				mY > element[i].selfCollide.dimension.y && mY < element[i].selfCollide.dimension.y + element[i].selfCollide.dimension.h && 
				getStateOfLeftButton() && getStateOfOldLeftButton() == SDL_FALSE)
			{
				if(buildingPanel.texture == 9)
				{
					changeGoldTEAM1(100);
				}
				else if(buildingPanel.texture == 10)
				{
					changeGoldTEAM1(250);
				}
				buildingPanel.texture = 0;
				selection = element[i].id;
				element[i].selected = SDL_TRUE;
				element[i].selfCollide.couleur = getBleu(255);
			}

			if(getStateOfRightButton())
			{
				if(buildingPanel.texture == 9)
				{
					changeGoldTEAM1(100);
				}
				else if(buildingPanel.texture == 10)
				{
					changeGoldTEAM1(250);
				}
				buildingPanel.texture = 0;
				selection = -1;
				element[i].selfCollide.couleur = getVert(255);
			}

			if(element[i].selected && selection != element[i].id)
			{
				element[i].selected = SDL_FALSE;
			}
		}
	}

	if(isActiveEndGame() == SDL_FALSE)
	{
		updateGroupeGui(&other);
		if(isActiveConstruction() == SDL_TRUE)
		{
			setSelection(-1);
			updateGroupeGui(&constructionGui);
		}
		if(isActiveGameOption() == SDL_TRUE)
		{
			setSelection(-1);
			menu.liste_barre[0].sprite.dimension.w = (getVolumeMusic() * menu.liste_barre[0].tailleReel.w) / 10;
			menu.liste_barre[1].sprite.dimension.w = (getVolumeFx() * menu.liste_barre[1].tailleReel.w) / 10;
			updateGroupeGui(&menu);
		}

		if(getSelection() == 9 || getSelection() == 10)
		{
			buildingPanel.texture = getSelection();
			buildingPanel.dimension.x = getMouseX() - buildingPanel.dimension.w / 2;
			buildingPanel.dimension.y = getMouseY() - buildingPanel.dimension.h / 2;
		}
	}
	else 
	{
		updateGroupeGui(&endMenu);
	}
}

void drawGameGui(void)
{
	for(int i = 0; i < nbElement; i++)
	{
		if(element[i].selected)
		{
			drawTexture(getTexture(element[i].panelSelect.texture), &element[i].panelSelect.dimension, NULL);
		}
		else
		{
			drawTexture(getTexture(element[i].panelOriginal.texture), &element[i].panelOriginal.dimension, NULL);
		}
		drawTexture(getTexture(element[i].texture), &element[i].dimension, &element[i].animation[0][element[i].currentAnimation]);
	}
	drawGroupeGui(&other);
	if(isActiveConstruction() == SDL_TRUE)
	{
		drawGroupeGui(&constructionGui);
	}
	if(isActiveGameOption() == SDL_TRUE)
	{
		drawGroupeGui(&menu);
	}
	if(isActiveEndGame() == SDL_TRUE)
	{
		drawGroupeGui(&endMenu);
	}

	if(buildingPanel.texture == 9 || buildingPanel.texture == 10)
	{
		drawPanel(&buildingPanel);
	}
}

void cleanGameGui(void)
{
	SDL_Log("CLEAN GAME GUI EN COURS\n");
	cleanGroupeGui(&constructionGui);
	cleanGroupeGui(&other);
	cleanGroupeGui(&menu);
	cleanGroupeGui(&endMenu);
	SDL_Log("CLEAN GAME GUI TERMINER\n");
}

void resetBuildingPanel(void)
{
	buildingPanel.texture = 0;
}

void initEndMenu(SDL_bool victory)
{
	endMenu.liste_bouton = NULL;
	endMenu.liste_texte = NULL;
	endMenu.liste_panel = NULL;
	endMenu.liste_barre = NULL;

	endMenu.nbTexte = 2;
	endMenu.nbBouton = 1;
	endMenu.nbPanel = 1;
	endMenu.nbBarre = 0;

	endMenu.liste_bouton = malloc(sizeof(Bouton) * endMenu.nbBouton);
	endMenu.liste_panel = malloc(sizeof(Panel) * endMenu.nbPanel);
	endMenu.liste_texte = malloc(sizeof(Texte) * endMenu.nbTexte);
	if(endMenu.liste_bouton == NULL || endMenu.liste_panel == NULL)
	{
		fprintf(stderr, "malloc: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	endMenu.liste_panel[0] = createPanel(200, 50, 400, 200, 8, getGris(255), SDL_TRUE);

	endMenu.liste_texte[0] = createTexte(350, 70, 100, 50, "MERCI D'AVOIR JOUER A LA DEMO", getBlanc(255), getFont1());
	if(victory)
	{
		endMenu.liste_texte[1] = createTexte(350, 130, 100, 50, "FELICITATION VOUS AVEZ GAGNER", getBlanc(255), getFont1());
	}
	else
	{
		endMenu.liste_texte[1] = createTexte(350, 130, 100, 50, "DOMMAGE VOUS AVEZ PERDU", getBlanc(255), getFont1());
	}

	endMenu.liste_bouton[0] = createBouton(325, 200, 150, 25, ORIGINAL, getGris(255), "CONTINUEZ", getNoir(255), getFont1(), SDL_FALSE, 4);
}

void setSelection(int active)
{
	selection = active;
}

int getSelection(void)
{
	return selection;
}
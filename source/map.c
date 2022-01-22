#include "prototype.h"

static Map map;
static int elementSizeX;
static int elementSizeY;
static Background lineBackground;
static Background ennemyBackground;
static Background playerBackground;
static Background upBackground;
static Background downBackground;

static void removeElementInLine(void);

void initMap(void)
{
	setPrintGame(SDL_TRUE);
	initGameGui();
	initRessourceTEAM1();
	initRessourceTEAM2();

	elementSizeX = 64 * getScaleX();
	elementSizeY = 64 * getScaleY();

	SDL_Rect r10 = {150 * getScaleX(), 50 * getScaleY(), 500 * getScaleX(), 463 * getScaleY()};
	SDL_Rect r11 = {650 * getScaleX(), 50 * getScaleY(), 150 * getScaleX(), 550 * getScaleY()};
	SDL_Rect r12 = {0, 50 * getScaleY(), 150 * getScaleX(), 550 * getScaleY()};
	SDL_Rect r13 = {0, 0, 800 * getScaleX(), 50 * getScaleY()};
	SDL_Rect r14 = {150 * getScaleX(), 512 * getScaleY(), 500 * getScaleX(), 88 * getScaleY()};

	downBackground.couleur = getMarron(255);
	downBackground.dimension = r14;
	downBackground.texture = 8;

	ennemyBackground.couleur = getNoir(255);
	ennemyBackground.dimension = r11;
	ennemyBackground.texture = 7;

	playerBackground.couleur = getNoir(255);
	playerBackground.dimension = r12;
	playerBackground.texture = 7;

	lineBackground.couleur = getMarron(255);
	lineBackground.dimension = r10;
	lineBackground.texture = 6;

	upBackground.couleur = getMarron(255);
	upBackground.dimension = r13;
	upBackground.texture = 11;

	map.line[0].dimension.y = 50 * getScaleY();
	map.line[0].ennemyBuilding.panel.dimension.x = 660 * getScaleX();
	map.line[0].ennemyBuilding.panel.dimension.y = map.line[0].dimension.y;
	map.line[0].ennemyBuilding.panel.dimension.w = 100 * getScaleX();
	map.line[0].ennemyBuilding.panel.dimension.h = elementSizeY;

	map.line[0].playerBuilding.panel.dimension.x = 40 * getScaleX();
	map.line[0].playerBuilding.panel.dimension.y = map.line[0].dimension.y;
	map.line[0].playerBuilding.panel.dimension.w = 100 * getScaleX();
	map.line[0].playerBuilding.panel.dimension.h = elementSizeY;

	map.line[1].dimension.y = 150 * getScaleY();
	map.line[1].ennemyBuilding.panel.dimension.x = 660 * getScaleX();
	map.line[1].ennemyBuilding.panel.dimension.y = map.line[1].dimension.y;
	map.line[1].ennemyBuilding.panel.dimension.w = 100 * getScaleX();
	map.line[1].ennemyBuilding.panel.dimension.h = elementSizeY;

	map.line[1].playerBuilding.panel.dimension.x = 40 * getScaleX();
	map.line[1].playerBuilding.panel.dimension.y = map.line[1].dimension.y;
	map.line[1].playerBuilding.panel.dimension.w = 100 * getScaleX();
	map.line[1].playerBuilding.panel.dimension.h = elementSizeY;

	map.line[2].dimension.y = 250 * getScaleY();
	map.line[2].ennemyBuilding.panel.dimension.x = 660 * getScaleX();
	map.line[2].ennemyBuilding.panel.dimension.y = map.line[2].dimension.y;
	map.line[2].ennemyBuilding.panel.dimension.w = 100 * getScaleX();
	map.line[2].ennemyBuilding.panel.dimension.h = elementSizeY;

	map.line[2].playerBuilding.panel.dimension.x = 40 * getScaleX();
	map.line[2].playerBuilding.panel.dimension.y = map.line[2].dimension.y;
	map.line[2].playerBuilding.panel.dimension.w = 100 * getScaleX();
	map.line[2].playerBuilding.panel.dimension.h = elementSizeX;

	map.line[3].dimension.y = 350 * getScaleY();
	map.line[3].ennemyBuilding.panel.dimension.x = 660 * getScaleX();
	map.line[3].ennemyBuilding.panel.dimension.y = map.line[3].dimension.y;
	map.line[3].ennemyBuilding.panel.dimension.w = 100 * getScaleX();
	map.line[3].ennemyBuilding.panel.dimension.h = elementSizeY;

	map.line[3].playerBuilding.panel.dimension.x = 40 * getScaleX();
	map.line[3].playerBuilding.panel.dimension.y = map.line[3].dimension.y;
	map.line[3].playerBuilding.panel.dimension.w = 100 * getScaleX();
	map.line[3].playerBuilding.panel.dimension.h = elementSizeX;

	map.line[4].dimension.y = 450 * getScaleY();
	map.line[4].ennemyBuilding.panel.dimension.x = 660 * getScaleX();
	map.line[4].ennemyBuilding.panel.dimension.y = map.line[4].dimension.y;
	map.line[4].ennemyBuilding.panel.dimension.w = 100 * getScaleX();
	map.line[4].ennemyBuilding.panel.dimension.h = elementSizeY;

	map.line[4].playerBuilding.panel.dimension.x = 40 * getScaleX();
	map.line[4].playerBuilding.panel.dimension.y = map.line[4].dimension.y;
	map.line[4].playerBuilding.panel.dimension.w = 100 * getScaleX();
	map.line[4].playerBuilding.panel.dimension.h = elementSizeY;

	for(int i = 0; i < 5; i++)
	{
		map.line[i].dimension.x = 150 * getScaleX();
		map.line[i].dimension.w = 500 * getScaleX();
		map.line[i].dimension.h = elementSizeY;

		map.line[i].texture = 6;
		map.line[i].fill = SDL_TRUE;
		map.line[i].couleur = getMarron(255);

		map.line[i].nbElementListe1 = 0;
		map.line[i].nbElementListe2 = 0;

		map.line[i].liste1Timer.ms = 2000;
		map.line[i].liste1Timer.currentTime = 0;
		map.line[i].liste1Timer.previousTime = 0;

		map.line[i].liste2Timer.ms = 2000;
		map.line[i].liste2Timer.currentTime = 0;
		map.line[i].liste2Timer.previousTime = SDL_GetTicks();

		SDL_Rect r1 = map.line[i].dimension;
		SDL_Rect r2 = map.line[i].dimension;

		map.line[i].canPlace = SDL_TRUE;
		map.line[i].canPlaceFill = SDL_FALSE;
		map.line[i].canPlaceCouleur1 = getRouge(255);
		map.line[i].canPlaceCouleur2 = getMarron(255);

		r1.x -= 17 * getScaleX();
		r1.w = elementSizeX;
		r1.h = elementSizeY;

		r2.x += map.line[i].dimension.w * getScaleX() - elementSizeX;
		r2.w = elementSizeX;
		r2.h = elementSizeY;

		map.line[i].ennemyBuilding.panel.fill = SDL_FALSE;
		map.line[i].ennemyBuilding.panel.couleur = getBlanc(255);
		map.line[i].ennemyBuilding.vie = 10;
		map.line[i].ennemyBuilding.maxVie = 10;
		map.line[i].ennemyBuilding.panel.texture = -1;
		map.line[i].ennemyBuilding.selfCollide.dimension = map.line[i].ennemyBuilding.panel.dimension;
		map.line[i].ennemyBuilding.selfCollide.fill = SDL_FALSE;
		map.line[i].ennemyBuilding.selfCollide.couleur = getVert(255);

		map.line[i].ennemyBuilding.maxWidth = map.line[i].ennemyBuilding.selfCollide.dimension.w;
		map.line[i].ennemyBuilding.lifeRemaning = createBarre(map.line[i].ennemyBuilding.selfCollide.dimension.x, map.line[i].ennemyBuilding.selfCollide.dimension.y - 10, map.line[i].ennemyBuilding.selfCollide.dimension.w, 8, getVert(255));
		map.line[i].ennemyBuilding.lifeRemove = createBarre(map.line[i].ennemyBuilding.selfCollide.dimension.x, map.line[i].ennemyBuilding.selfCollide.dimension.y - 10, map.line[i].ennemyBuilding.selfCollide.dimension.w ,8, getRouge(255));

		map.line[i].playerBuilding.panel.fill = SDL_FALSE;
		map.line[i].playerBuilding.panel.couleur = getBlanc(255);
		map.line[i].playerBuilding.vie = 10;
		map.line[i].playerBuilding.maxVie = 10;
		map.line[i].playerBuilding.panel.texture = -1;
		map.line[i].playerBuilding.selfCollide.dimension = map.line[i].playerBuilding.panel.dimension;
		map.line[i].playerBuilding.selfCollide.fill = SDL_FALSE;
		map.line[i].playerBuilding.selfCollide.couleur = getVert(255);

		map.line[i].playerBuilding.maxWidth = map.line[i].playerBuilding.selfCollide.dimension.w;
		map.line[i].playerBuilding.lifeRemaning = createBarre(map.line[i].playerBuilding.selfCollide.dimension.x, map.line[i].playerBuilding.selfCollide.dimension.y - 10, map.line[i].playerBuilding.selfCollide.dimension.w, 8, getVert(255));
		map.line[i].playerBuilding.lifeRemove = createBarre(map.line[i].playerBuilding.selfCollide.dimension.x, map.line[i].playerBuilding.selfCollide.dimension.y - 10, map.line[i].playerBuilding.selfCollide.dimension.w ,8, getRouge(255));
	}
}

void updateMap(void)
{	
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < map.line[i].nbElementListe1; j++)
		{
			updateTEAM1(&map.line[i].liste1[j]);
			if(map.line[i].nbElementListe2 > 0)
			{
				for(int k = 0; k < map.line[i].nbElementListe2; k++)
				{
					if(collide(map.line[i].liste1[j].armeCollide.dimension, map.line[i].liste2[k].dimension))
					{
						map.line[i].liste1[j].ennemyInRange = SDL_TRUE;
						if(map.line[i].liste1[j].hurtEnnemy == SDL_TRUE)
						{
							map.line[i].liste1[j].hurtEnnemy = SDL_FALSE;
							map.line[i].liste2[k].nombreDeDegat = map.line[i].liste1[j].degat;
							map.line[i].liste2[k].hurt = SDL_TRUE;
						}
					}
				}
			}
			else
			{
				map.line[i].liste1[j].ennemyInRange = SDL_FALSE;
			}
		}
		for(int j = 0; j < map.line[i].nbElementListe2; j++)
		{
			updateTEAM2(&map.line[i].liste2[j]);
			if(map.line[i].nbElementListe1 > 0)
			{
				for(int k = 0; k < map.line[i].nbElementListe1; k++)
				{
					if(collide(map.line[i].liste1[k].dimension, map.line[i].liste2[j].armeCollide.dimension))
					{
						map.line[i].liste2[j].ennemyInRange = SDL_TRUE;
						if(map.line[i].liste2[j].hurtEnnemy == SDL_TRUE)
						{
							map.line[i].liste2[j].hurtEnnemy = SDL_FALSE;
							map.line[i].liste1[k].nombreDeDegat = map.line[i].liste2[j].degat;
							map.line[i].liste1[k].hurt = SDL_TRUE;
						}
					}
				}
			}
			else
			{
				map.line[i].liste2[j].ennemyInRange = SDL_FALSE;
			}
		}
		map.line[i].playerBuilding.lifeRemaning.sprite.dimension.w = (map.line[i].playerBuilding.vie * map.line[i].playerBuilding.maxWidth) / map.line[i].playerBuilding.maxVie;
		map.line[i].ennemyBuilding.lifeRemaning.sprite.dimension.w = (map.line[i].ennemyBuilding.vie * map.line[i].ennemyBuilding.maxWidth) / map.line[i].ennemyBuilding.maxVie;
	}

	for(int i = 0; i < 5; i++)
	{
		int mX = getMouseX();
		int mY = getMouseY();
		int x = map.line[i].dimension.x;
		int y = map.line[i].dimension.y;
		int w = map.line[i].dimension.w;
		int h = map.line[i].dimension.h;

		if(isActiveGameOption() == SDL_FALSE && isActiveConstruction() == SDL_FALSE)
		{
			if(getStateOfLeftButton() && getStateOfOldLeftButton() == SDL_FALSE
				&& getSelection() >= 0 && mX > x && mX < x + w && mY > y && mY < y + h
				&& map.line[i].canPlace == SDL_TRUE)
			{
				if(getSelection() == ARCHER && getFoodTEAM1() > 10)
				{
					changeFoodTEAM1(-10);
					addElementInListe1(i, getSelection());
					map.line[i].canPlace = SDL_FALSE;
					map.line[i].liste1Timer.previousTime = SDL_GetTicks();
				}
				else if(getSelection() == WARRIOR && getFoodTEAM1() >= 5)
				{
					changeFoodTEAM1(-5);
					addElementInListe1(i, getSelection());
					map.line[i].canPlace = SDL_FALSE;
					map.line[i].liste1Timer.previousTime = SDL_GetTicks();
				}
				else if(getSelection() == KNIGHT && getFoodTEAM1() >= 10)
				{
					changeFoodTEAM1(-10);
					addElementInListe1(i, getSelection());
					map.line[i].canPlace = SDL_FALSE;
					map.line[i].liste1Timer.previousTime = SDL_GetTicks();
				}
			}

			if(map.line[i].canPlace == SDL_FALSE)
			{
				map.line[i].liste1Timer.currentTime = SDL_GetTicks();
				if(map.line[i].liste1Timer.currentTime >= map.line[i].liste1Timer.previousTime + map.line[i].liste1Timer.ms)
				{
					map.line[i].canPlace = SDL_TRUE;
				}
			}
		}

		x = map.line[i].playerBuilding.panel.dimension.x;
		y = map.line[i].playerBuilding.panel.dimension.y;
		w = map.line[i].playerBuilding.panel.dimension.w;
		h = map.line[i].playerBuilding.panel.dimension.h;

		if(getStateOfLeftButton() && getStateOfOldLeftButton() == SDL_FALSE
			&& getSelection() >= 0 && mX > x && mX < x + w && mY > y && mY < y + h)
		{
			if(map.line[i].playerBuilding.panel.texture == -1)
			{
				if(getSelection() == 9)
				{
					playFx(0);
					map.line[i].playerBuilding.panel.texture = 9;
					addIncomeGoldTEAM1(50);
					setSelection(-1);
					resetBuildingPanel();
				}
				else if(getSelection() == 10)
				{
					playFx(0);
					map.line[i].playerBuilding.panel.texture = 10;
					addIncomeFoodTEAM1(20);
					setSelection(-1);
					resetBuildingPanel();
				}
			}
		}

		map.line[i].liste2Timer.currentTime = SDL_GetTicks();

		if(map.line[i].liste2Timer.currentTime >= map.line[i].liste2Timer.previousTime + map.line[i].liste2Timer.ms)
		{
			if(isActiveConstruction() == SDL_FALSE && isActiveGameOption() == SDL_FALSE)
			{
				if(map.line[i].nbElementListe1 > 2 && getFoodTEAM2() >= 50)
				{
					int nbWarrior = 0;
					int nbKnight = 0;
					int nbArcher = 0;

					for(int j = 0; j < map.line[i].nbElementListe1; j++)
					{
						if(map.line[i].liste1[j].texture == ARCHER)
						{
							nbArcher++;
						}
						else if(map.line[i].liste1[j].texture == KNIGHT)
						{
							nbKnight++;
						}
						else if(map.line[i].liste1[j].texture == WARRIOR)
						{
							nbWarrior++;
						}
					}
					if(nbArcher > nbKnight && nbArcher > nbWarrior && getFoodTEAM2() >= 10)
					{
						changeFoodTEAM2(-10);
						addElementInListe2(i, KNIGHT);
					}
					else if(nbWarrior > nbKnight && nbWarrior > nbArcher && getFoodTEAM2() >= 10)
					{
						changeFoodTEAM2(-10);
						addElementInListe2(i, ARCHER);
					}
					else if(getFoodTEAM2() >= 5)
					{
						changeFoodTEAM2(-5);
						addElementInListe2(i, WARRIOR);
					}
				}
				else if(getFoodTEAM2() >= 50)
				{
					if(map.line[i].nbElementListe2 == 0)
					{
						changeFoodTEAM2(-10);
						addElementInListe2(i, KNIGHT);
					}
					else if(map.line[i].nbElementListe2 > 0 && map.line[i].liste2[0].texture == KNIGHT && getFoodTEAM2() >= 10 && map.line[i].nbElementListe2 < 2)
					{
						changeFoodTEAM2(-10);
						addElementInListe2(i, ARCHER);
					}
					else if(map.line[i].nbElementListe2 > 0 && map.line[i].liste2[0].texture == KNIGHT && getFoodTEAM2() >= 5 && map.line[i].nbElementListe2 < 2)
					{
						changeFoodTEAM2(-5);
						addElementInListe2(i, WARRIOR);
					}
				}
				else if(getFoodTEAM2() < 50 && map.line[i].nbElementListe1 > 0)
				{
					if(map.line[i].liste1[0].texture == ARCHER && getFoodTEAM2() >= 10)
					{
						changeFoodTEAM2(-10);
						addElementInListe2(i, KNIGHT);
					}
					else if(map.line[i].liste1[0].texture == WARRIOR && getFoodTEAM2() >= 5)
					{
						changeFoodTEAM2(-10);
						addElementInListe2(i, ARCHER);
					}
					else if(map.line[i].liste1[0].texture == KNIGHT && getFoodTEAM2() >= 10)
					{
						changeFoodTEAM2(-5);
						addElementInListe2(i, WARRIOR);
					}
					else if(getFoodTEAM2() >= 5)
					{
						changeFoodTEAM2(-5);
						addElementInListe2(i, WARRIOR);
					}
				}
				else if(getFoodTEAM2() < 50 && map.line[i].nbElementListe2 < 1)
				{
					changeFoodTEAM2(-5);
					addElementInListe2(i, WARRIOR);
				}

				if(map.line[i].ennemyBuilding.panel.texture == -1)
				{
					if(getGoldTEAM2() >= 100 && getNbForge() == 0)
					{
						setNbForge(1);
						changeGoldTEAM2(-100);
						addIncomeGoldTEAM2(50);
						map.line[i].ennemyBuilding.panel.texture = 9;
					}
					else if(getGoldTEAM2() >= 250 && getNbForge() == 1)
					{
						changeGoldTEAM2(-250);
						addIncomeFoodTEAM2(20);
						map.line[i].ennemyBuilding.panel.texture = 10;	
					}
				}
			}
			map.line[i].liste2Timer.previousTime = map.line[i].liste2Timer.currentTime;
		}
	}

	removeElementInLine();
}

void drawMap(void)
{
	drawTexture(getTexture(lineBackground.texture), &lineBackground.dimension, NULL);
	drawTexture(getTexture(ennemyBackground.texture), &ennemyBackground.dimension, NULL);
	drawTexture(getTexture(playerBackground.texture), &playerBackground.dimension, NULL);
	drawTexture(getTexture(upBackground.texture), &upBackground.dimension, NULL);
	drawTexture(getTexture(downBackground.texture), &downBackground.dimension, NULL);

	for(int i = 0; i < 5; i++)
	{
		drawRect(&map.line[i].ennemyBuilding.lifeRemove.sprite.dimension, &map.line[i].ennemyBuilding.lifeRemove.fill, &map.line[i].ennemyBuilding.lifeRemove.couleur);
		drawRect(&map.line[i].ennemyBuilding.lifeRemaning.sprite.dimension, &map.line[i].ennemyBuilding.lifeRemaning.fill, &map.line[i].ennemyBuilding.lifeRemaning.couleur);
		drawRect(&map.line[i].playerBuilding.lifeRemove.sprite.dimension, &map.line[i].playerBuilding.lifeRemove.fill, &map.line[i].playerBuilding.lifeRemove.couleur);
		drawRect(&map.line[i].playerBuilding.lifeRemaning.sprite.dimension, &map.line[i].playerBuilding.lifeRemaning.fill, &map.line[i].playerBuilding.lifeRemaning.couleur);

		drawPanel(&map.line[i].ennemyBuilding.panel);
		drawPanel(&map.line[i].playerBuilding.panel);

		if(map.line[i].canPlace == SDL_FALSE)
		{
			drawRect(&map.line[i].dimension, &map.line[i].canPlaceFill, &map.line[i].canPlaceCouleur1);
		}
		else
		{
			drawRect(&map.line[i].dimension, &map.line[i].canPlaceFill, &map.line[i].canPlaceCouleur2);
		}
	}

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < map.line[i].nbElementListe1; j++)
		{
			drawTEAM1(&map.line[i].liste1[j]);
		}
		for(int j = 0; j < map.line[i].nbElementListe2; j++)
		{
			drawTEAM2(&map.line[i].liste2[j]);
		}
	}
}

void cleanMap(void)
{
	SDL_Log("CLEAN MAP EN COURS\n");
	setPrintGame(SDL_FALSE);
	
	cleanGameGui();
	cleanTEAM1();
	cleanTEAM2();
	for(int i = 0; i < 5; i++)
	{
		if(map.line[i].liste1 != NULL)
		{
			free(map.line[i].liste1);
			map.line[i].liste1 = NULL;
		}
		if(map.line[i].liste2 != NULL)
		{
			free(map.line[i].liste2);
			map.line[i].liste2 = NULL;
		}
	}
	SDL_Log("CLEAN MAP TERMINER\n");
}

void removeLifeToBuildingTEAM1(int line)
{
	map.line[line].playerBuilding.vie--;
	if(map.line[line].playerBuilding.vie <= 0)
	{
		startMusic(6, SDL_TRUE);
		setSelection(-1);
		setPrintEndGame(SDL_TRUE);
		initEndMenu(SDL_FALSE);
	}
}

void removeLifeToBuildingTEAM2(int line)
{
	map.line[line].ennemyBuilding.vie--;
	map.line[line].ennemyBuilding.lifeRemaning.sprite.dimension.x += map.line[line].ennemyBuilding.maxWidth / map.line[line].ennemyBuilding.maxVie;
	if(map.line[line].ennemyBuilding.vie <= 0)
	{
		startMusic(6, SDL_TRUE);
		setSelection(-1);
		setPrintEndGame(SDL_TRUE);
		initEndMenu(SDL_TRUE);
	}
}

void addElementInListe1(int i, int classe)
{
	map.line[i].nbElementListe1++;

	map.line[i].liste1 = realloc(map.line[i].liste1, sizeof(Human) * map.line[i].nbElementListe1);

	if(map.line[i].liste1 == NULL)
	{
		fprintf(stderr, "realloc: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	SDL_Rect r1 = map.line[i].dimension;

	r1.x -= 17;
	r1.w = elementSizeX;
	r1.h = elementSizeX;

	if(classe == ARCHER)
	{
		map.line[i].liste1[map.line[i].nbElementListe1 - 1] = addElementInTEAM1(classe, r1, 10, elementSizeX, i);
	}
	else
	{
		map.line[i].liste1[map.line[i].nbElementListe1 - 1] = addElementInTEAM1(classe, r1, 10, 0, i);
	}
}

void addElementInListe2(int i, int classe)
{
	map.line[i].nbElementListe2++;

	map.line[i].liste2 = realloc(map.line[i].liste2, sizeof(Human) * map.line[i].nbElementListe2);

	if(map.line[i].liste2 == NULL)
	{
		fprintf(stderr, "realloc: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	SDL_Rect r1 = map.line[i].dimension;

	r1.x += map.line[i].dimension.w - elementSizeX;
	r1.w = elementSizeX;
	r1.h = elementSizeX;

	if(classe == ARCHER)
	{
		map.line[i].liste2[map.line[i].nbElementListe2 - 1] = addElementInTEAM2(classe, r1, 10, elementSizeX, i);
	}
	else
	{
		map.line[i].liste2[map.line[i].nbElementListe2 - 1] = addElementInTEAM2(classe, r1, 10, 10, i);
	}
}

int getMaxWidthMap(void)
{
	return map.line[0].dimension.x + map.line[0].dimension.w;
}

int getMinWidthMap(void)
{
	return map.line[0].dimension.x;
}

static void removeElementInLine(void)
{
	int nbToRemove = 0;

	for(int i = 0; i < 5; i++)
	{
		if(map.line[i].nbElementListe2 > 0)
		{
			for(int j = 0; j < map.line[i].nbElementListe2; j++)
			{
				if(map.line[i].liste2[j].remove == SDL_TRUE)
				{
					for(int k = j; k < map.line[i].nbElementListe2 - 1; k++)
					{
						Human tmp = map.line[i].liste2[k + 1];
						map.line[i].liste2[k] = map.line[i].liste2[k + 1];
						map.line[i].liste2[k] = tmp;
					}
					nbToRemove++;
				}
			}
		}

		map.line[i].nbElementListe2 -= nbToRemove;

		if(nbToRemove > 0)
		{
			map.line[i].liste2 = realloc(map.line[i].liste2, sizeof(Human) * map.line[i].nbElementListe2);
			if(map.line[i].liste2 == NULL && map.line[i].nbElementListe2 > 0)
			{
				fprintf(stderr, "realloc: %s\n", strerror(errno));
				exit(EXIT_FAILURE);
			}
			nbToRemove = 0;
		}
	}

	nbToRemove = 0;

	for(int i = 0; i < 5; i++)
	{
		if(map.line[i].nbElementListe1 > 0)
		{
			for(int j = 0; j < map.line[i].nbElementListe1; j++)
			{
				if(map.line[i].liste1[j].remove == SDL_TRUE)
				{
					for(int k = j; k < map.line[i].nbElementListe1 - 1; k++)
					{
						Human tmp = map.line[i].liste1[k + 1];
						map.line[i].liste1[k] = map.line[i].liste1[k + 1];
						map.line[i].liste1[k] = tmp;
					}
					nbToRemove++;
				}
			}
		}

		map.line[i].nbElementListe1 -= nbToRemove;

		if(nbToRemove > 0)
		{
			map.line[i].liste1 = realloc(map.line[i].liste1, sizeof(Human) * map.line[i].nbElementListe1);
			if(map.line[i].liste1 == NULL && map.line[i].nbElementListe1 > 0)
			{
				fprintf(stderr, "realloc: %s\n", strerror(errno));
				exit(EXIT_FAILURE);
			}
			nbToRemove = 0;
		}
	}
}
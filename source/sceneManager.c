#include "prototype.h"

static SDL_bool printMainMenu;
static SDL_bool printGame;
static SDL_bool printOption;
static SDL_bool printSelectDifficulty;
static SDL_bool printConstruction;
static SDL_bool printGameOption;
static SDL_bool printEndGame;

void initSceneManager(void)
{
	printMainMenu = SDL_FALSE;
	printGame = SDL_FALSE;
	printOption = SDL_FALSE;
	printSelectDifficulty = SDL_FALSE;
	printConstruction = SDL_FALSE;
	printGameOption = SDL_FALSE;
	printEndGame = SDL_FALSE;
}

SDL_bool isActiveOption(void)
{
	return printOption;
}

SDL_bool isActiveMainMenu(void)
{
	return printMainMenu;
}

SDL_bool isActiveGame(void)
{
	return printGame;
}

SDL_bool isActiveSelectDifficulty(void)
{
	return printSelectDifficulty;
}

SDL_bool isActiveConstruction(void)
{
	return printConstruction;
}

SDL_bool isActiveGameOption(void)
{
	return printGameOption;
}

SDL_bool isActiveEndGame(void)
{
	return printEndGame;
}

void setPrintSelectDifficulty(SDL_bool active)
{
	printSelectDifficulty = active;
}

void setPrintOption(SDL_bool active)
{
	printOption = active;
}

void setPrintMainMenu(SDL_bool active)
{
	printMainMenu = active;
}

void setPrintGame(SDL_bool active)
{
	printGame = active;
}

void setPrintConstruction(SDL_bool active)
{
	printConstruction = active;
}

void setPrintGameOption(SDL_bool active)
{
	printGameOption = active;
}

void setPrintEndGame(SDL_bool active)
{
	printEndGame = active;
}
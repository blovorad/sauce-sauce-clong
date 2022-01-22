//gcc source/*.c -o bin\prog.exe -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_mixer -lSDL2_image -lm
//gcc -Wall -Wextra -Werror --std=c99 source/*.c -o bin\prog.exe -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_mixer -lSDL2_image -lm
// "C:\Users\gauti\Desktop\projet C\projetAppar"

//-mwindows

#include "prototype.h"

Input input;																	//GESTION DES INPUTS
SDL_bool go;																	//VARIABLE DE CONTROLE

int main(int argc, char* argv[])
{
	atexit(cleanUp); 															//FONCTION LANCER SI ON RENCONTRE UN EXIT()...

	go = SDL_TRUE;

	printf("On a passer %d argument\n", argc);
	for(int i = 0; i < argc; i++)
	{
		printf("argv[%d] : ‘%s’\n", i, argv[i]);
	}

	Timer time;																	//STRUCTURE PERSONNEL POUR LA GESTION DU TEMPS
	
	time.currentTime = 0;														//première valeur du timer, pour la référence
	time.previousTime = SDL_GetTicks();											//deuxième valeur du timer, si current est au dessus c'est good
	time.ms = 1000;																//troisième valeur du timer, valeur référence pour la durée

	init();																		//fonction qui init le jeu !

	while(go)
	{
		time.currentTime = SDL_GetTicks();										//récupération du temps pour faire update/draw

		if(time.currentTime > (time.previousTime + time.ms / MAX_FPS))			//si le temps est supérieur aux valeurs alors on peut refaire
		{
			update(&input);														//update du jeu, on lui donne input car on va changer les touches
			draw();																//draw du jeu, on lui passe rien
			time.previousTime = time.currentTime;								//changement valeur temps pour après
		}
	}

	cleanUp();																	//fonction qui nettoie tout les choses allouer dynamiquement ou autre
	return 0;																	//fermeture du main, fin du programme
}

void setGo(SDL_bool active)														//fonction qui fait sortir de la boucle
{
	go = active;																//changement de la valeur de sortis
}
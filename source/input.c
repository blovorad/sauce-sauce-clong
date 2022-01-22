#include "prototype.h"

//CATALOGUE DES INPUTS ASSEZ CLAIR A LA LECTURE
void getInput(Input *input)
{
	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT :
				exit(EXIT_SUCCESS);
				break;
				
			case SDL_MOUSEBUTTONDOWN :
				if(event.button.button == SDL_BUTTON_LEFT)
				{
					actualiseLeftButton(1);
				}
				if(event.button.button == SDL_BUTTON_RIGHT)
				{
					actualiseRightButton(1);
				}
				break;

			case SDL_MOUSEBUTTONUP :
				if(event.button.button == SDL_BUTTON_LEFT)
				{
					actualiseLeftButton(2);
				}
				if(event.button.button == SDL_BUTTON_RIGHT)
				{
					actualiseRightButton(2);
				}
				break;
			case SDL_KEYDOWN :
				if(event.key.keysym.sym == SDLK_ESCAPE)
				{
					exit(EXIT_SUCCESS);
				}
				if(event.key.keysym.sym == SDLK_z)
				{
					input->z = SDL_TRUE;
				}
				if(event.key.keysym.sym == SDLK_s)
				{
					input->s = SDL_TRUE;
				}
				if(event.key.keysym.sym == SDLK_q)
				{
					input->q = SDL_TRUE;
				}
				if(event.key.keysym.sym == SDLK_d)
				{
					input->d = SDL_TRUE;
				}
				if(event.key.keysym.sym == SDLK_SPACE)
				{
					input->space = SDL_TRUE;
				}
				break;

			case SDL_KEYUP :
				if(event.key.keysym.sym == SDLK_z)
				{
					input->z = SDL_FALSE;
				}
				if(event.key.keysym.sym == SDLK_s)
				{
					input->s = SDL_FALSE;
				}
				if(event.key.keysym.sym == SDLK_q)
				{
					input->q = SDL_FALSE;
				}
				if(event.key.keysym.sym == SDLK_d)
				{
					input->d = SDL_FALSE;
				}
				if(event.key.keysym.sym == SDLK_SPACE)
				{
					input->space = SDL_FALSE;
				}
				break;

			default :
				break;
		}
	}
}
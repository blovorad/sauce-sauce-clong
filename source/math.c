#include "prototype.h"

//Fonction qui nous revoie une valeur absolue en ####INT####
int absolue(int a, int b)
{
	int c = a - b;
	if(c < 0)
	{
		c = -c;
	}

	return c;
}

float getAngle(int x1, int y1, int x2, int y2)
{
	return atan2(y2-y1, x2-x1);
}

//Fonction de collision
SDL_bool collide(SDL_Rect a, SDL_Rect b)
{
	return SDL_HasIntersection(&a, &b);
}
#include "prototype.h"

void cleanGroupeGui(GroupeGui *groupe)
{
	SDL_Log("CLEAN GROUPE GUI EN COURS\n");
	if(groupe->liste_texte != NULL)
	{
		for(int i = 0; i < groupe->nbTexte; i++)
		{
			if(groupe->liste_texte[i].sprite.texture != NULL)
			{
				SDL_DestroyTexture(groupe->liste_texte[i].sprite.texture);
				groupe->liste_texte[i].sprite.texture = NULL;
			}
		}
	}
	if(groupe->liste_bouton != NULL)
	{
		for(int i = 0; i < groupe->nbBouton; i++)
		{
			if(groupe->liste_bouton[i].texte.sprite.texture != NULL)
			{
				SDL_DestroyTexture(groupe->liste_bouton[i].texte.sprite.texture);
				groupe->liste_bouton[i].texte.sprite.texture = NULL;
			}
		}
	}
	
	groupe->nbBouton = 0;
	groupe->nbTexte = 0;
	groupe->nbPanel = 0;
	groupe->nbBarre = 0;

	free(groupe->liste_texte);
	groupe->liste_texte = NULL;
	free(groupe->liste_bouton);
	groupe->liste_bouton = NULL;
	free(groupe->liste_panel);
	groupe->liste_panel = NULL;
	free(groupe->liste_barre);
	groupe->liste_barre = NULL;
	SDL_Log("CLEAN GROUPE GUI TERMINER\n");
}

void updateGroupeGui(GroupeGui *groupe)
{
	if(groupe->liste_bouton != NULL)
	{
		int mx = getMouseX();
		int my = getMouseY();

		for(int i = 0; i < groupe->nbBouton; i++)
		{
			int x = groupe->liste_bouton[i].panel.dimension.x;
			int y =  groupe->liste_bouton[i].panel.dimension.y;
			int w =  groupe->liste_bouton[i].panel.dimension.w;
			int h =  groupe->liste_bouton[i].panel.dimension.h;

			if(mx > x && mx < x + w && my > y && my < y + h && groupe->liste_bouton[i].isPressed == SDL_FALSE)
			{
				groupe->liste_bouton[i].isHover = SDL_TRUE;
				if(groupe->liste_bouton[i].normal == SDL_TRUE)
				{
					groupe->liste_bouton[i].panel.texture = SELECT;
				}
			}
			else if(groupe->liste_bouton[i].isPressed == SDL_FALSE)
			{
				groupe->liste_bouton[i].isHover = SDL_FALSE;
				if(groupe->liste_bouton[i].normal == SDL_TRUE)
				{
					groupe->liste_bouton[i].panel.texture = ORIGINAL;
				}
			}

			if(groupe->liste_bouton[i].isHover == SDL_TRUE && getStateOfLeftButton() == SDL_TRUE && getStateOfOldLeftButton() == SDL_FALSE)
			{
				groupe->liste_bouton[i].isPressed = SDL_TRUE;
				if(groupe->liste_bouton[i].normal == SDL_TRUE)
				{
					groupe->liste_bouton[i].panel.texture = PRESSED;
				}
			}
			if(groupe->liste_bouton[i].isPressed == SDL_TRUE && getStateOfLeftButton() == SDL_FALSE)
			{
				groupe->liste_bouton[i].isPressed = SDL_FALSE;
				if(groupe->liste_bouton[i].normal == SDL_TRUE)
				{
					groupe->liste_bouton[i].panel.texture = ORIGINAL;
				}
				playEvent(groupe->liste_bouton[i].event);
			}
		}
	}
}

void drawGroupeGui(GroupeGui *groupe)
{
	if(groupe->liste_panel != NULL)
	{
		for(int i = 0; i < groupe->nbPanel; i++)
		{
			drawPanel(&groupe->liste_panel[i]);
		}
	}
	if(groupe->liste_texte != NULL)
	{
		for(int i = 0; i < groupe->nbTexte; i++)
		{
			drawTexte(&groupe->liste_texte[i]);
		}
	}
	if(groupe->liste_bouton != NULL)
	{
		for(int i = 0; i < groupe->nbBouton; i++)
		{
			drawBouton(&groupe->liste_bouton[i]);
		}
	}
	if(groupe->liste_barre != NULL)
	{
		for(int i = 0; i < groupe->nbBarre; i++)
		{
			drawBarre(&groupe->liste_barre[i]);
		}
	}
}

void drawPanel(Panel *panel)
{
	if(panel->texture != -1)
	{
		drawTexture(getTexture(panel->texture), &panel->dimension, NULL);
	}
	else
	{
		drawRect(&panel->dimension, &panel->fill, &panel->couleur);
	}
}

void drawTexte(Texte *texte)
{
	drawTexture(texte->sprite.texture, &texte->sprite.dimension, NULL);
}

void drawBouton(Bouton *bouton)
{
	drawPanel(&bouton->panel);
	drawTexte(&bouton->texte);
}

void drawBarre(Barre *barre)
{
	drawRect(&barre->sprite.dimension, &barre->fill, &barre->couleur);
}

Panel createPanel(int x, int y, int w, int h, int texture, SDL_Color color, SDL_bool pFill)
{
	Panel myPanel;

	myPanel.texture = texture;

	myPanel.dimension.x = x * getScaleX();
	myPanel.dimension.y = y * getScaleY();
	myPanel.dimension.w = w * getScaleX();
	myPanel.dimension.h = h * getScaleY();
	myPanel.couleur = color;
	myPanel.fill = pFill;

	return myPanel;
}

Barre createBarre(int x, int y, int w, int h, SDL_Color color)
{
	Barre myBarre;

	myBarre.sprite.texture = NULL;
	myBarre.sprite.dimension.x = x;
	myBarre.sprite.dimension.y = y;
	myBarre.sprite.dimension.w = w;
	myBarre.sprite.dimension.h = h;

	myBarre.couleur = color;
	myBarre.empty = SDL_FALSE;
	myBarre.fill = SDL_TRUE;
	myBarre.tailleReel = myBarre.sprite.dimension;

	return myBarre;
}

Texte createTexte(int x, int y, int w, int h, char *texte, SDL_Color color, TTF_Font *font)
{
	Texte myTexte;
	if(texte != NULL)
	{
		int width, height;

		if(TTF_SizeText(font, texte, &width, &height) != 0)
		{
			SDL_Log("IMPOSSIBLE DE PRENDRE SIZE TEXTE DANS CREATE TEXTE GUI : %s",TTF_GetError());
			exit(EXIT_FAILURE);
		}

		SDL_Surface *surface;

		surface = TTF_RenderText_Blended(font, texte, color);

		myTexte.sprite.texture = SDL_CreateTextureFromSurface(getRenderer(), surface);
		SDL_FreeSurface(surface);
		surface = NULL;

		if(myTexte.sprite.texture == NULL)
		{
			SDL_Log("IMPOSSIBLE DE CRRER LA TEXTURE TEXTE :%s",SDL_GetError());
			exit(EXIT_FAILURE);
		}

		myTexte.sprite.dimension.x = (x + ((w - width) / 2)) * getScaleX();
		myTexte.sprite.dimension.y = (y + ((h - height) / 2)) * getScaleY();
		myTexte.sprite.dimension.w = width * getScaleX();
		myTexte.sprite.dimension.h = height * getScaleY();
		myTexte.sprite.angle = 0;
		myTexte.sprite.currentDirection = 0;
		myTexte.couleur = color;
	}

	return myTexte;
}

Bouton createBouton(int x, int y, int w, int h, int texture,SDL_Color panelColor, char *ptexte, SDL_Color texteColor, TTF_Font *font, SDL_bool pFill, int event)
{
	Bouton myBouton;

	myBouton.panel = createPanel(x, y, w, h, texture, panelColor, pFill);
	myBouton.texte = createTexte(x, y, w, h, ptexte, texteColor, font);
	myBouton.isHover = SDL_FALSE;
	myBouton.isPressed = SDL_FALSE;
	myBouton.alpha = panelColor.a;
	myBouton.event = event;
	if(texture == ORIGINAL)
	{
		myBouton.normal = SDL_TRUE;
	}
	else
	{
		myBouton.normal = SDL_FALSE;
	}

	return myBouton;
}
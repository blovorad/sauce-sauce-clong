#ifndef __PROTOTYPE__H__
#define __PROTOTYPE__H__

#include "structure.h"

//MAIN FUNCTION
extern void setGo(SDL_bool active);

//CLEANUP FUNCTION
extern void cleanUp(void);
extern void cleanAudio(void);

//INIT FUNCTION
extern void init(void);
extern void initMouse(void);
extern void initEvent(void);
extern void initAudio(int nbMusic, int nbFx);
extern void initSceneManager(void);

//UPDATE FUNCTION
extern void update(Input *input);
extern void updateAudio(void);
extern void updatePlayer(void);

//DRAW FUNCTION
extern void draw(void);
extern void drawPlayer(void);
extern void drawRect(SDL_Rect *r, SDL_bool *fill, SDL_Color *couleur);
extern void drawTexture(SDL_Texture *texture, SDL_Rect *dst, SDL_Rect *src);
extern void drawTextureEx(SDL_Texture *texture, SDL_Rect *dst, SDL_Rect *src, SDL_Point *center, int angle, SDL_RendererFlip flip);
extern void setRenderColor(SDL_Color *couleur);
extern void drawLine(int *x1, int *y1, int *x2, int *y2, SDL_Color *couleur);
extern void drawPoint(int *x, int *y, SDL_Color *couleur);

//MAIN MENU FUNCTION
extern void initMainMenu(void);
extern void updateMainMenu(void);
extern void drawMainMenu(void);
extern void cleanMainMenu(void);

//OPTION FUNCTION
extern void initOption(void);
extern void updateOption(void);
extern void drawOption(void);
extern void cleanOption(void);
extern void changeBoutonFullscreen(void);
extern void changeBoutonResolution(void);

//TEAM1 FUNCTION
extern Human addElementInTEAM1(int classe, SDL_Rect dimension, int wCollide, int offset, int line);
extern void updateTEAM1(Human *myHuman);
extern void drawTEAM1(Human *myHuman);
extern void cleanTEAM1(void);
extern void initRessourceTEAM1(void);
extern void updateRessourceTEAM1(void);
extern void drawRessourceTEAM1(void);
extern void changeFoodTEAM1(int change);
extern void changeGoldTEAM1(int change);
extern void addIncomeFoodTEAM1(int income);
extern void addIncomeGoldTEAM1(int income);
extern int getFoodTEAM1(void);
extern int getGoldTEAM1(void);

//TEAM2 FUNCTION
extern Human addElementInTEAM2(int classe, SDL_Rect dimension, int wCollide, int offset, int line);
extern void updateTEAM2(Human *myHuman);
extern void drawTEAM2(Human *myHuman);
extern void cleanTEAM2(void);
extern void initRessourceTEAM2(void);
extern void updateRessourceTEAM2(void);
extern void changeFoodTEAM2(int change);
extern void changeGoldTEAM2(int change);
extern void addIncomeFoodTEAM2(int income);
extern void addIncomeGoldTEAM2(int income);
extern void setNbForge(int number);
extern int getNbForge(void);
extern int getFoodTEAM2(void);
extern int getGoldTEAM2(void);

//MAP FUNCTION
extern void initMap(void);
extern void updateMap(void);
extern void drawMap(void);
extern void cleanMap(void);
extern void removeLifeToBuildingTEAM1(int line);
extern void removeLifeToBuildingTEAM2(int line);
extern void addElementInListe1(int i, int classe);
extern void addElementInListe2(int i, int classe);
extern int getMaxWidthMap(void);
extern int getMinWidthMap(void);

//FONT FUNCTION
extern void initFont1(void);
extern void cleanFont1(void);
extern TTF_Font *getFont1(void);

//GAME GUI FUNCTION
extern void initGameGui(void);
extern void updateGameGui(void);
extern void drawGameGui(void);
extern void cleanGameGui(void);
extern void resetBuildingPanel(void);
extern void initEndMenu(SDL_bool victory);
extern void setSelection(int active);
extern int getSelection(void);

//RESOLUTION MANAGER FUNCTION
extern SDL_Renderer *getRenderer(void);
extern SDL_Window *getWindow(void);
extern SDL_bool getFullscreen(void);
extern SDL_bool getOldFullscreen(void);
extern void initWindowAndRenderer(void);
extern void cleanWindowAndRenderer(void);
extern void setScale(void);
extern void setResolution(void);
extern void setFullscreen(SDL_bool active);
extern void resetResolution(int reset);
extern void changeResolution(int w, int h);
extern int getCurrentResolution(void);
extern int getOldCurrentResolution(void);
extern int getWidth(void);
extern int getHeight(void);
extern float getScaleX(void);
extern float getScaleY(void);

//GUI FUNCTION
extern void cleanGroupeGui(GroupeGui *groupe);
extern void updateGroupeGui(GroupeGui *groupe);
extern void drawGroupeGui(GroupeGui *groupe);
extern void drawPanel(Panel *panel);
extern void drawTexte(Texte *texte);
extern void drawBouton(Bouton *bouton);
extern void drawBarre(Barre *barre);
extern Panel createPanel(int x, int y, int w, int h, int texture, SDL_Color color, SDL_bool pFill);
extern Texte createTexte(int x, int y, int w, int h, char *texte, SDL_Color color, TTF_Font *font);
extern Barre createBarre(int x, int y, int w, int h, SDL_Color color);
extern Bouton createBouton(int x, int y, int w, int h, int texture,SDL_Color panelColor, char *ptexte, SDL_Color texteColor, TTF_Font *font, SDL_bool pFill, int event);

//SCENEMANAGER FUNCTION
extern SDL_bool isActiveMainMenu(void);
extern SDL_bool isActiveGame(void);
extern SDL_bool isActiveOption(void);
extern SDL_bool isActiveSelectDifficulty(void);
extern SDL_bool isActiveConstruction(void);
extern SDL_bool isActiveGameOption(void);
extern SDL_bool isActiveEndGame(void);
extern void setPrintOption(SDL_bool active);
extern void setPrintMainMenu(SDL_bool active);
extern void setPrintGame(SDL_bool active);
extern void setPrintSelectDifficulty(SDL_bool active);
extern void setPrintConstruction(SDL_bool active);
extern void setPrintGameOption(SDL_bool active);
extern void setPrintEndGame(SDL_bool active);

//INPUT FUNCTION
extern void getInput(Input *input);

//COLOR FUNCTION
extern SDL_Color getVert(int alpha);
extern SDL_Color getVertFoncer(int alpha);
extern SDL_Color getGris(int alpha);
extern SDL_Color getRouge(int alpha);
extern SDL_Color getBleu(int alpha);
extern SDL_Color getBlanc(int alpha);
extern SDL_Color getNoir(int alpha);
extern SDL_Color getMarron(int alpha);
extern SDL_Color getJaune(int alpha);

//EVENT FUNCTION
extern void startGame(void);
extern void quitGame(void);
extern void goToOption(void);
extern void goToMenu(void);
extern void backToMenu(void);
extern void addVolumeMusique(void);
extern void addVolumeFx(void);
extern void removeVolumeMusique(void);
extern void removeVolumeFx(void);
extern void goToConstruction(void);
extern void returnToGame(void);
extern void buyForge(void);
extern void buyFerme(void);
extern void goToOptionGame(void);
extern void returnToGameplay(void);
extern void applyChange(void);
extern void setFullscreenOption(void);
extern void setResolutionEvent(void);
extern void playEvent(int event);

//MOUSE FUNCTION
extern SDL_bool getStateOfRightButton(void);
extern SDL_bool getStateOfLeftButton(void);
extern SDL_bool getStateOfOldRightButton(void);
extern SDL_bool getStateOfOldLeftButton(void);
extern void getMousePos(void);
extern void actualiseRightButton(int n);
extern void actualiseLeftButton(int n);
extern void actualiseOldRightButton(void);
extern void actualiseOldLeftButton(void);
extern int getMouseX(void);
extern int getMouseY(void);

//AUDIO FUNCTION
extern void playFx(int fx);
extern void startMusic(int music, SDL_bool loop);
extern void upVolumeFx(void);
extern void downVolumeFx(void);
extern void upVolumeMusic(void);
extern void downVolumeMusic(void);
extern int getVolumeMusic(void);
extern int getVolumeFx(void);

//MATH FUNCTION
extern SDL_bool collide(SDL_Rect a, SDL_Rect b);
extern int absolue(int a, int b);
extern float getAngle(int x1, int y1, int x2, int y2);

//TEXTURE FUNCTION
extern SDL_Texture *createTexture(char *chemin, SDL_Rect *rect);
extern SDL_Texture *getTexture(int texture);
extern void initTexture(void);
extern void cleanTexture(void);

#endif
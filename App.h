#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"
#include "Character.h"
#include "Background.h"
#include "Platform.h"
#include "myCoin.h"
#include <vector>
#include <list>
#include "TexRect.h"
#include "SOIL.h"
#include "Projectile.h"
#include "Enemy.h"

class App: public GlutApp {
    
public:
    //AnimatedRect* cat;
    
    AnimatedRect* hat;
    TexRect coinIcon;
    TexRect heart1;
    TexRect heart2;
    TexRect heart3;

    Rect coinbackgroundRect;
    Rect heartbackground;
    
    
    TexRect* background;
    TexRect* background2;
    Character* mainCharacter;
    Background* levelbackground;
    
    // todo: change to vector of platforms
    vector<Platform> myplatforms;
    Platform* platform;
    Platform* platform2;
    
    
    vector<myCoin> mycoins;
    int numberofCoins;
    
    vector<Projectile> myprojectiles;
    
    //todo: vector of enemies
    vector<Enemy> myenemies;
    
    
    //todo: vector of gaps
    // vector<Gap> mygaps;
    
    //todo: finish flag texRect
    // TexRect finishFlag;
    
    //todo: finish screen ( for dying or completing the level) 
    //FinishScreen myfinishScreen;
    
    
    int selectedKey; 
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw();
    void keyDown(unsigned char key, float x, float y);
    void specialKeyDown(int key, float x, float y);
    void specialKeyUp(int key, float x, float y); 
    ~App();
    friend void timer(int);
    
};

#endif

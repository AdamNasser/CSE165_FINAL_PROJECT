#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"
#include "Character.h"
#include "Background.h"
#include "Platform.h"
#include <vector>

class App: public GlutApp {
    
public:
    //AnimatedRect* cat;
    TexRect* background;
    TexRect* background2;
    Character* mainCharacter;
    Background* levelbackground;
    Platform* platform;
    Platform* platform2; 
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

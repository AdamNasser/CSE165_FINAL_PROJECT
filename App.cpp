#include <iostream>
#include "App.h"
#define JUMP_HEIGHT 1;
App* singleton;


//as game progresses, handle background and character movements through this timer method 
void timer(int id){
    //handle background
    singleton->levelbackground->handleBackgroundMovement();
    
    //handle mainCharacter movement
    singleton->mainCharacter->handleMovement();
    
    
    //handle platform
    singleton->platform->checkOccupied();
    singleton->platform->handleMovement();
    
    singleton->platform2->checkOccupied();
    singleton->platform2->handleMovement();
    
    
    
    singleton->redraw();
    
    
    //cout<<"character y: "<<singleton->mainCharacter->getY()<<endl;
    //cout<<"platform y: "<<singleton->platform->getY()<<endl;
    
    //cout<<"character x: "<<singleton->mainCharacter->getX()<<endl;
    //cout<<"platform x: "<<singleton->platform->getX()<<endl;
    
    glutTimerFunc(100, timer, id);
}

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
   
    singleton = this;
    this->selectedKey = 0; 
   
    singleton->mainCharacter = new Character(1, false,"cat.png",false,false);
    
    singleton->platform = new Platform(1.3,0.1,-0.2);
    singleton->platform->mainCharacter = singleton->mainCharacter;
    
    singleton->platform2 = new Platform(2.0,3.9,-0.2);
    singleton->platform2->mainCharacter = singleton->mainCharacter;
    
    singleton->levelbackground = new Background();
    singleton->levelbackground->mainCharacter = singleton->mainCharacter;
    
    timer(1);
}
void App::draw() {
    platform->draw();
    platform2->draw();
     levelbackground->t1->draw(0);
     levelbackground->t2->draw(0);
    
     mainCharacter->draw(0.15);
    
 
}
void App::specialKeyDown(int key, float x, float y){
    std::cout<<key<<std::endl;
    this->selectedKey = mainCharacter->handleKeyInput(key,selectedKey,"down");
}

void App::specialKeyUp(int key, float x, float y){
    this->selectedKey = singleton->mainCharacter->handleKeyInput(key, selectedKey, "up");
}
void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
}

//virtual void specialKeyUp(int, float, float){}

App::~App(){
    std::cout << "Exiting..." << std::endl;
}

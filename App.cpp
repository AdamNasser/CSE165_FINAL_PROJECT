#include <iostream>
#include "App.h"
#include <vector>
#include <list>
#include<string>
#define JUMP_HEIGHT 1;
App* singleton;
float currentcoinX = 4.2;
float currentcoinY = 0.0;
float currentEnemyX = 1.5;
float currentEnemyY = -0.4; 

float width = 1000;
float height = 500;
void renderText(string text, float x, float y, void* font = GLUT_BITMAP_TIMES_ROMAN_24, float r = 1, float g = 1, float b = 1){
    glColor3f(r, g, b);
    float offset = 0;
    for (int i = 0; i < text.length(); i++) {
        glRasterPos2f(x+offset, y);
        glutBitmapCharacter(font, text[i]);
        int w = glutBitmapWidth(font, text[i]);
        offset += ((float)w / width)*4;
    }
}

//as game progresses, handle background and character movements through this timer method
void timer(int id){
    //handle background
    singleton->levelbackground->handleBackgroundMovement();
    
    //handle mainCharacter movement
    singleton->mainCharacter->handleMovement();
    
    
    //handle platforms
    
    singleton->platform->checkOccupied();
    singleton->platform->handleMovement();
    singleton->platform2->checkOccupied();
    singleton->platform2->handleMovement();
    
  
    
    
    //handle coins
    for (int i = 0; i < 20; i++) {
        if(singleton->mycoins.at(i).myplatform == NULL) {
            singleton->mycoins.at(i).isOnPlatform = false;
              singleton->mycoins.at(i).handleMovement();
        } else {
            singleton->mycoins.at(i).myplatform->checkOccupied();
            singleton->mycoins.at(i).mycharacter =  singleton->mycoins.at(i).myplatform->mainCharacter;
            singleton->mycoins.at(i).handleMovement();
        }
    }
    
  
    if(singleton->myprojectiles.size() != 0) {
        //handle projectiles
        for(int i = 0; i < singleton->myprojectiles.size(); i++) {
            float projectileX = singleton->myprojectiles.at(i).handleMovement();
            float projectileY = singleton->myprojectiles.at(i).getY();
            
            //projectile is off screen can erase it
            if( projectileX > singleton->mainCharacter->getX() + 2.2) {
                cout<<"erased a projectile"<<endl;
                  singleton->myprojectiles.erase(singleton->myprojectiles.begin());
            }
            
            
            for(int i = 0; i < singleton->myenemies.size(); i++) {
                singleton->myenemies.at(i).handleMovement(projectileX,projectileY);
                singleton->redraw();
            }
            
            
        }
    } else {
         for(int i = 0; i < singleton->myenemies.size(); i++) {
                  singleton->myenemies.at(i).handleMovement(100000,100000);
             
         }
    }
    
    singleton->redraw();
    
    
    //cout<<"character y: "<<singleton->mainCharacter->getY()<<endl;\
     //cout<<"coin y: "<<singleton->coin1->getY()<<endl;
    //cout<<"platform y: "<<singleton->platform->getY()<<endl;
    
    //cout<<"character x: "<<singleton->mainCharacter->getX()<<endl;
    //cout<<"coin x:"<< singleton->coin1->getX()<<endl;
    //cout<<"platform x: "<<singleton->platform->getX()<<endl;
 
    glutTimerFunc(100, timer, id);
}

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
   
     singleton = this;
    
    
     this->coinbackgroundRect = Rect(1.2,1,0.5,0.2,0,0,0);
     this->coinIcon = TexRect("coin.png", 1.3, 1.0, 0.15, 0.15);
    this->heartbackground= Rect(0.5,1,0.7,0.2,0,0,0);
    this->heart1 = TexRect("heart.png", 0.6, 1.0, 0.15, 0.15);
    this->heart2 = TexRect("heart.png", 0.8, 1.0, 0.15, 0.15);
    this->heart3 = TexRect("heart.png", 1.0, 1.0, 0.15, 0.15);

    this->selectedKey = 0;
    
    this->numberofCoins = 0; 
   
    singleton->mainCharacter = new Character(1, false,"cat.png",false,false);
    
     //todo: change to vector of platforms
    singleton->platform = new Platform(1.3,4.0,-0.2);
    singleton->platform->mainCharacter = singleton->mainCharacter;
    
    singleton->platform2 = new Platform(2.0,7.9,-0.2);
    singleton->platform2->mainCharacter = singleton->mainCharacter;
    //end: platforms
    
    singleton->levelbackground = new Background();
    singleton->levelbackground->mainCharacter = singleton->mainCharacter;
    
    
    //coin initialization
    for(int i = 0; i < 5; i++) {
        myCoin newCoin = myCoin(currentcoinX, currentcoinY);
        newCoin.mycharacter = singleton->mainCharacter;
        newCoin.isOnPlatform = true;
        newCoin.myplatform = singleton->platform;
        this->mycoins.push_back(newCoin);
        currentcoinX = currentcoinX + 0.3;
    }
    
    for(int i = 0; i < 15; i++) {
        myCoin newCoin = myCoin(currentcoinX, currentcoinY -0.5);
        newCoin.mycharacter = singleton->mainCharacter;
        newCoin.isOnPlatform = false;
        this->mycoins.push_back(newCoin);
        currentcoinX = currentcoinX + 0.3;
    }
    
    //enemy initalization
    for (int i = 0; i < 6; i++) {
        Enemy enemy = Enemy(currentEnemyX, currentEnemyY);
        currentEnemyX += 4.0;
        enemy.mycharacter = this->mainCharacter;
        enemy.explosion = new AnimatedRect("output-onlinepngtools.png",6,6,100,true,true, enemy.getX(),enemy.getY()+0.2,0.5,0.5);
        myenemies.push_back(enemy);
    }
    timer(1);
}
void App::draw() {
    renderText(to_string(numberofCoins), 1.6, 0.89, GLUT_BITMAP_TIMES_ROMAN_24, 1, 1, 1);
    this->coinIcon.draw(0);
    this->coinbackgroundRect.draw();
    switch (mainCharacter->lives)
    {
        case 1: // code to be executed if n = 1;
            this->heart1.draw(0);
            break;
        case 2: // code to be executed if n = 2;
            this->heart1.draw(0);
            this->heart2.draw(0);
            break;
        case 3:
            this->heart1.draw(0);
            this->heart2.draw(0);
            this->heart3.draw(0);
            break;
    }
    
    this->heartbackground.draw();
    platform->draw();
    platform2->draw();
    levelbackground->t1->draw(0);
    levelbackground->t2->draw(0);
    numberofCoins = 0;
    
    for(int i = 0; i < 20; i++) {
        if(mycoins.at(i).isAvailable) {
            mycoins.at(i).draw(0.10);
        } else {
            this->numberofCoins++;
        }
    }

     mainCharacter->draw(0.15);
    
    
    //handle projectiles
    for(int i = 0; i < singleton->myprojectiles.size(); i++) {
        singleton->myprojectiles.at(i).draw(0.20);
        
    }
    
    
    //handle enemies
    for(int i = 0; i < myenemies.size(); i++) {
        if(myenemies.at(i).isAvailable){
             myenemies.at(i).draw(0.30);
        } else if(myenemies.at(i).isAvailable == false) {
            myenemies.at(i).explosion->draw(0.40);
           
            myenemies.at(i).didExplode = true;
        }
       
    }
    
}
void App::specialKeyDown(int key, float x, float y){
    //std::cout<<key<<std::endl;
    this->selectedKey = mainCharacter->handleKeyInput(key,selectedKey,"down");
}

void App::specialKeyUp(int key, float x, float y){
    this->selectedKey = singleton->mainCharacter->handleKeyInput(key, selectedKey, "up");
}
void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }else if(key == ' ') {
        cout<<"shot a projectile"<<endl;
        myprojectiles.push_back(Projectile(this->mainCharacter->getX(), this->mainCharacter->getY(), this->mainCharacter->orientation));
        mainCharacter->lives-=1;
        
    }
}

//virtual void specialKeyUp(int, float, float){}

App::~App(){
    std::cout << "Exiting..." << std::endl;
}

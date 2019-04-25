//
//  Character.h
//  glutapp
//
//  Created by Adam Nasser on 4/21/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//
#ifndef Character_h
#define Character_h

#include "AnimatedRect.h"
#include "Timer.h"

using namespace std;
class Character: public AnimatedRect {
      
public:
    Character(int , bool , const char*, bool , bool);
    
    int orientation;  //  =  left(0) or right(1)
    
    float ceiling;
    
    bool characterisMoving;
    
    void handleMovement();
    
    int handleKeyInput(int key, int lastSelectedKey,string type);
    
    bool isJumping;
    
    bool isDescending;
    
    bool isOnPlatform; 
    
    
    
};

#endif

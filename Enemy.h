//
//  Enemy.h
//  glutapp
//
//  Created by Adam Nasser on 5/6/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#ifndef Enemy_h
#define Enemy_h
#include "TexRect.h"
#include "Character.h"
class Enemy: public TexRect {
public: 
    Enemy(float, float);
    bool isAvailable;
    bool didExplode; 
    bool handleMovement(float px , float py);
    int pace;
    Character* mycharacter;
    AnimatedRect* explosion; 
   
};

#endif /* Enemy_h */

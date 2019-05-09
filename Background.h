//
//  Background.h
//  glutapp
//
//  Created by Adam Nasser on 4/22/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#ifndef Background_h
#define Background_h
#include "TexRect.h"
#include "Character.h"
using namespace std;
class Background {
public:
    Background();
    Character* mainCharacter; 
    void handleMovement();
    void handleBackgroundMovement(); 
    void resetBackground();
    bool needsReset(); 
    TexRect* t1;
    TexRect* t2;
    int backgroundCounter; 
};
#endif /* Background_h */

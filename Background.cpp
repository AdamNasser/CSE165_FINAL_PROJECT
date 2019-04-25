//
//  Background.cpp
//  glutapp
//
//  Created by Adam Nasser on 4/22/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#include <stdio.h>
#include "Background.h"
#include "TexRect.h"
Background::Background() {
    this->t1 = new TexRect("bg.png",-2.0,1,4,2);
    this->t2 = new TexRect("bg.png",2.0,1,4,2);
    this->backgroundCounter = 0; 
}

void Background::handleMovement() {
    this->t1->setX(this->t1->getX()-0.1);
    this->t2->setX(this->t2->getX()-0.1);
    this->backgroundCounter++; 
}

void Background::handleBackgroundMovement() {
    if(this->mainCharacter->characterisMoving) {
        if(this->needsReset()) {
            this->resetBackground();
        } else if(this->mainCharacter->orientation == 1) {
            this->handleMovement();
        }
    }
}

void Background::resetBackground() {
    this->t1->setX(-2);
    this->t2->setX(2);
    this->backgroundCounter = 0; 
}

bool Background::needsReset() {
    return this->backgroundCounter >= 35; 
}

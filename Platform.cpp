//
//  Platform.cpp
//  glutapp
//
//  Created by Adam Nasser on 4/22/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#include "Platform.h"
using namespace std;
Platform::Platform(float width, float x, float y):Rect(x,y,width,0.08,0.545,0.271,0.075) {
    this->setWidth(width);
}

void Platform::setWidth(float width) {
    this->width = width;
}

int Platform::getWidth() {
    return this->width;
}

void Platform::handleMovement() {
    switch (this->mainCharacter->orientation) {
        case 1:
            if(this->mainCharacter->characterisMoving){
                this->setX(this->getX() - 0.1);
            }
                break;
        default:
            break;
    }
}

bool Platform::checkXContains() {
    return (this->mainCharacter->getX() >= this->getX()-0.5 && this->mainCharacter->getX() <= this->getX() + this->getWidth());
}


void Platform::checkOccupied() {
    if(this->mainCharacter->getY() >= this->getY()+0.3 && checkXContains()) {
           // cout<<"landing verified"<<endl;
            this->mainCharacter->setY(this->getY() +0.5);
            this->mainCharacter->isOnPlatform = true;
    } else {
        this->mainCharacter->isOnPlatform = false;
    }
}

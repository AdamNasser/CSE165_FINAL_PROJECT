//
//  Character.cpp
//  glutapp
//
//  Created by Adam Nasser on 4/21/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#include <iostream>
#include "Character.h"
using namespace std;
Character::Character(int orientation, bool characterisMoving, const char * map_filename, bool isJumping, bool isDescending): AnimatedRect(map_filename, 4, 2,100,true,false,0.1,-0.2,1,0.5){
    cout<<"New Character created"<<endl;
    this->orientation = orientation;
    this->characterisMoving = characterisMoving;
    this->isJumping = isJumping;
    this->isDescending = isDescending;
    this->isOnPlatform = false;
    this->ceiling = 0.45; 
}
int Character::handleKeyInput(int key, int selectedKey, string type) {
    cout<<"Character is handling key input...."<<type<<endl;
    if (type == "up") {
        if(key == 102 ) { // right arrow key
            if(this->orientation == 0) {
                this->flip();
                this->orientation = 1;
            }
            this->characterisMoving = false;
            this->orientation = 1;
            this->reset();
            this->pause();
            return 0;
        } else if(key == 100) {//left arrow key
            if(this->orientation == 1) {
                this->flip();
                this->orientation = 0;
            }
            this->characterisMoving = false;
            this->orientation = 0;
            this->reset();
            this->pause();
            return 0;
        }
        return selectedKey;
    } else if(type == "down") {
        if(key == 102 && selectedKey != 102) { // right arrow key
            if(this->orientation == 0) {
                this->flip();
                this->orientation = 1;
            }
            this->characterisMoving = true;
            this->playLoop();
            return 102;
        } else if(key == 100 && selectedKey != 100) {//left arrow key
            if(this->orientation == 1) {
                this->flip();
                this->orientation= 0;
            }
            this->characterisMoving = true;
            this->playLoop();
            return 100;
        } else if(key == 101) {// up arrow key
            std::cout<<"Jumping !!"<<std::endl;
            if (this->isDescending) {
                cout<<"is descending, cant jump"<<endl; 
                return selectedKey;
            }else {
                this->isJumping = true;
                this->isDescending = false;
            }
        }
        return selectedKey;
    }
    return selectedKey; 
}

void Character::handleMovement() {
    //handle jumps
    if(this->isJumping) {
        this->setY(this->getY() + 0.2);
    }
    
    //player has jumped and should fall back down
    if(this->getY() > this->ceiling && !isOnPlatform) {
        std::cout<<"Reached max jump height"<<std::endl;
        this->isJumping = false;
        this->isDescending = true;
    }
    //begin descending from jump
    if(this->isDescending && this->getY() > -0.20) {
        this->setY(this->getY() - 0.1);
    } else if(this->getY() < -0.15 && this->getY() > -0.30 && this->isDescending ) {
        cout<<"end of descent";
        this->setY(-0.20);
        this->isDescending = false;
    }
    if (this->characterisMoving) {
        //handle moving left to right
        switch (this->orientation) {
            case 1:
                //move cat to right until it hits the edge
                if(this->getX() < 0.5) {
                    this->setX(this->getX() + 0.1);
                }
                break;
            case 0:
                if(this->getX() > -1.7) {
                    this->setX(this->getX() - 0.1);
                }
                break;
            default:
                break;
        }
    }

}



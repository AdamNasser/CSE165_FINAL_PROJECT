//
//  Enemy.cpp
//  glutapp
//
//  Created by Adam Nasser on 5/6/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#include <stdio.h>
#include "Enemy.h"
#include "math.h"
using namespace std;
Enemy::Enemy(float xPos,float yPos): TexRect("goomba.png",xPos,yPos,0.4,0.4 ){
    cout<<"new enemy"<<endl;
    isAvailable = true;
    didExplode = false;
    pace = 0;
}

bool Enemy::handleMovement(float px, float py) {
    if(isAvailable){
    switch (this->mycharacter->orientation) {
        case 1:
            if(this->mycharacter->characterisMoving){
                this->setX(this->getX() - 0.1);
                this->explosion->setX(this->explosion->getX() -0.1); // update explosion location when invisible
            }
            break;
        default:
            break;
    }
        
        //move back and forth
        if(pace < 10) {
            this->setX(this->getX() + 0.04);
            this->explosion->setX(this->explosion->getX() + 0.04);
            this->pace++;
        } else if(pace < 20) {
             this->setX(this->getX() - 0.04);
            this->explosion->setX(this->explosion->getX() - 0.04);
            this->pace++;
        } else {
            pace = 0;
        }
        
        if(px == 100000){
            isAvailable = true;
             return false;
        }
        // determine if hit
        if(fabs(this->getX() - px) < 0.3) {
            this->isAvailable = false;
            return true;
        }
        
    } else if(didExplode) {
        switch (this->mycharacter->orientation) {
            case 1:
                if(this->mycharacter->characterisMoving){
                    this->explosion->setX(this->explosion->getX() - 0.1);
                }
                break;
            default:
                break;
        }
    }
    return false;
}


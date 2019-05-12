//
//  Enemy.cpp
//  glutapp
//
//  Created by Adam Nasser on 5/6/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#include <stdio.h>
#include "Enemy.h"
using namespace std;
Enemy::Enemy(float xPos,float yPos): TexRect("goomba.png",xPos,yPos,0.4,0.4 ){
    cout<<"new enemy"<<endl;
    isAvailable = true;
    pace = 0;
}

void Enemy::handleMovement() {
    if(isAvailable){
    switch (this->mycharacter->orientation) {
        case 1:
            if(this->mycharacter->characterisMoving){
                this->setX(this->getX() - 0.1);
            }
            break;
        default:
            break;
    }
    }
}


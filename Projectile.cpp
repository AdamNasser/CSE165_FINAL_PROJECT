//
//  Projectile.cpp
//  glutapp
//
//  Created by Adam Nasser on 5/6/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#include <stdio.h>
#include "Projectile.h"
using namespace std;

Projectile::Projectile(float catX, float catY, int dir) : TexRect("projectilefire.png",catX+0.3,catY-0.2,0.25,0.25 ){
    cout<<"new projectile"<<endl;
    this->isAvailable = true;
    this->direction=dir;
}
int Projectile::handleMovement() {
        //cout<<"handling movement"<<endl;
    if(this->direction==1){
        this->setX(this->getX() + 0.4);
    }
    if(this->direction==0){
        this->setX(this->getX()- 0.4);
    }
    return this->getX();
}


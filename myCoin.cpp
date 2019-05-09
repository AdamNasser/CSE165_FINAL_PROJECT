//
//  Coin.cpp
//  glutapp
//
//  Created by Adam Nasser on 4/25/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#include "myCoin.h"
#include <iostream>
#include <cmath>
using namespace std; 
myCoin::myCoin( float xPos,  float yPos):TexRect("coin.png",xPos,yPos,0.15,0.15){
    cout<<"new coin created"<<endl;
    this->x = xPos;
    this->y = yPos;
    this->isAvailable = true;
    this->myplatform = NULL; 
}

//handles coin movement
void myCoin::handleMovement() {
    switch (this->mycharacter->orientation) {
        case 1:
            if(this->mycharacter->characterisMoving){
                this->setX(this->getX() - 0.1);
            }
            break;
        default:
            break;
    }
    
    //handle collection
   // cout<<"character on platform: "<<this->mycharacter->isOnPlatform<<endl; 
    if(mycharacter->isOnPlatform && isOnPlatform) {
        cout<<"character is on platform"<<endl; 
        if( isOnPlatform && abs(mycharacter->getX() - getX()) <= 0.7) {
            //cout<<"touchedCoin"<<endl;
            isAvailable = false;
        }
        
    } else if(isOnPlatform == false){
        if(abs(mycharacter->getY() - getY()) < 0.8 && abs(mycharacter->getX() - getX()) <= 0.6) {
            //cout<<"touchedCoin"<<endl;
            isAvailable = false;
            
        }
    }
   
}

void myCoin::action(){
    
}



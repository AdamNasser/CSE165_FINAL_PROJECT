//
//  myCoin.h
//  glutapp
//
//  Created by Adam Nasser on 4/25/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#ifndef myCoin_h
#define myCoin_h

#include "TexRect.h"
#include "Character.h"
#include "Platform.h"


using namespace std;
class myCoin:public TexRect {
public:
    myCoin( float   , float  );

    
    Character* mycharacter;
    Platform* myplatform;
    
    
   // bool isAvailable(int mainCharacterX, int mainCharacterY);
    bool isAvailable; 
    void handleMovement();
    bool isOnPlatform; 
    char* filename;
    float x;
    float y;
    void action();
    
};



#endif /* myCoin_h */

//
//  Platform.h
//  glutapp
//
//  Created by Adam Nasser on 4/22/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#ifndef Platform_h
#define Platform_h

#include "Rect.h"
#include "Character.h"
using namespace std;
class Platform: public Rect {
    float width;
public:
    Platform(float ,float, float);  // width, x , and y
    Character* mainCharacter;
    int getWidth();
    void setWidth(float width);
    void checkOccupied();
    bool checkXContains();
    void handleMovement(); 
};
#endif /* Platform_h */

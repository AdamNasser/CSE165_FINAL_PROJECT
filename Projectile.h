//
//  Projectile.h
//  glutapp
//
//  Created by Adam Nasser on 5/6/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#ifndef Projectile_h
#define Projectile_h

#include "TexRect.h"
#include "Character.h"

class Projectile: public TexRect {
public:
    int handleMovement();
    bool isAvailable;
    bool didExplode; 
    int direction;
    Projectile(float , float, int);
}; 



#endif /* Projectile_h */

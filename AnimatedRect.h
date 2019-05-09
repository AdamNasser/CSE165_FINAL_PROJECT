#ifndef AnimatedRect_h
#define AnimatedRect_h

#include "TexRect.h"
#include "Timer.h"
#include <string>
using namespace std; 

class AnimatedRect: public TexRect, protected Timer {
    
    int rows;
    int cols;
    
    int curr_row;
    int curr_col;
    
    bool complete;
    
    bool loop;
    
    bool animating;
    bool visible;
    
    void advance();
    bool done();
    
    bool flipped;
    
     const char* filename; 
    
    
public:
    
    
    AnimatedRect (const char*, int, int, int, bool, bool, float, float, float, float);
    AnimatedRect(const AnimatedRect &arect); 
    
    void draw(float z);
    
    void playLoop();
    
    void playOnce();
    
    void reset();
    
    void pause();
    
    void resume();
    
    void action();
    
    void play();
    
    void flip();
 
    
};

#endif

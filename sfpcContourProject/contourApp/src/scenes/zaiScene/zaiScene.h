#pragma once

#include "ofMain.h"
#include "baseScene.h"

class zaiScene : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();
     
    
    ofEasyCam cam;
    
    ofPoint centerSmooth;
    ofTrueTypeFont helvetica;
};

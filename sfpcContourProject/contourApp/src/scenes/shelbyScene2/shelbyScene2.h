#pragma once

#include "ofMain.h"
#include "baseScene.h"

class shelbyScene2 : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();
    
    vector < float > energies;
    
};

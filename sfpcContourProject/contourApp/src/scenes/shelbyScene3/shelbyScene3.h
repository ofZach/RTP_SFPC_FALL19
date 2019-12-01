#pragma once

#include "ofMain.h"
#include "baseScene.h"

class shelbyScene3 : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();
    
    vector< ofVec3f > history;
    
};

#pragma once

#include "ofMain.h"
#include "baseScene.h"

class mncScene2 : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();
    
    vector<ofPolyline> history;
    
};

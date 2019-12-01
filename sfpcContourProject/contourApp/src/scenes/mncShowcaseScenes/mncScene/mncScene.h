#pragma once

#include "ofMain.h"
#include "baseScene.h"

class mncScene : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();
    
    vector<ofPolyline> history;
    
};

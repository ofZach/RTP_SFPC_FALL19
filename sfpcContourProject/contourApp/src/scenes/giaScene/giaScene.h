#pragma once

#include "ofMain.h"
#include "baseScene.h"

class giaScene : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();
    
    vector<ofPolyline> history;
};

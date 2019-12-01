#pragma once

#include "ofMain.h"
#include "baseScene.h"

class yuzhuChaiScene : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();
    
    vector <ofPoint> history;
    vector < ofPoint > pts;
};

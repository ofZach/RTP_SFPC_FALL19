#pragma once

#include "ofMain.h"
#include "baseScene.h"

class franScene : public baseScene{
    
public:
    void setup();
    void update();
    void draw();

    vector <ofPolyline> history;
    vector <ofPath> history_paths;
    
};

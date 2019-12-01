#pragma once

#include "ofMain.h"
#include "baseScene.h"

class Kath_scene1 : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();
	
	vector <ofPolyline> history;
	vector <ofColor> palette;
};

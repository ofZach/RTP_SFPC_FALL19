#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "ofxTriangleMesh.h"

class estherScene : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofxTriangleMesh tri;
    
};

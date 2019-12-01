#pragma once

#include "ofMain.h"
#include "contourTracker.h"
#include "contourFramer.h"
#include "ofxGui.h"
#include "inputManager.h"




class baseScene {
    
public:
    
    virtual void setup(){};
    virtual void update(){};
    virtual void draw(){};
    virtual void reset(){};
    
    virtual void startScene() {};
    
    virtual void mouseDragged(int x, int y, int button){};
    virtual void mousePressed(int x, int y, int button){};
    virtual void mouseReleased(int x, int y, int button){};
    
    contourTracker * CT;
    contourFramer * CF;
    inputManager * IM;
    
    string studentName = "";
    
    ofxPanel panel;
    ofParameterGroup group;
    ofRectangle bounds;
    
    float currentPct = 0.5;
    int currentFrame;
    
};

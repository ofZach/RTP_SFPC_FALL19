



#pragma once

#include "ofMain.h"
#include "contourTracker.h"

class contourFramer {
    
public:
    
    contourTracker * CT;
    ofRectangle bounds;

    void update();
    
    void reset(){
        bResetCenterSmooth = true;
    }
    bool bResetCenterSmooth = false;
    ofPoint centerSmoothed;
    ofPolyline line;
    ofPolyline lineOrig;
    
    ofPolyline orig;
    
    float centerSmoothing = 0.95;;
    float scale = 2.1;
    float xOffset = 0;
    float yOffset = 0;
};


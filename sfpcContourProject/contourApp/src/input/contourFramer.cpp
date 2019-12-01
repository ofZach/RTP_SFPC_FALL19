


#include "contourFramer.h"

void contourFramer::update(){

    
   ofPolyline lineme = CT->resampleSmoothedOrig;
    
    ofPoint center;
    for (int i = 0; i < lineme.size(); i++){
        center += lineme[i];
    }
    center /= (float)lineme.size();
    
    if (bResetCenterSmooth == true){
        bResetCenterSmooth = false;
        centerSmoothed = center; //ofPoint(1920/2, 1080/2);
    } else {
        centerSmoothed = centerSmoothing * centerSmoothed + (1-centerSmoothing)* center;
    }
    
    for (int i = 0; i < lineme.size(); i++){
        lineme[i] -= ofPoint(centerSmoothed.x, 1080/2);
        lineme[i] *= scale;
        lineme[i] += ofPoint(bounds.getWidth()/2,bounds.getHeight()/2);
        lineme[i] += ofPoint(xOffset, yOffset);
    }
    line = lineme;
    
    
    lineme = orig;
    for (int i = 0; i < lineme.size(); i++){
        lineme[i] -= ofPoint(centerSmoothed.x, 1080/2);
        lineme[i] *= scale;
        lineme[i] += ofPoint(bounds.getWidth()/2,bounds.getHeight()/2);
        lineme[i] += ofPoint(xOffset, yOffset);
    }
    lineOrig = lineme;
    
}

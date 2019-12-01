#include "mncScene2.h"
//---------------------------------------------------------------
void mncScene2::setup(){
    

}


//---------------------------------------------------------------
void mncScene2::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed

}


//---------------------------------------------------------------
void mncScene2::draw(){
    
    ofPolyline line = CT->resampleSmoothed.getResampledByCount(2000);

        float mirrors = 10;

        ofTranslate(0, -100);
        for (int i = 0; i < line.size(); i++) {
            float xOrigin = line[i].x;
            float yOrigin = line[i].y;
            float radius = 120;

            float theta = ofGetElapsedTimef() + i * (PI/15) * mirrors * 2;
            float offset = 2;
            float x = xOrigin + radius * sin(theta) * offset;
            float y = yOrigin + radius * sin(theta) * cos(theta) * offset;

        ofSetColor(255,255,255);
        ofDrawCircle(x, y, 5);
        }

    
}

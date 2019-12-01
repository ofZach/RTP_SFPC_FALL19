

#include "zaiScene.h"

//---------------------------------------------------------------
void zaiScene::setup(){
        ofSetCircleResolution(100);
        cam.enableOrtho(); // disable 3D scaling
         
        

}


//---------------------------------------------------------------
void zaiScene::update(){
    
}


//---------------------------------------------------------------
void zaiScene::draw(){
    
    ofPushMatrix();
     
    ofPolyline outline = CT->resampleSmoothed;
    
    
    
    //    ofEnableDepthTest();
        cam.begin();
        ofScale(1,-1,1);
        ofBackground(0);
        
    
        ofPoint centroid = outline.getCentroid2D();
    centerSmooth = 0.95 * centerSmooth + 0.05 * centroid;
    
        ofRotateYDeg((centerSmooth.x - ofGetWidth()/2 )*1.0 );
        ofRotateXDeg((centerSmooth.y - ofGetHeight() / 2)*1.0 );
//        ofRotateZDeg( 10);
    
    
    
    //
    //    ofRotateXDeg(ofGetElapsedTimef());
    //    ofRotateXDeg(ofGetElapsedTimef() / 2);
    //    ofRotateYDeg(ofGetElapsedTimef() / 4);
    //    ofScale(1 - (0.005* ofGetElapsedTimef()));
        
        float smallR = 8; // rad of thinnest circles
        float medFactor = 5; // factor to multiple smallR by for medium lines
        float largeFactor = 10; // factor to multiple smallR by for thickest lines
        float largestRad = (smallR * medFactor * largeFactor) ; // size of biggest circle
        float centerX = ofGetWidth()/2;
        float centerY = ofGetHeight()/2;
        float time = ofGetElapsedTimef()/5;
        float thetaMap = 2*PI / 36;
        
        
        ofTranslate(-centerX, -centerY);
        
        
        // CIRCLES
        ofNoFill();
        ofSetColor(200);
        
        for(int i = 0; i < 50; i++ ) {
            
            // draw 5 thickest lines - every 10 thin circles
            if(i < 6) {
                ofSetLineWidth(3);
                ofDrawCircle(centerX, centerY, i*smallR*largeFactor, smallR * largeFactor * i);
            }

            // draw 10 med-thick lines - every 5 thin circles
            if(i < 11) {
                ofSetLineWidth(2);
                ofDrawCircle(centerX, centerY,  i*smallR*medFactor, smallR * medFactor * i);
            }

            // draw 50 thin circles - every 8px
            if(i <= 50) {
                ofSetLineWidth(1);
                ofDrawCircle(centerX, centerY,  i*smallR, smallR * i);
            }
            
        }
        
        
        
        
        // LINES
        
        for(int i = 0; i < 36; i++ ) {
            
            ofSetColor(100);
            
            float angle = ofMap(i, 0, 36, 0, 2 * PI);
            float oneDeg = 0.0055555555556 * PI; // 1 degree to radians
            
            
            // 36 thickest lines from smallR to edges
            
            ofSetLineWidth(2);
            ofDrawLine(centerX + cos(angle) * largestRad, // x1
                       centerY + sin(angle) * largestRad, // y1
                       centerX + cos(angle) * smallR, // x2
                       centerY + sin(angle) * smallR); // y2
     
            
            // 36 med-thick lines from largest circle to 7th largest circle. lines are shifted 5 degrees from thickest lines.
            
            float radSeven = 160; // size of 7th largest circle
            ofSetLineWidth(2);
            ofDrawLine(centerX + cos(angle + oneDeg*5) * largestRad, //x1
                       centerY + sin(angle + oneDeg*5) * largestRad, // y1
                       -50,
                       centerX + cos(angle + oneDeg*5) * radSeven, // x2
                       centerY + sin(angle + oneDeg*5) * radSeven, // y2
                       -50); // y2
            
            
            // 360 (36 x 10) thin lines from largest circle to 7th largest circle. lines are shifted 1 degree.
            
            ofSetLineWidth(1);
            
            for (int j = 0; j < 10; j++) {
                ofDrawLine(centerX + cos(angle + oneDeg*j) * largestRad, //x1
                       centerY + sin(angle + oneDeg*j) * largestRad, // y1
                       centerX + cos(angle + oneDeg*j) * radSeven, // x2
                       centerY + sin(angle + oneDeg*j) * radSeven); // y2
            }
            
            
            // 180 (36 * 5)  thin lines from 7th largest circle to 9th largest circle. lines are shifted 2 degrees.
            
            float radNine = 80; // size of 7th largest circle
            
            for (int j = 0; j < 5; j++) {
                ofDrawLine(centerX + cos(angle + oneDeg*j*2) * radSeven, //x1
                           centerY + sin(angle + oneDeg*j*2) * radSeven, // y1
                           -150, // z1
                           centerX + cos(angle + oneDeg*j*2) * radNine, // x2
                           centerY + sin(angle + oneDeg*j*2) * radNine, // y2
                           -150); // z2
            }
            
            
            // 72 (36 * 2) thin lines from 9th largest circle to 10th. lines are shifted 2 degrees.
            
            float radTen = 40; // size of 7th largest circle
            
            for (int j = 0; j < 2; j++) {
                ofDrawLine(centerX + cos(angle + oneDeg*j*5) * radTen, //x1
                           centerY + sin(angle + oneDeg*j*5) * radTen, // y1
                           centerX + cos(angle + oneDeg*j*5) * radNine, // x2
                           centerY + sin(angle + oneDeg*j*5) * radNine); // y2
            }
            
            
            
        }
    
    
        
        ofPushMatrix();
            ofSetColor(0, 0, 0);
    //        ofRotateYDeg(170);
        
        
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        
         
        
        
        
     
        
        ofPopMatrix();
        
        
        
        
        // LARGE RECTANGLE
        ofNoFill();
        ofSetColor(255);
        ofSetLineWidth(3);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        
        
//        CT->resampleSmoothed.draw();
    
    ofPopMatrix();
    cam.end();
    
    
}

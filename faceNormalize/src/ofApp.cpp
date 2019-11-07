#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640,480);
    tracker.setup();
    
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
    if (grabber.isFrameNew()){
        tracker.update(grabber);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    //grabber.draw(0,0);
    //tracker.drawDebug();
    
    if (tracker.size() > 0){
        ofPolyline leye = tracker.getInstances()[0].getLandmarks().getImageFeature(ofxFaceTracker2Landmarks::LEFT_EYE);
        
        //leye.draw();
        ofPoint lavg;
        for (int i = 0; i < leye.size(); i++){
            lavg += leye[i];
        }
        lavg /= (float)leye.size();
        //ofCircle(lavg,5);
        
        
        // right
        
         ofPolyline reye = tracker.getInstances()[0].getLandmarks().getImageFeature(ofxFaceTracker2Landmarks::RIGHT_EYE);
        
        ofPoint ravg;
        for (int i = 0; i < reye.size(); i++){
            ravg += reye[i];
        }
        ravg /= (float)reye.size();
        //ofCircle(ravg,5);
        
        //ofDrawLine(lavg, ravg);
        
        // comment these lines more :) 
        ofPoint diff = ravg - lavg;
        float angle = atan2(diff.y, diff.x);
        float length = diff.length();
        float scale = 300.0 / length;
        
        ofPushMatrix();
        ofTranslate(300,300);
        grabber.setAnchorPoint(lavg.x, lavg.y);
        ofRotateZRad(-angle);
        ofScale(scale,scale);
        grabber.draw(0,0);
        ofPopMatrix();
        
        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

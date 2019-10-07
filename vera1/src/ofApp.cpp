#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    ofBackground(0);
    float w = (750-50) / 5.0;
    float h = (750-50) / 5.0;
    ofNoFill();
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSeedRandom(mouseX * 1000);
    
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            
            float x = ofMap(i, 0, 5, 50, 750);
            float y = ofMap(j, 0, 5, 50, 750);
            
            //ofDrawRectangle(x,y,w,h);
            for (int k = 0; k < 10; k++){
                float rectWidth = ofMap(k, 0, 10, 8, w);
                
                if (ofRandom(0,1) < .99){
                    ofDrawRectangle(x + w/2,
                                    y + h/2,
                                    rectWidth,
                                    rectWidth);
                }
            }
            
        }
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

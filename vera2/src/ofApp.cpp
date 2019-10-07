#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);
    ofSetColor(0);
    
    ofSeedRandom(264*1000);
    cout << mouseX << endl;
    
    
    for (int i = 0; i < 40; i++){
        for (int j = 0; j < 40; j++){
            
            float x = ofMap(i, 0, 40, 50, 750);
            float y = ofMap(j, 0, 40, 50, 750);
            
            if (ofNoise(i*0.09, j*0.09, mouseX*0.01) < .85){
                ofPushMatrix();
                ofTranslate(x,y);
                ofRotateZ(ofRandom(0,360));
                ofDrawLine(0-15,0,0+15, 0);
                ofPopMatrix();
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

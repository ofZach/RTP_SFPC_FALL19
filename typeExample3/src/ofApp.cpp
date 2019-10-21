#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("framd.ttf", 100, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofEnableDepthTest();
 
    //cam.enableOrtho();
    
    
    ofBackground(0);
//    cam.begin();
//    ofDrawAxis(100);
//    ofSetColor(255);
//    font.drawStringAsShapes("hello",0,0);
//    ofPushMatrix();
//    ofRotateYDeg(90);
//    ofSetColor(255,0,0);
//    font.drawStringAsShapes("world",0,0);
//    ofPopMatrix();
//    cam.end();
    
    
    cam.begin();
    
    ofPushMatrix();
    ofScale(1,-1,1);
    
    ofDrawAxis(100);
    ofSetColor(255);
    
    vector < ofPath > paths =
    font.getStringAsPoints("hello");
    for (int i = 0; i < paths.size(); i++){
        paths[i].draw();
    }
    
    //font.drawStringAsShapes("hello",0,0);
    ofPushMatrix();
    ofRotateYDeg(90);
    ofSetColor(255,0,0);
    
    
    paths =
    font.getStringAsPoints("world");
    for (int i = 0; i < paths.size(); i++){
        paths[i].draw();
    }
    
    ofPopMatrix();
    
    ofPopMatrix();
    cam.end();
    
    
    //font.drawString("hello",300,300);
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

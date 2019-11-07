#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    panel.setup();
    panel.add(radius.set("radius", 50, 0, 100));
    panel.add(yPos.set("yPos", 150, 0, 1000));
    panel.add(xPos.set("xPos", 150, 0, 1000));
    panel.add(circleResolution.set("res", 100, 1, 200));
    
    
    panel.loadFromFile("settings.xml");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    ofSetCircleResolution(circleResolution);
    ofDrawCircle(xPos, yPos, radius);
    
    panel.draw();
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

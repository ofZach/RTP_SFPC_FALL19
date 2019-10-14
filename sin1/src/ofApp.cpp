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
    
    // cout << sin(ofGetElapsedTimef()) << endl;
    
    // freq!
    
    float x = ofMap(sin(ofGetElapsedTimef()*2),-1,1,0,800 );
    ofDrawCircle(x,400,50);
    
    float x2 = ofMap(sin(ofGetElapsedTimef()*1),-1,1,0,800 );
    ofDrawCircle(x2,200,50);
    
    float x3 = ofMap(sin(ofGetElapsedTimef()*3),-1,1,0,800 );
    ofDrawCircle(x3,600,50);
    
    
    // phase
    /*
    float x = ofMap(sin(ofGetElapsedTimef()),-1,1,0,800 );
    ofDrawCircle(x,400,50);
    
    float x2 = ofMap(sin(ofGetElapsedTimef()+1),-1,1,0,800 );
    ofDrawCircle(x2,200,50);
    
    float x3 = ofMap(sin(ofGetElapsedTimef()+2),-1,1,0,800 );
    ofDrawCircle(x3,600,50);
     */
    
    // amplitude
    
    /*
    float x = ofMap(sin(ofGetElapsedTimef()),-1,1,0,800 );
    ofDrawCircle(x,400,50);
    
    float x2 = ofMap(sin(ofGetElapsedTimef()),-1,1,300,500 );
    ofDrawCircle(x2,200,50);
    
    float x3 = ofMap(sin(ofGetElapsedTimef()),-1,1,200,600 );
    ofDrawCircle(x3,600,50);
     */
     
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

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    player.load("input.mov");
    player.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    player.update();
    if (player.isFrameNew()){
        finder.setMinArea(10);
        finder.setThreshold(127);
        finder.findContours(player);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofScale(2,2);
    
    player.draw(0,0);
    //finder.draw();
    
    
    if (finder.size() > 0){
        ofPolyline line = finder.getPolyline(0);
        ofPoint top;
        for (int i = 0; i < line.size(); i++){
            if (i == 0) top = line[i];
            else if (line[i].y < top.y){
                top = line[i];
            }
        }
        ofSetColor(255,0,0);
        ofDrawCircle(top, 3);
        trail.addVertex(top);
        if (trail.size() > 100){
            trail.getVertices().erase(trail.getVertices().begin());
        }
        trail.draw();
        ofSetColor(255);
        
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

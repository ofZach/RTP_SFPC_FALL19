#include "ofApp.h"

// Goal:
// 
//

//--------------------------------------------------------------
void ofApp::setup(){

    // Load the input sample video
    player.load("input.mov");
    player.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Advance the video player
    player.update();
    
    // If it is a new frame
    if (player.isFrameNew()){
        
        // Set some settings for the contour finder
        finder.setMinArea(10); // We only keep track of contours that are big enough.
        finder.setThreshold(127); // Use 127 as the threshold for finding contours. 127 is halfway between white and black
        
        // Find the contours in the current video frame
        finder.findContours(player);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    // Draw the video player
    player.draw(0,0);
    //finder.draw();
    
    ofTranslate(player.getWidth(), 0);
    ofScale(2,2);
    
    // If we have found a contour
    if (finder.size() > 0){
        
        // Get the first contour
        ofPolyline line = finder.getPolyline(0);
        
        // Make line pretty. Smooth it.
        line = line.getResampledBySpacing(1);
        line = line.getSmoothed(3);
        
        // Keep track of a trail of the past 100 contours
        lines.push_back(line);
        if (lines.size() > 100){
            lines.erase(lines.begin());
        }
        
        
    }
    
    // Draw the past 100 contours detected.
    for (int i = 0; i < lines.size(); i++){
        lines[i].draw();
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

#include "ofApp.h"


// Goal: Draw a trail of the top point in a contour body over time.
// 
// player: Demo video player. input.mov is a white figure on a black background.
// finder: our contour finder, which will find the white figure in our input mov
// trail: an ofPolyline that keeps track of the top point of the contour. We draw this trail in red.
//
// Still confused by:
// We should've setSortBySize = True for the finder, to make sure we grab the biggest contour. bc it's only coincidence that our input.mov has one white figure.
//
//--------------------------------------------------------------
void ofApp::setup(){

    // Use the demo video, so we don't need to get up and walk in front of the camera every time we need to test.
    player.load("input.mov");
    player.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    player.update();
    
    // If there is a new frame
    // We only need to do this bc OpenFrameworks might be faster than the demo video frame rate.
    if (player.isFrameNew()){
        
        
        finder.setMinArea(10); // Only look at contours that are big/signficant enough
        finder.setThreshold(127); // 127 bc it is halfway between 0 and 255
        finder.findContours(player);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofScale(2,2);
    
    // Draw the demo video input, as is.
    player.draw(0,0);
    //finder.draw();
    
    // If the ContourFinder has found at least one contour
    if (finder.size() > 0){
        
        // Get the biggest contour / white area
        ofPolyline line = finder.getPolyline(0);
        
        // Find the top point of the contour body.
        // This is so we can draw with it later.
        ofPoint top;
        
        // For each point in the contour line,
        for (int i = 0; i < line.size(); i++){
            if (i == 0) top = line[i]; // Initialize the current top
            // If the current point is higher than the current top, make it the new top
            else if (line[i].y < top.y){
                top = line[i];
            }
        }
        
        // Draw in red, a circle at the top point of the contour
        ofSetColor(255,0,0);
        ofDrawCircle(top, 3);
        
        // Keep a polyline called `trail` of the past 100 top points/
        trail.addVertex(top);
        if (trail.size() > 100){
            // Erase the oldest top point if our trail gets too long
            trail.getVertices().erase(trail.getVertices().begin());
        }
        
        // Draw the trail in red.
        trail.draw();
        
        // Set drawing color back to white.
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

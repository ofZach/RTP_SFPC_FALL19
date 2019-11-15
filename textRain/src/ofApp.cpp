#include "ofApp.h"

//
// Objective: Recreate textRain, where falling dots rest on the top edges of objects.
// https://www.youtube.com/watch?v=f_u3sSffS78
//
// Steps:
//  * Draw 100 dots along the top of the screen.
//  * Threshold the webcam input on brightness, so that we have a clear binary test to tell each   dot to keep moving, or stop. Store this thresholded image as an ofImage.
//  * For each dot:
//       - If the dot is on a light pixel of the thresholded image, then have the dot keep falling.
//       - Otherwise, if the pixel is dark, then the dot is somewhere where it shouldn't be (because it is inside the object it should be resting on!) and we need to move it to the next "empty space" / white pixel above it. You do this by making a for loop that starts at the dot's -y-position, and you look upward until you find the next white spot, and then set the dot's y-position to the white spot's y-position.
////--------------------------------------------------------------
void ofApp::setup(){

    // Setup the video input stream
    grabber.setup(640,480);
    
    // Make a space in memory for a thresholded image frame of the video input
    threshold.allocate(640,480, OF_IMAGE_GRAYSCALE);
    
    // Set up 100 dots along the top of the screen.
    for (int i = 0; i < 100; i++){
        ofPoint pt;
        pt.x = ofMap(i, 0, 100, 0, grabber.getWidth());
        pt.y = 0;
        pts.push_back( pt  );
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    
    for (int x = 0; x < grabber.getWidth(); x++){
         for (int y = 0; y < grabber.getHeight(); y++){
             ofColor color = grabber.getPixels().getColor(x,y);
             if (color.getBrightness() > mouseX){
                 threshold.setColor(x,y,ofColor::white);
             } else {
                 threshold.setColor(x,y,ofColor::black);
             }
         }
    }
    threshold.update();
    
    //  For each dot:
    for (int i = 0; i < pts.size(); i++){
        
        ofColor color = threshold.getColor(pts[i].x, pts[i].y);
        
    //  If the dot is on a light pixel of the thresholded image, then have the dot keep falling.
        if (color.getBrightness() > 127){
            pts[i].y += 1; //green light
        } else {
//  Otherwise, if the pixel is dark, then the dot is somewhere where it shouldn't be (because it is inside the object it should be resting on!) and we need to move it to the next "empty space" / white pixel above it. Look upward until you find the next white spot, and put the dot there.
            
            // Start at the dot, and look at the pixels above it
            for (int y = pts[i].y; y >= 0; y--){
                
                // Get the color of the pixel above the dot that you're examining
                ofColor color2 = threshold.getColor(pts[i].x, y);
                
                // If it's white,
                if (color2.getBrightness() > 127){
                    // yay, white spot found!
                    // Put the dot here.
                    pts[i].y = y;
                    break;
                }
            }
            
            ; // red light
        }
        
        // Make the dots loop. When they hit the ground, they respawn at the top of the screen.
        if (pts[i].y >= grabber.getHeight()){
            pts[i].y = 0;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // Draw the video stream.
    grabber.draw(0,0);
    
    // Next to it, draw the thresholded img.
    threshold.draw(grabber.getWidth(), 0);
    
    // Draw all the dots in red.
    ofSetColor(255,0,0);
    for (int i = 0; i < pts.size(); i++){
        ofDrawCircle(pts[i], 3);
    }
    
    // Set drawing color back to white.
    ofSetColor(255);
    
    
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

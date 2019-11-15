#include "ofApp.h"

// Goal: Draw an outline Contour of a human body / the largest  object in the videostream.
//
// Steps:
// (1) grabber: Take video input from grabber.
// (2) ofImage `grayscale`: Take the current img from the video stream, and convert it to grayscale.
// (3) ofImage `background`: On keypress, capture the background image.
// (4) ofImage `diff`: Find the difference between the grayscale video img, and the background img.
// (5) ofxCv::ContourFinder `finder`: Use helpful robot from the ofxCv library that can find contours for us, and tell it to find contours in our difference img. We tell the robot to order its list of contours from biggest to smallest, and then tell it to give us the biggest one.
// (6) We draw the biggest contour from the difference image on the video input.
//
//--------------------------------------------------------------
void ofApp::setup(){

    // Setup the video input of 640px x 480px
    grabber.setup(640,480);

    // Make a space in memory for an ofImage called `grayscale`. Make it an image of the same size as the grabber's video input.
    // We use OF_IMAGE_GRAYSCALE because a grayscale img will take up different amt of memory than an rgb one.
    grayscale.allocate(grabber.getWidth(),grabber.getHeight(), OF_IMAGE_GRAYSCALE);
    
   // Make a space in memory for an ofImage called `background`.
background.allocate(grabber.getWidth(),grabber.getHeight(), OF_IMAGE_GRAYSCALE);
    
    // We set bLearnBackground to true initially, so we have a background img already set on start, when we initially run the program.
    bLearnBackground = true;
}

//--------------------------------------------------------------
void ofApp::update(){

    // Get new video input. If you don't do this, you won't get new video data!
    grabber.update();
    
    // ofxCv::convertColor this is a function from the ofxCv library.
    // This function converts the image `grabber` to grayscale, and puts it in the ofImage `grayscale`.
    // `CV_RGB2GRAY` is a special keyword telling it to do the transformation: change from RGB to grayscale.
    convertColor(grabber, grayscale, CV_RGB2GRAY);
    
    // bLearnBackground = 'boolean learn background'. This `b` thing is a naming scheme for booleans. Another naming suggestion from the group was `shouldCaptureBackground`.
    // This is a boolean flag that will be used to capture the background image on keypress.
    //
    if (bLearnBackground == true){
        // Assign all the pixels in the ofImage `background` to all the pixels in the ofImage `grayscale`.
        background.setFromPixels(grayscale.getPixels());
        bLearnBackground = false;
    }
    
    // ofxCv::absdiff This is a function from the ofxCv library.
    // This function subtracts the two images `grayscale` and `background`, and puts the result in `diff:
    // `diff` = abs(`grayscale` - `background`)
    // An important nuance here is why we use *abs*diff, which takes the *absolute value* of the difference. We do this (and not just a regular substraction), because we care about any difference- the direction of the difference does not matter.
    // For example, if a light object is on a dark background, we want that to be picked up. If a dark object is on a light background, that should also be picked up.
    absdiff(grayscale, background, diff);
    
    // ofxCv::threshold This is a function from the ofxCv library.
    // According to a threshold, make dark pixels in `diff` and make them all black, and make light pixels white.
    // mouseX to adjust the threshold
    threshold(diff, mouseX);
    
    // "Save" the changes you've put in your ofImage containers.
    diff.update();
    background.update();
    grayscale.update();
    
    // ofxCv ContourFinder
    // `finder` is a helpful robot from the ofxCv library that can find contours for us!
    finder.setSortBySize(true); // Hey robot, while you're finding the contours, sort the contours by biggest first.
    finder.findContours(diff); // Find the white blobs in `diff`.
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofScale(0.7, 0.7); // Don't draw too big, so we draw at 70%.
    
    // Draw video input at top left.
    grabber.draw(0,0);
    
    // Draw grayscale image at top right.
    grayscale.draw(grabber.getWidth(), 0);
    
    // Draw background img in bottom left.
    background.draw(0,grabber.getHeight());
    
    // Draw diff img in bottom right.
    diff.draw(grabber.getWidth(), grabber.getHeight());
    
    
    // If the helpful robot `finder` has found any contours to give us,
    if (finder.size() > 0){
        
        // Get the first contour in the list-- the biggest contour. `finder` has a list of all the contours in the image, stored as polylines.
        ofPolyline line = finder.getPolyline(0);
        
        // Draw the biggest contour.
        // Note: the contour is drawn on the top left img (the video input), even though the contour is taken from the bottom right img (the diff img).
        line.draw();
        
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // When a key is pressed, capture a new background img.
    bLearnBackground = true;
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

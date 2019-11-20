#pragma once

#include "ofMain.h"
#include "ofxCv.h"

using namespace ofxCv;


class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();

        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    
    
        ofVideoGrabber grabber; // Video input
        ofImage grayscale; // An ofImage that is the video input's current image, but converted to grayscale.
        ofImage background; // An ofImage that we will put the  background image in, also grayscale.
        ofImage diff; // Difference image between the above grayscale and background images.
        bool bLearnBackground = false; // This is a boolean flag that will be used to capture the background image on keypress.
        ContourFinder finder; //ofxCv ContourFinder: a helpful robot from the ofxCv library that can find contours for us!
    
};

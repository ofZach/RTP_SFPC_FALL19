#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "contourTracker.h"
#include "sceneManager.h"
#include "baseScene.h"
#include "inputManager.h"
#include "contourFramer.h"



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
		
    
        inputManager            IM;
        contourTracker          CT;
        sceneManager            SM;
        contourFramer           CF;
    
    
        bool bDrawDebug;

        ofPoint rectPosSmoothed;
        float rectWidthSmoothed;
        float noPersonEnergy;

        ofTrueTypeFont font;

        ofTrueTypeFont font2;

        int nFramesInScene = 0;

        bool bOkToChangeOnStepOut = false;
        ofParameter < float > scale;
        ofParameter < float > xOffset;
        ofParameter < float > yOffset;
        ofParameter < float > centerSmoothing;
        ofParameter < ofPoint > pts[4];
    
        ofParameterGroup group;
        ofxPanel panel;
    
    
    
    
        ofFbo mainFbo;
    bool bPresentationMode = false;
    
    ofVideoPlayer bodyVid;
    
    ofTrueTypeFont font3;
    
    
};

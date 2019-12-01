#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ctmf.h"
#include "ofxGui.h"



//#include "ofxKinect.h"

#include "ofxKinectV2.h"



using namespace milton;

//#define USE_VIDEO

#ifdef USE_VIDEO
#define INPUT_W 320
#define INPUT_H 240
#else
//#define INPUT_W 640
//#define INPUT_H 480

#define INPUT_W 512
#define INPUT_H 424

#endif

class inputManager {
    
public:
    
    void setup();
    void update();
    void draw();
    
    void changeMovie( string fileName);
    
    
#ifdef USE_VIDEO
    ofVideoPlayer player;
#else
//    ofxKinect kinect;
//    ofTexture texDepth;
//    ofTexture texRGB;
    
    shared_ptr<ofxKinectV2>  kinect;
    ofTexture texDepth;
    ofTexture texRGB;
    
    
    ofImage maxDepthLearned;
    
    bool bLearningBg;
    int nFramesLearning;
    void learn(){
        bLearningBg = true;
        nFramesLearning = 0;
        for (int i= 0; i < maxDepthLearned.getWidth(); i++){
            for (int j = 0; j < maxDepthLearned.getHeight(); j++){
                maxDepthLearned.setColor(i,j, ofColor::black);
            }
        }
    }
    
    bool bPreLearn = false;
    float startPreLearnTime = 0;
     ofParameter < bool > learnBG;
    
    
#endif
    
    
    bool bIsFrameNew = false;
    
    
    // I basically have a contour that represents the blob on this frame.
    
    bool bFoundABlobThisFrame;
    unsigned char * thresholdedImage;
    unsigned char * graypixels;
    unsigned char * medianFiltered;
    
    
    
    ofImage medianFilteredResult;
    
    ofxCv::ContourFinder finder;
    
    ofParameterGroup group;
    ofParameter < int > threshold;
    
    #ifndef USE_VIDEO
        ofParameter < int > threshold2;
       ofParameter < bool > bUseBothThresholds;
      ofParameter < int > distanceFromBg;
    #endif
    
    ofParameter < int > minBlobSize;
    
    ofParameter < int > medianFilterAmount;
    ofParameter < float > speed;
    ofxPanel panel;
    
    
    
    
    
};

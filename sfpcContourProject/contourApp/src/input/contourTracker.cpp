

#include "contourTracker.h"

//---------------------------------------------------------------
void contourTracker::setup(){
}


//---------------------------------------------------------------
void contourTracker::analyze( ofPolyline & curFrame ){
    
    
    ofPolyline line = curFrame;
 
    
    // A++ if you fix getResampledByCount end points !
    //
    
    ofPolyline resampled = line.getResampledByCount( 180);
    
    while(resampled.size() < 180){
        resampled.getVertices().push_back(resampled[resampled.size()-1]);
    }
    
 
    if (prevFrameOrig.size() > 0){
        
        // if you want to make this faster
        // you will get an A +
        // this is pretty slow :(
        // but it works.
        
        int smallestStart = -1;
        float smallestAvgLen = 10000000;
        
        for (int i = 0; i < 180; i++){
            
            float avgLen = 0;
            for (int j = 0; j < 180; j++){
                avgLen += ((ofPoint)resampled[ (j + i ) % 180] - (ofPoint)prevFrameOrig[j]).length() / 180.0;
            }
            if (avgLen < smallestAvgLen){
                smallestAvgLen = avgLen;
                smallestStart = i;
            }
            
        }
        
        ofPolyline temp;
        for (int i = 0; i < 180; i++){
            temp.addVertex( resampled[ (i + smallestStart) % 180]);
        }
        resampled = temp;
        
        
        
    }
    
    ofPolyline tempT = resampled.getResampledByCount(100);
    
    while(tempT.size() < 100){
        tempT.getVertices().push_back(tempT[tempT.size()-1]);
    }
    
    if (resampleSmoothedOrig.size() == 0){
        resampleSmoothedOrig = tempT;
    } else {
        for (int i = 0; i < 100; i++){
            resampleSmoothedOrig[i] = 0.55f * resampleSmoothedOrig[i] + 0.45f * tempT[i];
        }
    }
    
    for (auto p : resampleSmoothedOrig.getVertices()){
        
        unsigned int nearestIndex = 0;
        resampled.getClosestPoint(p, &nearestIndex);
        
        
    }
    
    
    prevFrameOrig = resampled;

}


//---------------------------------------------------------------
void contourTracker::draw(){
}

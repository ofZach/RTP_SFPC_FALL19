

#include "franScene.h"

//---------------------------------------------------------------
void franScene::setup(){
    

}


//---------------------------------------------------------------
void franScene::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed

}


//---------------------------------------------------------------
void franScene::draw(){
    // CT->resampleSmoothed.draw();
    history.push_back(CT->resampleSmoothed);
    
    ofPolyline outline = CT->resampleSmoothed;
    
    ofPath path;
    
    for(int i = 0; i < outline.getVertices().size(); i++) {
        if(i == 0) {
            path.newSubPath();
            path.moveTo(outline.getVertices()[i] );
        } else {
            path.lineTo(outline.getVertices()[i] );
        }
    }
    
    
    path.close();
 //   path.simplify();
    
     history_paths.push_back(path);
    
//    path.draw();
    
//    if (history.size() > 10) {
//        history.erase(history.begin());
//    }
    
    if (history_paths.size() > 10) {
        history_paths.erase(history_paths.begin());
    }
    
   // ofGetWidth();;
    
    
    for (int i = 0; i < history_paths.size(); i++) {
        
//        ofSetColor()
       // ofColor(255.0 / (float)history_paths.size());
        
        // ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        ofColor fill = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
        ofPath path = history_paths[i];
        path.setFillColor(fill);
        path.draw();

    }

//
//    for (int i = 0; i < history.size(); i++) {
//        for (int j = 0; j < history[i].size(); j++) {
//            ofPoint p = history[i].getNormalAtIndex(j);
//
//
//            // make the outline fatter
//            history[i][j] += p*ofGetMouseX()/5;
//
//
//        }
//        history[i].draw();
//
//    }
    
    
   
    
//    ofPoint center = outline.getCentroid2D();
//    float r = ofMap(sin(ofGetElapsedTimef()), -1, 1, 5, 20);
//    ofDrawCircle(center.x + 30, center.y - 120, r);
    
}

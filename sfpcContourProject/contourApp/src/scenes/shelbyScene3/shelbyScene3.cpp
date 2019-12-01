#include "shelbyScene3.h"

//---------------------------------------------------------------
void shelbyScene3::setup(){
    ofSeedRandom(1);
}


//---------------------------------------------------------------
void shelbyScene3::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed

}


//---------------------------------------------------------------
void shelbyScene3::draw(){
    ofVec3f v;
    v.set(ofRandom(ofGetWidth()), 1, ofRandom(160) - 80);
    history.push_back(v);
    
    for (int i; i < history.size(); i += 1) {
        ofPushMatrix();
        ofTranslate(0, 0, history[i].z);
        ofDrawCircle(history[i].x, history[i].y, 3);
        ofPopMatrix();
        
        if (!CT->resampleSmoothed.inside(history[i].x, history[i].y)) {
            history[i].y += 2;
        } else {
            history[i].y -= 2;
        }
    }
    
    if (history[0].y >= ofGetHeight() + 100) {
        history.erase(history.begin());
    }
}

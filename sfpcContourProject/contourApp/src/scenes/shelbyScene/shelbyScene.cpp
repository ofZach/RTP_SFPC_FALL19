

#include "shelbyScene.h"

//---------------------------------------------------------------
void shelbyScene::setup(){

}


//---------------------------------------------------------------
void shelbyScene::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed

}


//---------------------------------------------------------------
void shelbyScene::draw(){
    
    for (int i = 0; i < CT->resampleSmoothed.size(); i += 1) {
        ofPolyline l;

        l.addVertex(0, ofMap(sin(ofGetElapsedTimef()/3), -1, 1, 0, ofGetHeight()));

        l.addVertex(CT->resampleSmoothed[i].x, CT->resampleSmoothed[i].y);

        l.addVertex(ofGetWidth(), ofMap(sin(ofGetElapsedTimef()/3), -1, 1, 0, ofGetHeight()));

        l = l.getResampledByCount(100);
        l = l.getSmoothed(11);
        l.draw();

    }
}

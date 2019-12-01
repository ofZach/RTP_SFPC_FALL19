#include "giaScene.h"

//---------------------------------------------------------------
void giaScene::setup(){

}


//---------------------------------------------------------------
void giaScene::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed

}


//---------------------------------------------------------------
void giaScene::draw(){
    
    
    //CT->resampleSmoothed.draw();
//
//    history.push_back(CT->resampleSmoothed);
//    if (history.size() > 50) {
//        history.erase(history.begin());
//    }
//
//    for (int historyIndex = 0; historyIndex < history.size(); historyIndex++) {
//        for (int lineIndex = 0; lineIndex < history[historyIndex].size(); lineIndex++){
//            history[historyIndex][lineIndex].z += 20;
//
//            ofPoint p = history[historyIndex].getNormalAtIndex(lineIndex);
//            ofSetColor(242, 141, 212);
//            ofDrawLine(
//                       CT-> resampleSmoothed[lineIndex].x,
//                       CT-> resampleSmoothed[lineIndex].y,
//                       CT-> resampleSmoothed[lineIndex].x + p.x * 10,
//                       CT-> resampleSmoothed[lineIndex].x + p.y * 10);
//
//        }
//    }
//
//
//    circles example --------------------------------------------------
    for (int i=0; i<CT -> resampleSmoothed.size(); i++) {
        ofSetColor(242, 141, 212);
        ofDrawCircle(
            CT ->resampleSmoothed[i].x,
            CT ->resampleSmoothed[i].y, 2);
         ofDrawLine(
                    ((ofGetWidth())/2) +(CT ->resampleSmoothed[i].x / 5) , 0,
                    CT ->resampleSmoothed[i].x, CT ->resampleSmoothed[i].y);
    }

}

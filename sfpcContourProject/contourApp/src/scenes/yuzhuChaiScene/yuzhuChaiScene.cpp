

#include "yuzhuChaiScene.h"

//---------------------------------------------------------------
void yuzhuChaiScene::setup(){
    

}


//---------------------------------------------------------------
void yuzhuChaiScene::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed
    
    

}


//---------------------------------------------------------------
void yuzhuChaiScene::draw(){
    
    
//    CT->resampleSmoothed.draw();
    
//    history.push_back(CT->resampleSmoothed);
    
    ofPoint center = CT->resampleSmoothed.getCentroid2D();

    
    for (int i = 0; i < CT->resampleSmoothed.size(); i++){
        ofPoint pt;
        pt.x = center.x;
        pt.y = center.y-100;
        history.push_back(pt);
    }
    
    for (int i = 0; i < history.size(); i++){
        
            history[i].x += ofRandom(-30, 30);
            history[i].y += ofRandom(-30, 30);

        if (!CT->resampleSmoothed.inside(history[i].x, history[i].y)){
            history[i].y = CT->resampleSmoothed[i].y;
            history[i].x = CT->resampleSmoothed[i].x;
            ofSetColor(ofColor :: blueSteel);
            ofDrawBitmapString("outside", history[i].x, history[i].y);
            history.erase(history.begin());
        } else {
            ofSetColor(ofColor :: pink);
            ofDrawBitmapString("inside", history[i].x, history[i].y);
        }
    }
    
    
    
    
}

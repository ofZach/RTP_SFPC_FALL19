

#include "noiseScene.h"

//---------------------------------------------------------------
void noiseScene::setup(){
    

}


//---------------------------------------------------------------
void noiseScene::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed

}


//---------------------------------------------------------------
void noiseScene::draw(){
    
    //cout << CT->resampleSmoothed.size() << endl;
    
    //CT->resampleSmoothed.draw();
   
    for (int i = 0; i < CT->resampleSmoothed.size(); i++){
        float radius = ofSignedNoise(CT->resampleSmoothed[i].x*0.001,
                                     CT->resampleSmoothed[i].y*0.001,
                                     ofGetElapsedTimef()*0.1) * 50;
        ofDrawCircle(CT->resampleSmoothed[i], radius);
    }
}

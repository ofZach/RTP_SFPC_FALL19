

#include "spikeScene.h"

//---------------------------------------------------------------
void spikeScene::setup(){
    

}


//---------------------------------------------------------------
void spikeScene::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed

}


//---------------------------------------------------------------
void spikeScene::draw(){
    CT->resampleSmoothed.draw();

    for (int i = 0; i < CT->resampleSmoothed.size(); i++){
      // the normal is a vector at a right angle to the curve
      // this vector has a length of 1
      ofPoint normal = CT->resampleSmoothed.getNormalAtIndex(i);
      
      // we draw the vector relative to the vertex
      ofDrawLine(
                 // start at the vertex...
                 CT->resampleSmoothed[i],
                 // ...end at normal * 50 (scales line by 50 pixels)
                 CT->resampleSmoothed[i] + normal * 50);
    }
}



#include "wavyScene.h"

//---------------------------------------------------------------
void wavyScene::setup(){
    

}


//---------------------------------------------------------------
void wavyScene::update(){

}


//---------------------------------------------------------------
void wavyScene::draw(){
    // loop over all vertices in the contour
    for (int i = 0; i < CT->resampleSmoothed.size(); i++) {
      // draw a circle at each vertex, but offset the x value in a wavy pattern
      ofDrawCircle(
                   CT->resampleSmoothed[i].x + sin(CT->resampleSmoothed[i].y / 20.0) * 20,
                   CT->resampleSmoothed[i].y,
                   5);
    }

    // here's an alternate version where we modify the polyline:
//    for (int i = 0; i < CT->resampleSmoothed.size(); i++) {
//      CT->resampleSmoothed[i].x += sin(CT->resampleSmoothed[i].y / 20.0) * 20;
//    }
//    CT->resampleSmoothed.draw();
}

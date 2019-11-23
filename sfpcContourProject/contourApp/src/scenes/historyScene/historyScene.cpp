

#include "historyScene.h"

//---------------------------------------------------------------
void historyScene::setup(){
    

}


//---------------------------------------------------------------
void historyScene::update(){

}


//---------------------------------------------------------------
void historyScene::draw(){
    // add the current contour to the back of our history vector
    history.push_back(CT->resampleSmoothed);
  
    // if we have over 50 saved contours in our history, erase the beginning
    if (history.size() > 50) {
      history.erase(history.begin());
    }
  
    // loop over every contour in our history...
    for (int i = 0; i < history.size(); i++) {
      // loop over every vertex of the contour...
      for (int j = 0; j < history[i].size(); j++) {
        // push the vertex forward (along the z axis)
        history[i][j].z += 20;
      }
      
      // draw the contour
      history[i].draw();
    }
}

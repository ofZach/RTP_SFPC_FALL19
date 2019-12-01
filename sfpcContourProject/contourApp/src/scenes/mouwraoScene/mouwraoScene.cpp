

#include "mouwraoScene.h"

//---------------------------------------------------------------
void mouwraoScene::setup(){
    

}


//---------------------------------------------------------------
void mouwraoScene::update(){
   
    //the info you want is here:
//    CT->resampleSmoothed

}


//---------------------------------------------------------------
void mouwraoScene::draw(){
  history.push_back(CT->resampleSmoothed);
  
  ofSetColor(200, 200, 110);
  ofNoFill();
  
  for (int i = 0; i < history.size(); i++){
    for (int j = 0; j < history[i].size(); j++){
      
      ofPoint p = history[i].getNormalAtIndex(j);
      int difX = history[i][j].x - history[i][j-3].x;
      int difY = history[i][j].y - history[i][j-3].y;

      int halfway = (history[i].size() / 2) - 10;
      
      if (j < halfway && j % 3 == 0 && difX > 20){

        ofDrawTriangle(history[i][j].x,
                     history[i][j].y - (difX*2),
                     history[i][j].x,
                     history[i][j].y- (cos(difX)+20),
                     history[i][j].x - 30,
                     history[i][j].y);
      }

      if (j < halfway&& j % 4 == 0 && difY > 20){
        ofDrawCircle(history[i][j].x + 90 + difX, history[i][j].y + difX, sin(difX) * 30);
      }
      
      if (j < halfway&& j % 12 == 0 && difX > 500){
        ofDrawCircle(history[i][j].x + (difX * 100), history[i][j].y - (difX * 100), sin(difX)*30);
      }
      if (difX > 2000){
        ofDrawTriangle(history[i][j].x, history[i][j].y, history[i][j].x + 90, history[i][j].y - 80, 500, 700);
      }
      if(difY > 2000){//history[i][j].y - history[i][j-3].y > 2000){
        ofDrawTriangle(history[i][j].x, history[i][j].y, history[i][j].x - 90, history[i][j].y - 90,700,700 );
      };
    }

    if(history.size() > 9){
      history.erase(history.begin());
    }
    
    history[i].draw();
  }
}

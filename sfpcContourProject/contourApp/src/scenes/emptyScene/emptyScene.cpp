

#include "emptyScene.h"

//---------------------------------------------------------------
void emptyScene::setup(){
    
    
    panel.setup("emptyScene", "emptySceneSettings.xml");
    
    panel.loadFromFile("emptyScene.xml");
    
    

}

void emptyScene::reset(){
    
}


//---------------------------------------------------------------
void emptyScene::update(){
   
    
}


//---------------------------------------------------------------
void emptyScene::draw(){
    
    
    CF->line.draw();
    
    //CT->resampleSmoothed.draw();
//    ofPoint avg;
//    for (int i = 0; i < CT->resampleSmoothed.size(); i++){
//        avg += CT->resampleSmoothed[i];
//    }
//    avg /= (float) CT->resampleSmoothed.size();
//    for (int i = 0; i < CT->resampleSmoothed.size(); i++){
//        ofLine(avg, CT->resampleSmoothed[i]);
//        ofPoint diff = CT->resampleSmoothed[i] - avg;
//        diff.normalize();
//        ofLine(CT->resampleSmoothed[i] + diff*0,
//               CT->resampleSmoothed[i] + diff*1000);
//
//    }
    
    
}

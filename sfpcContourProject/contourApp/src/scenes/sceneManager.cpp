

#include "sceneManager.h"

//---------------------------------------------------------------
void sceneManager::setup(){
    
    // traditional for loop
    for (int i = 0; i < scenes.size(); i++){
        scenes[i]->setup();
    }
    
    for (int i = 0; i < scenes.size(); i++){
        scenes[i]->panel.setPosition(ofPoint(20,50));
    }
    
    // range based for loop
//    for (auto scene : scenes){
//        scene->setup();
//    }
//    
    currentScene = 0;
    
}

void sceneManager::nextScene(){
    currentScene++;
    currentScene %= scenes.size();
}



//---------------------------------------------------------------
void sceneManager::update(){
    scenes[currentScene]->currentFrame = ofGetFrameNum();
    scenes[currentScene]->currentPct = sin(ofGetElapsedTimef()*0.1 ) * 0.5 + 0.5;
    
    scenes[currentScene]->update();
    
}


//---------------------------------------------------------------
void sceneManager::drawGUI(){
    
    scenes[currentScene]->panel.draw();
    
}


//---------------------------------------------------------------
void sceneManager::draw(){
    ofPushStyle();
    scenes[currentScene]->draw();
    ofPopStyle();
}

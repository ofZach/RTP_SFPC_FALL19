

#include "Kath_scene1.h"

//---------------------------------------------------------------
void Kath_scene1::setup(){
    

}


//---------------------------------------------------------------
void Kath_scene1::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed

}


//---------------------------------------------------------------
void Kath_scene1::draw(){
	
	history.push_back(CT->resampleSmoothed);
	ofEnableBlendMode(OF_BLENDMODE_SCREEN);

	
	
	////// draw dots:
	
	if (history.size() > 50) {
		history.erase(history.begin());
		
	}
	
	for (int i = 0; i < history.size(); i++) {

		
		for(int j = 0; j < history[i].size(); j++) {
			
			float wave = ofMap(sin(ofGetElapsedTimef()), -1, 1, -j, 0);
			ofNoFill();
			ofDrawCircle(history[i][j].x, history[i][j].y += wave, wave);
			
		}

	}



	
//    CT->resampleSmoothed.draw();
	
//	for (int i = 0; i < CT->resampleSmoothed.size(); i++) {
//		
//		ofDrawCircle(CT->resampleSmoothed[i].x, CT->resampleSmoothed[i].y, 5);
//		
//	}
	
}

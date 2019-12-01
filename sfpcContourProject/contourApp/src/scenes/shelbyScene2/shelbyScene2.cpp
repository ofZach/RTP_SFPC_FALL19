

#include "shelbyScene2.h"

//---------------------------------------------------------------
void shelbyScene2::setup(){
}


//---------------------------------------------------------------
void shelbyScene2::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed

}


//---------------------------------------------------------------
void shelbyScene2::draw(){
    
    if (energies.size() == 0){
        for (int i = 0; i < ofGetWidth(); i += 20) {
            for (int j = 0; j < ofGetHeight(); j += 20) {
                energies.push_back(1.0);
            }
        }
    } else {
        int count = 0;
        for (int i = 0; i < ofGetWidth(); i += 20) {
            for (int j = 0; j < ofGetHeight(); j += 20) {
                if (CT->resampleSmoothed.size() > 0) {
                    if (CT->resampleSmoothed.inside(i,j)) {
                        energies[count] = 0;
                    }
                }
            count++;
            }
        }
        
        
        for (int i = 0; i < energies.size(); i++){
            energies[i] = 0.99 * energies[i] + 0.01 * 1.0;
        }
    }
    
    int count = 0;
    for (int i = 0; i < ofGetWidth(); i += 20) {
        for (int j = 0; j < ofGetHeight(); j += 20) {
            if (CT->resampleSmoothed.size() > 0) {
                    float r = 1;
                    if (ofNoise(i, j) > 0.7) {
                        r = ofMap(cos(ofGetElapsedTimef() + i) * sin(ofGetElapsedTimef() + j), -1.0, 1.0, 0, 3.0);
                    }

                    ofDrawCircle(i,j,r*energies[count]);
                
            }
            count++;
        }
    }
}

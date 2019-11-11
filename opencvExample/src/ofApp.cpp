#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640,480);
    grayscale.allocate(grabber.getWidth(),grabber.getHeight(), OF_IMAGE_GRAYSCALE);
    
     background.allocate(grabber.getWidth(),grabber.getHeight(), OF_IMAGE_GRAYSCALE);
    
    bLearnBackground =true;
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
    convertColor(grabber, grayscale, CV_RGB2GRAY);
    if (bLearnBackground == true){
        // copy the data from grayscale to background
        background.setFromPixels(grayscale.getPixels());
        bLearnBackground = false;
    }
    
    absdiff(grayscale, background, diff);
    threshold(diff, mouseX);
    diff.update();
    background.update();
    grayscale.update();
    
    finder.setSortBySize(true);
    finder.findContours(diff);
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofScale(0.7, 0.7);
    grabber.draw(0,0);
    grayscale.draw(grabber.getWidth(), 0);
    background.draw(0,grabber.getHeight());
    diff.draw(grabber.getWidth(), grabber.getHeight());
    
    //finder.draw();
    
    if (finder.size() > 0){
        ofPolyline line = finder.getPolyline(0);
        line.draw();
//        for (int i = 0; i < finder.size(); i++){
//            ofPolyline line = finder.getPolyline(i);
//            cout << i << " --- " << finder.getContourArea(i) << endl;
//        }
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    bLearnBackground = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

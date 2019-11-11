#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    grabber.setup(640,480);
    threshold.allocate(640,480, OF_IMAGE_GRAYSCALE);
    
    for (int i = 0; i < 100; i++){
        ofPoint pt;
        pt.x = ofMap(i, 0, 100, 0, grabber.getWidth());
        pt.y = 0;
        pts.push_back( pt  );
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    
    for (int x = 0; x < grabber.getWidth(); x++){
         for (int y = 0; y < grabber.getHeight(); y++){
             ofColor color = grabber.getPixels().getColor(x,y);
             if (color.getBrightness() > mouseX){
                 threshold.setColor(x,y,ofColor::white);
             } else {
                 threshold.setColor(x,y,ofColor::black);
             }
         }
    }
    threshold.update();
    
    for (int i = 0; i < pts.size(); i++){
        
        ofColor color = threshold.getColor(pts[i].x, pts[i].y);
        if (color.getBrightness() > 127){
            pts[i].y += 1; //green light
        } else {
            for (int y = pts[i].y; y >= 0; y--){
                ofColor color2 = threshold.getColor(pts[i].x, y);
                if (color2.getBrightness() > 127){
                    // yay
                    pts[i].y = y;
                    break;
                }
            }
            
            ; // red light
        }
        if (pts[i].y >= grabber.getHeight()){
            pts[i].y = 0;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    grabber.draw(0,0);
    threshold.draw(grabber.getWidth(), 0);
    
    ofSetColor(255,0,0);
    for (int i = 0; i < pts.size(); i++){
        ofDrawCircle(pts[i], 3);
    }
    ofSetColor(255);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

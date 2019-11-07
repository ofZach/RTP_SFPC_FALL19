#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofDirectory dir;
    dir.listDir("Polar bears");
    dir.sort();
    
    //cout << dir.size() << endl;
    for (int i = 0; i < dir.size(); i++){
        cout << dir.getPath(i) << endl;
        
//        ofImage img;
//        img.load(dir.getPath(i));
//        images.push_back( img );
        
        ofImage img;
        images.push_back( img );
        images.back().load(dir.getPath(i));
        
        
        // naive way
        //images.back().resize(640,480);
        
        
        
        ofRectangle target = ofRectangle(0,0,640,480);
        ofRectangle source =
            ofRectangle(0,0, images.back().getWidth(),
                images.back().getHeight());
        target.scaleTo(source);
        
        images.back().crop(target.x, target.y, target.width, target.height);
        images.back().resize(640,480);
        //cout << source << " " << target << endl;
        
        
        
        
    }
    
    
    composite.allocate(640,480, OF_IMAGE_COLOR);
    
    for (int x = 0; x < 640; x++){
        for (int y = 0; y < 480; y++){
            int avgR = 0;
            int avgG = 0;
            int avgB = 0;
            for (int i = 0; i < images.size(); i++){
                ofColor color = images[i].getColor(x,y);
                avgR += color.r;
                avgG += color.g;
                avgB += color.b;
            }
            ofColor avg = ofColor( (float)avgR/(float)images.size(),
                                  (float)avgG/(float)images.size(),
                                  (float)avgB/(float)images.size());
            composite.setColor(x,y,avg);
        }
    }
    
    // copy the pixels from RAM to the graphics card....
    composite.update();
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    images[mouseX%images.size()].draw(0,0);
    composite.draw(0,480);
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

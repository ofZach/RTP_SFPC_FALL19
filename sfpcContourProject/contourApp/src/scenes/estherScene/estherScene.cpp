

#include "estherScene.h"

//---------------------------------------------------------------
void estherScene::setup(){
    

}


//---------------------------------------------------------------
void estherScene::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed

}


//---------------------------------------------------------------
void estherScene::draw(){
    
    ofEnableDepthTest();
    
    //cout << CT->resampleSmoothed.size() << endl;
    
    //CT->resampleSmoothed.draw();
    
//    ofPushMatrix();
    
    int count = 1;
    for (int n = 0; n < count; n++) {
        ofVec3f center = CT->resampleSmoothed.getCentroid2D();
        ofPolyline tmp = CT->resampleSmoothed.getResampledBySpacing(5);
        for (int i=0; i < tmp.size(); i++) {
            
            float x = tmp[i].x;
            float y = tmp[i].y;
            
            ofMatrix4x4 mat;
            mat.makeRotationMatrix(ofGetElapsedTimef()* 200 + 360 * ofNoise(0.001 * x, 0.001 * y, ofGetElapsedTimef()) * sin(ofMap(y, 0, ofGetHeight(), 0, 2 * PI) + 0.1 * ofGetElapsedTimef()), ofPoint(0,1,0));
            ofVec3f scale = ofVec3f(ofNoise(0.01 * y, ofGetElapsedTimef()) * ofMap(n, 0, count, 1, 1.5) + 1, 1, 1);
            tmp[i] = mat * ((ofVec3f(tmp[i]) - center) * scale) + center + ofVec3f(0, 0, 0);
        }
    
//        cout << tmp.size() << endl;
        if (tmp.size() > 0 && n == 0) {
            ofSetColor(0, 0, 0, 10);
            tri.triangulate(tmp, -1, 500);
            tri.triangulatedMesh.draw();
//            tri.triangulatedMesh.drawWireframe();
        }
        ofSetColor(255);
        tmp.draw();
    }
    
    ofDisableDepthTest();
//    ofPopMatrix();
}

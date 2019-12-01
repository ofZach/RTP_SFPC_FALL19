#include "ofApp.h"
#include "emptyScene.h"

#include "Kath_scene1.h"
#include "allisonScene.h"
#include "estherScene.h"
#include "franScene.h"
#include "giaScene.h"
#include "iainShapesScene.h"
#include "maxbBallScene.h"
#include "maxbScene.h"
#include "mncScene.h"
#include "mncScene2.h"
#include "mouwraoScene.h"
#include "shelbyScene.h"
#include "shelbyScene2.h"
#include "shelbyScene3.h"
#include "shelbyScene4.h"
#include "yuzhuChaiScene.h"



//--------------------------------------------------------------
void ofApp::setup(){

    font2.load("Agipo regular.otf", 100, true, true, true);
    
    ofSetVerticalSync(false);
   
    bPresentationMode = true;
    
    bodyVid.load("body.mov");
    bodyVid.play();
    
  //
    
    ofRectangle r;
    r.set(0,0,1080,1920);
    r.scaleTo(ofRectangle(0,0,ofGetScreenWidth(), ofGetScreenHeight()));
    ofSetWindowShape(r.width, r.height);
    ofSetWindowPosition(r.x, r.y);
    noPersonEnergy = 0;
    
    ofSetFullscreen(true);
    
    IM.setup();
//    SM.scenes.push_back(new emptyScene());
//    SM.scenes.back()->studentName = "hello";


//    SM.scenes.push_back(new emptyScene());
//    SM.scenes.back()->studentName = "hello";
//
    
SM.scenes.push_back(new Kath_scene1());
     SM.scenes.back()->studentName = "Katherine Diemert";
SM.scenes.push_back(new allisonScene());
     SM.scenes.back()->studentName = "Allison Chan";
SM.scenes.push_back(new estherScene());
     SM.scenes.back()->studentName = "Esther Bouquet";
SM.scenes.push_back(new franScene());
     SM.scenes.back()->studentName = "Francisco Rojo";
SM.scenes.push_back(new giaScene());
     SM.scenes.back()->studentName = "Gia Castello";
SM.scenes.push_back(new iainShapesScene());
     SM.scenes.back()->studentName = "Iain Nash";
SM.scenes.push_back(new maxbBallScene());
     SM.scenes.back()->studentName = "Max Bittker";
SM.scenes.push_back(new maxbScene());
     SM.scenes.back()->studentName = "Max Bittker";
SM.scenes.push_back(new mncScene());
     SM.scenes.back()->studentName = "Maxwell Neely-Cohen";
    SM.scenes.push_back(new mncScene2());
    SM.scenes.back()->studentName = "Maxwell Neely-Cohen";
SM.scenes.push_back(new mouwraoScene());
     SM.scenes.back()->studentName = "Mathilde Mouw-Rao";
SM.scenes.push_back(new shelbyScene());
     SM.scenes.back()->studentName = "Shelby Wilson";
SM.scenes.push_back(new shelbyScene2());
     SM.scenes.back()->studentName = "Shelby Wilson";
SM.scenes.push_back(new shelbyScene3());
     SM.scenes.back()->studentName = "Shelby Wilson";
//SM.scenes.push_back(new shelbyScene4());
//     SM.scenes.back()->studentName = "Shelby Wilson";
SM.scenes.push_back(new yuzhuChaiScene());
     SM.scenes.back()->studentName = "Yuzhu Chai";

    
    
    ofRandomize(SM.scenes);
    
    
    
    
    
    mainFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 4);
    
    
    
    // share a pointer to the CT object
    for (int i = 0; i < SM.scenes.size(); i++){
        SM.scenes[i]->CT = &CT;
        SM.scenes[i]->IM = &IM;
    }
    
    CF.CT = &CT;
    CF.bounds = ofRectangle(0,0, mainFbo.getWidth(), mainFbo.getHeight());
    
    for (int i = 0; i < SM.scenes.size(); i++){
        SM.scenes[i]->CF = &CF;
         SM.scenes[i]->bounds = CF.bounds;
    }
    
    
    
    SM.setup();
    CT.setup();
    
    bDrawDebug = false;
    font2.load("ApercuBold.otf", 30);
    font.load("ApercuBold.otf", 50);
    
    panel.setup();
    group.add(scale.set("scale", 2.1,0,5));
    group.add(xOffset.set("xOffset", 0,-2000,2000));
    group.add(yOffset.set("yOffset", 0,-2000,2000));
    group.add(centerSmoothing.set("centerSmoothing", 0.95, 0, 1));
    
    ofRectangle rr;
    rr.set(0,0, ofGetWidth(), ofGetHeight());
    group.add(pts[0].set("pt " + ofToString(0), rr.getTopLeft(), ofPoint(0,0,0), ofPoint(2000,2000,0) ));
    group.add(pts[1].set("pt " + ofToString(1), rr.getTopRight(), ofPoint(0,0,0), ofPoint(2000,2000,0) ));
    group.add(pts[2].set("pt " + ofToString(2), rr.getBottomRight(), ofPoint(0,0,0), ofPoint(2000,2000,0) ));
    group.add(pts[3].set("pt " + ofToString(3), rr.getBottomLeft(), ofPoint(0,0,0), ofPoint(2000,2000,0) ));

    
   
    panel.add(group);
     panel.loadFromFile("settings.xml");
    
#ifdef USE_VIDEO
    ofRectangle rrr(0,0, mainFbo.getWidth(), mainFbo.getHeight());
    rrr.scaleTo(ofRectangle(0,0, ofGetWidth(), ofGetHeight()));
    pts[0] = rrr.getTopLeft();
    pts[1] = rrr.getTopRight();
    pts[2] = rrr.getBottomRight();
    pts[3] = rrr.getBottomLeft();
    scale = 1.65;
    yOffset = -91;
    
#endif
    

    
    
}


ofRectangle rrrr;
bool bPresentationModeLastFrame = false;
//--------------------------------------------------------------
void ofApp::update(){
    
    
   
    
    if (bPresentationMode &&
        !bPresentationModeLastFrame){
            ofHideCursor();
    } else {
        if (bPresentationModeLastFrame){
            ofShowCursor();
        }
    }
    
    bPresentationModeLastFrame = bPresentationMode;
    
    
    if (bDrawDebug){
        ofShowCursor();
    }
    
//    cout << ofGetFrameRate() << endl;
    
    CF.centerSmoothing = centerSmoothing;
    CF.scale = scale;
    CF.xOffset = xOffset;
    CF.yOffset = yOffset;
    
    
    IM.update();
    
    
    ofRectangle input(0,0,IM.medianFilteredResult.getWidth(), IM.medianFilteredResult.getHeight());
    ofRectangle output(0,0, ofGetWidth(), ofGetHeight());
    
    ofRectangle inputScaled = input;
    inputScaled.scaleTo(output);

    if (IM.finder.size() > 0){
        
        
        bOkToChangeOnStepOut = true;
        
        nFramesInScene++;
        noPersonEnergy = 0.9 * noPersonEnergy + 0.1 * 0.0;
        
        ofPolyline line = IM.finder.getPolyline(0);
        
        line = line.getResampledByCount(500);
        line = line.getSmoothed(3);
        
        #ifndef USE_VIDEO
        ofMatrix4x4 mat;
        mat.makeRotationMatrix(-90, ofPoint(0,0,1));
        for (auto & pt : line){
            ofPoint pt2 = pt;
            pt2 -= ofPoint(512/2.0, 424.0/2.0);
            pt2 = pt2 * mat;
            pt2.x *= -1;
            pt2 += ofPoint(512/2.0, 424.0/2.0);
            pt = pt2;
        }
       
        line.addVertex(line.getVertices().back());
        line.getVertices().erase(line.getVertices().begin());
        #endif
//
        
        // TODO fix this !
        
        
        //ofRectangle input = line.getBoundingBox();
//
//        rectPosSmoothed = positionChangeSpeed * rectPosSmoothed + (1-positionChangeSpeed) * input.getCenter();
//        rectWidthSmoothed = scaleChangeSpeed * rectWidthSmoothed + (1-scaleChangeSpeed) * input.getWidth();
//        float inputAspect = (float)input.height / (float)input.width;
//        ofPoint topLeft = rectPosSmoothed - ofPoint(rectWidthSmoothed/2, rectWidthSmoothed/2 * inputAspect);
//        ofPoint bottomRight = rectPosSmoothed + ofPoint(rectWidthSmoothed/2, rectWidthSmoothed/2 * inputAspect);
//        input = ofRectangle(topLeft.x, topLeft.y, (bottomRight - topLeft).x, (bottomRight-topLeft).y);
//        ofRectangle inputScaled = input;
//        inputScaled.scaleTo(output);
//        ofNoFill();

        rrrr = inputScaled;
//
       // input.scaleFromCenter(1.2);
        ofPolyline tempLine = line;
        for (int i = 0; i < tempLine.size(); i++){ 
            float x = tempLine[i].x;
            float y = tempLine[i].y;
            float newX = ofMap(x, input.x, input.x + input.width,
                               inputScaled.x + inputScaled.width, inputScaled.x);
            float newY = ofMap(y, input.y, input.y + input.height,
                               inputScaled.y, inputScaled.y + inputScaled.height);
            tempLine[i].x = newX;
            tempLine[i].y = newY;
            
        }
        CT.analyze(tempLine);
        
        CF.orig = tempLine;
        CF.update();
        
        CT.resampleSmoothed = CF.line;
        
        
    } else {
        
        noPersonEnergy = 0.9 * noPersonEnergy + 0.1 * 1.0;
        
        if (noPersonEnergy > 0.99 && bOkToChangeOnStepOut){
            bOkToChangeOnStepOut = false;
            keyPressed(OF_KEY_RIGHT);
            nFramesInScene = 0;
        }
    }
    
    
    SM.update();
    
    
//    if (nFramesInScene > (60 * 30)){
//        nFramesInScene = 0;
//        keyPressed(OF_KEY_RIGHT);
//    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    
    
    ofRectangle input(0,0,IM.medianFilteredResult.getWidth(), IM.medianFilteredResult.getHeight());

    ofBackground(0,0,0);
    
    
    
    if (IM.bLearningBg == true){
        ofBackground(255, 0, 0  );
    }
    if (bDrawDebug){
        IM.draw();
        //ofShowCursor();
    }else {
        //ofHideCursor();
        mainFbo.begin();
        ofClear(0,0,0, 255);
        ofPushStyle();
        SM.draw();
        ofPopStyle();
        
        
//        ofRectangle r = font2.getStringBoundingBox(SM.scenes[SM.currentScene]->studentName, 50, 100);
//        r.scaleFromCenter(1.05, 1.3);
//        ofSetColor(0,0,0,100);
//        ofFill();
//        ofDrawRectangle(r);
//        ofSetColor(255);
//        font2.drawString(SM.scenes[SM.currentScene]->studentName, 50, 100);
        
        
        if (noPersonEnergy > 0.01){
            
            if (bodyVid.isPaused() == true){
                bodyVid.setPaused(false);
            }
            bodyVid.update();

            ofSetColor(0,0,0,noPersonEnergy*255);
            
            ofFill();
            ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
            ofSetColor(255,255,255,255*noPersonEnergy);
            ofRectangle rrrr(0,0,ofGetWidth(), ofGetHeight());
            rrrr.scaleFromCenter(0.96, 1.0);
            bodyVid.draw(rrrr);
            
            ofSetColor(255,255,255,255*noPersonEnergy);
            ofRectangle rr = font.getStringBoundingBox("STEP FORWARD", ofGetWidth()/2, ofGetHeight()/2);
            
            font.drawString("STEP FORWARD",  ofGetWidth()/2-rr.getWidth()/2, ofGetHeight()/2-rr.getHeight()/2);
            
            ofSetColor(255);
            
        } else {
            if (bodyVid.isPaused() == false){
                bodyVid.setPaused(true);
            }
            
            
            ofRectangle r = font.getStringBoundingBox(SM.scenes[SM.currentScene]->studentName, 0,0);
            r.scaleFromCenter(1.2);
            ofSetColor(255 - 255*noPersonEnergy);
            font.drawString(SM.scenes[SM.currentScene]->studentName,  ofGetWidth()-r.width, ofGetHeight()-r.height);
    
        }
        
        ofClearAlpha();
        mainFbo.end();
        
        
        // draw full screen
        mainFbo.draw(0,0,ofGetWidth(), ofGetHeight());
        
        
        
        
        // draw skew for projector
//        mainFbo.getTexture().bind();
//        for (int i = 0; i < 10; i++){
//            ofPoint topA = (ofPoint)pts[0] + ((ofPoint)pts[1] - (ofPoint)pts[0]) * ofMap(i, 0, 10, 0, 1);
//            ofPoint topB = (ofPoint)pts[0] + ((ofPoint)pts[1] - (ofPoint)pts[0]) * ofMap(i+1, 0, 10, 0, 1);
//            ofPoint bottomA = (ofPoint)pts[3] + ((ofPoint)pts[2] - (ofPoint)pts[3]) * ofMap(i, 0, 10, 0, 1);
//            ofPoint bottomB = (ofPoint)pts[3] + ((ofPoint)pts[2] - (ofPoint)pts[3]) * ofMap(i+1, 0, 10, 0, 1);
//            ofMesh m;
//            m.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
//            for (int j = 0; j < 10; j++){
//                ofPoint mixA = topA + (bottomA-topA) * ofMap(j, 0, 9, 0, 1);
//                ofPoint mixB = topB + (bottomB-topB) * ofMap(j, 0, 9, 0, 1);
//                m.addVertex(mixA);
//                m.addVertex(mixB);
//                m.addTexCoord( mainFbo.getTexture().getCoordFromPercent((float)i/10.0, (float)j/9.0));
//                m.addTexCoord( mainFbo.getTexture().getCoordFromPercent((float)(i+1)/10.0, (float)j/9.0));
//            }
//            ofSetColor(255);
//            m.draw();
//        }
//        mainFbo.getTexture().unbind();
        
        
        if (!bPresentationMode){
            SM.drawGUI();
            
            ofDrawLine((ofPoint)pts[0], (ofPoint)pts[2]);
            ofDrawLine((ofPoint)pts[1], (ofPoint)pts[3]);
        }
        
        
        if (!bPresentationMode){
            panel.draw();
        
            ofDrawBitmapString(ofToString(ofGetFrameRate()), 600,50);
        }
    }
    
    
    
    
   
    
    //CT.resampleSmoothed.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == OF_KEY_RIGHT){
        SM.nextScene();
        SM.scenes[SM.currentScene]->reset();
        nFramesInScene= 0;
    }
    
    if (key == ' '){
        bDrawDebug = !bDrawDebug;
    }
    
    if (key == 'f'){
        
        ofToggleFullscreen();
        
    }
    
    if (key == 'p'){
        bPresentationMode = !bPresentationMode;
    }
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



#include "iainShapesScene.h"

//---------------------------------------------------------------
void iainShapesScene::setup(){
    outlineBuffer.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    ofEnableAlphaBlending();
    outlineBuffer.begin();
    ofClear(255,255,255, 0);
    outlineBuffer.end();
    profileBuffer.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    profileBuffer.begin();
    ofClear(255,255,255, 0);
    profileBuffer.end();
}


//---------------------------------------------------------------
void iainShapesScene::update(){
    ofEnableAlphaBlending();
    LineHistory historyEntry;
    ofMesh theMesh;
    ofTessellator tess;

    tess.tessellateToMesh(CT->resampleSmoothed, ofPolyWindingMode::OF_POLY_WINDING_ODD, theMesh, true);
    
    historyEntry.line = CT->resampleSmoothed;
    historyEntry.mesh = theMesh;
    
    
    if (history.size() > 0) {
        LineHistory lastHistryEntry = history[history.size()-1];
        double avgDiff = 0;
        for (unsigned int i = 0; i < min(historyEntry.line.size(), lastHistryEntry.line.size()); i++) {
            double xDiff = pow((historyEntry.line[i].x - lastHistryEntry.line[i].x), 2);
            double yDiff = pow((historyEntry.line[i].y - lastHistryEntry.line[i].y), 2);
            double diffPoint = sqrt(xDiff + yDiff);
            avgDiff = diffPoint + avgDiff / 2;
        }
        historyEntry.diff = avgDiff;
    } else {
        historyEntry.diff = 0;
    }
    history.push_back(historyEntry);
    
    if (history.size() > 40) {
        history.erase(history.begin());
    }
    writeProfileBuffer();
    writeBlockBuffer();
    
}

void iainShapesScene::writeProfileBuffer() {
    ofEnableAlphaBlending();
    profileBuffer.begin();
    
    int lastColorRed = -1;
    // loop over every contour in our history...
    for (int i = 0; i < history.size(); i++) {
        int colorRed;
        if (lastColorRed) {
            colorRed = ofMap(history[i].diff, 0, 30, 0, 255) / 2 + lastColorRed / 2;
            lastColorRed = colorRed;
        } else {
            colorRed = ofMap(history[i].diff, 0, 30, 0, 255);
            lastColorRed = colorRed;
        }
      
//      ofSetColor(min(255, colorRed), 255-min(255, colorRed), 0, ofMap(i, 0, 30, 40, 100)*min(200, colorRed)/255.0);
        ofSetColor(min(255, colorRed), 255-min(255, colorRed), 0, ofMap(i, 0, 40, 0, 120));
        
        ofSetLineWidth(10);

        ofPushMatrix();
        //ofTranslate(0, 0, ofMap(i, 0, 40, -200, 200));
        history[i].mesh.draw();
        ofPopMatrix();
        
        
      //history[i].line.getT
      //history[i].line.draw();
    }
    profileBuffer.end();
}

void iainShapesScene::writeBlockBuffer() {
    outlineBuffer.begin();
    ofEnableAlphaBlending();
    if (history[history.size()-1].line.size() > 0) {
        ofFill();
        //ofBackground(0, 0, 0, 10);
        ofSetColor(0, 0, 0, 1);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        int diff = history[history.size()-1].diff;
        
        ofPolyline lastLine = history[history.size()-1].line;
        
        for (int y = 0; y < ofGetHeight(); y += 20) {
            for (int x = 0; x < ofGetWidth(); x += 20) {
                
                if (lastLine.inside(x, y)) {
                    ofSetColor(min(255, diff), 255-min(255, diff), 255, ofMap(y, 0, ofGetHeight(), 255, 0));
                  ofDrawRectangle(x, y, 20, 20);
                }
          }
        }
        
    }
    outlineBuffer.end();
}

//---------------------------------------------------------------
void iainShapesScene::draw(){
    ofEnableAlphaBlending();
    float cross = sin(ofGetElapsedTimef()/20);
    ofSetColor(255, 255, 255, ofMap(cross, 0, 1, 0, 255));
    outlineBuffer.draw(0, 0);
    ofSetColor(255, 255, 255, ofMap(1-cross, 0, 1, 0, 255));
    profileBuffer.draw(0, 0);
}

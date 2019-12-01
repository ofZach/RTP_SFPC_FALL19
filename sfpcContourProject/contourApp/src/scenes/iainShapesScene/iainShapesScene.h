#pragma once

#include "ofMain.h"
#include "baseScene.h"

class LineHistory {
public:
    ofPolyline line;
    ofMesh mesh;
    float diff;
};

class iainShapesScene : public baseScene {
public:
    
    void setup();
    void update();
    void draw();
private:
    void writeProfileBuffer();
    void writeBlockBuffer();
    vector<LineHistory> history;
    ofFbo outlineBuffer;
    ofFbo profileBuffer;
};

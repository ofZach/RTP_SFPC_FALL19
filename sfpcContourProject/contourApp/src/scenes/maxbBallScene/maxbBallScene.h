#pragma once

#include "baseScene.h"
#include "ofMain.h"

class maxbBallScene : public baseScene {

public:
  void setup();
  void update();
  void draw();

  vector<ofPoint> balls;
  vector<ofVec2f> speeds;
};
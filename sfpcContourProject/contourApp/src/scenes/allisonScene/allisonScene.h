#pragma once

#include "baseScene.h"
#include "ofMain.h"

class allisonScene : public baseScene {

public:
  void setup();
  void update();
  void draw();

  vector<ofPoint> stars;
};
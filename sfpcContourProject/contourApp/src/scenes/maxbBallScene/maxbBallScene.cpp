

#include "maxbBallScene.h"

//---------------------------------------------------------------
void maxbBallScene::setup() {

  // ofSetBackgroundAuto(false);
  // ofEnableAlphaBlending();
  // ofEnableBlendMode(OF_BLENDMODE_ALPHA);

  // ofBackground(10, 10, 20);

  balls.clear();
  speeds.clear();
  for (int i = 0; i < 1000; i++) {
    float x = ofMap(i, 0, 1000, 20, ofGetWidth() - 20);
    balls.push_back(ofPoint(x, ofRandomHeight()));
    speeds.push_back(ofVec2f(0., 0.));
  }
}

//---------------------------------------------------------------
void maxbBallScene::update() {

  ofPolyline line = CT->resampleSmoothed;

  for (int i = 0; i < balls.size(); i++) {
    ofPoint ball = balls[i];
    ofPoint speed = speeds[i];
    ofPoint closest = line.getClosestPoint(ball);

    ofVec2f delta = closest - ball;
    ofVec2f dir = delta.getNormalized();

    float force = sqrt(delta.length() / 50.) / 10.0;

    ofVec2f gravity = ofVec2f(0, 10.0) / 40.0;
    ofVec2f perp = dir.getPerpendicular() * 10;

    ofVec2f impulse = (delta * force) - gravity + perp;
    speeds[i] = speed + (impulse / 60.0);
    speeds[i] = speeds[i] * 0.98;

    balls[i] = ball + speed;

    // ofPoint newball = balls[i];
    // ofPoint newspeed = speeds[i];
    // ofPoint newclosest = line.getClosestPoint(newball);
    // ofVec2f newDelta = newclosest - newball;

    // if (newDelta.length() < 15.0) {
    //   speeds[i] = speeds[i] * -1.0;
    //   balls[i] = newball + 2.0 * speed[i];
    //   // balls[i] = ball + speed;
    // }
  }
}

//---------------------------------------------------------------
void maxbBallScene::draw() {

  ofPolyline line = CT->resampleSmoothed;
  // .draw();

  // ofBackground(0);

  // ofSetColor(0, 0, 0, 5);
  // ofDrawRectangle(0, 0, ofGetWidth(); ofGetHeight());
  // line.draw();

  ofSeedRandom(0);
  //   ofScale(2, 2);

  ofPolyline temp = line.getResampledBySpacing(5);
  temp.getSmoothed(1);
  ofPoint heart = line.getCentroid2D();
  heart.y -= line.getBoundingBox().height * 0.2;
  heart.x += line.getBoundingBox().width * 0.02;
  ofNoFill();

  float beat = 20.0 + sin(ofGetElapsedTimeMillis() / 50.0) * 6.0;
  float beat2 = 18.0 + sin(0.8 + (ofGetElapsedTimeMillis() / 50.0)) * 5.8;

  ofDrawCircle(heart, beat);

  ofDrawCircle(heart, beat2);

  for (int i = 0; i < balls.size(); i++) {
    ofPoint ball = balls[i];
    ofPoint closest = line.getClosestPoint(ball);

    ofDrawCircle(balls[i], 10);
    // ofDrawLine(ball, closest);
  }
}

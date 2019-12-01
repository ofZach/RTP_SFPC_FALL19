

#include "maxbScene.h"

//---------------------------------------------------------------
void maxbScene::setup() {

  // ofSetBackgroundAuto(false);
  // ofEnableAlphaBlending();
  // ofEnableBlendMode(OF_BLENDMODE_ALPHA);

  // ofBackground(10, 10, 20);
}

//---------------------------------------------------------------
void maxbScene::update() {
  //   std::stringstream strm;
  // cout << "fps: " << ofGetFrameRate() << endl;
  //   ofSetWindowTitle(strm.str());
  // the info you want is here:
  // CT->resampleSmoothed
  // ofSetBackgroundAuto(false);
}

//---------------------------------------------------------------
void maxbScene::draw() {

  ofPolyline line = CT->resampleSmoothed;
  // .draw();

  // ofBackground(0);

  // ofSetColor(0, 0, 0, 5);
  // ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

  ofSeedRandom(0);
  //   ofScale(2, 2);


    float maxtime = ofGetElapsedTimeMillis();
  ofPolyline temp = line.getResampledBySpacing(5);
  temp.getSmoothed(1);
  ofPoint heart = line.getCentroid2D();
  heart.y -= line.getBoundingBox().height * 0.2;
  heart.x += line.getBoundingBox().width * 0.02;
  ofNoFill();

  float beat = 20.0 + sin(maxtime / 50.0) * 6.0;
  float beat2 = 18.0 + sin(0.8 + (maxtime / 50.0)) * 5.8;

  for (int layer = 1; layer < 5; layer++) {
    if (layer > 1) {

      temp = temp.getResampledBySpacing(20);
      // temp = temp.getSmoothed(1);
      for (int k = 0; k < temp.size(); k++) {
        float r = -4.0 + sin(0.8 + (maxtime / 50.0)) * 0.2;
        r *= 1.5 * MIN(0.01 + line.getBoundingBox().width / 100.0, 5.0);
        ofPoint me = temp[k];
        ofPoint b = temp[temp.getWrappedIndex(k - 1)];
        ofPoint a = temp[temp.getWrappedIndex(k + 1)];
        ofVec2f normal = b - a;
        normal = temp.getNormalAtIndexInterpolated(k);
        temp[k].x += normal.x * r;
        temp[k].y += normal.y * r;
      }

      // temp.simplify();
    }

    // ofFill();

    int a = 50;
    //  / layer;
    // switch 5(int(player.getCurrentFrame()) % 4) {

    ofColor c = ofColor::fromHsb(
        int(((layer * 3.0) + ofGetElapsedTimef() * 20.0)) % 255, 150, 155);
    ofSetColor(c);
    // temp.draw();

    // c.a = a;

    ofSetColor(c);
    temp.draw();

    // ofPushMatrix();
    // ofTranslate(ofRandomWidth() - 300, ofRandomHeight() - 300);

    // ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    // ofBeginShape();
    // for (int v = 0; v < temp.getVertices().size(); v++) {
    //   ofVertex(temp.getVertices().at(v).x, temp.getVertices().at(v).y);
    // }
    // ofEndShape();
    // ofPopMatrix();
  }
  ofDrawCircle(heart, beat);

  temp = line.getResampledBySpacing(15);
  for (int layer = 1; layer < 8; layer++) {
    temp = temp.getResampledBySpacing(25 + layer * 5);
    // temp = temp.getSmoothed(3);
    for (int k = 0; k < temp.size(); k++) {
      float r = 4.0 - sin(0.8 + (maxtime / 50.0)) * 0.1;
      r *= 1.5 * MIN(0.01 + line.getBoundingBox().width / 100.0, 5.0);
      ofPoint me = temp[k];
      ofPoint b = temp[temp.getWrappedIndex(k - 1)];
      ofPoint a = temp[temp.getWrappedIndex(k + 1)];
      ofVec2f normal = b - a;
      normal = temp.getNormalAtIndexInterpolated(k);
      temp[k].x += normal.x * r;
      temp[k].y += normal.y * r;
    }

    temp.simplify();
    // ofFill();

    int a = 50;
    //  / layer;
    // switch 5(int(player.getCurrentFrame()) % 4) {

    ofColor c = ofColor::fromHsb(
        int(((layer * 3.0) + ofGetElapsedTimef() * 3.0)) % 255, 150, 155);
    ofSetColor(c);
    // temp.draw();

    // c.a = a;

    ofSetColor(c);
    temp.draw();

    // ofPushMatrix();
    // ofTranslate(ofRandomWidth() - 300, ofRandomHeight() - 300);

    // ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    // ofBeginShape();
    // for (int v = 0; v < temp.getVertices().size(); v++) {
    //   ofVertex(temp.getVertices().at(v).x, temp.getVertices().at(v).y);
    // }
    // ofEndShape();
    // ofPopMatrix();
  }
  ofDrawCircle(heart, beat2);

  // ofSetColor(0);
  // ofPolyline simpleLine = line.getResampledBySpacing(5);
  // ofBeginShape();
  // for (int v = 0; v < simpleLine.getVertices().size(); v++) {
  //   ofVertex(simpleLine.getVertices().at(v).x,
  //            simpleLine.getVertices().at(v).y);
  // }
  // ofEndShape();
}

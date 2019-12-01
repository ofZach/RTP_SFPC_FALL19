

#include "allisonScene.h"

//---------------------------------------------------------------
void allisonScene::setup() {
  // GENERATING BG STAR POINTS
  for (int i = 0; i < 500; i++) {
    ofPoint star;
    star.x = ofRandom(ofGetWidth());
    star.y = ofRandom(ofGetHeight());
    stars.push_back(star);
  }
}

//---------------------------------------------------------------
void allisonScene::update() {}

//---------------------------------------------------------------
void allisonScene::draw() {
  // the info you want is here:
  ofPolyline line = CT->resampleSmoothed;
  // .draw();

  line.draw();
  ofSetColor(255, 100, 255);
  ofDrawCircle(50, 50, 50);

  ofColor color1(13, 22, 66);
  ofColor color2(5, 9, 28);

  ofBackgroundGradient(color1, color2, OF_GRADIENT_LINEAR);
  float sect = 85;
  float x = (ofGetWidth() - 100) / sect;
  float y = (ofGetWidth() - 100) / sect;

  // DRAWING THE BACKGROUND STARS!!
  for (int i = 0; i < stars.size(); i++) {
    ofSetColor(ofRandom(190, 255), ofRandom(190, 255), ofRandom(190, 255));
    ofDrawCircle(stars[i].x, stars[i].y, ofRandom(3));
  }

  float sampleDis = 2;
  ofPolyline outline = line;
  //   for (int i = 0; i < outline.size(); i++) {
  // outline[i].x += 0;
  // outline[i].y += 750;
  // outline[i].x += 50 * sin(outline[i].y * 0.01 + ofGetElapsedTimef() * 3);
  //   }
  for (int i = 50; i <= ofGetWidth() - 50; i += x) {
    for (int j = 50; j <= ofGetHeight() - 50; j += y) {
      ofSetLineWidth(0.2);
      ofSetColor(255, 255, 255, 2);
      if (i == 50 || i == ofGetHeight() - 50) {
      } else {
        // ofDrawLine(i, 50, i, ofGetWidth() - 50);
      }
      if (j == 50 || j == ofGetWidth() - 50) {
      } else {
        // ofDrawLine(50, j, ofGetHeight() - 50, j);
      }

      float dotSize = 0;
      // sampling!!!! thanks max!!!!!!!!
      ofPoint dot;
      dot.x = i;
      dot.y = j;
      ofPoint dot1;
      dot1.x = i + (x / sampleDis);
      dot1.y = j + (y / sampleDis);
      ofPoint dot2;
      dot2.x = i + (x / sampleDis);
      dot2.y = j - (y / sampleDis);
      ofPoint dot3;
      dot3.x = i - (x / sampleDis);
      dot3.y = j - (y / sampleDis);
      ofPoint dot4;
      dot4.x = i - (x / sampleDis);
      dot4.y = j + (y / sampleDis);
      ofSetColor(ofRandom(60, 255), ofRandom(60, 255), ofRandom(60, 255));
      if (outline.inside(dot) == true) {
        dotSize += 1.5;
      }
      if (outline.inside(dot1) == true) {
        dotSize += 1.5;
      }
      if (outline.inside(dot2) == true) {
        dotSize += 1.5;
      }
      if (outline.inside(dot3) == true) {
        dotSize += 1.5;
      }
      if (outline.inside(dot4) == true) {
        dotSize += 1.5;
      }
      dotSize *= ofNoise(i / 20.0, j / 20.0, ofGetElapsedTimeMicros() / 1000.0);
      ofDrawCircle(i, j, dotSize);
    }
  }
}

#include "ofApp.h"

void ofApp::setup(){
  kui.setCamera(cam);
  cam.setPosition(0, 0, 2000);
}

void ofApp::draw(){
  ofDisableLighting();
  ofBackgroundGradient( ofColor(40,40,40), ofColor(0,0,0), OF_GRADIENT_CIRCULAR); 

  cam.begin();
    scene.draw();
  cam.end();

  drawHelp();

  kui.draw();
}

void ofApp::drawHelp(){
  ofSetColor(ofColor::white);
  ofDisableLighting();
  float y = 20;
  ofDrawBitmapString("First press 'c' to enter camera mode.", 5, y);
  y += 20;
  ofDrawBitmapString("Then, use the following keys to move the camera.", 5, y);
  y += 30;
  ofDrawBitmapString("Position:", 5, y);
  y += 30;
  ofDrawBitmapString("[s] Move down", 10, y);
  y += 20;
  ofDrawBitmapString("[d] Move up", 10, y);
  y += 30;
  ofDrawBitmapString("[f] Move right", 10, y);
  y += 20;
  ofDrawBitmapString("[q] Move left", 10, y);
  y += 30;
  ofDrawBitmapString("[z] Move forward", 10, y);
  y += 20;
  ofDrawBitmapString("[x] Move backward", 10, y);
  y += 30;
  ofDrawBitmapString("Rotation:", 5, y);
  y += 30;
  ofDrawBitmapString("[k] Rotate down around horizontal axis", 10, y);
  y += 20;
  ofDrawBitmapString("[l] Rotate up around horizontal axis", 10, y);
  y += 30;
  ofDrawBitmapString("[j] Rotate left around vertical axis", 10, y);
  y += 20;
  ofDrawBitmapString("[m] Rotate right around vertical axis", 10, y);
  y += 30;
  ofDrawBitmapString("Press 'Esc' to exit camera mode.", 5, y);
}

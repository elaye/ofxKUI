#pragma once

#include "ofMain.h"
#include "ofxKUI.h"

class ofApp : public ofBaseApp{

  ofColor color;

  ofxKUI kui;

  public:
    void setup();
    void newColor();
    void draw();

};

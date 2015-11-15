#pragma once

#include "ofMain.h"
#include "ofxKUI.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

  ofEasyCam cam;

  ofBoxPrimitive box;

  ofMaterial material;
  ofLight light;

  ofParameterGroup parameters;
  ofParameter<float> scale;
  ofParameter<float> scale1;
  ofParameter<bool> button;
  
  ofxKUI kui;
  ofxPanel panel;

  public:
    void setup();
    void update();
    void draw();

};

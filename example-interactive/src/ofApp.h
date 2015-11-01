#pragma once

#include "ofMain.h"
#include "ofxKUI.h"

class ofApp : public ofBaseApp{

  ofEasyCam cam;

  ofBoxPrimitive box;

  ofMaterial material;
  ofLight light;

  ofParameterGroup parameters;
  ofParameter<float> scale;
  
  ofxKUI kui;

  public:
    void setup();
    void update();
    void draw();

};

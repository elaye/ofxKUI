#pragma once

#include "ofMain.h"
#include "ofxKUI.h"

#include "Scene.h"

class ofApp : public ofBaseApp{

  // ofEasyCam cam;
  ofCamera cam;

  Scene scene;

  ofxKUI kui;

  public:
    void setup();
    void draw();
    void drawHelp();

};
#pragma once

#include "ofMain.h"
#include "ofxKUI.h"

enum class Geometry {
  BOX, SPHERE
};

class ofApp : public ofBaseApp{

  ofEasyCam cam;

  Geometry geometry;
  ofBoxPrimitive box;
  ofSpherePrimitive sphere;

  ofMaterial material;
  ofLight light;

  ofxKUI kui;

  public:
    void setup();
    void update();
    void draw();

    void toggleLight();
    void switchGeometry();

};

#pragma once

#include "ofMain.h"

class Scene {

  vector<ofBoxPrimitive> objects;

  ofMaterial material;
  ofLight light;

  public:
    Scene();
    void draw();

};
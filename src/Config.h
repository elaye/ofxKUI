#pragma once

#include "ofMain.h"

class Config {

  ofColor backgroundColor = ofColor::green;
  ofColor selectedBackgroundColor = ofColor::red;

  float percentCoarse = 0.1;
  float percentFine = 0.01;

  float cameraPositionCoarse = 20.0;
  float cameraPositionFine = 4.0;
  float cameraAngleCoarse = 5.0;
  float cameraAngleFine = 1.0;

  public:
    ofColor getBackgroundColor(){ return backgroundColor; }
    void setBackgroundColor(ofColor color){ backgroundColor = color; }
    ofColor getSelectedBackgroundColor(){ return backgroundColor; }
    void setSelectedBackgroundColor(ofColor color){ backgroundColor = color; }

    float getPercentCoarse(){ return percentCoarse; } 
    void setPercentCoarse(float p){ percentCoarse = p; }
    float getPercentFine(){ return percentFine; }
    void setPercentFine(float p){ percentFine = p; }

    float getCameraPositionCoarse(){ return cameraPositionCoarse; }
    void setCameraPositionCoarse(float c){ cameraPositionCoarse = c; }
    float getCameraPositionFine(){ return cameraPositionFine; }
    void setCameraPositionFine(float f){ cameraPositionFine = f; }
    float getCameraAngleCoarse(){ return cameraAngleCoarse; }
    void setCameraAngleCoarse(float c){ cameraAngleCoarse = c; }
    float getCameraAngleFine(){ return cameraAngleFine; }
    void setCameraAngleFine(float f){ cameraAngleFine = f; }
};
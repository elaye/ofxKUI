#pragma once

#include "ofMain.h"

#include "ofxGui.h"

struct GUITheme {
  ofColor headerBackgroundColor;
  ofColor backgroundColor;
  ofColor selectedBackgroundColor;
  ofColor fillColor;
  ofColor selectedFillColor;
  ofColor textColor;
  ofColor selectedTextColor;
  ofColor borderColor;
  ofColor selectedBorderColor;
};

class Config {

  GUITheme lightTheme;
  GUITheme darkTheme;

  GUITheme currentTheme;

  float percentCoarse = 0.1;
  float percentFine = 0.01;

  float cameraPositionCoarse = 20.0;
  float cameraPositionFine = 4.0;
  float cameraAngleCoarse = 5.0;
  float cameraAngleFine = 1.0;

  public:
    Config();

    GUITheme getTheme();
    void setTheme(GUITheme theme);

    void useDarkTheme();
    void useLightTheme();

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

  private:
    void setupDarkTheme();
    void setupLightTheme();
};
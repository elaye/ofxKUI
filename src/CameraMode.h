#pragma once

#include "ofMain.h"

#include "UI.h"

class CameraMode {

  UI& ui;

  ofCamera* camera;

  public:
    CameraMode(UI& ui);

    void action(char c);

    void setCamera(ofCamera& camera);
    ofCamera* getCamera();

  private:
  	float getPositionStep();
  	float getAngleStep();
};
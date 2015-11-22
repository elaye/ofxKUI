#pragma once

#include "ofMain.h"

#include "UI.h"

class Help {

  UI& ui;
  ofPath background;

  public:
    Help(UI& ui);
    void draw();

  private:
    void windowResized(ofResizeEventArgs& event);
    void initUI();
};
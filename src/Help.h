#pragma once

#include "ofMain.h"

#include "UI.h"

class Help {

  UI& ui;
  ofPath background;
  ofPoint cursor, cursorStart;
  float lineHeight, lineWidth;

  public:
    Help(UI& ui);
    void draw();

  private:
    void windowResized(ofResizeEventArgs& event);
    void initUI();
    void printNext(string s);
};
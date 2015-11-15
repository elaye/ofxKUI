#pragma

#include "ofMain.h"

#include "ofxGui.h"

#include "UI.h"

class InteractiveMode {

  UI& ui;

  ofxPanel* panel;

  int activeControl;

  // ofParameterGroup* parameters;

  // float sliderWidth, sliderHeight;
  // float hmargin, vmargin;
  // float sliderStopHeight, sliderStopWidth;

  public:
    InteractiveMode(UI& ui);

    void enable();
    void disable();

    void action(char key);

    void leftAction();
    void rightAction();

    void setGUI(ofxPanel& panel);
    void selectNext();
    void selectPrev();
    void select(int i);
    void deselectActive();

    // void addParameters(ofParameterGroup& parameters);   
    // void drawParameters();
    // void drawParameter(ofParameter<float>& param);
    // void drawSlider(float t, float min, float max);
};
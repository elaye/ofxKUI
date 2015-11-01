#pragma

#include "ofMain.h"

#include "UI.h"

class InteractiveMode {

  UI ui;

  ofParameterGroup* parameters;

  float sliderWidth, sliderHeight;
  float hmargin, vmargin;
  float sliderStopHeight, sliderStopWidth;

  public:
    InteractiveMode();

    void action(char key);

    void addParameters(ofParameterGroup& parameters);   
    void drawParameters();
    void drawParameter(ofParameter<float>& param);
    void drawSlider(float t, float min, float max);
};
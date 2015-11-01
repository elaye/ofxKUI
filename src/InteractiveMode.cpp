#include "InteractiveMode.h"

InteractiveMode::InteractiveMode(){
  sliderWidth = 100;
  sliderHeight = 2;
  hmargin = 20;
  vmargin = 20;
  sliderStopHeight = 10;
  sliderStopWidth = 2;
  parameters = nullptr;
}

void InteractiveMode::addParameters(ofParameterGroup& params){
  parameters = &params;
}

void InteractiveMode::action(char key){
  ofParameter<float> scale = parameters->getFloat("Scale");
  float v;
  if(UI::getAdjustment() == KUIAdjust::COARSE){
    v = 10;
  }
  else{
    v = 1;
  }
  switch(key){
    case 'j':
      if(scale - v > scale.getMin()){
        scale.set(scale - v);
      }
      else {
        scale.set(scale.getMin());
      }
      break;
    case 'm':
      if(scale + v < scale.getMax()){
        scale.set(scale + v);
      }
      else{
        scale.set(scale.getMax());
      }
      break;
  }
}

void InteractiveMode::drawParameters(){
  if(parameters == nullptr) return;
  for(std::size_t i = 0; i < parameters->size(); i++){
    string type = parameters->getType(i);
    // if(type == typeid(ofParameter<int32_t>).name()){
    //   auto p = parameters->getInt(i);
    //   drawParameter(p);
    // }else if(type == typeid(ofParameter<uint32_t>).name()){
    //   auto p = parameters->get<uint32_t>(i);
    //   drawParameter(p);
    // }else if(type == typeid(ofParameter<int64_t>).name()){
    //   auto p = parameters->get<int64_t>(i);
    //   drawParameter(p);
    // }else if(type == typeid(ofParameter<uint64_t>).name()){
    //   auto p = parameters->get<uint64_t>(i);
    //   drawParameter(p);
    // }else if(type == typeid(ofParameter<int8_t>).name()){
    //   auto p = parameters->get<int8_t>(i);
    //   drawParameter(p);
    // }else if(type == typeid(ofParameter<uint8_t>).name()){
    //   auto p = parameters->get<uint8_t>(i);
    //   drawParameter(p);
    // }else if(type == typeid(ofParameter<int16_t>).name()){
    //   auto p = parameters->get<int16_t>(i);
    //   drawParameter(p);
    // }else if(type == typeid(ofParameter<uint16_t>).name()){
    //   auto p = parameters->get<uint16_t>(i);
    //   drawParameter(p);
    // }
    if(type == typeid(ofParameter<float>).name()){
      auto p = parameters->getFloat(i);
      drawParameter(p);
    }
    // else if(type == typeid(ofParameter<double>).name()){
    //   auto p = parameters->get<double>(i);
    //   drawParameter(p);
    // }else if(type == typeid(ofParameter<bool>).name()){
    //   auto p = parameters->getBool(i);
    //   drawParameter(p);
    // }else if(type == typeid(ofParameter<ofVec2f>).name()){
    //   auto p = parameters->getVec2f(i);
    //   drawParameter(p);
    // }else if(type == typeid(ofParameter<ofVec3f>).name()){
    //   auto p = parameters->getVec3f(i);
    //   drawParameter(p);
    // }else if(type == typeid(ofParameter<ofVec4f>).name()){
    //   auto p = parameters->getVec4f(i);
    //   drawParameter(p);
    // }else if(type == typeid(ofParameter<ofColor>).name()){
    //   auto p = parameters->getColor(i);
    //   drawParameter(p);
    // }else if(type == typeid(ofParameter<ofShortColor>).name()){
    //   auto p = parameters->getShortColor(i);
    //   drawParameter(p);
    // }else if(type == typeid(ofParameter<ofFloatColor>).name()){
    //   auto p = parameters->getFloatColor(i);
    //   drawParameter(p);
    // }else if(type == typeid(ofParameter<string>).name()){
    //   auto p = parameters->getString(i);
    //   drawParameter(p);
    // }
    else if(type == typeid(ofParameterGroup).name()){
      ofLogError() << "No support for nested ofParameterGroups yet :(";
    }else{
      ofLogError() << "No control for parameter of type " << type;
    } 
  }
}

void InteractiveMode::drawParameter(ofParameter<float>& p){
  drawSlider(p.get(), p.getMin(), p.getMax());
}

void InteractiveMode::drawSlider(float t, float min, float max){
  ofSetColor(ofColor::white);
  float xStopLeft = hmargin - sliderStopWidth / 2;
  float xStopRight = xStopLeft + sliderWidth;
  float yStop = vmargin - sliderStopHeight / 2;
  ofDrawRectangle(xStopLeft, yStop, sliderStopWidth, sliderStopHeight);
  ofDrawRectangle(xStopRight, yStop, sliderStopWidth, sliderStopHeight);
  float w =  t / (max - min) * sliderWidth;
  float xSlider = hmargin;
  float ySlider = vmargin - sliderHeight / 2;
  ofDrawRectangle(xSlider, ySlider, w, sliderHeight);
}
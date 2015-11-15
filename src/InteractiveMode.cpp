#include "InteractiveMode.h"

InteractiveMode::InteractiveMode(UI& _ui) :
  ui(_ui)
{
  panel = nullptr;
  activeControl = 0;
}

void InteractiveMode::setGUI(ofxPanel& _panel){
  panel = &_panel;
}

void InteractiveMode::enable(){
  select(0);
}

void InteractiveMode::disable(){
  deselectActive();
}

void InteractiveMode::select(int i){
  ofLog() << "select start";
  int n = panel->getNumControls();
  if(i < n){
    auto control = panel->getControl(i);
    control->setBackgroundColor(ofColor::red);
  }
  ofLog() << "select end";
}

void InteractiveMode::selectNext(){
  ofLog() << "start select next";
  ofLog() << "a: " << activeControl;
  deselectActive();
  int n = panel->getNumControls();
  if(n > 0){
    activeControl += 1;
  ofLog() << "a: " << activeControl;
    activeControl %= n;
  ofLog() << "a: " << activeControl;
    select(activeControl);
  }
  ofLog() << "end select next";
}

void InteractiveMode::selectPrev(){
  deselectActive();
  int n = panel->getNumControls();
  activeControl -= 1;
  if(activeControl < 0){
    activeControl = n - 1;
  }
  select(activeControl);
}

void InteractiveMode::leftAction(){
  auto control = panel->getControl(activeControl);
  auto& param = control->getParameter(); 

  string type = param.type();
  if(type == typeid(ofParameter<float>).name()){
    auto p = param.cast<float>();

    float pmax = p.getMax();
    float pmin = p.getMin();
    float dec = (pmax - pmin) / 100.0;
    float p0 = p.get();
    p.set(p0 - dec);
  }
  else if(type == typeid(ofParameter<bool>).name()){
    auto p = param.cast<bool>();
    p.set(false);
  }
}

void InteractiveMode::rightAction(){
  auto control = panel->getControl(activeControl);
  auto& param = control->getParameter(); 

  string type = param.type();
  if(type == typeid(ofParameter<float>).name()){
    auto p = param.cast<float>();

    float pmax = p.getMax();
    float pmin = p.getMin();
    float inc = (pmax - pmin) / 100.0;
    float p0 = p.get();
    p.set(p0 + inc);
  }
  else if(type == typeid(ofParameter<bool>).name()){
    auto p = param.cast<bool>();
    p.set(true);
  }
}

void InteractiveMode::deselectActive(){
  auto control = panel->getControl(activeControl);
  control->setBackgroundColor(ofColor::green);
}

void InteractiveMode::action(char key){
  if(key == KUIKey::Esc){
    deselectActive();
    ui.setMode(KUIMode::NORMAL);
    return;
  }
  if(key == KUIKey::Space){
    ui.toggleAdjustment();
  }
  // ofParameter<float> scale = parameters->getFloat("Scale");
  float v;
  if(ui.getAdjustment() == KUIAdjust::COARSE){
    v = 10;
  }
  else{
    v = 1;
  }
  switch(key){
    case 'k':
      selectNext();
      break;
    case 'l':
      selectPrev();
      break;
    case 'j':
      leftAction();
      break;
    case ';':
      rightAction();
      break;
    default:
      break;
  }
}

// void InteractiveMode::action(char key){
//   if(key == KUIKey::Esc){
//     ui.setMode(KUIMode::NORMAL);
//     return;
//   }
//   if(key == KUIKey::Space){
//     ui.toggleAdjustment();
//   }
//   ofParameter<float> scale = parameters->getFloat("Scale");
//   float v;
//   if(ui.getAdjustment() == KUIAdjust::COARSE){
//     v = 10;
//   }
//   else{
//     v = 1;
//   }
//   switch(key){
//     case 'j':
//       if(scale - v > scale.getMin()){
//         scale.set(scale - v);
//       }
//       else {
//         scale.set(scale.getMin());
//       }
//       break;
//     case 'm':
//       if(scale + v < scale.getMax()){
//         scale.set(scale + v);
//       }
//       else{
//         scale.set(scale.getMax());
//       }
//       break;
//   }
// }

// void InteractiveMode::drawParameters(){
//   if(parameters == nullptr) return;
//   for(std::size_t i = 0; i < parameters->size(); i++){
//     string type = parameters->getType(i);
//     // if(type == typeid(ofParameter<int32_t>).name()){
//     //   auto p = parameters->getInt(i);
//     //   drawParameter(p);
//     // }else if(type == typeid(ofParameter<uint32_t>).name()){
//     //   auto p = parameters->get<uint32_t>(i);
//     //   drawParameter(p);
//     // }else if(type == typeid(ofParameter<int64_t>).name()){
//     //   auto p = parameters->get<int64_t>(i);
//     //   drawParameter(p);
//     // }else if(type == typeid(ofParameter<uint64_t>).name()){
//     //   auto p = parameters->get<uint64_t>(i);
//     //   drawParameter(p);
//     // }else if(type == typeid(ofParameter<int8_t>).name()){
//     //   auto p = parameters->get<int8_t>(i);
//     //   drawParameter(p);
//     // }else if(type == typeid(ofParameter<uint8_t>).name()){
//     //   auto p = parameters->get<uint8_t>(i);
//     //   drawParameter(p);
//     // }else if(type == typeid(ofParameter<int16_t>).name()){
//     //   auto p = parameters->get<int16_t>(i);
//     //   drawParameter(p);
//     // }else if(type == typeid(ofParameter<uint16_t>).name()){
//     //   auto p = parameters->get<uint16_t>(i);
//     //   drawParameter(p);
//     // }
//     if(type == typeid(ofParameter<float>).name()){
//       auto p = parameters->getFloat(i);
//       drawParameter(p);
//     }
//     // else if(type == typeid(ofParameter<double>).name()){
//     //   auto p = parameters->get<double>(i);
//     //   drawParameter(p);
//     // }else if(type == typeid(ofParameter<bool>).name()){
//     //   auto p = parameters->getBool(i);
//     //   drawParameter(p);
//     // }else if(type == typeid(ofParameter<ofVec2f>).name()){
//     //   auto p = parameters->getVec2f(i);
//     //   drawParameter(p);
//     // }else if(type == typeid(ofParameter<ofVec3f>).name()){
//     //   auto p = parameters->getVec3f(i);
//     //   drawParameter(p);
//     // }else if(type == typeid(ofParameter<ofVec4f>).name()){
//     //   auto p = parameters->getVec4f(i);
//     //   drawParameter(p);
//     // }else if(type == typeid(ofParameter<ofColor>).name()){
//     //   auto p = parameters->getColor(i);
//     //   drawParameter(p);
//     // }else if(type == typeid(ofParameter<ofShortColor>).name()){
//     //   auto p = parameters->getShortColor(i);
//     //   drawParameter(p);
//     // }else if(type == typeid(ofParameter<ofFloatColor>).name()){
//     //   auto p = parameters->getFloatColor(i);
//     //   drawParameter(p);
//     // }else if(type == typeid(ofParameter<string>).name()){
//     //   auto p = parameters->getString(i);
//     //   drawParameter(p);
//     // }
//     else if(type == typeid(ofParameterGroup).name()){
//       ofLogError() << "No support for nested ofParameterGroups yet :(";
//     }else{
//       ofLogError() << "No control for parameter of type " << type;
//     } 
//   }
// }

// void InteractiveMode::drawParameter(ofParameter<float>& p){
//   drawSlider(p.get(), p.getMin(), p.getMax());
// }

// void InteractiveMode::drawSlider(float t, float min, float max){
//   ofSetColor(ofColor::white);
//   float xStopLeft = hmargin - sliderStopWidth / 2;
//   float xStopRight = xStopLeft + sliderWidth;
//   float yStop = vmargin - sliderStopHeight / 2;
//   ofDrawRectangle(xStopLeft, yStop, sliderStopWidth, sliderStopHeight);
//   ofDrawRectangle(xStopRight, yStop, sliderStopWidth, sliderStopHeight);
//   float w =  t / (max - min) * sliderWidth;
//   float xSlider = hmargin;
//   float ySlider = vmargin - sliderHeight / 2;
//   ofDrawRectangle(xSlider, ySlider, w, sliderHeight);
// }
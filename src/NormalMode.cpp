#include "NormalMode.h"

NormalMode::NormalMode(UI& _ui) : 
  ui(_ui)
{

}

void NormalMode::action(char key){
  if(maps.find(key) != maps.end()){
    ofNotifyEvent(maps[key].event);
    return;
  }
  if(key == 'c'){
    ui.setMode(KUIMode::CAMERA);
  }
  if(key == 'd'){
    ui.setMode(KUIMode::COMMAND);
    return;
  }
  if(key == 'i'){
    // TODO? Add warning when no parameters were set
    ui.setMode(KUIMode::INTERACTIVE);
    return;
  }
  if(key == 'f'){
    ui.toggleAdjustment();
  }
}

void NormalMode::drawDescription(){
  auto& font = ui.getFont();
  float descWidth = 0;
  for(auto& m : maps){
    float w = font.stringWidth(m.second.desc);
    if(w > descWidth) descWidth = w;
  }

  float y = 15;
  for(auto& m : maps){
    string desc = m.second.desc;
    if(desc == "") continue;
    float x = ofGetWidth() - descWidth - 10;
    // ofSetColor(ofColor::green);
    ofSetColor(ofColor::white);
    font.drawString(desc, x, y); 
    y += font.getLineHeight();
  } 
}
#include "UI.h"

UI::UI(){
  fontPath = "Hack-v2_015-ttf/Hack-Regular.ttf";
  loadFont();
}

void UI::loadFont(){
  font.load(fontPath, 10);
  charWidth = font.stringWidth("0");
}

string UI::getFontPath(){
  return fontPath;
}

float UI::getCharWidth(){
  return charWidth;
}

ofTrueTypeFont& UI::getFont(){
  return font;
}

KUIMode UI::getMode(){
  return mode;
}

void UI::setMode(KUIMode m){
  mode = m;
}

KUIAdjust UI::getAdjustment(){
  return adjust;
}

void UI::setAdjustment(KUIAdjust adj){
  adjust = adj;
}

void UI::toggleAdjustment(){
  if(adjust == KUIAdjust::COARSE){
    adjust = KUIAdjust::FINE;
  }
  else{
    adjust = KUIAdjust::COARSE;
  }
}

void UI::drawMode(){
  string m;
  // switch(mode){
  switch(mode){
    case KUIMode::NORMAL:
      m = "normal";
      break;
    case KUIMode::COMMAND:
      m = "command";
      break;
    case KUIMode::CAMERA:
      m = "camera";
      break;
    case KUIMode::INTERACTIVE:
      m = "interactive";
      break;
  }
  float x = ofGetWidth() - font.stringWidth(m) - 5;
  // font.drawString(m, x, comStrPos.y);
  font.drawString(m, x, 40);
}
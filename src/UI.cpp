#include "UI.h"

UI::UI(){
  fontPath = "Hack-v2_015-ttf/Hack-Regular.ttf";
  loadFont();
  config = shared_ptr<Config>(new Config());
}

shared_ptr<Config> UI::getConfig(){
  return config;
}

void UI::setConfig(shared_ptr<Config> _config){
  config = _config;
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
  float fh = font.getLineHeight();
  ofPath path;
  float w = 1.2 * font.stringWidth(m);
  float h = 1.2 * fh;
  path.setFilled(true);
  path.setFillColor(ofColor::grey);
  path.rectangle(ofGetWidth() - w, ofGetHeight() - h, w, h);
  path.draw();
  float x = ofGetWidth() - font.stringWidth(m) - 5;
  float y = ofGetHeight() - 0.2 * fh;
  font.drawString(m, x, y);
}
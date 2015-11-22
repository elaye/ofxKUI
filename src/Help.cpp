#include "Help.h"

Help::Help(UI& _ui):
ui(_ui)
{
  initUI();
  ofAddListener(ofEvents().windowResized, this, &Help::windowResized);
}

void Help::windowResized(ofResizeEventArgs& event){
  initUI();
}

void Help::initUI(){
  background.clear();
  background.rectangle(0, 0, ofGetWidth(), ofGetHeight());
  background.setFilled(true);
  background.setFillColor(ofColor(0, 0, 0, 180));
}

void Help::draw(){
  // ui.drawString();
  background.draw();
  auto font = ui.getFont();
  float x = 10;
  float y = 20;
  float l = 15;
  font.drawString("Help", x, y);
  y += l;
  font.drawString("---------------------", x, y);
  y += l;
  font.drawString("? Show/hide this help", x, y);
}
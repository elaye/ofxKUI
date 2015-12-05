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
  y += l;
  font.drawString("[Esc] Return to normal mode", x, y);
  y += 2 * l;

  font.drawString("Camera mode [c]", x, y);
  y += l;
  font.drawString("---------------------", x, y);
  y += 2 * l;

  font.drawString("[s] Move down", x, y);
  y += l;
  font.drawString("[d] Move up", x, y);
  y += l;
  font.drawString("[f] Move right", x, y);
  y += l;
  font.drawString("[a] Move left", x, y);
  y += l;
  font.drawString("[w] Move forward", x, y);
  y += l;
  font.drawString("[x] Move backward", x, y);
  y += 2 * l;

  font.drawString("[k] Rotate down around horizontal axis", x, y);
  y += l;
  font.drawString("[l] Rotate up around horizontal axis", x, y);
  y += l;
  font.drawString("[j] Rotate left around vertical axis", x, y);
  y += l;
  font.drawString("[;] Rotate right around vertical axis", x, y);
}
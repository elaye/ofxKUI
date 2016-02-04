#include "Help.h"

Help::Help(UI& _ui):
ui(_ui)
{
  initUI();
  cursorStart = ofPoint(10, 20);
  cursor = cursorStart;
  lineHeight = ui.getLineHeight();
  lineWidth = 0;
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
  lineWidth = 0;
  cursor = cursorStart;
  background.draw();

  printNext("Help");
  printNext("----");
  printNext("? Show/hide this help");
  printNext("<Esc> Return to normal mode");
  printNext("<Space> Switch between coarse and fine adjustment");
  printNext("");

  printNext("Camera mode [c]");
  printNext("---------------");
  printNext("");

  printNext("[s] Move down");
  printNext("[d] Move up");
  printNext("[f] Move right");
  printNext("[a] Move left");
  printNext("[w] Move forward");
  printNext("[x] Move backward");
  printNext("");

  printNext("[k] Rotate down around horizontal axis");
  printNext("[l] Rotate up around horizontal axis");
  printNext("[j] Rotate left around vertical axis");
  printNext("[;] Rotate right around vertical axis");
  printNext("");
}

void Help::printNext(string s){
  auto font = ui.getFont();
  if (cursor.y > ofGetHeight() - lineHeight) {
    cursor.y = cursorStart.y;
    cursor.x += lineWidth + 40;
  }
  else {
    cursor.y += lineHeight;
  }
  float w = ui.stringWidth(s);
  if (w > lineWidth) lineWidth = w;
  ui.drawString(s, cursor.x, cursor.y);
}

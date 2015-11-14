#include "CommandMode.h"

CommandMode::CommandMode(UI& _ui) :
  ui(_ui) 
{
  prompt = "> ";
  initUI();
  ofLog() << "command init";
}

void CommandMode::initUI(){
  float w = ofGetWidth();
  float fontHeight = ui.getFont().getLineHeight();
  float h = 1.2 * fontHeight;
  float x = 0; 
  float y = ofGetHeight() - h; 
  rect.rectangle(x, y, w, h);

  ofColor color = (0, 0, 0, 70);
  rect.setFillColor(color);
  rect.setFilled(true);

  comStrPos.x = x + 5;
  comStrPos.y = y + 0.9 * fontHeight;
}

void CommandMode::action(char key){
  ofSetEscapeQuitsApp(false);
  if (key == KUIKey::Backspace) {
    if(command.length() > 0){
      command.pop_back();
    }
  }
  else if(key == KUIKey::Return){
    parseExecCommand(command);
    ui.setMode(KUIMode::NORMAL);
    command = "";
  }
  else if(key == KUIKey::Esc){
    ui.setMode(KUIMode::NORMAL);
    command = "";
  }
  else {
    if(command.length() < 32){
      command.push_back(key);
    }
  }
}

void CommandMode::parseExecCommand(string cmd){
  ofLog() << cmd;
}

void CommandMode::drawPrompt(){
  auto& font = ui.getFont();
  rect.draw(); 
  // Print prompt
  ofSetColor(ofColor::white);
  float x = comStrPos.x;
  font.drawString(prompt, x, comStrPos.y);
  // Print commands
  ofSetColor(ofColor::white);
  x += font.stringWidth(prompt) + 5;
  font.drawString(command, x, comStrPos.y);
  ofEnableLighting();
}
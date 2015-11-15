#include "CommandMode.h"

CommandMode::CommandMode(UI& _ui) :
  ui(_ui) 
{
  prompt = "> ";
  caretLoopIndex = 0;
  initUI();
  ofAddListener(ofEvents().windowResized, this, &CommandMode::windowResized);
}

void CommandMode::windowResized(ofResizeEventArgs& event){
  initUI();
}

void CommandMode::initUI(){
  rect.clear();
  caret.clear();
  auto& font = ui.getFont();
  float w = ofGetWidth();
  float fontHeight = font.getLineHeight();
  float h = 1.2 * fontHeight;
  float x = 0.0; 
  float y = ofGetHeight() - h; 
  rect.rectangle(x, y, w, h);

  ofColor promptColor = (0, 0, 0, 70);
  rect.setFillColor(promptColor);
  rect.setFilled(true);

  comStrPos.x = x + 5;
  comStrPos.y = y + 0.9 * fontHeight;

  ofColor caretColor = (255, 255, 255, 255);
  float caretX = font.stringWidth(prompt) + 5.0 + ui.getCharWidth();
  float caretY = ofGetHeight() - (fontHeight + h) / 2.0;
  caret.rectangle(caretX, caretY, ui.getCharWidth(), fontHeight);
  caret.setFillColor(caretColor);
  caret.setFilled(true);
}

void CommandMode::action(char key){
  ofSetEscapeQuitsApp(false);
  if (key == KUIKey::Backspace) {
    if(command.length() > 0){
      command.pop_back();
      caretLoopIndex = 0;
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
    // Max command length = 32 and only printable characters
    if(command.length() < 32 && key > 31 && key < 127){
      command.push_back(key);
      caretLoopIndex = 0;
      ofLog() << command;
    }
  }
}

void CommandMode::parseExecCommand(string cmd){
  ofLog() << cmd;
}

void CommandMode::draw(){
  drawPrompt();
  drawCaret();
}

void CommandMode::drawCaret(){
  int f = ofGetFrameRate();
  int f2 = floor(f / 2.0); 
  if(caretLoopIndex > f){
    caretLoopIndex = 0;
    return;
  }
  if(caretLoopIndex < f2){
    ofPushMatrix();
      ofTranslate(command.length() * ui.getCharWidth(), 0, 0);
      caret.draw();
    ofPopMatrix();
  }
  ++caretLoopIndex;
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
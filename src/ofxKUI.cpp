#include "ofxKUI.h"

ofxKUI::ofxKUI(){
  ofRegisterKeyEvents(this); 
  ofSetEscapeQuitsApp(false);
  loadFont();
  initUI();
  prompt.append("> ");
  bShowDescription = true;
  bShowMode = true;
  mode = KUIMode::NORMAL;
  leader = ':';
}

void ofxKUI::loadFont(){
  font.load("Hack-v2_015-ttf/Hack-Regular.ttf", 10);
}

void ofxKUI::initUI(){
  float w = ofGetWidth();
  float fontHeight = font.getLineHeight();
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

void ofxKUI::setLeader(char c){
  leader = c;
}

void ofxKUI::draw(){
  ofPushStyle();
    ofDisableDepthTest();
    ofDisableLighting();
    if(bShowDescription){
      drawDescription();
    }
    if(mode == KUIMode::COMMAND){
      drawPrompt();
    }
    if(bShowMode){
      drawMode();
    }
    ofEnableLighting();
  ofPopStyle();
}

void ofxKUI::drawPrompt(){
  rect.draw(); 
  // Print prompt
  ofSetColor(ofColor::red);
  float x = comStrPos.x;
  font.drawString(prompt, x, comStrPos.y);
  // Print commands
  ofSetColor(ofColor::white);
  x += font.stringWidth(prompt) + 5;
  font.drawString(command, x, comStrPos.y);
  ofEnableLighting();
}

void ofxKUI::drawMode(){
  string m;
  switch(mode){
    case KUIMode::NORMAL:
      m = "normal";
      break;
    case KUIMode::COMMAND:
      m = "command";
      break;
  }
  float x = ofGetWidth() - font.stringWidth(m) - 5;
  font.drawString(m, x, comStrPos.y);
}

void ofxKUI::drawDescription(){
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

void ofxKUI::keyPressed(ofKeyEventArgs& key){
  ofLog() << key.key;

  if(mode == KUIMode::NORMAL){
    if(maps.find(key.key) != maps.end()){
      ofNotifyEvent(maps[key.key].event);
      return;
    }
    if(key.key == leader){
      mode = KUIMode::COMMAND;
      return;
    }
  }
  else if(mode == KUIMode::COMMAND){
    ofSetEscapeQuitsApp(false);
    if (key.key == 8) {
      if(command.length() > 0){
        command.pop_back();
      }
    }
    else if(key.key == 13){
      parseExecCommand(command);
      mode = KUIMode::NORMAL;
      command = "";
    }
    else if(key.key == 27){
      mode = KUIMode::NORMAL;
      command = "";
    }
    else {
      if(command.length() < 32){
        command.push_back(key.key);
      }
    }
  }
}

void ofxKUI::showDescription(bool b){
  bShowDescription = b;
}

void ofxKUI::showMode(bool b){
  bShowMode = b;
}

void ofxKUI::parseExecCommand(string cmd){
  ofLog() << cmd;
}

void ofxKUI::keyReleased(ofKeyEventArgs& key){

}
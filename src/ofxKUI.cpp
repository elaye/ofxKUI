#include "ofxKUI.h"

ofxKUI::ofxKUI(){
  ofRegisterKeyEvents(this); 
  loadFont();
  initUI();
  prompt.append("> ");
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
  ofPopStyle();
}

void ofxKUI::drawCommands(){
  float descWidth = 0;
  for(auto& m : maps){
    float w = font.stringWidth(m.second.desc);
    if(w > descWidth) descWidth = w;
  }

  ofPushStyle();
      ofDisableDepthTest();
      ofDisableLighting();
      float y = 15;
      for(auto& m : maps){
        string desc = m.second.desc;
        float x = ofGetWidth() - descWidth - 10;
        // ofSetColor(ofColor::green);
        ofSetColor(ofColor::white);
        font.drawString(desc, x, y); 
        y += font.getLineHeight();
      }
      ofEnableLighting();
  ofPopStyle();
}

void ofxKUI::keyPressed(ofKeyEventArgs& key){
  ofLog() << key.key;

  if(maps.find(key.key) != maps.end()){
    ofNotifyEvent(maps[key.key].event);
    return;
  }

  if(key.key == leader){
    ofLog() << "leader";
  }
  else if (key.key == 8) {
    if(command.length() > 0){
      command.pop_back();
    }
  }
  else {
    if(command.length() < 32){
      command.push_back(key.key);
    }
  }

}

void ofxKUI::keyReleased(ofKeyEventArgs& key){

}
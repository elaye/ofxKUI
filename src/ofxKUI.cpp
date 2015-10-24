#include "ofxKUI.h"

ofxKUI::ofxKUI(){
  ofRegisterKeyEvents(this); 
  initUI();
  loadFont();
}

void ofxKUI::loadFont(){
  font.load("Hack-v2_015-ttf/Hack-Regular.ttf", 32);
}

void ofxKUI::initUI(){
  float w = ofGetWidth();
  float h = 20;
  float x = 0; 
  float y = ofGetHeight() - h; 
  rect.rectangle(x, y, w, h);

  ofColor color = (0, 0, 0, 70);
  rect.setFillColor(color);
  rect.setFilled(true);

  comStrPos.x = x + 10;
  comStrPos.y = y;
}

void ofxKUI::setLeader(char c){
  leader = c;
}

void ofxKUI::draw(){
  ofPushStyle();
      ofEnableAlphaBlending();
      rect.draw(); 
      font.drawString(command.str(), comStrPos.x, comStrPos.y);
  ofPopStyle();
}

void ofxKUI::keyPressed(ofKeyEventArgs& key){
  if(key.key == leader){
    ofLog() << "leader";
  }
  command.put(key.key);
  ofLog() << command.str();
}

void ofxKUI::keyReleased(ofKeyEventArgs& key){
  // ofLog() << key.key;
}
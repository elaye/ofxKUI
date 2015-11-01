#include "ofxKUI.h"

ofxKUI::ofxKUI(){
  ofRegisterKeyEvents(this); 
  ofSetEscapeQuitsApp(false);
  loadFont();
  initUI();
  prompt = "> ";
  bShowDescription = true;
  bShowMode = true;
  bShowParameters = true;
  cameraPositionStep = 20;
  cameraAngleStep = 5;
  mode = KUIMode::NORMAL;
  camera = nullptr;
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

void ofxKUI::setCamera(ofCamera& cam){
  camera = &cam;
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
    if(bShowParameters){
      imode.drawParameters();
    }
    ofEnableLighting();
  ofPopStyle();
}

void ofxKUI::drawPrompt(){
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

void ofxKUI::drawMode(){
  string m;
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
    if(key.key == 'd'){
      mode = KUIMode::COMMAND;
      return;
    }
    if(key.key == 'c'){
      if(camera == nullptr) {
        ofLogError() << "You need to set a camera to use the camera mode";
        return;
      }
      mode = KUIMode::CAMERA;
      return;
    }
    if(key.key == 'i'){
      // TODO? Add warning when no parameters were set
      mode = KUIMode::INTERACTIVE;
      return;
    }
    if(key.key == 'f'){
      UI::toggleAdjustment();
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
  else if(mode == KUIMode::CAMERA){
    switch(key.key){
      // <Esc>
      case 27:
        mode = KUIMode::NORMAL;
        break;
      // Positions
      case 'd': camera->boom(cameraPositionStep); break;
      case 's': camera->boom(-cameraPositionStep); break;

      case 'z': camera->dolly(-cameraPositionStep); break;
      case 'x': camera->dolly(cameraPositionStep); break;

      case 'f': camera->truck(cameraPositionStep); break;
      case 'q': camera->truck(-cameraPositionStep); break;

      // Rotations
      case 'l': 
        camera->rotateAround(-cameraAngleStep, camera->getXAxis(), ofVec3f(0, 0, 0)); 
        camera->lookAt(ofVec3f(0, 0, 0));
        break;
      case 'k': 
        camera->rotateAround(cameraAngleStep, camera->getXAxis(), ofVec3f(0, 0, 0)); 
        camera->lookAt(ofVec3f(0, 0, 0));
        break;
      case 'j': 
        camera->rotateAround(-cameraAngleStep, ofVec3f(0, 1, 0), ofVec3f(0, 0, 0)); 
        camera->lookAt(ofVec3f(0, 0, 0));
        break;
      case 'm': 
        camera->rotateAround(cameraAngleStep, ofVec3f(0, 1, 0), ofVec3f(0, 0, 0)); 
        camera->lookAt(ofVec3f(0, 0, 0));
        break;
      case 32:
        UI::toggleAdjustment();
        break;
    }
  }
  else if(mode == KUIMode::INTERACTIVE){
    if(key.key == 27){
      mode = KUIMode::NORMAL;
      return;
    }
    if(key.key == 32){
      UI::toggleAdjustment();
    }
    imode.action(key.key);
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

void ofxKUI::addParameters(ofParameterGroup& param){
  imode.addParameters(param);
}

void ofxKUI::keyReleased(ofKeyEventArgs& key){

}
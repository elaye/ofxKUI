#include "ofxKUI.h"

ofxKUI::ofxKUI() :
  norMode(ui),
  comMode(ui),
  camMode(ui),
  intMode(ui)
{
  ofRegisterKeyEvents(this); 
  ofSetEscapeQuitsApp(false);
  bShowDescription = true;
  bShowMode = true;
  bShowParameters = true;
}

void ofxKUI::setCamera(ofCamera& cam){
  camMode.setCamera(cam);
}

void ofxKUI::draw(){
  ofPushStyle();
    ofDisableDepthTest();
    ofDisableLighting();
    if(bShowDescription){
      norMode.drawDescription();
    }
    if(ui.getMode() == KUIMode::COMMAND){
      comMode.drawPrompt();
    }
    if(bShowMode){
      ui.drawMode();
    }
    if(bShowParameters){
      intMode.drawParameters();
    }
    ofEnableLighting();
  ofPopStyle();
}

void ofxKUI::keyPressed(ofKeyEventArgs& event){
  auto key = event.key;
  ofLog() << key;
  auto mode = ui.getMode();
  if(mode == KUIMode::NORMAL){
    if(key == 'c' && camMode.getCamera() == nullptr){
      ofLogError() << "You need to set a camera to use the camera mode";
      return;
    }
    norMode.action(key);
  }
  else if(mode == KUIMode::COMMAND){
    comMode.action(key);
  }
  else if(mode == KUIMode::CAMERA){
    camMode.action(key);
  }
  else if(mode == KUIMode::INTERACTIVE){
    intMode.action(key);
  }
}

void ofxKUI::showDescription(bool b){
  bShowDescription = b;
}

void ofxKUI::showMode(bool b){
  bShowMode = b;
}

void ofxKUI::addParameters(ofParameterGroup& param){
  intMode.addParameters(param);
}

void ofxKUI::keyReleased(ofKeyEventArgs& key){

}
#include "ofxKUI.h"

ofxKUI::ofxKUI() :
  intMode(ui),
  comMode(ui),
  camMode(ui),
  norMode(ui),
  help(ui)
{
  ofRegisterKeyEvents(this); 
  ofSetEscapeQuitsApp(false);
  bShowDescription = true;
  bShowMode = true;
  bShowParameters = true;
  keyTimer = 0;
  lastKey = "";
  keyFont.load("Hack-v2_015-ttf/Hack-Regular.ttf", 32);
}

shared_ptr<Config> ofxKUI::getConfig(){
  return ui.getConfig();
}

void ofxKUI::setCamera(ofCamera& cam){
  camMode.setCamera(cam);
}

void ofxKUI::setGUI(ofxPanel& panel){
  intMode.setGUI(panel);
}

void ofxKUI::draw(){
  ofPushStyle();
    ofDisableDepthTest();
    //ofDisableLighting();
    if(bShowDescription){
      norMode.drawDescription();
    }
    if(ui.getMode() == KUIMode::COMMAND){
      comMode.draw();
    }
    if(bShowMode){
      ui.drawMode();
    }
    if(bShowParameters){
      // intMode.drawParameters();
    }
    if(bHelp){
      help.draw();
    }
    // drawKey();
    //ofEnableLighting();
  ofPopStyle();
}

void ofxKUI::keyPressed(ofKeyEventArgs& event){
  auto key = event.key;
  // ofLog() << key;
  setLastKey(key);
  auto mode = ui.getMode();
  if(key == '?'){
    bHelp = !bHelp;
  }
  if(mode == KUIMode::NORMAL){
    if(key == 'c' && camMode.getCamera() == nullptr){
      ofLogError() << "You need to set a camera to use the camera mode";
      return;
    }
    if(key == 'i'){
      intMode.enable();
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

void ofxKUI::setLastKey(char c){
  keyTimer = 1.0;
  switch(c){
    case KUIKey::Space:
      lastKey = "Space";
      break;
    case KUIKey::Esc:
      lastKey = "Esc";
      break;
    default:
      lastKey = c;
      break;
  }
}

void ofxKUI::drawKey(){
  float strWidth = keyFont.stringWidth(lastKey);
  float strHeight = keyFont.getLineHeight();
  float xc = ofGetWidth() - 200.0;
  float w = strWidth + 30.0;
  float h = strHeight + 15.0;
  float xr = xc - w / 2.0;
  float yr = ofGetHeight() - 150.0;
  float xs = xc - strWidth / 2.0 - 4;
  float ys = yr + strHeight;
  float a = 255 * keyTimer;

  ofSetColor(ofColor(127, 127, 127, a));
  // ofDrawRectRounded(xr, yr, w, h, 20);
  ofDrawRectangle(xr, yr, w, h);

  ofSetColor(ofColor(0, 0, 0, a));
  keyFont.drawString(lastKey, xs, ys);
  keyTimer *= 0.98;
}

// void ofxKUI::addParameters(ofParameterGroup& param){
//   intMode.addParameters(param);
// }

void ofxKUI::keyReleased(ofKeyEventArgs& key){

}

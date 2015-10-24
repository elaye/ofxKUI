#include "ofxKUI.h"

ofxKUI::ofxKUI(){
  ofRegisterKeyEvents(this); 
}

void ofxKUI::keyPressed(ofKeyEventArgs& key){
  switch(key.key){
    case 'd':
      ofLog() << "d";
      break;
    default:
      ofLog() << "def";
  }
}

void ofxKUI::keyReleased(ofKeyEventArgs& key){
  ofLog() << key.key;
}
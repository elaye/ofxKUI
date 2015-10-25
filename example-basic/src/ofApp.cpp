#include "ofApp.h"

void ofApp::setup(){
  newColor();
  kui.mapCommand('r', this, &ofApp::newColor, "New random color");
}

void ofApp::newColor(){
  color.r = ofRandom(255);
  color.g = ofRandom(255);
  color.b = ofRandom(255);
}

void ofApp::draw(){
  ofBackground(color); 
  kui.draw();
}

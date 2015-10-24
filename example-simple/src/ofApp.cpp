#include "ofApp.h"

void ofApp::setup(){
  // box.set(100);
  sphere.setRadius(100);
  light.setPosition(300, 300, 0);
  light.setAmbientColor(ofColor(100, 100, 100));
  material.setAmbientColor(ofColor(201, 167, 139));
  material.setDiffuseColor(ofColor(201, 198, 139));

}

void ofApp::update(){

}

void ofApp::draw(){
  ofBackgroundGradient( ofColor(40,40,40), ofColor(0,0,0), OF_GRADIENT_CIRCULAR); 
  ofEnableDepthTest();

  cam.begin();
    light.enable();
    material.begin();
      // box.draw();
      sphere.draw();
    material.end();
  cam.end();
}

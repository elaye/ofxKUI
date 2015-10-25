#include "ofApp.h"

void ofApp::setup(){

  geometry = Geometry::BOX;
  box.set(100);
  sphere.setRadius(100);

  light.setPosition(300, 300, 0);
  light.setAmbientColor(ofColor(100, 100, 100));
  light.enable();
  material.setAmbientColor(ofColor(201, 167, 139));
  material.setDiffuseColor(ofColor(201, 198, 139));

  kui.mapCommand('l', this, &ofApp::toggleLight, "Toggle light");
  kui.mapCommand('g', this, &ofApp::switchGeometry, "Switch geometry");

}

void ofApp::toggleLight(){
  if(light.getIsEnabled()){
    light.disable();
  }
  else{
    light.enable();
  }
}

void ofApp::switchGeometry(){
  if(geometry == Geometry::BOX){
    geometry = Geometry::SPHERE;
  }
  else{
    geometry = Geometry::BOX;
  }
}

void ofApp::update(){

}

void ofApp::draw(){
  ofBackgroundGradient( ofColor(40,40,40), ofColor(0,0,0), OF_GRADIENT_CIRCULAR); 
  ofEnableDepthTest();

  cam.begin();
    material.begin();
      // light.enable();
        if(geometry == Geometry::BOX){
          box.draw();
        }
        else{
          sphere.draw();
        }
      // light.disable();
    material.end();
  cam.end();

  kui.draw();
}

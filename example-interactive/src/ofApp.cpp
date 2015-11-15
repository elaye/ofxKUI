#include "ofApp.h"

void ofApp::setup(){

  box.set(100);

  light.setPosition(300, 300, 0);
  light.setAmbientColor(ofColor(100, 100, 100));
  light.enable();

  material.setAmbientColor(ofColor(201, 167, 139));
  material.setDiffuseColor(ofColor(201, 198, 139));

  parameters.setName("Parameters");
  parameters.add(scale.set("Scale", 25, 0, 200));
  parameters.add(scale1.set("Scale1", 125, 0, 200));
  parameters.add(button.set("Button", true));

  panel.setup(parameters);
  kui.setGUI(panel);
  // kui.addParameters(parameters);

}

void ofApp::update(){

}

void ofApp::draw(){
  ofBackgroundGradient( ofColor(40,40,40), ofColor(0,0,0), OF_GRADIENT_CIRCULAR); 
  ofEnableDepthTest();

  cam.begin();
    material.begin();
      box.draw();
    material.end();
  cam.end();

  ofEnableLighting();
  ofDisableDepthTest();
  panel.draw();
  kui.draw();
}

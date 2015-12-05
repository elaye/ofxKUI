#include "ofApp.h"

void ofApp::setup(){
  kui.setCamera(cam);
  kui.mapKey('r', &scene, &Scene::generate, "Regenerate the scene");
  cam.setPosition(0, 0, 2000);
}

void ofApp::draw(){
  ofDisableLighting();
  ofBackgroundGradient( ofColor(40,40,40), ofColor(0,0,0), OF_GRADIENT_CIRCULAR); 

  cam.begin();
    scene.draw();
  cam.end();

  kui.draw();
}

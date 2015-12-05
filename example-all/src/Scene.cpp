#include "Scene.h"

Scene::Scene(){
  generate();
  light.setPosition(300, 300, 0);
  light.setAmbientColor(ofColor(100, 100, 100));
  light.enable();
  material.setAmbientColor(ofColor(201, 167, 139));
  material.setDiffuseColor(ofColor(201, 198, 139));
}

void Scene::generate(){
  objects.clear();
  float s = 500;
  for(int i = 0; i < 100; ++i){
    ofBoxPrimitive box;
    box.set(ofRandom(50, 150));
    float x = ofRandom(-s, s);
    float y = ofRandom(-s, s);
    float z = ofRandom(-s, s);
    box.setPosition(x, y, z);
    objects.push_back(box);
  }
}

void Scene::draw(){
  ofEnableLighting();
    ofEnableDepthTest();
    material.begin();
      for(auto& o : objects){
        o.draw();
      }
    material.end();
  ofDisableLighting();
}
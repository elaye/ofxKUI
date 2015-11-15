#include "CameraMode.h"

CameraMode::CameraMode(UI& _ui) :
  ui(_ui) 
{
  camera = nullptr;
}

ofCamera* CameraMode::getCamera(){
  return camera;
}

void CameraMode::setCamera(ofCamera& cam){
  camera = &cam;
}

void CameraMode::action(char key){
   switch(key){
    case KUIKey::Esc:
      ui.setMode(KUIMode::NORMAL);
      break;
    // Positions
    case 'd': camera->boom(-getPositionStep()); break;
    case 's': camera->boom(getPositionStep()); break;

    case 'w': camera->dolly(-getPositionStep()); break;
    case 'x': camera->dolly(getPositionStep()); break;

    case 'f': camera->truck(-getPositionStep()); break;
    case 'a': camera->truck(getPositionStep()); break;

    // Rotations
    case 'l': 
      camera->rotateAround(-getAngleStep(), camera->getXAxis(), ofVec3f(0, 0, 0)); 
      camera->lookAt(ofVec3f(0, 0, 0));
      break;
    case 'k': 
      camera->rotateAround(getAngleStep(), camera->getXAxis(), ofVec3f(0, 0, 0)); 
      camera->lookAt(ofVec3f(0, 0, 0));
      break;
    case 'j': 
      camera->rotateAround(-getAngleStep(), ofVec3f(0, 1, 0), ofVec3f(0, 0, 0)); 
      camera->lookAt(ofVec3f(0, 0, 0));
      break;
    case ';': 
      camera->rotateAround(getAngleStep(), ofVec3f(0, 1, 0), ofVec3f(0, 0, 0)); 
      camera->lookAt(ofVec3f(0, 0, 0));
      break;
    case KUIKey::Space:
      ui.toggleAdjustment();
      break;
  } 
}

float CameraMode::getPositionStep(){
  if(ui.getAdjustment() == KUIAdjust::COARSE){
    return ui.getConfig()->getCameraPositionCoarse();
  }
  else{
    return ui.getConfig()->getCameraPositionFine();
  }
}

float CameraMode::getAngleStep(){
  if(ui.getAdjustment() == KUIAdjust::COARSE){
    return ui.getConfig()->getCameraAngleCoarse();
  }
  else{
    return ui.getConfig()->getCameraAngleFine();
  }
}
#include "CameraMode.h"

CameraMode::CameraMode(UI& _ui) :
  ui(_ui) 
{
  cameraPositionStep = 20;
  cameraAngleStep = 5;
  camera = nullptr;
  ofLog() << "camera init";
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
    case 'd': camera->boom(cameraPositionStep); break;
    case 's': camera->boom(-cameraPositionStep); break;

    case 'z': camera->dolly(-cameraPositionStep); break;
    case 'x': camera->dolly(cameraPositionStep); break;

    case 'f': camera->truck(cameraPositionStep); break;
    case 'q': camera->truck(-cameraPositionStep); break;

    // Rotations
    case 'l': 
      camera->rotateAround(-cameraAngleStep, camera->getXAxis(), ofVec3f(0, 0, 0)); 
      camera->lookAt(ofVec3f(0, 0, 0));
      break;
    case 'k': 
      camera->rotateAround(cameraAngleStep, camera->getXAxis(), ofVec3f(0, 0, 0)); 
      camera->lookAt(ofVec3f(0, 0, 0));
      break;
    case 'j': 
      camera->rotateAround(-cameraAngleStep, ofVec3f(0, 1, 0), ofVec3f(0, 0, 0)); 
      camera->lookAt(ofVec3f(0, 0, 0));
      break;
    case 'm': 
      camera->rotateAround(cameraAngleStep, ofVec3f(0, 1, 0), ofVec3f(0, 0, 0)); 
      camera->lookAt(ofVec3f(0, 0, 0));
      break;
    case 32:
      ui.toggleAdjustment();
      break;
  } 
}
#pragma once

#include "ofMain.h"

#include "UI.h"

#include "NormalMode.h"
#include "InteractiveMode.h"
#include "CameraMode.h"
#include "CommandMode.h"

class ofxKUI {

  UI ui;

  InteractiveMode intMode;
  CameraMode camMode;
  CommandMode comMode;
  NormalMode norMode;

  bool bShowDescription;
  bool bShowParameters;
  bool bShowMode;

  public:

    ofxKUI();
    void setCamera(ofCamera& camera);

    void draw();

    void showDescription(bool b);
    void showMode(bool b);

    template <class ListenerClass>
    void mapKey(char c, ListenerClass* listener, void (ListenerClass::*listenerMethod)(void), string desc = ""){
      norMode.mapKey(c, listener, listenerMethod, desc);
    }

    void addParameters(ofParameterGroup& parameters);

    void keyPressed(ofKeyEventArgs& key);
    void keyReleased(ofKeyEventArgs& key);

    static KUIAdjust getAdjustment();

  private:
    void initUI();

};
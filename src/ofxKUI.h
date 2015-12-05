#pragma once

#include "ofMain.h"

#include "ofxGui.h"

#include "UI.h"
#include "Config.h"
#include "Help.h"

#include "NormalMode.h"
#include "InteractiveMode.h"
#include "CameraMode.h"
#include "CommandMode.h"

class ofxKUI {

  UI ui;

  Help help;

  InteractiveMode intMode;
  CameraMode camMode;
  CommandMode comMode;
  NormalMode norMode;

  bool bShowDescription;
  bool bShowParameters;
  bool bShowMode;
  bool bHelp;

  ofTrueTypeFont keyFont;
  string lastKey;
  float keyTimer;

  public:

    ofxKUI();
    void setCamera(ofCamera& camera);

    shared_ptr<Config> getConfig();

    void draw();

    void showDescription(bool b);
    void showMode(bool b);

    template <class ListenerClass>
    void mapKey(char c, ListenerClass* listener, void (ListenerClass::*listenerMethod)(void), string desc = ""){
      norMode.mapKey(c, listener, listenerMethod, desc);
    }

    // void addParameters(ofParameterGroup& parameters);
    void setGUI(ofxPanel& panel);

    void keyPressed(ofKeyEventArgs& key);
    void keyReleased(ofKeyEventArgs& key);

    static KUIAdjust getAdjustment();

  private:
    void initUI();
    void drawKey();
    void setLastKey(char c);

};
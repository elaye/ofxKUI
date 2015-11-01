#pragma once

#include "ofMain.h"

#include "UI.h"
#include "InteractiveMode.h"

class ofxKUI {

  UI ui;

  ofPath rect;
  ofTrueTypeFont font;

  ofCamera* camera;
  float cameraPositionStep;
  float cameraAngleStep;

  string prompt;
  string command;
  ofPoint comStrPos;

  map<char, Command> maps;

  InteractiveMode imode;

  bool bShowDescription;
  bool bShowParameters;
  bool bShowMode;
  KUIMode mode;

  public:

    ofxKUI();
    void setCamera(ofCamera& camera);

    void draw();
    void drawPrompt();
    void drawMode();
    void drawDescription();

    void showDescription(bool b);
    void showMode(bool b);

    void parseExecCommand(string cmd);

    void addParameters(ofParameterGroup& parameters);

    void keyPressed(ofKeyEventArgs& key);
    void keyReleased(ofKeyEventArgs& key);

    static KUIAdjust getAdjustment();

    template <class ListenerClass>
    void mapCommand(char c, ListenerClass* listener, void (ListenerClass::*listenerMethod)(void), string desc = ""){
      if(c == 'i' || c == 'c' || c == 'd' || c == 32){
        ofLogWarning() << "Mapping a command using a character already used for mode switching";
      }
      ofEvent<void> e;
      Command com;
      com.event = e;
      if(desc == ""){
        com.desc = "";
      }
      else{
        stringstream cs;
        cs << c;
        com.desc = "[" + cs.str() + "] " + desc;
      }
      maps[c] = com;
      ofAddListener(maps[c].event, listener, listenerMethod);
    }

  private:
    void loadFont();
    void initUI();

};
#pragma once

#include "ofMain.h"

enum class KUIMode {
  NORMAL,
  COMMAND,
  CAMERA
};

struct Command {
  ofEvent<void> event;
  string desc;
};

class ofxKUI {

  ofPath rect;
  ofTrueTypeFont font;

  ofCamera* camera;
  float cameraPositionStep;
  float cameraAngleStep;

  string prompt;
  string command;
  ofPoint comStrPos;
  char leader;

  map<char, Command> maps;

  bool bShowDescription;
  bool bShowMode;
  KUIMode mode;

  public:
    ofxKUI();
    void setLeader(char c);
    void setCamera(ofCamera& camera);

    void draw();
    void drawPrompt();
    void drawMode();
    void drawDescription();

    void showDescription(bool b);
    void showMode(bool b);

    void parseExecCommand(string cmd);

    void keyPressed(ofKeyEventArgs& key);
    void keyReleased(ofKeyEventArgs& key);

    template <class ListenerClass>
    void mapCommand(char c, ListenerClass* listener, void (ListenerClass::*listenerMethod)(void), string desc = ""){
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
#pragma once

#include "ofMain.h"

struct Command {
  ofEvent<void> event;
  string desc;
};

class ofxKUI {

  ofPath rect;
  ofPath descRect;
  ofTrueTypeFont font;

  string prompt;
  string command;
  ofPoint comStrPos;
  char leader;

  map<char, Command> maps;

  public:
    ofxKUI();
    void setLeader(char c);

    void draw();
    void drawCommands();

    void keyPressed(ofKeyEventArgs& key);
    void keyReleased(ofKeyEventArgs& key);

    template <class ListenerClass>
    void mapCommand(char c, ListenerClass* listener, void (ListenerClass::*listenerMethod)(void), string desc = ""){
      ofEvent<void> e;
      Command com;
      com.event = e;
      stringstream cs;
      cs << c;
      com.desc = "[" + cs.str() + "] " + desc;
      maps[c] = com;
      ofAddListener(maps[c].event, listener, listenerMethod);
    }

  private:
    void loadFont();
    void initUI();

};
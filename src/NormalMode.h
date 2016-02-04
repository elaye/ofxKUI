#pragma once

#include "ofMain.h"

#include "UI.h"

struct Command {
  ofEvent<void> event;
  string desc;
};

class NormalMode {

  UI& ui;

  map<char, Command> maps;

  public:
    NormalMode(UI& ui);

    void action(char key);
    void drawDescription();

    string getKeyString(char c);

    template <class ListenerClass>
    void mapKey(char c, ListenerClass* listener, void (ListenerClass::*listenerMethod)(void), string desc = ""){
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
//        stringstream cs;
//        cs << getKeyString(c);
//        com.desc = "[" + cs.str() + "] " + desc;
        com.desc = "[" + getKeyString(c) + "] " + desc;
      }
      maps[c] = com;
      ofAddListener(maps[c].event, listener, listenerMethod);
    }
};

#pragma once

#include "ofMain.h"

#include "UI.h"

class CommandMode {

  UI& ui;
  string command;

  string prompt;
  ofPoint comStrPos;

  ofPath rect;

  public:
    CommandMode(UI& ui);

    void action(char key);
    void drawPrompt();

  private:
  	void initUI();
    void parseExecCommand(string cmd);
};
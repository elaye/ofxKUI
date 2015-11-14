#pragma once

#include "ofMain.h"

#include "UI.h"

class CommandMode {

  UI& ui;
  string command;

  string prompt;
  ofPoint comStrPos;

  ofPath rect;
  ofPath caret;

  int caretLoopIndex;

  public:
    CommandMode(UI& ui);

    void action(char key);
    void draw();

  private:
    void caretForward();
    void caretBackward();
    void drawPrompt();
    void drawCaret();
  	void initUI();
    void windowResized(ofResizeEventArgs& event);
    void parseExecCommand(string cmd);
};
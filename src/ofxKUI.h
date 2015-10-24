#pragma once

#include "ofMain.h"

class ofxKUI {

  ofPath rect;
  ofTrueTypeFont font;

  std::ostringstream command;
  ofPoint comStrPos;
  char leader;

  public:
    ofxKUI();
    void map(char c);
    void setLeader(char c);

    void draw();

    void keyPressed(ofKeyEventArgs& key);
    void keyReleased(ofKeyEventArgs& key);

  private:
    void loadFont();
    void initUI();

};
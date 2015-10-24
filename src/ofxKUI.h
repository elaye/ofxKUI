#pragma once

#include "ofMain.h"

class ofxKUI {

  public:
    ofxKUI();
    void map(char c);

    void keyPressed(ofKeyEventArgs& key);
    void keyReleased(ofKeyEventArgs& key);

};
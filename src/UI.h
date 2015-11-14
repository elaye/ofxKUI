#pragma once

#include "ofMain.h"

enum class KUIMode {
  NORMAL,
  COMMAND,
  INTERACTIVE,
  CAMERA
};

enum class KUIAdjust {
  COARSE,
  FINE
};

namespace KUIKey {
  const int Space = 32;
  const int Esc = 27;
  const int Return = 13;
  const int Backspace = 8;
};

class UI {

  KUIMode mode;
  KUIAdjust adjust;

  ofTrueTypeFont font;

  public:
    UI();
    ofTrueTypeFont& getFont();
    KUIMode getMode();
    void setMode(KUIMode mode);

    KUIAdjust getAdjustment();
    void setAdjustment(KUIAdjust adj);
    void toggleAdjustment();

    void drawMode();

  private: 
    void loadFont();

};
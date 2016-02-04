#pragma once

#include "ofMain.h"

#include "Config.h"

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

  shared_ptr<Config> config;

  string fontPath;
  ofTrueTypeFont font;

  bool bUseFont;

  float charWidth;
  float lineHeight;

  public:
    UI(string fontPath = "");
    ofTrueTypeFont& getFont();
    string getFontPath();

    shared_ptr<Config> getConfig();
    void setConfig(shared_ptr<Config> config);

    KUIMode getMode();
    void setMode(KUIMode mode);

    KUIAdjust getAdjustment();
    void setAdjustment(KUIAdjust adj);
    void toggleAdjustment();

    float getCharWidth();
    void drawMode();

    void drawString(string str, float x, float y);
    float stringWidth(string str);
    float getLineHeight();

  private: 
    void loadFont();

};

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

// enum class KUIKey {
// space = 32
// };

struct Command {
  ofEvent<void> event;
  string desc;
};

class UI {

  static KUIAdjust adjust;

  public:
    static KUIAdjust getAdjustment();
    static void setAdjustment(KUIAdjust adj);
    static void toggleAdjustment();

};
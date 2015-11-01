#include "UI.h"

KUIAdjust UI::adjust = KUIAdjust::COARSE;

KUIAdjust UI::getAdjustment(){
  return UI::adjust;
}

void UI::setAdjustment(KUIAdjust adj){
  UI::adjust = adj;
}

void UI::toggleAdjustment(){
  if(UI::adjust == KUIAdjust::COARSE){
    UI::adjust = KUIAdjust::FINE;
  }
  else{
    UI::adjust = KUIAdjust::COARSE;
  }
}
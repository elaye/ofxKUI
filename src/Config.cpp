#include "Config.h"

Config::Config(){
  setupDarkTheme();
  setupLightTheme();
  useDarkTheme();
}

void Config::setupDarkTheme(){
  darkTheme.headerBackgroundColor = ofColor(0, 0, 0, 225);
  darkTheme.backgroundColor = ofColor(0, 0, 0, 200);
  darkTheme.selectedBackgroundColor = ofColor(50, 50, 50, 200);
  darkTheme.fillColor = ofColor(75, 75, 75, 200);
  darkTheme.selectedFillColor = ofColor(100, 100, 100, 200);
  darkTheme.textColor = ofColor(200, 200, 200, 255);
  darkTheme.selectedTextColor = ofColor(255, 255, 255, 255);
  darkTheme.borderColor = ofColor(200, 200, 200, 255);
  darkTheme.selectedBorderColor = ofColor(255, 255, 255, 255);
}

void Config::setupLightTheme(){
  lightTheme.headerBackgroundColor = ofColor(255, 255, 255, 225);
  lightTheme.backgroundColor = ofColor(255, 255, 255, 200);
  lightTheme.selectedBackgroundColor = ofColor(200, 200, 200, 200);
  lightTheme.fillColor = ofColor(180, 180, 180, 200);
  lightTheme.selectedFillColor = ofColor(155, 155, 155, 200);
  lightTheme.textColor = ofColor(55, 55, 55, 255);
  lightTheme.selectedTextColor = ofColor(0, 0, 0, 255);
  lightTheme.borderColor = ofColor(55, 55, 55, 255);
  lightTheme.selectedBorderColor = ofColor(0, 0, 0, 255);
}

void Config::useDarkTheme(){
  setTheme(darkTheme);
}

void Config::useLightTheme(){
  setTheme(lightTheme);
}

GUITheme Config::getTheme(){
  return currentTheme;
}

void Config::setTheme(GUITheme theme){
  ofxGuiSetBackgroundColor(theme.backgroundColor);
  ofxGuiSetFillColor(theme.fillColor);
  ofxGuiSetHeaderColor(theme.headerBackgroundColor);
  ofxGuiSetTextColor(theme.textColor);
  ofxGuiSetBorderColor(theme.borderColor);
  currentTheme = theme;
}
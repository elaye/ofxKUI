#pragma once

#include "ofMain.h"
#include "ofxKUI.h"

class ofApp : public ofBaseApp{

	ofEasyCam cam;

	ofBoxPrimitive box;
	ofSpherePrimitive sphere;

	ofMaterial material;
	ofLight light;

	ofxKUI kui;

	public:
		void setup();
		void update();
		void draw();

};

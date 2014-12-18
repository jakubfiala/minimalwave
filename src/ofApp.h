#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "ofxMaxim.h"
#include <vector>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    vector<double> waveform;
    maxiSample player;
    maxiMix mix;
    maxiEnvelope env;
    double outputs[2];
    double rate;
    double adsr[8] = {1, 200, 0.4, 500, 0.35, 500, 0, 700};
    
    void audioRequested(float * output, int bufferSize, int nChannels);
		
};

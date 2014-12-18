#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    for (int i = 0; i < 1024; i++) {
        waveform.push_back(0);
    }
    ofSetColor(255);
    
    
    ofSoundStreamSetup(2,0,this, 44100, 512, 4);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < 1024; i++) {
        ofRect((float)i, (float)waveform[i] + 300, 1, 1);
    }
}

void ofApp::audioRequested(float * output, int bufferSize, int nChannels)
{
    for (int i = 0; i < bufferSize; i++){
        double out = player.jfBufferPlay(waveform, 1024);
        
        mix.stereo(out, outputs, 0.5);
        
        output[0] = outputs[0];
        output[1] = outputs[1];
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int mx, int my, int button){
    waveform[mx] = my - 300;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

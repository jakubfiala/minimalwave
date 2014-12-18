#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    for (int i = 0; i < 1024; i++) {
        waveform.push_back(0);
    }
    ofSetColor(255);
    
    rate = 1;
    env.amplitude = 0;
    
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
        double out = player.jfBufferPlay(waveform, 1024, rate);
        
        double adsrOut = env.line(8, adsr);
        mix.stereo(out*adsrOut, outputs, 0.5);
        
        output[0] = outputs[0];
        output[1] = outputs[1];
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 97: //a
            rate = 1;
            break;
        case 119: //w
            rate = 1.059463;
            break;
        case 115: //s
            rate = 1.1224618484;
            break;
        case 101: //e
            rate = 1.1892067973;
            break;
        case 100: //d
            rate = 1.2599206011;
            break;
        case 102: //f
            rate = 1.3348392598;
            break;
        case 116: //t
            rate = 1.4142128067;
            break;
        case 103: //g
            rate = 1.4983061428;
            break;
        case 122: //z
            rate = 1.587399921;
            break;
        case 104: //h
            rate = 1.6817914825;
            break;
        case 117: //u
            rate = 1.7817958494;
            break;
        case 106: //j
            rate = 1.887746776;
            break;
        case 107: //k
            rate = 2.0;
            break;
            
        default:
            break;
    }
    env.trigger(0, adsr[0]);
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

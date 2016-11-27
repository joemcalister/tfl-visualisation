#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

    // easycam support
    camera = ofEasyCam();
    
    // create vis object
    visObject = VisObject();
    
    // set loading flag
    loading = true;
    
    // load the background thread for the vis object
    visThread.visObject = &visObject;
    visThread.startThread();
    
    // colour code toggle
    colourCodeToggle = JSButton(ofGetWidth()-170, 20, 150, 40, "Toggle colour");
    colourCodeToggle.setBackgroundColorNormal(255, 255, 255);
    colourCodeToggle.setBorderWidth(1);
    colourCodeToggle.setBorderColor(0, 0, 0);
    
    // load font -- remove soon
    font.load("SF-UI-Display-Medium.otf", 12);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // redraw background
    ofBackground(255);
    
    // if loaded, draw
    if (visObject.loaded)
    {
        camera.begin();
        visObject.draw();
        camera.end();
    }
    
    // draw the colour code button
    colourCodeToggle.draw();
    
    // load the font -- do this in a custom label class next time
    if (!visObject.loaded)
    {
        font.drawString("Asking TfL for data...", (ofGetWidth()/2) - (font.stringWidth("Asking TfL for data...")/2), ofGetHeight()/2);
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
void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::buttonCallback(bool finshed)
{
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //colourCodeToggle.mousePressed(&buttonCallback, x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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

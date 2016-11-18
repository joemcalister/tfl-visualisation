#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

    //debugButton = UIButton(300, 300, 100, 50, "It works!");
    //debugButton.setBackgroundColorNormal(255, 100, 0);
    //debugButton.setBackgroundColorHover(0, 255, 100);
    
   
    float r = 10;
    float y = 100;
    for (int i=0; i<30; i++)
    {
        circle c = circle(r, y);
        circles.push_back(c);
        
        r+=3;
        y-=3;
    }
    
    camera = ofEasyCam();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  
    
    ofBackground(255);
    
    //debugButton.draw();
    
    
    camera.begin();
    for (auto &circle:circles)
    {
        circle.draw();
    }
    camera.end();
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

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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

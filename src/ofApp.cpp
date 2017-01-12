#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    // easycam support
    camera = ofEasyCam();
    camera.disableMouseMiddleButton();
    
    // create vis object
    visObject = VisObject();
    smallObject = VisObject();
    
    // set loading flag
    loading = true;
    ready = false;
    
    // load the background thread for the vis object
    visThread.visObject = &visObject;
    visThread.startThread();
    
    // colour code toggle
    colourCodeToggle = JSButton(ofGetWidth()-170, 20, 150, 40, "Toggle colour");
    
    // view layers toggle
    viewLayers = JSButton(ofGetWidth()-170, 65, 150, 40, "View layers");
    
    // up layer toggle
    upLayer = JSButton(ofGetWidth()-170, 110, 150, 40, "UP");
    
    // down layer toggle
    downLayer = JSButton(ofGetWidth()-170, 155, 150, 40, "DOWN");
    
    // create vector of buttons for loop
    vector <JSButton*> buttons = {&colourCodeToggle, &viewLayers, &upLayer, &downLayer};
    for (auto &button:buttons)
    {
        // apply styling to the buttons
        button->setBackgroundColorNormal(0, 0, 0);
        button->setBorderWidth(1);
        button->setBorderColor(255,255,255);
        button->setTextColor(255, 255, 255);
        button->setHighlightedTextColor(0, 0, 0);
        button->setBackgroundColorOn(255, 255, 255);
        button->setOnTextColor(0, 0, 0);
    }
    
    paragraph = ofxParagraph("Descriptive text here", 300);
    paragraph.setColor(ofColor(255,255,255));
    paragraph.setFont("SF-UI-Display-Medium.otf", 12);
    paragraph.setLeading(5);
    paragraph.setIndent(0);
    paragraph.setAlignment(ofxParagraph::ALIGN_LEFT);
    
    // load font -- remove soon
    font.load("SF-UI-Display-Medium.otf", 12);
    
    // load my logo
    logo.load("logo.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // redraw background
    ofBackground(0);
    
    // if loaded, draw
    if (ready)
    {
        camera.begin();
        visObject.draw();
        camera.end();
        
        // draw the colour code button
        if (!visObject.layerMode)
        {
            colourCodeToggle.draw();
        }else {
            colourCodeToggle.hide();
        }
        
        if (visObject.coloured)
        {
            viewLayers.draw();
        }else {
            viewLayers.hide();
        }
        
        if (visObject.layerMode)
        {
            upLayer.draw();
            downLayer.draw();
            paragraph.draw(50, 70);
        }else {
            upLayer.hide();
            downLayer.hide();
        }
    }
    
    // load the font -- do this in a custom label class next time
    if (!ready)
    {
        ofSetColor(255, 255, 255);
        
        string tflString;
        if (!visObject.loaded)
        {
            tflString = "Fetching recent data from TfL...\nControls: Page scroll zooms in and out, click and drag to pan around the object.\nKey: Red to yellow == Most to least severe, the smaller the more recent the incident.";
            ofHideCursor();
        }else {
            tflString = "\nControls: Page scroll zooms in and out, click and drag to pan around the object.\nKey: Red to yellow == Most to least severe, the smaller the more recent the incident.\n\nClick to begin.";
            ofShowCursor();
        }
        
        // fraw the fonts string
        font.drawString(tflString, (ofGetWidth()/2) - (font.stringWidth(tflString)/2), ofGetHeight()/2);
        
        // also draw my logo at the bottom center
        logo.draw((ofGetWidth()/2) - 25, ofGetHeight()-125, 50, 56);
        
    }else {
        // fallback to make sure the cursor is always visible
        ofShowCursor();
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

void ofApp::toggleColourCallback(bool clicked)
{
    if (clicked)
    {
        visObject.coloured = !visObject.coloured;
        colourCodeToggle.on = !colourCodeToggle.on;
    }
}

void ofApp::viewLayersCallback(bool clicked)
{
    if (clicked)
    {
        if (!visObject.layerMode)
        {
            paragraph.setText(visObject.descriptionForLayer(visObject.layerIndex));
        }
        visObject.toggleLayers(!visObject.layerMode);
        viewLayers.on = !viewLayers.on;
    }
}

void ofApp::upLayerCallback(bool clicked)
{
    if (clicked&&visObject.layerIndex > 0)
    {
        visObject.layerIndex -= 1;
        paragraph.setText(visObject.descriptionForLayer(visObject.layerIndex));
    }
}

void ofApp::downLayerCallback(bool clicked)
{
    if (clicked&&visObject.layerIndex<(visObject.numberOfLayers()-1))
    {
        visObject.layerIndex += 1;
        paragraph.setText(visObject.descriptionForLayer(visObject.layerIndex));
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    // trigger ready if needed, this hides the splash screen
    if (!ready)
    {
        ready = true;
    }
    
    // add the mouse pressed handler for colourcodetoggle
    colourCodeToggle.addHandler(std::bind(&ofApp::toggleColourCallback, this, std::placeholders::_1));
    
    // add the mouse pressed handler for viewlayers
    viewLayers.addHandler(std::bind(&ofApp::viewLayersCallback, this, std::placeholders::_1));
    
    // add the mouse pressed handler for upLayer
    upLayer.addHandler(std::bind(&ofApp::upLayerCallback, this, std::placeholders::_1));
    
    // add the mouse pressed handler for downLayer
    downLayer.addHandler(std::bind(&ofApp::downLayerCallback, this, std::placeholders::_1));
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

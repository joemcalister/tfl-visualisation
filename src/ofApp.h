#pragma once

#include "ofMain.h"
#include "JSButton.hpp"
#include "circle.hpp"
#include "VisObject.hpp"
#include <vector>
#include <thread>
#include "ofxParagraph.h"

class VisThread : public ofThread {
    
    // thread function
    void threadedFunction() {
        // create the vis object
        visObject->createVisObject();
    }
    
    public:
        VisObject *visObject;
};

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void toggleColourCallback(bool clicked);
        void viewLayersCallback(bool clicked);
        void upLayerCallback(bool clicked);
        void downLayerCallback(bool clicked);
        JSButton debugButton, colourCodeToggle, viewLayers, upLayer, downLayer;
        ofEasyCam camera;
        vector <circle> circles;
        VisObject visObject;
        bool loading;
        VisThread visThread;
        ofTrueTypeFont font;
        ofxParagraph paragraph;
        ofImage logo;
};



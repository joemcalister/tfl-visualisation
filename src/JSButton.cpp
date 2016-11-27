//
//  uibutton.cpp
//  traffic-visualization
//
//  Created by Joe on 07/11/2016.
//
//

#include "JSButton.hpp"

JSButton::JSButton(float _x, float _y, float _w, float _h, string _t)
{
    // set non-user defaults
    regularBackground = ofColor();
    regularBackground.r = 210;
    regularBackground.g = 210;
    regularBackground.b = 210;
    hoverBackground.r = 200;
    hoverBackground.g = 200;
    hoverBackground.b = 200;
    borderColor.r = 0;
    borderColor.g = 0;
    borderColor.b = 0;
    borderWidth = 0;
    
    
    // set the coordinates
    base.x = _x;
    base.y = _y;
    base.width = _w;
    base.height = _h;
    highlightCover.x = _x;
    highlightCover.y = _y + 2;
    highlightCover.width = _w;
    highlightCover.height = _h - 2;
    shadowCover.x = _x;
    shadowCover.y = _y + 2;
    shadowCover.width = _w;
    shadowCover.height = _h;
    
    // set title
    title = _t;
    
    // load font
    font.load("SF-UI-Display-Medium.otf", 12);
    
}

JSButton::JSButton()
{
    // set non-user defaults
    regularBackground = ofColor();
    regularBackground.r = 210;
    regularBackground.g = 210;
    regularBackground.b = 210;
    hoverBackground.r = 200;
    hoverBackground.g = 200;
    hoverBackground.b = 200;
    borderColor.r = 0;
    borderColor.g = 0;
    borderColor.b = 0;
    borderWidth = 0;
    
    
    // set the default coordinates and string
    base.x = 0;
    base.y = 0;
    base.width = 50;
    base.height = 50;
    
    // load font
    font.load("SF-UI-Display-Medium.otf", 12);
}

void JSButton::draw()
{
    // draw the rectangle
    ofFill();
    
    
    // detect mouse over
    if (((ofGetMouseX() >= base.x)&&(ofGetMouseX() <= base.x + base.width))&&((ofGetMouseY() >= base.y)&&(ofGetMouseY() <= base.y + base.height)))
    {
        
        // draw a border -- change to polyline method soon
        if (borderWidth > 0)
        {
            ofRectangle newRect = ofRectangle();
            newRect.x = base.x-1;
            newRect.y = base.y-1;
            newRect.width = base.width+2;
            newRect.height = base.height+2;
            
            ofSetColor(borderColor);
            ofDrawRectRounded(newRect, 10);
        }
    
        // mouse over
        ofSetColor(hoverBackground);
        
        // draw the shadow
        if (ofGetMousePressed())
        {
            ofSetColor(hoverBackground-30);
            ofDrawRectRounded(shadowCover, 10);
        }
        
        // draw the rectangle
        ofSetColor(hoverBackground);
        ofDrawRectRounded(base, 10);
        
        
        // mouse is pressed
        if (ofGetMousePressed())
        {
            ofSetColor(hoverBackground-20);
            ofDrawRectRounded(highlightCover, 10);
        }
        
    }else {
        // mouse not over
        
        // draw a border -- change to polyline method soon
        if (borderWidth > 0)
        {
            ofRectangle newRect = ofRectangle();
            newRect.x = base.x-1;
            newRect.y = base.y-1;
            newRect.width = base.width+2;
            newRect.height = base.height+2;
            
            ofSetColor(borderColor);
            ofDrawRectRounded(newRect, 10);
        }
        
        // draw the rectangle
        ofSetColor(regularBackground);
        ofDrawRectRounded(base, 10);
        
    }
    
    
    // draw the text
    ofPushMatrix();
    ofTranslate(base.x, base.y);
    ofSetColor(0,0,0);
    
    // load the font
    font.drawString(title, (base.width/2) - (font.stringWidth(title)/2), 25);
    
    // pop the matrix
    ofPopMatrix();

    
}

void JSButton::setBackgroundColorNormal(float _r, float _g, float _b)
{
    // set the regular background -- this is when the mouse is not over or pressed
    regularBackground.r = _r;
    regularBackground.g = _g;
    regularBackground.b = _b;
}

void JSButton::setBackgroundColorHover(float _r, float _g, float _b)
{
    // set the hover background -- this is when the mouse is over the button but not pressed
    hoverBackground.r = _r;
    hoverBackground.g = _g;
    hoverBackground.b = _b;
}

void JSButton::setBorderColor(float _r, float _g, float _b)
{
    // set the border color
    borderColor.r = _r;
    borderColor.g = _g;
    borderColor.b = _b;
}

void JSButton::setBorderWidth(int width)
{
    // set the border width
    borderWidth = width;
}

/*
void JSButton::mousePressed(void (*ofApp::callback)(bool), int _x, int _y, int _button)
{
    callback(true);
}
*/


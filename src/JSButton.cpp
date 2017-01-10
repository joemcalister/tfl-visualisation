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
    regularBackground = ofColor(210,210,210);
    hoverBackground = ofColor(200,200,200);
    borderColor = ofColor(0,0,0);
    borderWidth = 0;
    textColor = ofColor(255,255,255);
    onTextColor = ofColor(255,255,255);
    highlightedTextColor = ofColor(255,255,255);
    onBackground = ofColor(210,210,210);
    
    
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
    regularBackground = ofColor(210,210,210);
    hoverBackground = ofColor(200,200,200);
    borderColor = ofColor(0,0,0);
    borderWidth = 0;
    textColor = ofColor(255,255,255);
    onTextColor = ofColor(255,255,255);
    highlightedTextColor = ofColor(255,255,255);
    onBackground = ofColor(210,210,210);
    
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
    // not hidden
    hidden = false;
    
    // draw the rectangle
    ofFill();
    
    // detect mouse over
    ofColor textCol;
    if (((ofGetMouseX() >= base.x)&&(ofGetMouseX() <= base.x + base.width))&&((ofGetMouseY() >= base.y)&&(ofGetMouseY() <= base.y + base.height)))
    {
        // text color
        textCol = highlightedTextColor;
        
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
        
        // text color
        if (!on)
        {
            textCol = textColor;
        }else {
            textCol = onTextColor;
        }
        
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
        if (on)
        {
            ofSetColor(onBackground);
        }else {
            ofSetColor(regularBackground);
        }
        
        ofDrawRectRounded(base, 10);
    }
    
    // draw the text
    ofPushMatrix();
    ofTranslate(base.x, base.y);
    ofSetColor(textCol);
    
    // load the font
    font.drawString(title, (base.width/2) - (font.stringWidth(title)/2), 25);
    
    // pop the matrix
    ofPopMatrix();
}

void JSButton::hide()
{
    hidden = true;
}

void JSButton::setBackgroundColorNormal(float _r, float _g, float _b)
{
    // set the regular background -- this is when the mouse is not over or pressed
    regularBackground = ofColor(_r,_g,_b);
}

void JSButton::setBackgroundColorHover(float _r, float _g, float _b)
{
    // set the hover background -- this is when the mouse is over the button but not pressed
    hoverBackground = ofColor(_r,_g,_b);
}

void JSButton::setBorderColor(float _r, float _g, float _b)
{
    // set the border color
    borderColor = ofColor(_r,_g,_b);
}

void JSButton::setBorderWidth(int width)
{
    // set the border width
    borderWidth = width;
}

void JSButton::setTextColor(float _r, float _g, float _b)
{
    textColor = ofColor(_r, _g, _b);
}

void JSButton::setOnTextColor(float _r, float _g, float _b)
{
    onTextColor = ofColor(_r, _g, _b);
}

void JSButton::setHighlightedTextColor(float _r, float _g, float _b)
{
    highlightedTextColor = ofColor(_r, _g, _b);
}

void JSButton::setBackgroundColorOn(float _r, float _g, float _b)
{
    onBackground = ofColor(_r, _g, _b);
}

void JSButton::addHandler(std::function<void(bool)> callback)
{
    // determine if was pressed
    if ((((ofGetMouseX() >= base.x)&&(ofGetMouseX() <= base.x + base.width))&&((ofGetMouseY() >= base.y)&&(ofGetMouseY() <= base.y + base.height))) && !hidden)
    {
        // mouse was pressed
        callback(true);
    }else {
        // mouse was not pressed
        callback(false);
    }
}



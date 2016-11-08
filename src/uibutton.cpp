//
//  uibutton.cpp
//  traffic-visualization
//
//  Created by Joe on 07/11/2016.
//
//

#include "uibutton.hpp"

UIButton::UIButton(float _x, float _y, float _w, float _h, string _t)
{
    // set non-user defaults
    regularBackground = ofColor();
    regularBackground.r = 210;
    regularBackground.g = 210;
    regularBackground.b = 210;
    hoverBackground.r = 200;
    hoverBackground.g = 200;
    hoverBackground.b = 200;
    
    
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
    
    
    
    title = _t;
    
    // load font
    font.loadFont("SF-UI-Display-Medium.otf", 12);
    
}

UIButton::UIButton()
{
    // set non-user defaults
    regularBackground = ofColor();
    regularBackground.r = 210;
    regularBackground.g = 210;
    regularBackground.b = 210;
    
    
    // set the default coordinates and string
    base.x = 0;
    base.y = 0;
    base.width = 50;
    base.height = 50;
    
    // load font
    font.loadFont("SF-UI-Display-Medium.otf", 12);
}

void UIButton::draw()
{
    // draw the rectangle
    ofFill();
    
    // detect mouse over
    if (((ofGetMouseX() >= base.x)&&(ofGetMouseX() <= base.x + base.width))&&((ofGetMouseY() >= base.y)&&(ofGetMouseY() <= base.y + base.height)))
    {
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
        
        // draw the rectangle
        ofSetColor(regularBackground);
        ofDrawRectRounded(base, 10);
    }
    
    
    // draw the text
    ofPushMatrix();
    ofTranslate(base.x, base.y);
    ofSetColor(0,0,0);
    
    // load the font
    font.drawString(title, (base.width/2) - (font.stringWidth(title)/2), 30);
    
    // pop the matrix
    ofPopMatrix();

    
}

void UIButton::setBackgroundColorNormal(float _r, float _g, float _b)
{
    // set the regular background -- this is when the mouse is not over or pressed
    regularBackground.r = _r;
    regularBackground.g = _g;
    regularBackground.b = _b;
}

void UIButton::setBackgroundColorHover(float _r, float _g, float _b)
{
    // set the hover background -- this is when the mouse is over the button but not pressed
    hoverBackground.r = _r;
    hoverBackground.g = _g;
    hoverBackground.b = _b;
}


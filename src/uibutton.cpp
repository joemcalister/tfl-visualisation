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
    regularBackground.r = 255;
    regularBackground.g = 255;
    regularBackground.b = 255;
    
    
    // set the coordinates
    base.x = _x;
    base.y = _y;
    base.width = _w;
    base.height = _h;
    title = _t;
    
}

UIButton::UIButton()
{
    // set non-user defaults
    regularBackground = ofColor();
    regularBackground.r = 255;
    regularBackground.g = 255;
    regularBackground.b = 255;
    
    
    // set the default coordinates and string
    base.x = 0;
    base.y = 0;
    base.width = 50;
    base.height = 50;
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
    }else {
        // mouse not over
        ofSetColor(regularBackground);
    }
    
    
    
    
    ofDrawRectRounded(base, 10);
    
 
    // draw the text
    ofPushMatrix();
    ofTranslate(base.x, base.y);
    ofSetColor(0,0,0);
    ofDrawBitmapString(title, 0, 0);
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


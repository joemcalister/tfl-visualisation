//
//  uibutton.hpp
//  traffic-visualization
//
//  Created by Joe on 07/11/2016.
//
//

#ifndef JSButton_hpp
#define JSButton_hpp

#include <stdio.h>
#include "ofMain.h"
#include <string>

class JSButton
{
    public:
        JSButton();
        JSButton(float _x, float _y, float _w, float _h, string _t);
        void draw();
    
        void setBackgroundColorNormal(float _r, float _g, float _b);
        void setBackgroundColorHover(float _r, float _g, float _b);
    private:
        ofRectangle base, highlightCover, shadowCover;
        string title;
        ofColor regularBackground, hoverBackground;
        ofTrueTypeFont font;
};

#endif /* JSButton_hpp */

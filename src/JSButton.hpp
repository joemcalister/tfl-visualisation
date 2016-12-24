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
        void hide();
        void setBackgroundColorNormal(float _r, float _g, float _b);
        void setBackgroundColorHover(float _r, float _g, float _b);
        void setBackgroundColorOn(float _r, float _g, float _b);
        void setBorderColor(float _r, float _g, float _b);
        void setBorderWidth(int width);
        void setTextColor(float _r, float _g, float _b);
        void setHighlightedTextColor(float _r, float _g, float _b);
        void setOnTextColor(float _r, float _g, float _b);
        void addHandler(std::function<void(bool)> callback);
        bool on = false;
    private:
        bool hidden;
        ofRectangle base, highlightCover, shadowCover;
        string title;
        ofColor regularBackground, hoverBackground, onBackground, borderColor, textColor, highlightedTextColor, onTextColor;
        ofTrueTypeFont font;
        int borderWidth;
};

#endif /* JSButton_hpp */

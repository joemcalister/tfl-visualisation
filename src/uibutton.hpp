//
//  uibutton.hpp
//  traffic-visualization
//
//  Created by Joe on 07/11/2016.
//
//

#ifndef uibutton_hpp
#define uibutton_hpp

#include <stdio.h>
#include "ofMain.h"
#include <string>

class UIButton
{
    public:
        UIButton();
        UIButton(float _x, float _y, float _w, float _h, string _t);
        void draw();
    
        void setBackgroundColorNormal(float _r, float _g, float _b);
        void setBackgroundColorHover(float _r, float _g, float _b);
    private:
        ofRectangle base;
        string title;
        ofColor regularBackground, hoverBackground;
};

#endif /* uibutton_hpp */

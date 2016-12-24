//
//  circle.hpp
//  traffic-visualization
//
//  Created by Joe on 17/11/2016.
//
//

#ifndef circle_hpp
#define circle_hpp

#include <stdio.h>
#include "ofMain.h"

class circle {
    
    private:
        float radius = 200;
        float amplitude = 0.8;
        float spike = 10;
        float circle_point = 300;
        float amount_around = 6.28;
        float count = 0;
        float z = 0;
        float z_base = 0;
        float c = 0;
        string severity;
    
    public:
    
        circle();
        circle(float _radius, float _z, string _severity);
        void draw(bool coloured, bool layered);
};

#endif /* circle_hpp */

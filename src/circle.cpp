//
//  circle.cpp
//  traffic-visualization
//
//  Created by Joe on 17/11/2016.
//
//

#include "circle.hpp"


circle::circle(float _radius, float _z, string _severity) : radius(_radius), z(_z), severity(_severity)
{
    
}

circle::circle()
{
    
}

void circle::draw(bool coloured, bool layered)
{
    // push matrix allowing local changes
    ofPushMatrix();
    
    // always draw in 0,0
    ofTranslate(0,0);
    
    // set line colour to black
    if (coloured)
    {
        if (severity == "Minimal")
        {
            ofSetColor(236,228,19);
        }else if (severity == "Moderate")
        {
            ofSetColor(236,177,19);
        }else if (severity == "Serious")
        {
            ofSetColor(236,101,19);
        }else if (severity == "Severe")
        {
            ofSetColor(236,25,19);
        }else {
            ofSetColor(255);
        }
    }else {
        ofSetColor(255);
    }
    
    // if filled
    if (layered)
    {
        ofFill();
    }else {
        ofNoFill();
    }
    
    // start drawing the shape
    ofBeginShape();
    
    // loop around the full circle
    for (float a=0; a<=360; a++)
    {
        // degrees to radians
        float radians = ofDegToRad(a);
        
        // create noise to alter the shape of the lines
        float raw_noise = ofNoise(cos(radians)*spike+1, sin(radians)*spike+1, c);
        
        // create the final noise mapped between 0.0 and 1.0
        float noise = ofMap(raw_noise, 0.0, 1.0, amplitude, 1.0);
        
        // calculate the x and y coordinates for the vertex
        float x = (cos(radians)*radius)*noise;
        float y = (sin(radians)*radius)*noise;
        
        // draw the vertex
        ofVertex(x, y, z);
    }
    
    // end drawing the shape
    ofEndShape();
    
    // pop matrix allowing global changes afterwards
    ofPopMatrix();
 
    // itterate c, this changes the noise causing the 'flux' effect
    c+= 0.01;
}

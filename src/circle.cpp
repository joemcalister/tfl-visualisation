//
//  circle.cpp
//  traffic-visualization
//
//  Created by Joe on 17/11/2016.
//
//

#include "circle.hpp"


circle::circle(float _radius, float _z) : radius(_radius), z(_z)
{
    
}

circle::circle()
{
    
}

void circle::draw()
{
    // push matrix allowing local changes
    ofPushMatrix();
    
    // always draw in 0,0
    ofTranslate(0,0);
    
    // dont fill the shape
    ofNoFill();
    
    // set line colour to black
    ofSetColor(0);
    
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

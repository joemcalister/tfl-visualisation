//
//  VisObject.cpp
//  traffic-visualisation
//
//  Created by Joe on 19/11/2016.
//
//

#include "VisObject.hpp"

VisObject::VisObject()
{
    
}

bool VisObject::createVisObject()
{
    // create the vis object
    network = Networking();
    bool got_data = network.getTFLData();
    
    if (got_data)
    {
        // we need to process the data into circles
        
        float r = 10;
        float y = 100;
        
        y = (5*network.data.size())/2;
        
        for (auto &obj:network.data)
        {
            // create and add the circles to the vector
            circle c = circle(r, y);
            circles.push_back(c);
            
            r += 5;
            y -= 5;
        }
        
    }else {
        // there's been an error
        cout << "Error runnng program, please check internet connectivity and try again" << endl;
        return false;
    }
    
}

void VisObject::draw()
{
    for (auto &circle:circles)
    {
        circle.draw();
    }
}

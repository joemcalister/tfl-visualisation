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
    loaded = false;
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
        
        // almost center the object
        y = (5*network.data.size())/2;
        
        for (auto &obj:network.data)
        {
            // create and add the circles to the vector
            circle c = circle(r, y, obj["severity"]);
            circles.push_back(c);
            
            // push back the descriptions
            string des = "";
            des.append(obj["location"]);
            
            if (obj["comments"].size() != 0)
            {
                //des.append("\n");
                des.append(obj["comments"]);
            }
            
            
            
            descriptions.push_back(des);
            
            r += 5;
            y -= 5;
        }
        
        // loaded flag
        loaded = true;
        
    }else {
        // there's been an error
        cout << "Error runnng program, please check internet connectivity and try again" << endl;
        return false;
    }
    
}

// main draw function for the object
void VisObject::draw()
{
    int count = 0;
    for (auto &circle:circles)
    {
        // determine if layer mode is enabed, if so which should be featured
        bool featured = false;
        
        if (layerMode&&layerIndex==count)
        {
            featured = true;
        }
        
        circle.draw(coloured, featured);
        count++;
    }
}

void VisObject::toggleLayers(bool state)
{
    // we toggle the layers
    layerMode = state;
    layerIndex = 0;
}

int VisObject::numberOfLayers()
{
    return circles.size();
}

string VisObject::descriptionForLayer(int index)
{
    return descriptions[index];
}


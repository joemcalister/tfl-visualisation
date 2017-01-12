//
//  VisObject.hpp
//  traffic-visualisation
//
//  Created by Joe on 19/11/2016.
//
//

#ifndef VisObject_hpp
#define VisObject_hpp

#include <stdio.h>
#include "Networking.hpp"
#include <vector>
#include "circle.hpp"

class VisObject
{
    private:
        Networking network;
        vector<circle> circles;
        vector<string> descriptions;
    public:
        VisObject();
        bool createVisObject();
        void draw();
        bool loaded;
        bool coloured = false;
        void toggleLayers(bool state);
        bool layerMode = false;
        int layerIndex;
        int numberOfLayers();
        string descriptionForLayer(int index);
    
};

#endif /* VisObject_hpp */

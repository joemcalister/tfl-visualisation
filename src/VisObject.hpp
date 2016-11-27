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
    public:
        VisObject();
        bool createVisObject();
        void draw();
        bool loaded;
};

#endif /* VisObject_hpp */

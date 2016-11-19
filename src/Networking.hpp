//
//  Networking.hpp
//  traffic-visualisation
//
//  Created by Joe on 19/11/2016.
//
//

#ifndef Networking_hpp
#define Networking_hpp

#include <stdio.h>
#include <vector>
#include <ctime>
#include "ofMain.h"
#include "json.hpp"

using namespace std;
using namespace nlohmann;

class Networking
{
    private:
        string getDateString(float offset);
    public:
        Networking();
        bool getTFLData();
        json data;
};

#endif /* Networking_hpp */

//
//  Networking.cpp
//  traffic-visualisation
//
//  Created by Joe on 19/11/2016.
//
//

#include "Networking.hpp"

Networking::Networking()
{
    
}

bool Networking::getTFLData()
{
    // create request string
    string today = getDateString(0);
    string yesterday = getDateString(1);
    string requestURL = "https://api.tfl.gov.uk/Road/All/Disruption?startDate="+yesterday+"&endDate="+today;
    
    // make request, get json
    ofHttpResponse resp = ofLoadURL(requestURL);
    string resultRaw = resp.data;
    
    // parse it
    json j;
    auto parsed = json::parse(resultRaw);
    
    if (parsed.is_array())
    {
        // it's ok
        data = parsed;
        return true;
    }else {
        // error parsing
        cout << "Error parsing json file" << endl;
        return false;
    }
}

string Networking::getDateString(float offset)
{
    time_t t = time(0);
    t -= (24*60*60) * offset;
    struct tm * now = localtime(&t);
    return to_string(now->tm_year + 1900) + '-' + to_string(now->tm_mon + 1) +  '-' + to_string(now->tm_mday);
}

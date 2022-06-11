#include <iostream>
#include "bus_db.h"

using std::string_view, std::to_string, std::cout;

void BusDB::addStop(const string& stopName, double lat, double lon) {
    if (stopMap.count(stopName)) return;
    stopMap[stopName] = {lat, lon};
}

void BusDB::addRoute(const string& busName, const string& routeString) {
    if (busMap.count(busName)) return;
    Route& route = busMap[busName];
    string_view routeView(routeString);

    char delim = '>';
    if (routeView.find_first_of('-') != routeView.npos)
        delim = '-';
    
    size_t pos =  0;
    while (pos != routeView.npos) {
        pos = routeView.find_first_of(delim);
        string stopName {routeView.substr(0, pos-1)};
        route.addStop(stopName);
        routeView.remove_prefix(pos+2);
    }
    if (delim == '-') {
        for (auto it = ++route.crbegin(); it != route.crend(); it++)
            route.addStop(*it);
    }
}

optional<BusStats> BusDB::getBusStats(const string& busName) {
    optional<BusStats> bs;
    if (!busMap.count(busName))
        return bs;
    Route& route = busMap.at(busName);
    bs = {route.getCount(), route.getCountUnq(), route.getDistance(stopMap)};
    return bs;
}
#pragma once
#include <unordered_set>
#include <unordered_map>
#include "route.h"

using std::unordered_set, std::unordered_map;

struct BusStats {
    size_t count, countUnq;
    double distance;
};

class BusDB {
public:
    BusDB() = default;
    void addStop(const string& stopName, double lat, double lon);
    void addRoute(const string& busName, const string& routeString);
    optional<BusStats> getBusStats(const string& busName);
private:
    unordered_map<string, Route> busMap;
    unordered_map<string, Stop> stopMap;
};
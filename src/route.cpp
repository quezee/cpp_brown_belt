#include <cmath>
#include "route.h"

void Route::addStop(const string& stop) {
    if (!path.empty() && path.back() == stop)
        return;
    stops.insert(stop);
    path.push_back(stop);
}

size_t Route::getCount() const {return path.size();}
size_t Route::getCountUnq() const {return stops.size();}

double Route::getDistance(const unordered_map<string, Stop>& stopMap) {
    if (distance) return *distance;
    distance = 0;
    auto it = path.begin();
    string& prev = *it++;
    while (it != path.end()) {
        *distance += calcDist(stopMap.at(prev), stopMap.at(*it));
        prev = *it++;
    }
    return *distance;
}

double Route::calcDist(const Stop& lhs, const Stop& rhs) {
    double dLat = (lhs.lat - rhs.lat) * pi / 180.;
    double dLon = (lhs.lon - rhs.lon) * pi / 180.;

    double lat1 = (lhs.lat) * pi / 180.;
    double lat2 = (rhs.lat) * pi / 180.;

    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);
    double c = 2 * asin(sqrt(a));
    return earthRad * c * 1e3;
}

RouteIt Route::crbegin() const {
    return path.rbegin();
}

RouteIt Route::crend() const {
    return path.crend();
}
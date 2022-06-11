#pragma once
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <string_view>
#include <optional>
#include "stop.h"

using std::unordered_set, std::unordered_map, std::list, std::string, std::string_view, std::optional;
using RouteIt = std::reverse_iterator<std::__cxx11::list<std::string>::const_iterator>;

class Route {
public:
    Route() = default;
    void addStop(const string& stop);
    size_t getCount() const;
    size_t getCountUnq() const;
    double getDistance(const unordered_map<string, Stop>& stopMap);
    static double calcDist(const Stop& lhs, const Stop& rhs);
    RouteIt crbegin() const;
    RouteIt crend() const;
private:
    unordered_set<string> stops;
    list<string> path;
    optional<double> distance;
    static constexpr double pi = 3.1415926535;
    static constexpr double earthRad = 6371.;
};
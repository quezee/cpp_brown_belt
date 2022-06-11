#pragma once
#include <string>

using std::string;

class Stop {
public:
    double lat, lon;

    Stop(double lat, double lon)
        : lat(lat), lon(lon) {}

    Stop() : Stop(-1, -1) {}
};

// struct hashStop {
//     size_t operator() (const Stop& stop) {
//         return std::hash<string>{} (stop.name);
//     }
// };
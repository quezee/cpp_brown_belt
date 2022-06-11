#include <iostream>
#include <iomanip>
#include "bus_db.h"

using std::cout, std::cin, std::endl, std::ws, std::setprecision;

int main() {
    BusDB busDB;
    int n;
    double lat, lon;
    char comma;
    string request, stopName, busName, routeString;
    
    // input requests
    cin >> n;
    while (n--) {
        cin >> request;
        if (request == "Stop") {
            getline(cin >> ws, stopName, ':');
            cin >> lat >> comma >> lon;
            busDB.addStop(stopName, lat, lon);
        }
        else if (request == "Bus") {
            getline(cin >> ws, busName, ':');
            std::getline(cin >> ws, routeString);
            busDB.addRoute(busName, routeString);
        }
    }
    // output requests
    cin >> n;
    while (n--) {
        cin >> request;
        if (request == "Bus") {
            cin >> busName;
            optional<BusStats> bs = busDB.getBusStats(busName);
            if (!bs)
                cout << "Bus " << busName << ": not found\n";
            else
                cout << "Bus " << busName << ": " << bs->count << " stops on route, "
                     << bs->countUnq << " unique stops, "
                     << setprecision(6) << bs->distance << " route length\n";            
        }
    }
}
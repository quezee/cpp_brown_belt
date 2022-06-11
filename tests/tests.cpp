#include "gtest/gtest.h"
#include "bus_db.h"

struct RouteTest : testing::Test {
    Route route;
    unordered_map<string, Stop> stopMap;

    RouteTest() {
        route.addStop("s1");
        route.addStop("s2");
        route.addStop("s1");

        stopMap["s1"] = {55.0, 33.0};
        stopMap["s2"] = {55.1, 33.2};
    }
};

TEST_F(RouteTest, Counts) {
    ASSERT_EQ(route.getCount(), 3);
    ASSERT_EQ(route.getCountUnq(), 2);
}

TEST_F(RouteTest, Distance) {
    double answer = route.getDistance(stopMap);
    double expected = Route::calcDist(stopMap["s1"], stopMap["s2"]) * 2;
    ASSERT_EQ(answer, expected);
}

// TEST(DBTest, Final) {
//     BusDB busDB;
//     busDB.addRoute("36", "Tulaka > Obuvnaya > Volgu");
//     busDB.addStop("Tulaka", 55, 33);
//     busDB.addStop("Obuvnaya", 55.1, 33.1);
//     busDB.addStop("Volgu", 55.2, 33.2);
//     auto bs = busDB.getBusStats("36");
//     ASSERT_EQ(bs->count, 3);
//     ASSERT_EQ(bs->countUnq, 3);
// }
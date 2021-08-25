// Arda Onal 21903350 Section1
#ifndef __FLIGHTMAP_H
#define __FLIGHTMAP_H
#include "CityList.h"
#include "FlightList.h"
class FlightMap {
public:
    FlightMap( const string cityFile, const string flightFile );
    ~FlightMap();
    void displayAllCities() const;
    void displayAdjacentCities( const string cityName ) const;
    void displayFlightMap() const;
    void findFlights( const string deptCity, const string destCity ) const;
    void findLeastCostFlight( const string deptCity, const string destCity ) const;
    void runFlightRequests( const string requestFile ) const;
private:
    CityList cities;
    FlightList flights;
    int** cityMatrix;
};
#endif


// Arda Onal 21903350 Section1
#ifndef __FLIGHT_H
#define __FLIGHT_H
#include "City.h"
#include <string>
using namespace std;
class Flight
{
private:
    string originCity;
    string destinationCity;
    int flightId;
    int cost;
public:
    Flight();
    Flight(string,string,int,int);
    ~Flight();

    string getOriginCity() const;
    string getDestinationCity() const;
    int getFlightId() const;
    int getCost() const;

    void setOriginCity(string);
    void setDestinationCity(string);
    void setFlightId(int);
    void setCost(int);
};
#endif

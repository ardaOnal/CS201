// Arda Onal 21903350 Section1
#include "Flight.h"
using namespace std;
Flight::Flight()
{
    originCity = "";
    destinationCity = "";
    flightId = 0;
    cost = 0;
}
Flight::Flight(string org,string dest,int id,int flightCost)
{
    originCity = org;
    destinationCity = dest;
    flightId = id;
    cost = flightCost;
}
Flight::~Flight()
{

}
string Flight::getOriginCity() const
{
    return originCity;
}
string Flight::getDestinationCity() const
{
    return destinationCity;
}
int Flight::getFlightId() const
{
    return flightId;
}
int Flight::getCost() const
{
    return cost;
}

void Flight::setOriginCity(string s)
{
    originCity = s;
}
void Flight::setDestinationCity( string s)
{
    destinationCity = s;
}
void Flight::setFlightId( int id)
{
    flightId = id;
}
void Flight::setCost(int tmp)
{
    cost = tmp;
}

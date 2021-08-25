// Arda Onal 21903350 Section1
#include "City.h"
City::City()
{
    cityName = "";
}
City::City(string name)
{
    cityName = name;
}
string City::getCityName() const
{
   return cityName;
}
void City::setCityName(string name)
{
    cityName = name;
}



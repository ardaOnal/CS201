//Arda Onal 21903350 Section1
#ifndef __CITY_H
#define __CITY_H
#include <string>
using namespace std;
class City{
private:
    string cityName;
public:
City();

City(string);

string getCityName() const;

void setCityName(string name);

};
#endif

// Arda Onal 21903350 Section01
#include "FlightMap.h"
#include "Stack.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

FlightMap::FlightMap(const string cityFile, const string flightFile)
{
    string cityText;
    ifstream fileCity;

    fileCity.open(cityFile.c_str(),ios_base::in);
    while ( fileCity.eof() == false)
    {
        getline(fileCity,cityText,'\n');
        cities.insert(cities.getLength()+1,City(cityText));
    }
//    while ( fileCity >> cityText)
//    {
//        cities.insert(cities.getLength()+1,City(cityText));
//    }


//    for ( cityText; getline(fileCity,cityText,'\n');)
//    {
//        cities.insert(cities.getLength()+1,City(cityText));
//    }
    fileCity.close();

    cityMatrix = new int*[cities.getLength()];
    for ( int i = 0; i < cities.getLength();i++)
    {
        cityMatrix[i] = new int[cities.getLength()];
    }


    for ( int i = 0; i < cities.getLength(); i++)
    {
        for ( int j = 0; j < cities.getLength(); j++)
        {
            cityMatrix[i][j] = 0;
        }
    }

    string text;
    string originCity;
    string destinationCity;
    string id;
    int flightId;
    string strCost;
    int cost;
    ifstream fileFlight;
    fileFlight.open(flightFile.c_str(),ios_base::in);
    while ( getline(fileFlight, text))
    {
        stringstream ss(text);
        getline (ss,originCity,',');
        getline (ss,destinationCity,',');
        getline(ss,id,',');
        istringstream(id) >> flightId;
        getline(ss,strCost,'\n');
        istringstream(strCost) >> cost;
        flights.insert(flights.getLength()+1, Flight(originCity,destinationCity,flightId,cost));
    }
    fileFlight.close();

    for ( int i = 1; i <= flights.getLength(); i++)
    {
        Flight tmp;
        flights.retrieve(i,tmp);
        cityMatrix[cities.getIndex(tmp.getOriginCity()) - 1][ cities.getIndex(tmp.getDestinationCity()) - 1 ] = 1;
    }

}
FlightMap::~FlightMap()
{
    for (int i = 0; i < cities.getLength(); i++)
    {
        delete [] cityMatrix[i];
    }
    delete [] cityMatrix;
}
void FlightMap::displayAllCities() const
{
    for ( int i = 1; i <= cities.getLength(); i++ )
    {
        City tmp;
        cities.retrieve(i,tmp);
        cout << tmp.getCityName() << ", ";
    }
    cout << endl;

}
void FlightMap::displayAdjacentCities( const string cityName ) const
{
    for ( int i = 0; i < cities.getLength(); i++)
    {
        City tmp;
        cities.retrieve(i+1,tmp);
        if ( tmp.getCityName().compare(cityName) == 0)
        {
            cout << cityName << " -> ";
            for ( int j = 0; j < cities.getLength(); j++)
            {
                if ( cityMatrix[cities.getIndex(tmp.getCityName())-1][j] == 1)
                {
                    City tmp2;
                    cities.retrieve(j+1,tmp2);

                    cout << tmp2.getCityName() << ", ";
                }
            }
            cout << endl;
            return;
        }
    }
}
void FlightMap::displayFlightMap( ) const
{
    for ( int i = 1; i <= cities.getLength(); i++)
    {
        City tmp;
        cities.retrieve(i,tmp);

        displayAdjacentCities(tmp.getCityName());
    }
}
void FlightMap::findFlights( const string deptCity, const string destCity ) const
{
    cout << "Request is to fly from " << deptCity << " to " << destCity << ":" << endl;
    Stack s;
    City tmp;
    // finding the deptCity
    for ( int i = 1; i <= cities.getLength();i++)
    {
        cities.retrieve(i,tmp);
        if ( tmp.getCityName().compare(deptCity)==0)
        {
            s.push(tmp);
            break;
        }
    }

    // Copying the matrix
    int** cityMatrixCopy;
    cityMatrixCopy = new int*[cities.getLength()];
    for ( int i = 0; i < cities.getLength();i++)
    {
        cityMatrixCopy[i] = new int[cities.getLength()];
    }
    for ( int i = 0; i < cities.getLength();i++)
        for ( int j = 0; j < cities.getLength(); j++)
            cityMatrixCopy[i][j] = cityMatrix[i][j];

    string* paths;
    paths = new string[20];
    int pathValid = 0;
    int counter = 0;

    while ( !s.isEmpty())
    {
        City top;
        City tmp2;
        City adjacent;
        s.getTop(top);

        int topIndex;
        int adjacentIndex;
        bool hasAdjacent = false;

        // Finding the index of top in the matrix
        for ( int i = 1; i <= cities.getLength();i++)
        {
            cities.retrieve(i,tmp2);
            if ( tmp2.getCityName().compare(top.getCityName())==0)
            {
                topIndex = i - 1;
                break;
            }
        }

        // Checking if it has adjacent/path
        for ( int i = 0; i < cities.getLength();i++)
        {
            City tmp5;
            cities.retrieve(i+1,tmp5);
            if ( cityMatrixCopy[topIndex][i] == 1 && !s.searchStack(tmp5.getCityName()))
            {
                cities.retrieve(i+1,adjacent);
                hasAdjacent = true;
                adjacentIndex = i;
                break;
            }
        }

        if ( hasAdjacent && !s.searchStack(adjacent.getCityName()))
        {
            cityMatrixCopy[topIndex][adjacentIndex] = 0;

            s.push(adjacent);

            s.getTop(top);

            if ( top.getCityName().compare(destCity) == 0)
            {
                // Storing the path
                Stack stackTmp = s;
                while ( !stackTmp.isEmpty())
                {
                    City pathTmp;
                    stackTmp.pop(pathTmp);
                    paths[pathValid] = "." + pathTmp.getCityName() + paths[pathValid];
                }
                paths[pathValid] = paths[pathValid] + "-";
                pathValid++;

                s.pop();
            }
        }
        else
        {
            for ( int i = 0; i < cities.getLength();i++)
            {
                if ( cityMatrix[topIndex][i] == 1)
                        cityMatrixCopy[topIndex][i] = 1;
            }
            s.pop();
        }
    }

    // print path
    if ( pathValid == 0)
        cout << "Sorry. HPAir does not fly from " << deptCity << " to " << destCity << endl;
    else
    {
        for ( int i = 0; i < pathValid; i++)
        {
            //cout << paths[i] << endl;
            string onepath = paths[i];
            int charCount = 1;
            int totalCost = 0;
            int prevIndex = 1;

            do
            {
                string firstCity = "";
                string secondCity = "";
                charCount = prevIndex;

                while ( onepath[charCount] != '.')
                {
                    firstCity = firstCity + onepath[charCount];
                    charCount++;
                }

                charCount++;
                prevIndex = charCount;
                while ( onepath[charCount] != '.')
                {
                    secondCity = secondCity + onepath[charCount];
                    charCount++;

                    if ( onepath[charCount] == '-')
                        break;
                }

                for ( int j = 1; j <= flights.getLength();j++)
                {
                    Flight f;
                    flights.retrieve(j,f);

                    if ( f.getOriginCity().compare(firstCity)== 0 && f.getDestinationCity().compare(secondCity) == 0)
                    {
                        cout << "Flight #" << f.getFlightId() << " from " << firstCity << " to " << secondCity << " Cost: " << f.getCost() << " TL" << endl;
                        totalCost = totalCost + f.getCost();
                        break;
                    }
                }
            } while ( onepath[charCount] != '-');
            cout << "Total Cost .......... " << totalCost << " TL" << endl;
            cout << endl;
        }

    }




    for (int i = 0; i < cities.getLength(); i++)
    {
        delete [] cityMatrixCopy[i];
    }

    delete [] cityMatrixCopy;
    delete [] paths;

}
void FlightMap::findLeastCostFlight( const string deptCity, const string destCity ) const
{
    cout << "Request is to fly from " << deptCity << " to " << destCity << ":" << endl;
    Stack s;
    City tmp;
    // finding the deptCity
    for ( int i = 1; i <= cities.getLength();i++)
    {
        cities.retrieve(i,tmp);
        if ( tmp.getCityName().compare(deptCity)==0)
        {
            s.push(tmp);
            break;
        }
    }

    // Copying the matrix
    int** cityMatrixCopy;
    cityMatrixCopy = new int*[cities.getLength()];
    for ( int i = 0; i < cities.getLength();i++)
    {
        cityMatrixCopy[i] = new int[cities.getLength()];
    }
    for ( int i = 0; i < cities.getLength();i++)
        for ( int j = 0; j < cities.getLength(); j++)
            cityMatrixCopy[i][j] = cityMatrix[i][j];

    string* paths;
    paths = new string[20];
    int pathValid = 0;
    int counter = 0;

    while ( !s.isEmpty())
    {
        City top;
        City tmp2;
        City adjacent;
        s.getTop(top);

        int topIndex;
        int adjacentIndex;
        bool hasAdjacent = false;

        // Finding the index of top in the matrix
        for ( int i = 1; i <= cities.getLength();i++)
        {
            cities.retrieve(i,tmp2);
            if ( tmp2.getCityName().compare(top.getCityName())==0)
            {
                topIndex = i - 1;
                break;
            }
        }

        // Checking if it has adjacent/path
        for ( int i = 0; i < cities.getLength();i++)
        {
            City tmp5;
            cities.retrieve(i+1,tmp5);
            if ( cityMatrixCopy[topIndex][i] == 1 && !s.searchStack(tmp5.getCityName()))
            {
                cities.retrieve(i+1,adjacent);
                hasAdjacent = true;
                adjacentIndex = i;
                break;
            }
        }

        if ( hasAdjacent && !s.searchStack(adjacent.getCityName()))
        {
            cityMatrixCopy[topIndex][adjacentIndex] = 0;

            s.push(adjacent);

            s.getTop(top);

            if ( top.getCityName().compare(destCity) == 0)
            {
                // Storing the path
                Stack stackTmp = s;
                while ( !stackTmp.isEmpty())
                {
                    City pathTmp;
                    stackTmp.pop(pathTmp);
                    paths[pathValid] = "." + pathTmp.getCityName() + paths[pathValid];
                }
                paths[pathValid] = paths[pathValid] + "-";
                pathValid++;

                s.pop();
            }
        }
        else
        {
            for ( int i = 0; i < cities.getLength();i++)
            {
                if ( cityMatrix[topIndex][i] == 1)
                        cityMatrixCopy[topIndex][i] = 1;
            }
            s.pop();
        }
    }

    // print path
    if ( pathValid == 0)
        cout << "Sorry. HPAir does not fly from " << deptCity << " to " << destCity << endl;
    else
    {
        int cheapeast = 0;
        int cnt = 0;
        int cheapestPath = 0;
        for ( int i = 0; i < pathValid; i++)
        {
            //cout << paths[i] << endl;
            string onepath = paths[i];
            int charCount = 1;
            int totalCost = 0;
            int prevIndex = 1;

            do
            {
                string firstCity = "";
                string secondCity = "";
                charCount = prevIndex;

                while ( onepath[charCount] != '.')
                {
                    firstCity = firstCity + onepath[charCount];
                    charCount++;
                }

                charCount++;
                prevIndex = charCount;
                while ( onepath[charCount] != '.')
                {
                    secondCity = secondCity + onepath[charCount];
                    charCount++;

                    if ( onepath[charCount] == '-')
                        break;
                }

                for ( int j = 1; j <= flights.getLength();j++)
                {
                    Flight f;
                    flights.retrieve(j,f);

                    if ( f.getOriginCity().compare(firstCity)== 0 && f.getDestinationCity().compare(secondCity) == 0)
                    {
                        cout << "Flight #" << f.getFlightId() << " from " << firstCity << " to " << secondCity << " Cost: " << f.getCost() << " TL" << endl;
                        totalCost = totalCost + f.getCost();
                        break;
                    }
                }
            } while ( onepath[charCount] != '-');
            cout << "Total Cost .......... " << totalCost << " TL" << endl;
            cout << endl;

            if ( cnt == 0)
            {
                cheapeast = totalCost;
                cnt++;
            }

            if ( totalCost < cheapeast)
            {
                cheapeast = totalCost;
                cheapestPath = i;
            }

        }

        cout << "A least cost path from " << deptCity << " to " << destCity << " is ";
        string onepath = paths[cheapestPath];
        int charCount = 1;

        do
        {
            if ( onepath[charCount] != '.')
            {
                cout << onepath[charCount];
            }
            charCount++;
            if (onepath[charCount] == '.')
                    cout << " -> ";

        } while ( onepath[charCount] != '-');


        cout << " and its cost is " << cheapeast << " TL" << endl;

    }

    for (int i = 0; i < cities.getLength(); i++)
    {
        delete [] cityMatrixCopy[i];
    }

    delete [] cityMatrixCopy;
    delete [] paths;
}
void FlightMap::runFlightRequests( const string requestFile ) const
{
    string request;
    ifstream file;

    string deptCity = "";
    string destCity = "";
    file.open( requestFile.c_str());
    while ( file.eof() == false) {
        getline( file, request, '\n');
        stringstream ss( request);
        getline( ss, deptCity, ',');
        getline( ss, destCity, '\n');
        findLeastCostFlight( deptCity, destCity);
    }
    file.close();
}

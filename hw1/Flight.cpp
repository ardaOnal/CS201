// Name: Arda Önal ID: 2190330
#include <iostream>
using namespace std;
#include "Flight.h"
Flight::Flight( int flightNum, int rowNum, int seatNum)
{
    flightNo = flightNum;
    rowNo = rowNum;
    seatNo = seatNum;

    totalSeatNo = rowNo*seatNo;

    seatsAvailable = new bool[totalSeatNo];
    rows = new int[rowNo];
    columns = new char[seatNo];

    for ( int i = 0; i < totalSeatNo; i++ )
    {
        seatsAvailable[i] = true; // All seats are available at the beginning.
    }

    for ( int i = 0; i < rowNo; i++ )
    {
        rows[i] = i+1; // Initializing all row numbers
    }

    for ( int i = 0; i < seatNo; i++ )
    {
        columns[i] = (char)(i+65); // Initializing all seat chars.
    }

    availableSeatNo = totalSeatNo;


}
Flight::Flight()
{
    flightNo = 0;
    rowNo = 0;
    seatNo = 0;

    totalSeatNo = rowNo*seatNo;

    seatsAvailable = NULL;
    rows = NULL;
    columns = NULL;

    availableSeatNo = totalSeatNo;
}
Flight::Flight( const Flight& copyFlight)
{
    flightNo = copyFlight.flightNo;
    rowNo = copyFlight.rowNo;
    seatNo = copyFlight.seatNo;

    totalSeatNo = rowNo*seatNo;

    seatsAvailable = new bool[totalSeatNo];
    rows = new int[rowNo];
    columns = new char[seatNo];

    for ( int i = 0; i < totalSeatNo; i++ )
    {
        seatsAvailable[i] = copyFlight.seatsAvailable[i]; // All seats are available at the beginning.
    }

    for ( int i = 0; i < rowNo; i++ )
    {
        rows[i] = copyFlight.rows[i]; // Initializing all row numbers
    }

    for ( int i = 0; i < seatNo; i++ )
    {
        columns[i] = copyFlight.columns[i]; // Initializing all seat chars.
    }

    availableSeatNo = totalSeatNo;
}
Flight& Flight::operator=( const Flight& copyFlight)
{
    if ( &copyFlight != this)
    {
        flightNo = copyFlight.flightNo;
        rowNo = copyFlight.rowNo;
        seatNo = copyFlight.seatNo;

        totalSeatNo = rowNo*seatNo;

        delete [] seatsAvailable;
        delete [] rows;
        delete [] columns;

        seatsAvailable = new bool[totalSeatNo];
        rows = new int[rowNo];
        columns = new char[seatNo];

        for ( int i = 0; i < totalSeatNo; i++ )
        {
            seatsAvailable[i] = copyFlight.seatsAvailable[i]; // All seats are available at the beginning.
        }

        for ( int i = 0; i < rowNo; i++ )
        {
            rows[i] = copyFlight.rows[i]; // Initializing all row numbers
        }

        for ( int i = 0; i < seatNo; i++ )
        {
            columns[i] = copyFlight.columns[i]; // Initializing all seat chars.
        }

        availableSeatNo = totalSeatNo;


    }
    return *this;
}
Flight::~Flight()
{
    delete [] seatsAvailable;

    delete [] rows;

    delete [] columns;

}
int Flight::getFlightNo()
{
    return flightNo;
}
int Flight::getRowNo()
{
    return rowNo;
}
int Flight::getSeatNo()
{
    return seatNo;
}
int Flight::getAvailableSeatNo()
{
    return availableSeatNo;
}
bool* Flight::getSeatsAvailable()
{
    return seatsAvailable;
}
int* Flight::getRows()
{
    return rows;
}
char* Flight::getColumns()
{
    return columns;
}

void Flight::setSeatsAvailable( const int numPassangers, const int*& row, const char*& col)
{
    for ( int i = 0; i < numPassangers; i++)
    {
       seatsAvailable[(row[i]-1)*seatNo+(int)col[i] - 65] = false;
       availableSeatNo--;
    }
}
void Flight::setSeatsCancel( const int numPassangers, const int* row, const char* col)
{
    for ( int i = 0; i < numPassangers; i++)
    {
       seatsAvailable[(row[i]-1)*seatNo+(int)col[i] - 65] = true;
       availableSeatNo++;
    }
}

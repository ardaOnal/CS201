// Name: Arda Önal ID: 2190330
#include <iostream>
using namespace std;
#include "Reservation.h"
Reservation::Reservation( const int reservCode, const int passNo, const int*& rowNo, const char*& colNo, const int flightNu)
{
    flightNum = flightNu;
    resCode = reservCode;
    numPassangers = passNo;

    seatRow = new int[numPassangers];
    seatCol = new char[numPassangers];

    for ( int i = 0; i < passNo; i++)
    {
        seatRow[i] = rowNo[i];
    }
    for ( int i = 0; i < passNo; i++)
    {
        seatCol[i] = colNo[i];
    }

}
Reservation::Reservation()
{
    resCode = 0;
    numPassangers = 0;
    seatRow = 0;
    seatCol = 0;
}
Reservation& Reservation::operator=( const Reservation& copyReservation)
{
    delete [] seatRow;
    delete [] seatCol;

    flightNum = copyReservation.flightNum;
    resCode = copyReservation.resCode;
    numPassangers = copyReservation.numPassangers;

    seatRow = new int[numPassangers];
    seatCol = new char[numPassangers];

    for ( int i = 0; i < numPassangers; i++)
    {
        seatRow[i] = copyReservation.seatRow[i];
    }
    for ( int i = 0; i < numPassangers; i++)
    {
        seatCol[i] = copyReservation.seatCol[i];
    }
    return *this;
}
Reservation::~Reservation()
{
    if ( seatRow)
        delete [] seatRow;

    if ( seatCol)
        delete [] seatCol;
}
int Reservation::getResCode()
{
    return resCode;
}
int Reservation::getNumPassangers()
{
    return numPassangers;
}
int Reservation::getFlightNo()
{
    return flightNum;
}
int* Reservation::getSeatRow()
{
    return seatRow;
}
char* Reservation::getSeatCol()
{
    return seatCol;
}

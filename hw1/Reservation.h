// Name: Arda Önal ID: 2190330
#ifndef __RESERVATION_H
#define __RESERVATION_H
using namespace std;
#include "Flight.h"
class Reservation {
public:
    Reservation( const int reservCode, const int passNo, const int*& rowNo, const char*& colNo, const int flightNu);
    Reservation();
    Reservation& operator=( const Reservation& copyReservation);
    ~Reservation();
    int getResCode();
    int getNumPassangers();
    int getFlightNo();
    int* getSeatRow();
    char* getSeatCol();
private:
    int resCode;
    int numPassangers;
    int flightNum;
    int* seatRow;
    char* seatCol;

}; // end of class
#endif

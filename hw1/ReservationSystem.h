// Name: Arda Önal ID: 2190330
#ifndef __RESERVATIONSYSTEM_H
#define __RESERVATIONSYSTEM_H
#include "Flight.h"
#include "Reservation.h"
using namespace std;
class ReservationSystem {
public:
    ReservationSystem();
    ~ReservationSystem();
    void addFlight( const int flightNo, const int rowNo, const int seatNo );
    void cancelFlight( const int flightNo );
    void showAllFlights();
    void showFlight( const int flightNo );
    int makeReservation( const int flightNo, const int numPassengers,const int *seatRow, const char *seatCol );
    void cancelReservation( const int resCode );
    void showReservation( const int resCode );
    void cancelReservationWithoutPrinting( const int resCode );
private:
    int flightsValid;
    int flightsSize;
    int reservationsValid;
    int reservationsSize;
    int resCode;
    Flight* flights;
    Reservation* reservations;
}; // end of class
#endif

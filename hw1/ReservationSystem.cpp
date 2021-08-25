// Name: Arda Önal ID: 2190330
#include "ReservationSystem.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
ReservationSystem::ReservationSystem()
{
    resCode = 1;
    flightsSize = 10; // default size of flights array
    reservationsSize = 10; // default size of flights array

    flights = new Flight[flightsSize];
    reservations = new Reservation[reservationsSize];

    flightsValid = 0;
    reservationsValid = 0;
}
ReservationSystem::~ReservationSystem()
{
    if ( flights)
        delete [] flights;

    if ( reservations)
        delete [] reservations;
}

//Done
void ReservationSystem::addFlight( const int flightNo, const int rowNo, const int seatNo )
{
    bool exist = false; // local variable for checking if the flightNo exists or not.

    for ( int i = 0; i < flightsValid; i++)
    {
        if (flights[i].getFlightNo() == flightNo )
        {
            cout << "Flight " << flightNo << " already exists." << endl;
            cout << endl; // Creating space between function calls.
            exist = true;
            return;
        }
    }

    if ( flightsValid >= flightsSize)
    {
        flightsSize = flightsSize + 10;
        Flight* newFlights = new Flight[flightsSize];
        for ( int i = 0; i < flightsValid; i++ )
        {
            newFlights[i] = flights[i];
        }

        delete[] flights;
        flights = newFlights;
    }

    if ( rowNo > 0 && seatNo > 0 && !exist)
    {

        Flight f(flightNo, rowNo, seatNo);
        flights[flightsValid] = f;
        flightsValid++;

        cout << "Flight " << flightNo << " has been added." << endl;
        return;
    }

    cout << "Invalid row or seat number entered." << endl;
    cout << endl; // Creating space between function calls.
}

// Not done
void ReservationSystem::cancelFlight( const int flightNo )
{
    bool exist = false; // local variable for checking if the flightNo exists or not.

    for ( int i = 0; i < flightsValid;i++)
    {
        if (flights[i].getFlightNo() == flightNo )
        {
            exist = true;

            // Canceling reservations
            for ( int k = 0; k < reservationsValid; k++)
            {
                if ( reservations[k].getFlightNo() == flightNo)
                {
                    cancelReservationWithoutPrinting(reservations[k].getResCode());
                }
            }
            if ( i == flightsValid - 1)
            {
                //delete (flights + flightsValid - 1);
                flightsValid--;
            }
            else
            {
                for ( int j =i; j < flightsValid - 1; j++)
                {
                    flights[j] = flights[j+1];
                }
                flightsValid--;
            }
            cout << "Flight " << flightNo << " and all of its reservations are canceled." << endl;
            cout << endl; // Creating space between function calls.
            return;
        }
    }

    if ( !exist)
        cout << "Flight " << flightNo << " does not exist." << endl;
        cout << endl; // Creating space between function calls.
}

// Done
void ReservationSystem::showAllFlights()
{
    if ( flightsValid == 0)
        cout << "No flights exist" << endl;
    else
    {
        cout << "Flights currently operated:" << endl;
        for ( int i = 0; i < flightsValid; i++)
        {
            cout << "Flight " << flights[i].getFlightNo() << " (" << flights[i].getAvailableSeatNo() << " available seats)" << endl;
        }
    }
    cout << endl; // Creating space between function calls.
}
// Done
void ReservationSystem::showFlight( const int flightNo )
{
    bool exist = false; // local variable for checking if the flightNo exists or not.
    int counter = 0;

    for ( int i = 0; i < flightsValid;i++)
    {
        if (flights[i].getFlightNo() == flightNo )
        {
            exist = true;
            cout << "Flight " << flights[i].getFlightNo() << " has " << flights[i].getAvailableSeatNo() << " available seats." << endl;
            cout << endl; // Creating space.
            cout << "  ";
            // Printing the column number using hexadecimal conversion
            for ( int j = 0; j < flights[i].getSeatNo(); j++)
            {

                if ( j == flights[i].getSeatNo() - 1)
                {
                    cout << (flights[i].getColumns())[j]<< endl; // gets the columns array from the Flight class
                }
                else
                {
                    cout << (flights[i].getColumns())[j];
                    cout << " ";
                }
            }

            // for loop for printing every row
            for ( int k = 0; k < flights[i].getRowNo(); k++)
            {
                cout << (flights[i].getRows())[k] << " "; // printing row number

                // for loop for printing every seat
                for ( int a = 0; a < flights[i].getSeatNo();a++)
                {
                    bool* foo = flights[i].getSeatsAvailable(); // array of booleans indicating all of seats availability.
                    if ( foo[counter]) // If seats are available
                    {
                        if ( a != flights[i].getSeatNo() - 1) // If it is not the last column
                        {
                            cout << "o ";
                            counter++;
                        }
                        else
                        {
                            cout << "o" << endl;
                            counter++;
                        }
                    }
                    else // If seats are not available
                    {
                        if ( a != flights[i].getSeatNo() - 1) // If it is not the last column
                        {
                            cout << "x ";
                            counter++;
                        }
                        else
                        {
                            cout << "x" << endl;
                            counter++;
                        }
                    }
                }
            }
        }
    }
    if ( !exist)
        cout << "Flight " << flightNo << " does not exist." << endl;
        cout << endl; // Creating space between function calls.
}
// Done
int ReservationSystem::makeReservation( const int flightNo, const int numPassengers,const int *seatRow, const char *seatCol )
{
    stringstream s;
    bool seatAvailable = true;
    for ( int i = 0; i < flightsValid; i++)
    {
        if ( flights[i].getFlightNo() == flightNo)
        {
            for ( int j = 0; j < numPassengers; j++)
            {
                if ( !(flights[i].getSeatsAvailable())[(seatRow[j]- 1)*(flights[i].getSeatNo())+(int)seatCol[j] - 65]) // If the seat is not occupied
                {
                    seatAvailable = false;
                    s << seatRow[j] << seatCol[j] << " ";
                }
            }

            if ( !seatAvailable && s.str().length() <= 3 )
            {
                cout << s.str() << " is not available" << endl;
                cout << endl; // Creating space between function calls.
                return -1;
            }
            else if ( !seatAvailable && s.str().length() > 3 )
            {
                cout << s.str() << " are not available" << endl;
                cout << endl; // Creating space between function calls.
                return -1;
            }
            else if ( seatAvailable)
            {
                Reservation r(resCode,numPassengers,seatRow,seatCol,flightNo);

                if ( reservationsValid >= reservationsSize)
                {
                    reservationsSize = reservationsSize + 10;
                    Reservation* newReservations = new Reservation[reservationsSize];
                    for ( int i = 0; i < reservationsValid; i++ )
                    {
                        newReservations[i] = reservations[i];
                    }

                    delete[] reservations;
                    reservations = newReservations;
                }

                reservations[reservationsValid] = r;
                reservationsValid++;
                int code = resCode;
                resCode++;

                flights[i].setSeatsAvailable(numPassengers,seatRow,seatCol);
                cout << endl; // Creating space between function calls.
                return code;
            }
        }
    }

    cout << "Flight " << flightNo << " does not exist.";
    cout << endl; // Creating space between function calls.
    return -1;
}
void ReservationSystem::cancelReservation( const int resCode )
{
    for ( int i = 0; i < reservationsValid; i++)
    {
        if ( reservations[i].getResCode() == resCode)
        {
            // Printing canceled seats
            cout << "Reservation for the seats ";
            for ( int j = 0; j < reservations[i].getNumPassangers(); j++)
            {
                cout << (reservations[i].getSeatRow())[j] << (reservations[i].getSeatCol())[j] << " ";
            }
            cout << "is canceled in Flight " << reservations[i].getFlightNo() << endl;

            for ( int k = 0; k < flightsValid; k++)
            {
                if ( flights[k].getFlightNo() == reservations[i].getFlightNo())
                {
                    // Cancelling reservations of flight
                    flights[k].setSeatsCancel(reservations[i].getNumPassangers(),reservations[i].getSeatRow(),reservations[i].getSeatCol());
                }
            }
            // If it is the last reservation
            if (i == reservationsValid - 1)
            {
                //delete (reservations + i);
                reservationsValid--;
            }
            else
            {
                for ( int k = i; k < reservationsValid - 1; k++)
                {
                    reservations[k] = reservations[k+1];

                }
                //delete (reservations + reservationsValid - 1);
                reservationsValid--;
            }
            cout << endl; // Creating space between function calls.
            return;
        }
    }

    cout << "No reservations are found under the code " << resCode << endl;
    cout << endl; // Creating space between function calls.
}
void ReservationSystem::showReservation( const int resCode )
{
    for ( int i = 0; i < reservationsValid; i++)
    {
        if ( reservations[i].getResCode() == resCode)
        {
            cout << "Reservation under the Code " << resCode << " in Flight " << reservations[i].getFlightNo() << ":";
            for ( int j = 0; j < reservations[i].getNumPassangers(); j++)
            {
                cout << (reservations[i].getSeatRow())[j] << (reservations[i].getSeatCol())[j] << " ";
            }
            cout << endl;
            return;
        }
    }

    cout << "No reservations are found under code " << resCode << endl;
    cout << endl; // Creating space between function calls.
}
void ReservationSystem::cancelReservationWithoutPrinting( const int resCode )
{
    for ( int i = 0; i < reservationsValid; i++)
    {
        if ( reservations[i].getResCode() == resCode)
        {

            for ( int k = 0; k < flightsValid; k++)
            {
                if ( flights[k].getFlightNo() == reservations[i].getFlightNo())
                {
                    // Canceling reservations of flight
                    flights[k].setSeatsCancel(reservations[i].getNumPassangers(),reservations[i].getSeatRow(),reservations[i].getSeatCol());
                }
            }
            // If it is the last reservation
            if (i == reservationsValid - 1)
            {
                //delete (reservations + i);
                reservationsValid--;
            }
            else
            {
                for ( int k = i; k < reservationsValid - 1; k++)
                {
                    reservations[k] = reservations[k+1];

                }
                //delete (reservations + reservationsValid - 1);
                reservationsValid--;
            }
            return;
        }
    }

    cout << "No reservations are found under the code " << resCode << endl;
    cout << endl; // Creating space between function calls.
}

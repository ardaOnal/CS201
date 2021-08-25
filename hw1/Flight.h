// Name: Arda Önal ID: 2190330
#ifndef __FLIGHT_H
#define __FLIGHT_H
using namespace std;
class Flight {
public:
    Flight( int flightNum, int rowNum, int seatNum);
    Flight();
    Flight( const Flight& copyFlight);
    Flight& operator=( const Flight& copyFlight);
    ~Flight();
    int getFlightNo();
    int getRowNo();
    int getSeatNo();
    int getAvailableSeatNo();
    bool* getSeatsAvailable();
    int* getRows();
    char* getColumns();
    void setSeatsAvailable(const int numPassangers, const int*& row, const char*& col);
    void setSeatsCancel(const int numPassangers, const int* row, const char* col);
private:
    int flightNo;
    int rowNo;
    int seatNo;
    int totalSeatNo;
    bool* seatsAvailable;
    int availableSeatNo;
    int* rows;
    char* columns;
}; // end of class
#endif

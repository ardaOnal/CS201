// Arda Onal 21903350 Section1
#ifndef __FLIGHTLIST_H
#define __FLIGHTLIST_H
#include "Flight.h"
#include <string>

typedef Flight FlightType;

class FlightList
{
private:
    struct FlightListNode
    {
        FlightType item;
        FlightListNode* next;
    };

    int size;
    FlightListNode* head;
    FlightListNode* find(int index) const;
    //friend class LibrarySystem;
public:
    FlightList();
    FlightList(const FlightList&);
    ~FlightList();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve( int index, FlightType& dataItem) const;
    bool insert(int index, FlightType newItem);
    bool remove(int index);


};
#endif



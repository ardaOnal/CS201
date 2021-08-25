// Arda Onal 21903350 Section1
#ifndef __CITYLIST_H
#define __CITYLIST_H
#include "City.h"
#include <string>

typedef City CityType;

class CityList
{
private:
    struct CityListNode
    {
        CityType item;
        CityListNode* next;
    };

    int size;
    CityListNode* head;
    CityListNode* find(int index) const;
    //friend class LibrarySystem;
public:
    CityList();
    CityList(const CityList&);
    ~CityList();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve( int index, CityType& dataItem) const;
    bool insert(int index, CityType newItem);
    bool remove(int index);
    int getIndex(string) const;
    bool exists(string) const;

};
#endif




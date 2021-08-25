// Arda Onal 21903350 Section1
#include "FlightList.h"

#include <string>
#include <cstddef>
#include <iostream>
using namespace std;

FlightList::FlightList(): size(0), head(NULL)
{
}
FlightList::FlightList( const FlightList& aList): size(aList.size)
{
    if ( aList.head == NULL)
        head = NULL;
    else
    {
        head = new FlightListNode;
        head->item = aList.head->item;
        FlightListNode* newPtr = head;

        for (FlightListNode* origPtr = aList.head->next; origPtr != NULL; origPtr = origPtr->next)
        {
            newPtr->next = new FlightListNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }
}
FlightList::~FlightList()
{
    while ( !isEmpty())
        remove(1);
}
bool FlightList::isEmpty() const
{
    return size == 0;
}
int FlightList::getLength() const
{
    return size;
}
FlightList::FlightListNode* FlightList::find( int index) const
{
    if ( ( index < 1) || (index > getLength()))
        return NULL;
    else
    {
        FlightListNode* cur = head;
        for ( int skip = 1; skip < index; skip++)
            cur = cur->next;
        return cur;
    }
}
bool FlightList::retrieve( int index, FlightType& dataItem) const
{
    if ((index < 1) || (index > getLength()))
        return false;
    FlightListNode* cur = find(index);
    dataItem = cur->item;

    return true;
}
bool FlightList::insert(int index, FlightType newItem)
{
    int newLength = getLength() + 1;

    if ( (index < 1) || index > newLength)
        return false;
    FlightListNode* newPtr = new FlightListNode;
    size = newLength;
    newPtr->item = newItem;

    if ( index == 1)
    {
        newPtr->next = head;
        head = newPtr;
    }
    else
    {
        FlightListNode* prev = find(index - 1);
        newPtr->next = prev->next;
        prev -> next = newPtr;
    }
    return true;
}
bool FlightList::remove(int index) {

   FlightListNode *cur;

   if ((index < 1) || (index > getLength()))
      return false;

   size--;
   if (index == 1){
      cur = head;
      head = head->next;
   }
   else{
      FlightListNode *prev = find(index-1);
      cur = prev->next;
      prev->next = cur->next;
   }
   cur->next = NULL;
   delete cur;
   cur = NULL;

   return true;
}



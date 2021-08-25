// Arda Onal 21903350 Section1
#include "CityList.h"

#include <string>
#include <cstddef>
#include <iostream>
using namespace std;

CityList::CityList(): size(0), head(NULL)
{
}
CityList::CityList( const CityList& aList): size(aList.size)
{
    if ( aList.head == NULL)
        head = NULL;
    else
    {
        head = new CityListNode;
        head->item = aList.head->item;
        CityListNode* newPtr = head;

        for (CityListNode* origPtr = aList.head->next; origPtr != NULL; origPtr = origPtr->next)
        {
            newPtr->next = new CityListNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }
}
CityList::~CityList()
{
    while ( !isEmpty())
        remove(1);
}
bool CityList::isEmpty() const
{
    return size == 0;
}
int CityList::getLength() const
{
    return size;
}
CityList::CityListNode* CityList::find( int index) const
{
    if ( ( index < 1) || (index > getLength()))
        return NULL;
    else
    {
        CityListNode* cur = head;
        for ( int skip = 1; skip < index; skip++)
            cur = cur->next;
        return cur;
    }
}
bool CityList::retrieve( int index, CityType& dataItem) const
{
    if ((index < 1) || (index > getLength()))
        return false;
    CityListNode* cur = find(index);
    dataItem = cur->item;

    return true;
}
bool CityList::insert(int index, CityType newItem)
{
    int newLength = getLength() + 1;

    if ( (index < 1) || index > newLength)
        return false;
    CityListNode* newPtr = new CityListNode;
    size = newLength;
    newPtr->item = newItem;

    if ( index == 1)
    {
        newPtr->next = head;
        head = newPtr;
    }
    else
    {
        CityListNode* prev = find(index - 1);
        newPtr->next = prev->next;
        prev -> next = newPtr;
    }
    return true;
}
bool CityList::remove(int index) {

   CityListNode *cur;

   if ((index < 1) || (index > getLength()))
      return false;

   size--;
   if (index == 1){
      cur = head;
      head = head->next;
   }
   else{
      CityListNode *prev = find(index-1);
      cur = prev->next;
      prev->next = cur->next;
   }
   cur->next = NULL;
   delete cur;
   cur = NULL;

   return true;
}

int CityList::getIndex(string name) const
{
    for ( int i = 1; i <= getLength(); i++)
    {
        if ( find(i)->item.getCityName().compare(name) == 0)
        {
            return i;
        }
    }
}
bool CityList::exists(string name) const
{
    for ( int i = 1; i <= getLength(); i++)
    {
        if ( find(i)->item.getCityName().compare(name) == 0)
        {
            return true;
        }
    }
}



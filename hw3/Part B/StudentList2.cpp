// Arda Onal 21903350 Section1
#include "StudentList2.h"

#include <string>
#include <cstddef>
#include <iostream>
using namespace std;

StudentList2::StudentList2(): size(0), head(NULL)
{
}
StudentList2::StudentList2( const StudentList2& aList): size(aList.size)
{
    if ( aList.head == NULL)
        head = NULL;
    else
    {
        head = new StudentListNode2;
        head->item = aList.head->item;
        StudentListNode2* newPtr = head;

        for (StudentListNode2* origPtr = aList.head->next; origPtr != NULL; origPtr = origPtr->next)
        {
            newPtr->next = new StudentListNode2;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }
}
StudentList2::~StudentList2()
{
    while ( !isEmpty())
        remove(1);
}
bool StudentList2::isEmpty() const
{
    return size == 0;
}
int StudentList2::getLength() const
{
    return size;
}
StudentList2::StudentListNode2* StudentList2::find( int index) const
{
    if ( ( index < 1) || (index > getLength()))
        return NULL;
    else
    {
        StudentListNode2* cur = head;
        for ( int skip = 1; skip < index; skip++)
            cur = cur->next;
        return cur;
    }
}
bool StudentList2::retrieve( int index, StudentType& dataItem) const
{
    if ((index < 1) || (index > getLength()))
        return false;
    StudentListNode2* cur = find(index);
    dataItem = cur->item;

    return true;
}
bool StudentList2::insert(int index, StudentType newItem)
{
    int newLength = getLength() + 1;

    if ( (index < 1) || index > newLength)
        return false;

    StudentListNode2* newPtr = new StudentListNode2;
    size = newLength;
    newPtr->item = newItem;
    if ( index == 1)
    {
        newPtr->next = head;
        head = newPtr;
    }
    else
    {
        StudentListNode2* prev = find(index - 1);
        newPtr->next = prev->next;
        prev -> next = newPtr;
    }
    return true;
}
bool StudentList2::remove(int index) {

   StudentListNode2 *cur;

   if ((index < 1) || (index > getLength()))
      return false;

   size--;
   if (index == 1){
      cur = head;
      head = head->next;
   }
   else{
      StudentListNode2 *prev = find(index-1);
      cur = prev->next;
      prev->next = cur->next;
   }
   cur->next = NULL;
   delete cur;
   cur = NULL;

   return true;
}


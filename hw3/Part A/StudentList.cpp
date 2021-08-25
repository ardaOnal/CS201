// Arda Onal 21903350
#include "StudentList.h"

#include <string>
#include <cstddef>
#include <iostream>
using namespace std;

StudentList::StudentList(): size(0), head(NULL)
{
}
StudentList::StudentList( const StudentList& aList): size(aList.size)
{
    if ( aList.head == NULL)
        head = NULL;
    else
    {
        head = new StudentListNode;
        head->item = aList.head->item;
        StudentListNode* newPtr = head;

        for (StudentListNode* origPtr = aList.head->next; origPtr != NULL; origPtr = origPtr->next)
        {
            newPtr->next = new StudentListNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }
}
StudentList::~StudentList()
{
    while ( !isEmpty())
        remove(1);
}
bool StudentList::isEmpty() const
{
    return size == 0;
}
int StudentList::getLength() const
{
    return size;
}
StudentList::StudentListNode* StudentList::find( int index) const
{
    if ( ( index < 1) || (index > getLength()))
        return NULL;
    else
    {
        StudentListNode* cur = head;
        for ( int skip = 1; skip < index; skip++)
            cur = cur->next;
        return cur;
    }
}
bool StudentList::retrieve( int index, ListItemType& dataItem) const
{
    if ((index < 1) || (index > getLength()))
        return false;
    StudentListNode* cur = find(index);
    dataItem = cur->item;

    return true;
}
bool StudentList::insert(int index, ListItemType newItem)
{
    int newLength = getLength() + 1;

    if ( (index < 1) || index > newLength)
        return false;
    StudentListNode* newPtr = new StudentListNode;
    size = newLength;
    newPtr->item = newItem;

    if ( index == 1)
    {
        newPtr->next = head;
        head = newPtr;
    }
    else
    {
        StudentListNode* prev = find(index - 1);
        newPtr->next = prev->next;
        prev -> next = newPtr;
    }
    return true;
}
bool StudentList::remove(int index) {

   StudentListNode *cur;

   if ((index < 1) || (index > getLength()))
      return false;

   size--;
   if (index == 1){
      cur = head;
      head = head->next;
   }
   else{
      StudentListNode *prev = find(index-1);
      cur = prev->next;
      prev->next = cur->next;
   }
   cur->next = NULL;
   delete cur;
   cur = NULL;

   return true;
}

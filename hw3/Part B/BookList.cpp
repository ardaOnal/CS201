// Arda Onal 21903350 Section1
#include "BookList.h"

#include <string>
#include <cstddef>
#include <iostream>
using namespace std;

BookList::BookList(): size(0), head(NULL)
{
}
BookList::BookList( const BookList& aList): size(aList.size)
{
    if ( aList.head == NULL)
        head = NULL;
    else
    {
        head = new BookListNode;
        head->item = aList.head->item;
        BookListNode* newPtr = head;

        for (BookListNode* origPtr = aList.head->next; origPtr != NULL; origPtr = origPtr->next)
        {
            newPtr->next = new BookListNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }
}
BookList::~BookList()
{
    while ( !isEmpty())
        remove(1);
}
bool BookList::isEmpty() const
{
    return size == 0;
}
int BookList::getLength() const
{
    return size;
}
BookList::BookListNode* BookList::find( int index) const
{
    if ( ( index < 1) || (index > getLength()))
        return NULL;
    else
    {
        BookListNode* cur = head;
        for ( int skip = 1; skip < index; skip++)
            cur = cur->next;
        return cur;
    }
}
bool BookList::retrieve( int index, BookItemType& dataItem) const
{
    if ((index < 1) || (index > getLength()))
        return false;
    BookListNode* cur = find(index);
    dataItem = cur->item;

    return true;
}
bool BookList::insert(int index, BookItemType newItem)
{
    int newLength = getLength() + 1;

    if ( (index < 1) || index > newLength)
        return false;
    BookListNode* newPtr = new BookListNode;
    size = newLength;
    newPtr->item = newItem;

    if ( index == 1)
    {
        newPtr->next = head;
        head = newPtr;
    }
    else
    {
        BookListNode* prev = find(index - 1);
        newPtr->next = prev->next;
        prev -> next = newPtr;
    }
    return true;
}
bool BookList::remove(int index) {

   BookListNode *cur;

   if ((index < 1) || (index > getLength()))
      return false;

   size--;
   if (index == 1){
      cur = head;
      head = head->next;
   }
   else{
      BookListNode *prev = find(index-1);
      cur = prev->next;
      prev->next = cur->next;
   }
   cur->next = NULL;
   delete cur;
   cur = NULL;

   return true;
}


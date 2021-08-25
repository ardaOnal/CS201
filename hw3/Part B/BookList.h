// Arda Onal 21903350 Section1
#ifndef __BOOKLIST_H
#define __BOOKLIST_H
#include "Book.h"
#include <string>

typedef Book BookItemType;

class BookList
{
private:
    struct BookListNode
    {
        BookItemType item;
        BookListNode* next;
    };

    int size;
    BookListNode* head;
    BookListNode* find(int index) const;
    friend class LibrarySystem;
public:
    BookList();
    BookList(const BookList&);
    ~BookList();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve( int index, BookItemType& dataItem) const;
    bool insert(int index, BookItemType newItem);
    bool remove(int index);

};
#endif // __BOOKLIST_H


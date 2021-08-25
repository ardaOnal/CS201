// Arda Onal 21903350 Section1
#ifndef __STUDENT_H
#define __STUDENT_H
#include <string>
#include "Book.h"
#include "BookList.h"
using namespace std;

class Student
{
private:
    BookList booksBorrowed;
    int id;
    string studentName;
    friend class LibrarySystem;
public:
    Student( int, string);
    Student();
    ~Student();
    void setId( int );
    void setName( string);
    void setBooksBorrowed(BookList);
    int getId() const;
    string getName() const;
    BookList& getBooksBorrowed();
};
#endif

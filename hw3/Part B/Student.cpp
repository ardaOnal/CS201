// Arda Onal 21903350 Section1
#include "Student.h"
#include <string>
using namespace std;
Student::Student()
{
    id = 0;
    studentName = "";
}
Student::Student(int ID, string name)
{
    id = ID;
    studentName = name;
}
Student::~Student()
{
    booksBorrowed.~BookList();
}
void Student::setId( int ID)
{
    id = ID;
}
void Student::setName( string name)
{
    studentName = name;
}
void Student::setBooksBorrowed(BookList l)
{
    booksBorrowed = l;
}
int Student::getId() const
{
    return id;
}
string Student::getName() const
{
    return studentName;
}
BookList& Student::getBooksBorrowed()
{
    return booksBorrowed;
}

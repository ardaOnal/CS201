// Arda Onal 21903350 Section1
#include "Book.h"
#include <string>
using namespace std;
Book::Book( int Id, string Title, int Year)
{
    id = Id;
    title = Title;
    year = Year;
}
Book::Book()
{
    id = 0;
    title = "";
    year = 0;
}
void Book::setId( int ID)
{
    id = ID;
}
void Book::setTitle( string Title)
{
    title = Title;
}
void Book::setYear(int Year)
{
    year = Year;
}
int Book::getId() const
{
    return id;
}
string Book::getTitle() const
{
    return title;
}
int Book::getYear() const
{
    return year;
}

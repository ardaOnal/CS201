// Arda Onal 21903350 Section1
#ifndef __BOOK_H
#define __BOOK_H
#include <string>
using namespace std;
class Book
{
private:
    int id;
    string title;
    int year;
public:
    Book( int,string,int);
    Book();
    void setId( int );
    void setTitle( string);
    void setYear(int);
    int getId() const;
    string getTitle() const;
    int getYear() const;
};
#endif

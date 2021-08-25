// Arda Onal 21903350 Section1
#ifndef __SIMPLESTUDENT_H
#define __SIMPLESTUDENT_H

#include <string>
using namespace std;

class SimpleStudent
{
private:
    int id;
    string studentName;
public:
    SimpleStudent( int, string);
    SimpleStudent();
    ~SimpleStudent();
    void setId( int );
    void setName( string);
    int getId() const;
    string getName() const;
};
#endif

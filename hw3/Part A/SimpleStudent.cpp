// Arda Onal 21903350 Section1
#include "SimpleStudent.h"
#include <string>
using namespace std;
SimpleStudent::SimpleStudent()
{
    id = 0;
    studentName = "";
}
SimpleStudent::SimpleStudent(int ID, string name)
{
    id = ID;
    studentName = name;
}
SimpleStudent::~SimpleStudent()
{

}
void SimpleStudent::setId( int ID)
{
    id = ID;
}
void SimpleStudent::setName( string name)
{
    studentName = name;
}
int SimpleStudent::getId() const
{
    return id;
}
string SimpleStudent::getName() const
{
    return studentName;
}

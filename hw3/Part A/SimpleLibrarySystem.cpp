// Arda Onal 21903350 Section1
#include "SimpleLibrarySystem.h"
#include <string>
#include <iostream>
using namespace std;

SimpleLibrarySystem::SimpleLibrarySystem()
{
}
SimpleLibrarySystem::~SimpleLibrarySystem()
{
    students.~StudentList();
}
void SimpleLibrarySystem::addStudent(const int id, const string name)
{
    if ( id < 1)
    {
        cout << "Error: Id must be greater than 0" << endl;
        return;
    }
    SimpleStudent tmp;
    bool alreadyExists = false;
    for ( int i = 1; i <= students.getLength(); i++)
    {
        if (students.retrieve(i, tmp))
        {
            if ( tmp.getId() == id)
            {
                alreadyExists = true;
                break;
            }
        }
    }

    if ( alreadyExists)
        cout << "Error: Student with id " << id << " already exists." << endl;
    else
       students.insert((students.getLength()+1), SimpleStudent(id,name));
}
void SimpleLibrarySystem::deleteStudent( const int studentId)
{
    SimpleStudent tmp;
    for ( int i = 1; i <= students.getLength(); i++)
    {
        if (students.retrieve(i, tmp))
        {
            if ( tmp.getId() == studentId)
            {
                students.remove(i);
                return;
            }
        }
    }
    cout << "Error: Student with id " << studentId << " does not exist." << endl;
}
void SimpleLibrarySystem::showStudent(const int id) const
{
    SimpleStudent tmp;
    for ( int i = 1; i <= students.getLength(); i++)
    {
        if (students.retrieve(i, tmp))
        {
            if ( tmp.getId() == id)
            {
                cout << "Student with id " << id << " is " << tmp.getName() << "." << endl;
                return;
            }
        }
    }
    cout << "Error: Student with id " << id << " does not exist." << endl;
}

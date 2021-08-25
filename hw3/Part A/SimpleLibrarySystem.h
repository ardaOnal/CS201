// Arda Onal 21903350 Section1
#ifndef __SIMPLESLIBRARYSYSTEM_H
#define __SIMPLESLIBRARYSYSTEM_H

#include "StudentList.h"
#include <string>
using namespace std;

class SimpleLibrarySystem
{
private:
    StudentList students;
public:
    SimpleLibrarySystem();
    ~SimpleLibrarySystem();

    void addStudent(const int, const string);
    void deleteStudent(const int);
    void showStudent(const int) const;
};
#endif

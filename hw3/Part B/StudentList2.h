// Arda Onal 21903350 Section1
#ifndef __STUDENTLIST2_H
#define __STUDENTLIST2_H
#include "Student.h"
#include <string>

typedef Student StudentType;

class StudentList2
{
private:
    struct StudentListNode2
    {
        StudentType item;
        StudentListNode2* next;
    };

    int size;
    StudentListNode2* head;
    StudentListNode2* find(int index) const;
    friend class LibrarySystem;
public:
    StudentList2();
    StudentList2(const StudentList2&);
    ~StudentList2();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve( int index, StudentType& dataItem) const;
    bool insert(int index, StudentType newItem);
    bool remove(int index);

};
#endif // __STUDENTLIST2_H


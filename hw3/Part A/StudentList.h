// Arda Onal 21903350 Section1
#ifndef __STUDENTLIST_H
#define __STUDENTLIST_H
#include "SimpleStudent.h"
#include <string>

typedef SimpleStudent ListItemType;

class StudentList
{
private:
    struct StudentListNode
    {
        ListItemType item;
        StudentListNode* next;
    };

    int size;
    StudentListNode* head;
    StudentListNode* find(int index) const;
public:
    StudentList();
    StudentList(const StudentList&);
    ~StudentList();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve( int index, ListItemType& dataItem) const;
    bool insert(int index, ListItemType newItem);
    bool remove(int index);

};
#endif // __STUDENTLIST_H

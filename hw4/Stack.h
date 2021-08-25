// Arda Onal 21903350 Section1
#ifndef __STACK_H
#define __STACK_H
#include "CityList.h" // list operations
#include "City.h"
typedef City StackItemType;

class Stack {

public:
   Stack();
   Stack(const Stack& aStack);
   ~Stack();

   bool isEmpty() const;
   bool push(StackItemType newItem);
   bool pop();
   bool pop(StackItemType& stackTop);
   bool getTop(StackItemType& stackTop) const;
   bool searchStack(string);
   //Stack& operator=( const Stack& right);


private:
   CityList aList;  // list of stack items

};
#endif

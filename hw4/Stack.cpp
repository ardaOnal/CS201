// Arda Onal 21903350 Section1
#include "Stack.h"
// default constructor
Stack::Stack(){

}
// copy constructor
Stack::Stack(const Stack& aStack)
           : aList(aStack.aList){

}
// destructor
Stack::~Stack() {

}
bool Stack::isEmpty() const {
   return aList.isEmpty();
}

bool Stack::getTop(StackItemType& stackTop)
       const {
   return aList.retrieve(1, stackTop);
}

bool Stack::push(StackItemType newItem){
     return aList.insert(1, newItem);
}
bool Stack::pop() {
    return aList.remove(1);
}


bool Stack::pop(StackItemType& stackTop) {
   if (aList.retrieve(1, stackTop))
      return aList.remove(1);
   else
      return false;
}

bool Stack::searchStack(string name)
{
    return aList.exists(name);
}
//Stack& Stack::operator=( const Stack& right)
//{
//    if ( &right != this)
//    {
//        for ( int i = 1; i <= aList.getLength(); i++)
//        {
//            City tmp;
//            aList.retrieve(i,tmp);
//            right.aList.insert(aList.getLength()+1,tmp);
//        }
//    }
//    return *this;
//}

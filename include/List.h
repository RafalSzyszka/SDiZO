#ifndef LIST_H
#define LIST_H

#include "Structure.h"

class List : public Structure
{
    public:
		List() : next(nullptr), value(-2147483647){} //default constructor
        List(int); //constructor with initial value

        List* add(int);   //add value at beginning
        List* addAtIndex(int, unsigned int);     //adds value at specific index of list
        List* addAtEnd(int);    //add to end of list

        void print();   //print list

        unsigned int getSize();     //return size of list
        int deleteFirst(Structure**);      //deletes first element and returns it's value
        int deleteLast();    //deletes last element and returns it's value
        int deleteAtIndex(unsigned int, Structure**);    //deletes specific element and returns it's value

        bool isEmpty();     //return true if list is empty, otherwise false
        bool findValue(int);    //searches for specific value
        int get(unsigned int);
        virtual ~List();

    private:
        List *next;
        int value;

        List* toEnd();  //goes to end of list
        List* toLastButOne();   //goes to last but one element on list
};

#endif // LIST_H

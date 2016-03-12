#ifndef LIST_H
#define LIST_H

class List
{
    public:
		List() {} //default constructor
        List(int); //constructor with initial value

        List* push(int);   //add value at beginning
        List* addAtIndex(int, unsigned int);     //adds value at specific index of list

        void printList();   //print list
        void addToEnd(int);    //add to end of list

        unsigned int getSize();     //return size of list
        int pop(List**);      //deletes first element and returns it's value
        int deleteFromEnd();    //deletes last element and returns it's value
        int deleteAtIndex(unsigned int, List**);    //deletes specific element and returns it's value
        int deleteFirstOf(int value, List**);       //deletes first ap of value

        bool isEmpty();     //return true if list is empty, otherwise false

        virtual ~List();

    private:
        List *next;
        int value;

        List* toEnd();  //goes to end of list
        List* toLastButOne();   //goes to last but one element on list
};

#endif // LIST_H

#ifndef DYNTAB_H
#define DYNTAB_H

#include "Structure.h"

class DynTab : public Structure
{
    public:
        DynTab();   //creates empty table
        DynTab(unsigned int);  //creates table with specific size

        DynTab* addAtIndex(int, unsigned int);     //adds value at specific index
        DynTab* add(int);     //adds value at the begin of table
        DynTab* addAtEnd(int);      //adds value at the end, and resizes table
        void print();   //prints structure

        unsigned int getSize() {return size;}

        int get(unsigned int);     //gets value not deleting it
        int deleteAtIndex(unsigned int, Structure** = nullptr);   //deletes value at specific index and resizes table
        int deleteFirst(Structure** = nullptr);  //deletes and returns first value
        int deleteLast();   //deletes and returns last value

        bool findValue(int);    //searches for specific value

        virtual ~DynTab();

    private:
        unsigned int size;
        int *tab;
};

#endif // DYNTAB_H

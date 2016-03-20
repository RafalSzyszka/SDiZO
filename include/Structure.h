#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <string>

class Structure
{
    public:
        virtual Structure* add(int)=0;    //adding at the beginning
        virtual Structure* addAtIndex(int, unsigned int)=0;   //adding at specified index
        virtual Structure* addAtEnd(int)=0;       //adding at the end

        virtual int get(unsigned int)=0;    //gets value at specific index
        virtual int deleteFirst(Structure** = nullptr)=0;    //deleting value at the beginning
        virtual int deleteAtIndex(unsigned int, Structure** = nullptr)=0;  //deleting at specified index
        virtual int deleteLast()=0;     //deleting last element

        virtual void print()=0;     //printing structure
        virtual Structure* initFromFile(std::string)=0; //initialize structure from file
        virtual int findValue(int)=0;  //searches for value

        virtual unsigned int getSize()=0;

        virtual ~Structure();
};

#endif // STRUCTURE_H

#ifndef STRUCTURE_H
#define STRUCTURE_H


class Structure
{
    public:
        virtual void add(int)=0;    //adding at the beginning
        virtual void addAtIndex(int, unsigned int)=0;   //adding at specified index
        virtual void addAtEnd(int)=0;       //adding at the end

        virtual int deleteFirst()=0;    //deleting value at the beginning
        virtual int deleteAtIndex(unsigned int)=0;  //deleting at specified index
        virtual int deleteLast()=0;     //deleting last element

        virtual void print()=0;     //printing structure
        virtual bool findValue(int)=0;  //searches for value
};

#endif // STRUCTURE_H

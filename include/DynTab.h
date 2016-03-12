#ifndef DYNTAB_H
#define DYNTAB_H


class DynTab
{
    public:
        DynTab();   //creates empty table
        DynTab(unsigned int);  //creates table with specific size

        void addAtIndex(int, unsigned int);     //adds value at specific index
        void addAtBegin(int);     //adds value at the begin of table
        void add(int);      //adds value at the end, and resizes table

        unsigned int getSize() {return size;}
        int getIndex(unsigned int);     //gets value not deleting it
        int deleteIndex(unsigned int);   //deletes value at specific index and resizes table
        int deleteFirst();  //deletes and returns first value
        int deleteLast();   //deletes and returns last value

        virtual ~DynTab();

    private:
        unsigned int size;
        int *tab;
};

#endif // DYNTAB_H

#ifndef STRUCTTESTER_H
#define STRUCTTESTER_H

#include "Structure.h"

#include <string>

/**simple tester, tests structure methods, prints structures states after each operation*/
class StructTester
{
    public:
        StructTester();
        StructTester(Structure*, Structure*, Structure*, Structure*);

        void testAdd(int);
        void testAddAtEnd(int);
        void testAddAtIndex(int, unsigned int);

        void testDeleteFirst();
        void testDeleteLast();
        void testDeleteAtIndex(unsigned int);

        void testFindValue(int);

        void fillStructuresFromFile(std::string);

        void printList();
        void printHeap();
        void printDTab();
        void printRbTr();

        void setStructures(Structure*,Structure*,Structure*,Structure*);
        void setList(Structure*);
        void setHeap(Structure*);
        void setDtab(Structure*);
        void setRbtr(Structure*);

        void clearStructures();
        void clearList();
        void clearHeap();
        void clearDtab();
        void clearRBtr();

        virtual ~StructTester();

    private:
        Structure* list;
        Structure* heap;
        Structure* dtab;
        Structure* rbtree;
};

#endif // STRUCTTESTER_H

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

        virtual ~StructTester();

    private:
        Structure* list;
        Structure* heap;
        Structure* dtab;
        Structure* rbtree;
};

#endif // STRUCTTESTER_H

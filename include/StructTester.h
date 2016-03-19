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

        void testAddAll(int);   //
        void testAddAtEndAll(int);  //
        void testAddAtIndexAll(int, unsigned int);  //

        void testAddList(int);  //
        void testAddAtEndList(int); //
        void testAddAtIndexList(int, unsigned int); //

        void testAddHeap(int);  //

        void testAddDTab(int);  //
        void testAddAtEndDTab(int); //
        void testAddAtIndexDTab(int, unsigned int); //

        void testAddRBTr(int);

        void testDeleteFirstAll(); //
        void testDeleteLastAll();//
        void testDeleteAtIndexAll(unsigned int);//

        void testDeleteFirstList(); //
        void testDeleteLastList();//
        void testDeleteAtIndexList(unsigned int);//

        void testDeleteFirstHeap();//

        void testDeleteFirstDTab();//
        void testDeleteLastDTab();//
        void testDeleteAtIndexDTab(unsigned int);//

        void testDeleteFirstRBTr();

        void testFindValueAll(int);
        void testFindValueList(int);
        void testFindValueHeap(int);
        void testFindValueDTab(int);
        void testFindValueRBTr(int);

        void fillStructuresFromFile(std::string);/**/

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

        void preOperationFile(Structure*, std::string, std::string, int, unsigned int, unsigned int, unsigned int);
        void afterOperationFile(Structure*, std::string, unsigned int, unsigned int);

};

#endif // STRUCTTESTER_H

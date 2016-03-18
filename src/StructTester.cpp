#include "StructTester.h"

#include "Structure.h"
#include "List.h"
#include "Heap.h"
#include "DynTab.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/**creates empty structures, for tests*/
StructTester::StructTester() :
    list(new List()), heap(new Heap()), dtab(new DynTab()), rbtree(nullptr) { }

/**gets structures for tests*/
StructTester::StructTester(Structure* l, Structure* h, Structure* dt, Structure* rbt) :
    list(l), heap(h), dtab(dt), rbtree(rbt) { }

/**tests adding at begin method for all structures same time,
creates/opens files named as structure class, write state before adding, adding value and state after addition*/
void StructTester::testAddAll(int value) {
    preOperationFile(list, "listAddTests.txt", "dodawania na poczatku", value, 0, 0, 5);
    list = list->add(value);
    afterOperationFile(list, "listAddTests.txt", 0, 5);

    preOperationFile(heap,"heapAddTests.txt", "dodawania na poczatku", value, 0, 0, 5);
    heap->add(value);
    afterOperationFile(heap, "heapAddTests.txt", 0, 5);

    preOperationFile(dtab, "DTabAddTests.txt", "dodawania na poczatku", value, 0, 0, 5);
    dtab->add(value);
    afterOperationFile(dtab, "DTabAddTests.txt", 0, 5);
    //testAddingWriteToFile("RBTrAddTests.txt", rbtree, value);
}

/**tests adding at end method for all structures same time,
creates/opens files named as structure class, write state before adding, adding value and state after addition*/
void StructTester::testAddAtEndAll(int value) {
    preOperationFile(list, "listAddAtEndTests.txt", "dodawania na koncu", value, NULL, list->getSize() -6, list->getSize());
    list = list->addAtEnd(value);
    afterOperationFile(list, "listAddAtEndTests.txt", list->getSize() -6, list->getSize());

    preOperationFile(dtab, "DTabAddAtEndTests.txt", "dodawania na koncu", value, NULL, dtab->getSize() -6, dtab->getSize());
    dtab->addAtEnd(value);
    afterOperationFile(dtab, "DTabAddAtEndTests.txt", dtab->getSize() -6, dtab->getSize());

}

/**tests adding at index method for all structures same time,
creates/opens files named as structure class, write state before adding, adding value and state after addition*/
void StructTester::testAddAtIndexAll(int value, unsigned int index) {
    preOperationFile(list, "listAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, index-3, index+3);
    list = list->addAtIndex(value, index);
    afterOperationFile(list, "listAddAtIndexTests.txt", index-3, index+4);

    preOperationFile(dtab, "DTabAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, index-3, index+3);
    dtab->addAtIndex(value, index);
    afterOperationFile(dtab, "DTabAddAtIndexTests.txt", index-3, index+4);
}

void StructTester::testAddList(int value) {
    preOperationFile(list, "listAddTests.txt", "dodawania na poczatku", value, 0, 0, 5);
    list = list->add(value);
    afterOperationFile(list, "listAddTests.txt", 0, 5);
}

void StructTester::testAddHeap(int value) {
    preOperationFile(heap, "heapAddTests.txt", "dodawania na poczatku", value, 0, 0, 5);
    heap->add(value);
    afterOperationFile(heap, "heapAddTests.txt", 0, 5);
}

void StructTester::testAddDTab(int value) {
    preOperationFile(dtab,"DTabAddTests.txt", "dodawania na poczatku", value, 0, 0, 5);
    dtab->add(value);
    afterOperationFile(dtab, "DTabAddTests.txt", 0, 5);
}

void StructTester::testAddAtEndList(int value) {
    preOperationFile(list, "listAddAtEndTests.txt", "dodawania na koncu", value, 0, list->getSize() -6, list->getSize());
    list = list->addAtEnd(value);
    afterOperationFile(list, "listAddAtEndTests.txt", list->getSize() -6, list->getSize());
}

void StructTester::testAddAtIndexList(int value, unsigned int index) {
    preOperationFile(list, "listAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, index-3, index+3);
    list = list->addAtIndex(value, index);
    afterOperationFile(list, "listAddAtIndexTests.txt", index-3, index+4);
}

void StructTester::testAddAtIndexDTab(int value, unsigned int index) {
    preOperationFile(dtab, "DTabAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, index-3, index+3);
    dtab->addAtIndex(value, index);
    afterOperationFile(dtab, "DTabAddAtIndexTests.txt", index-3, index+4);
}

void StructTester::testAddAtEndDTab(int value) {
    preOperationFile(dtab, "DTabAddAtEndTests.txt", "dodawania na koncu", value, NULL, dtab->getSize() -6, dtab->getSize());
    dtab->addAtEnd(value);
    afterOperationFile(dtab, "DTabAddAtEndTests.txt", dtab->getSize() -6, dtab->getSize());
}

/**initialize structures with values from file*/
void StructTester::fillStructuresFromFile(std::string filePath) {
    std::string line;
    std::ifstream dataFile(filePath);
    if(dataFile.is_open()) {
        std::cout << "Odczyt z pliku (moze to troche potrwac)...";
        while (getline(dataFile, line)) {
            int value;
            std::istringstream iss(line);   //converting string to int
            iss >> value;
            list->addAtEnd(value);  //adding value to structures
            heap->addAtEnd(value);
            dtab->addAtEnd(value);
        }
        std::cout << "Gotowe!\nStruktury wypelnione wartosciami z pliku!" << std::endl;
        dataFile.close();
    } else {
        std::cout << "Ups! Cos poszlo nie tak :(" << std::endl;
    }
}

/**4 methods below prints structures to standard out*/
void StructTester::printList() {
    list->print();
}

void StructTester::printHeap() {
    heap->print();
}

void StructTester::printDTab() {
    dtab->print();
}

void StructTester::printRbTr() {
    //rbtree->print();
}

void StructTester::setStructures(Structure *li, Structure *h, Structure *dt, Structure *rbt) {
    delete(list);
    list = (List*) li;
    delete(heap);
    heap = (Heap*) h;
    delete(dtab);
    dtab = (DynTab*) dt;
    //delete(rbtree);
    //rbtree = (RBTree*) rbt;
}

void StructTester::setList(Structure* li) {
    delete(list);
    list = (List*)li;
}

void StructTester::setHeap(Structure* he) {
    delete(heap);
    heap = (Heap*)he;
}

void StructTester::setDtab(Structure* dt) {
    delete(dtab);
    dtab = (DynTab*)dt;
}

void StructTester::setRbtr(Structure* rb) {
    //delete(RBTree);
    //rbtree = (RBTree*)rb;
}

void StructTester::clearStructures() {
    delete(list);
    list = new List();
    delete(heap);
    heap = new Heap();
    delete(dtab);
    dtab = new DynTab();
    //delete(rbtree);
    //rbtree = new RBTree();
}

void StructTester::clearList() {
    delete(list);
    list = new List();
}

void StructTester::clearHeap() {
    delete(heap);
    heap = new Heap();
}

void StructTester::clearDtab() {
    delete(dtab);
    dtab = new DynTab();
}

void StructTester::clearRBtr() {
    //delete(rbtree);
    //rbtree = new RBTree();
}

StructTester::~StructTester()
{
    delete(list);
    delete(heap);
    delete(dtab);
    delete(rbtree);
}

void StructTester::preOperationFile(Structure* st, std::string filename, std::string where, int value, unsigned int index, unsigned int begin, unsigned int end) {
    std::ofstream flist;
    flist.open(filename, std::ios::out | std::ios::app);
    if(flist.is_open()) {
        flist << "Testowanie " << where << " struktury.\nStan struktury:\n\n... ";
        std::cout << "Testowanie " << where << " struktury.\nStan struktury:\n\n... ";
        for(unsigned int i = begin; i < end; i++) {
            flist << st->get(i) << " ";
            std::cout << st->get(i) << " ";
        }
        flist << "\n\n";
        flist << "Wartosc: " << value << "  index: " << index << "\n\nStan struktury po operacji:\n\n... ";
        std::cout << "\n\n";
        std::cout << "Wartosc: " << value << "  index: " << index << "\n\nStan struktury po operacji:\n\n... ";
        flist.close();
    } else {
        std::cout << "Blad podczas otwierania pliku" << std::endl;
    }
}

void StructTester::afterOperationFile(Structure* st, std::string filename, unsigned int begin, unsigned int end) {
    std::ofstream flist;
    flist.open(filename, std::ios::out | std::ios::app);
    if(flist.is_open()) {
        for(unsigned int i = begin; i < end; i++) {
                flist << st->get(i) << " ";
                std::cout << st->get(i) << " ";
            }
            flist << "\n\n\n";
            std::cout << "\n\n\n";
            flist.close();
    } else {
        std::cout << "Blad podczas otwierania pliku!" << std::endl;
    }
}

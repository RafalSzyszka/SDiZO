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

#include "StructTester.h"

#include "Structure.h"
#include "List.h"
#include "Heap.h"
#include "DynTab.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

StructTester::StructTester() :
    list(new List()), heap(new Heap()), dtab(new DynTab()) { }

StructTester::StructTester(Structure* l, Structure* h, Structure* dt, Structure* rbt) :
    list(l), heap(h), dtab(dt), rbtree(rbt) { }

void StructTester::fillStructuresFromFile(std::string filePath) {
    std::string line;
    std::ifstream dataFile(filePath);
    if(dataFile.is_open()) {
        std::cout << "Odczyt z pliku (moze to troche potrwac)...";
        while (getline(dataFile, line)) {
            int value;
            std::istringstream iss(line);
            iss >> value;
            list->addAtEnd(value);
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

StructTester::~StructTester()
{
    delete(list);
    delete(heap);
    delete(dtab);
    delete(rbtree);
}

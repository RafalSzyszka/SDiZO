#include "StructTester.h"

#include "Structure.h"
#include "List.h"
#include "Heap.h"
#include "DynTab.h"
#include "RBTree.h"


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/**creates empty structures, for tests*/
StructTester::StructTester() :
    list(new List()), heap(new Heap()), dtab(new DynTab()), rbtree(new RBTree()) { }

/**gets structures for tests*/
StructTester::StructTester(Structure* l, Structure* h, Structure* dt, Structure* rbt) :
    list(l), heap(h), dtab(dt), rbtree(rbt) { }

/**tests adding at begin method for all structures same time,
creates/opens files named as structure class, write state before adding, adding value and state after addition*/
void StructTester::testAddAll(int value) {
    std::cout << "\nLISTA:\n";
    if(list->getSize() <= 10) {
        preOperationFile(list, "listAddTests.txt", "dodawania na poczatku", value, 0, 0, list->getSize());
        list = list->add(value);
        afterOperationFile(list, "listAddTests.txt", 0, list->getSize());
    } else {
        preOperationFile(list, "listAddTests.txt", "dodawania na poczatku", value, 0, 0, 5);
        list = list->add(value);
        afterOperationFile(list, "listAddTests.txt", 0, 5);
    }

    std::cout << "\nKOPIEC:\n";
    if(heap->getSize() <= 10) {
        preOperationFile(heap,"heapAddTests.txt", "dodawania na poczatku", value, 0, 0, heap->getSize());
        heap->add(value);
        afterOperationFile(heap, "heapAddTests.txt", 0, heap->getSize());
    } else {
        preOperationFile(heap,"heapAddTests.txt", "dodawania na poczatku", value, 0, 0, 5);
        heap->add(value);
        afterOperationFile(heap, "heapAddTests.txt", 0, 5);
    }

    std::cout << "\nTABLICA DYNAMICZNA:\n";
    if(dtab->getSize() <= 10) {
        preOperationFile(dtab, "DTabAddTests.txt", "dodawania na poczatku", value, 0, 0, dtab->getSize());
        dtab->add(value);
        afterOperationFile(dtab, "DTabAddTests.txt", 0, dtab->getSize());
    } else {
        preOperationFile(dtab, "DTabAddTests.txt", "dodawania na poczatku", value, 0, 0, 5);
        dtab->add(value);
        afterOperationFile(dtab, "DTabAddTests.txt", 0, 5);
    }

}

/**tests adding at end method for all structures same time,
creates/opens files named as structure class, write state before adding, adding value and state after addition*/
void StructTester::testAddAtEndAll(int value) {
    std::cout << "\nLISTA:\n";
    if(dtab->getSize() <= 10) {
        preOperationFile(list, "listAddAtEndTests.txt", "dodawania na koncu", value, NULL, 0, list->getSize());
        list = list->addAtEnd(value);
        afterOperationFile(list, "listAddAtEndTests.txt", 0, list->getSize());
    } else {
        preOperationFile(list, "listAddAtEndTests.txt", "dodawania na koncu", value, NULL, list->getSize() -6, list->getSize());
        list = list->addAtEnd(value);
        afterOperationFile(list, "listAddAtEndTests.txt", list->getSize() -6, list->getSize());
    }

    std::cout << "\nTABLICA DYNAMICZNA:\n";
    if(dtab->getSize() <= 10) {
        preOperationFile(dtab, "DTabAddAtEndTests.txt", "dodawania na koncu", value, NULL, 0, dtab->getSize());
        dtab->addAtEnd(value);
        afterOperationFile(dtab, "DTabAddAtEndTests.txt", 0, dtab->getSize());
    } else {
        preOperationFile(dtab, "DTabAddAtEndTests.txt", "dodawania na koncu", value, NULL, dtab->getSize() -6, dtab->getSize());
        dtab->addAtEnd(value);
        afterOperationFile(dtab, "DTabAddAtEndTests.txt", dtab->getSize() -6, dtab->getSize());
    }
}

/**tests adding at index method for all structures same time,
creates/opens files named as structure class, write state before adding, adding value and state after addition*/
void StructTester::testAddAtIndexAll(int value, unsigned int index) {
    std::cout << "\nLISTA:\n";
    if(list->getSize() <= 10) {
        preOperationFile(list, "listAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, 0, list->getSize());
        list = list->addAtIndex(value, index);
        afterOperationFile(list, "listAddAtIndexTests.txt", 0, list->getSize());
    } else if(index+5 >= list->getSize()) {
        preOperationFile(list, "listAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, index -3, list->getSize());
        list = list->addAtIndex(value, index);
        afterOperationFile(list, "listAddAtIndexTests.txt", index -3, list->getSize());
    } else if(index < 5) {
        preOperationFile(list, "listAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, 0, index+3);
        list = list->addAtIndex(value, index);
        afterOperationFile(list, "listAddAtIndexTests.txt", 0, index+3);
    } else {
        preOperationFile(list, "listAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, index-3, index+3);
        list = list->addAtIndex(value, index);
        afterOperationFile(list, "listAddAtIndexTests.txt", index-3, index+4);
    }

    std::cout << "\nTABLICA DYNAMICZNA:\n";
    if(dtab->getSize() <= 10) {
        preOperationFile(dtab, "DTabAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, 0, dtab->getSize());
        dtab->addAtIndex(value, index);
        afterOperationFile(dtab, "DTabAddAtIndexTests.txt", 0, dtab->getSize());
    } else if(index+5 >= dtab->getSize()) {
        preOperationFile(dtab, "DTabAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, index-3, dtab->getSize());
        dtab->addAtIndex(value, index);
        afterOperationFile(dtab, "DTabAddAtIndexTests.txt", index-3, dtab->getSize());
    } else if(index < 5) {
        preOperationFile(dtab, "DTabAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, 0, index+3);
        dtab->addAtIndex(value, index);
        afterOperationFile(dtab, "DTabAddAtIndexTests.txt", 0, index+4);
    } else {
        preOperationFile(dtab, "DTabAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, index-3, index+3);
        dtab->addAtIndex(value, index);
        afterOperationFile(dtab, "DTabAddAtIndexTests.txt", index-3, index+4);
    }
}

void StructTester::testAddList(int value) {
    if(list->getSize() <= 10) {
        preOperationFile(list, "listAddTests.txt", "dodawania na poczatku", value, 0, 0, list->getSize());
        list = list->add(value);
        afterOperationFile(list, "listAddTests.txt", 0, list->getSize());
    } else {
        preOperationFile(list, "listAddTests.txt", "dodawania na poczatku", value, 0, 0, 5);
        list = list->add(value);
        afterOperationFile(list, "listAddTests.txt", 0, 5);
    }
}

void StructTester::testAddHeap(int value) {
    if(heap->getSize() <= 10) {
        preOperationFile(heap,"heapAddTests.txt", "dodawania", value, 0, 0, heap->getSize());
        heap->add(value);
        afterOperationFile(heap, "heapAddTests.txt", 0, heap->getSize());
    } else {
        preOperationFile(heap,"heapAddTests.txt", "dodawania", value, 0, 0, 5);
        heap->add(value);
        afterOperationFile(heap, "heapAddTests.txt", 0, 5);
    }
}

void StructTester::testAddDTab(int value) {
    if(dtab->getSize() <= 10) {
        preOperationFile(dtab, "DTabAddTests.txt", "dodawania na poczatku", value, 0, 0, dtab->getSize());
        dtab->add(value);
        afterOperationFile(dtab, "DTabAddTests.txt", 0, dtab->getSize());
    } else {
        preOperationFile(dtab, "DTabAddTests.txt", "dodawania na poczatku", value, 0, 0, 5);
        dtab->add(value);
        afterOperationFile(dtab, "DTabAddTests.txt", 0, 5);
    }
}

void StructTester::testAddAtEndList(int value) {
    if(dtab->getSize() <= 10) {
        preOperationFile(list, "listAddAtEndTests.txt", "dodawania na koncu", value, NULL, 0, list->getSize());
        list = list->addAtEnd(value);
        afterOperationFile(list, "listAddAtEndTests.txt", 0, list->getSize());
    } else {
        preOperationFile(list, "listAddAtEndTests.txt", "dodawania na koncu", value, NULL, list->getSize() -6, list->getSize());
        list = list->addAtEnd(value);
        afterOperationFile(list, "listAddAtEndTests.txt", list->getSize() -6, list->getSize());
    }
}

void StructTester::testAddAtIndexList(int value, unsigned int index) {
    if(list->getSize() <= 10) {
        preOperationFile(list, "listAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, 0, list->getSize());
        list = list->addAtIndex(value, index);
        afterOperationFile(list, "listAddAtIndexTests.txt", 0, list->getSize());
    } else if(index+5 >= list->getSize()) {
        preOperationFile(list, "listAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, index -3, list->getSize());
        list = list->addAtIndex(value, index);
        afterOperationFile(list, "listAddAtIndexTests.txt", index -3, list->getSize());
    } else if(index < 5) {
        preOperationFile(list, "listAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, 0, index+3);
        list = list->addAtIndex(value, index);
        afterOperationFile(list, "listAddAtIndexTests.txt", 0, index+3);
    } else {
        preOperationFile(list, "listAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, index-3, index+3);
        list = list->addAtIndex(value, index);
        afterOperationFile(list, "listAddAtIndexTests.txt", index-3, index+4);
    }
}

void StructTester::testAddAtIndexDTab(int value, unsigned int index) {
    if(dtab->getSize() <= 10) {
        preOperationFile(dtab, "DTabAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, 0, dtab->getSize());
        dtab->addAtIndex(value, index);
        afterOperationFile(dtab, "DTabAddAtIndexTests.txt", 0, dtab->getSize());
    } else if(index+5 >= dtab->getSize()) {
        preOperationFile(dtab, "DTabAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, index-3, dtab->getSize());
        dtab->addAtIndex(value, index);
        afterOperationFile(dtab, "DTabAddAtIndexTests.txt", index-3, dtab->getSize());
    } else if(index < 5) {
        preOperationFile(dtab, "DTabAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, 0, index+3);
        dtab->addAtIndex(value, index);
        afterOperationFile(dtab, "DTabAddAtIndexTests.txt", 0, index+4);
    } else {
        preOperationFile(dtab, "DTabAddAtIndexTests.txt", "dodawania w okreslonym miejscu", value, index, index-3, index+3);
        dtab->addAtIndex(value, index);
        afterOperationFile(dtab, "DTabAddAtIndexTests.txt", index-3, index+4);
    }
}

void StructTester::testAddAtEndDTab(int value) {
    if(dtab->getSize() <= 10) {
        preOperationFile(dtab, "DTabAddAtEndTests.txt", "dodawania na koncu", value, NULL, 0, dtab->getSize());
        dtab->addAtEnd(value);
        afterOperationFile(dtab, "DTabAddAtEndTests.txt", 0, dtab->getSize());
    } else {
        preOperationFile(dtab, "DTabAddAtEndTests.txt", "dodawania na koncu", value, NULL, dtab->getSize() -6, dtab->getSize());
        dtab->addAtEnd(value);
        afterOperationFile(dtab, "DTabAddAtEndTests.txt", dtab->getSize() -6, dtab->getSize());
    }
}

void StructTester::testDeleteFirstAll() {
    std::cout << "\nLISTA:\n";
    if(list->getSize() <= 10) {
        preOperationFile(list, "listDeleteFTests.txt", "usuwania z poczatku", 0, 0, 0, list->getSize());
        int value = list->deleteFirst(&list);
        afterOperationFile(list, "listDeleteFTests.txt", 0, list->getSize());
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    } else {
        preOperationFile(list, "listDeleteFTests.txt", "usuwania z poczatku", 0, 0, 0, 5);
        int value = list->deleteFirst(&list);
        afterOperationFile(list, "listDeleteFTests.txt", 0, 5);
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    }

    std::cout << "\nKOPIEC:\n";
    if(heap->getSize() <= 10) {
        preOperationFile(heap,"heapDeleteFTests.txt", "usuwania z poczatku", 0, 0, 0, heap->getSize());
        int value = heap->deleteFirst();
        afterOperationFile(heap, "heapDeleteFTests.txt", 0, heap->getSize());
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    } else {
        preOperationFile(heap,"heapDeleteFTests.txt", "usuwania z poczatku", 0, 0, 0, 5);
        int value = heap->deleteFirst();
        afterOperationFile(heap, "heapDeleteFTests.txt", 0, 5);
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    }

    std::cout << "\nTABLICA DYNAMICZNA:\n";
    if(dtab->getSize() <= 10) {
        preOperationFile(dtab, "DTabDeleteFTests.txt", "usuwania z poczatku", 0, 0, 0, dtab->getSize());
        int value = dtab->deleteFirst();
        afterOperationFile(dtab, "DTabDeleteFTests.txt", 0, dtab->getSize());
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    } else {
        preOperationFile(dtab, "DTabDeleteFTests.txt", "usuwania z poczatku", 0, 0, 0, 5);
        int value = dtab->deleteFirst();
        afterOperationFile(dtab, "DTabDeleteFTests.txt", 0, 5);
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    }
}

void StructTester::testDeleteFirstList() {
    if(list->getSize() <= 10) {
        preOperationFile(list, "listDeleteFTests.txt", "usuwania z poczatku", 0, 0, 0, list->getSize());
        int value = list->deleteFirst(&list);
        afterOperationFile(list, "listDeleteFTests.txt", 0, list->getSize());
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    } else {
        preOperationFile(list, "listDeleteFTests.txt", "usuwania z poczatku", 0, 0, 0, 5);
        int value = list->deleteFirst(&list);
        afterOperationFile(list, "listDeleteFTests.txt", 0, 5);
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    }
}

void StructTester::testDeleteFirstHeap() {
    if(heap->getSize() <= 10) {
        preOperationFile(heap,"heapDeleteFTests.txt", "usuwania z poczatku", 0, 0, 0, heap->getSize());
        int value = heap->deleteFirst();
        afterOperationFile(heap, "heapDeleteFTests.txt", 0, heap->getSize());
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    } else {
        preOperationFile(heap,"heapDeleteFTests.txt", "usuwania z poczatku", 0, 0, 0, 5);
        int value = heap->deleteFirst();
        afterOperationFile(heap, "heapDeleteFTests.txt", 0, 5);
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    }
}

void StructTester::testDeleteFirstDTab() {
    if(dtab->getSize() <= 10) {
        preOperationFile(dtab, "DTabDeleteFTests.txt", "usuwania z poczatku", 0, 0, 0, dtab->getSize());
        int value = dtab->deleteFirst();
        afterOperationFile(dtab, "DTabDeleteFTests.txt", 0, dtab->getSize());
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    } else {
        preOperationFile(dtab, "DTabDeleteFTests.txt", "usuwania z poczatku", 0, 0, 0, 5);
        int value = dtab->deleteFirst();
        afterOperationFile(dtab, "DTabDeleteFTests.txt", 0, 5);
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    }
}

void StructTester::testDeleteLastAll() {
    std::cout << "\nLISTA:\n";
    if(list->getSize() <= 10) {
        preOperationFile(list, "listDeleteLTests.txt", "usuwania z konca", 0, 0, 0, list->getSize());
        int value = list->deleteLast();
        afterOperationFile(list, "listDeleteLTests.txt", 0, list->getSize());
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    } else {
        preOperationFile(list, "listDeleteLTests.txt", "usuwania z konca", 0, 0, 0, 5);
        int value = list->deleteLast();
        afterOperationFile(list, "listDeleteLTests.txt", 0, 5);
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    }

    std::cout << "\nTABLICA DYNAMICZNA:\n";
    if(dtab->getSize() <= 10) {
        preOperationFile(dtab, "DTabDeleteLTests.txt", "usuwania z konca", 0, 0, 0, dtab->getSize());
        int value = dtab->deleteLast();
        afterOperationFile(dtab, "DTabDeleteLTests.txt", 0, dtab->getSize());
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    } else {
        preOperationFile(dtab, "DTabDeleteLTests.txt", "usuwania z konca", 0, 0, 0, 5);
        int value = dtab->deleteLast();
        afterOperationFile(dtab, "DTabDeleteLTests.txt", 0, 5);
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    }
}

void StructTester::testDeleteLastList() {
    if(list->getSize() <= 10) {
        preOperationFile(list, "listDeleteLTests.txt", "usuwania z konca", 0, 0, 0, list->getSize());
        int value = list->deleteLast();
        afterOperationFile(list, "listDeleteLTests.txt", 0, list->getSize());
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    } else {
        preOperationFile(list, "listDeleteLTests.txt", "usuwania z konca", 0, 0, 0, 5);
        int value = list->deleteLast();
        afterOperationFile(list, "listDeleteLTests.txt", 0, 5);
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    }
}

void StructTester::testDeleteLastDTab() {
    if(dtab->getSize() <= 10) {
        preOperationFile(dtab, "DTabDeleteLTests.txt", "usuwania z konca", 0, 0, 0, dtab->getSize());
        int value = dtab->deleteLast();
        afterOperationFile(dtab, "DTabDeleteLTests.txt", 0, dtab->getSize());
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    } else {
        preOperationFile(dtab, "DTabDeleteLTests.txt", "usuwania z konca", 0, 0, 0, 5);
        int value = dtab->deleteLast();
        afterOperationFile(dtab, "DTabDeleteLTests.txt", 0, 5);
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    }
}

void StructTester::testDeleteAtIndexAll(unsigned int index) {
    std::cout << "\nLISTA:\n";
    if(list->getSize() <= 10) {
        preOperationFile(list, "listDeleteAITests.txt", "usuwania z podanego miejsca", 0, 0, 0, list->getSize());
        int value = list->deleteAtIndex(index, &list);
        afterOperationFile(list, "listDeleteAITests.txt", 0, list->getSize());
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    } else {
        preOperationFile(list, "listDeleteAITests.txt", "usuwania z podanego miejsca", 0, 0, 0, 5);
        int value = list->deleteAtIndex(index, &list);
        afterOperationFile(list, "listDeleteAITests.txt", 0, 5);
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    }

    std::cout << "\nTABLICA DYNAMICZNA:\n";
    if(dtab->getSize() <= 10) {
        preOperationFile(dtab, "DTabDeleteAITests.txt", "usuwania z podanego miejsca", 0, 0, 0, dtab->getSize());
        int value = dtab->deleteLast();
        afterOperationFile(dtab, "DTabDeleteAITests.txt", 0, dtab->getSize());
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    } else {
        preOperationFile(dtab, "DTabDeleteAITests.txt", "usuwania z podanego miejsca", 0, 0, 0, 5);
        int value = dtab->deleteLast();
        afterOperationFile(dtab, "DTabDeleteAITests.txt", 0, 5);
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    }
}

void StructTester::testDeleteAtIndexList(unsigned int index) {
    if(list->getSize() <= 10) {
        preOperationFile(list, "listDeleteAITests.txt", "usuwania z podanego miejsca", 0, 0, 0, list->getSize());
        int value = list->deleteAtIndex(index, &list);
        afterOperationFile(list, "listDeleteAITests.txt", 0, list->getSize());
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    } else {
        preOperationFile(list, "listDeleteAITests.txt", "usuwania z podanego miejsca", 0, 0, 0, 5);
        int value = list->deleteAtIndex(index, &list);
        afterOperationFile(list, "listDeleteAITests.txt", 0, 5);
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    }
}

void StructTester::testDeleteAtIndexDTab(unsigned int index) {
    if(dtab->getSize() <= 10) {
        preOperationFile(dtab, "DTabDeleteAITests.txt", "usuwania z podanego miejsca", 0, 0, 0, dtab->getSize());
        int value = dtab->deleteLast();
        afterOperationFile(dtab, "DTabDeleteAITests.txt", 0, dtab->getSize());
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    } else {
        preOperationFile(dtab, "DTabDeleteAITests.txt", "usuwania z podanego miejsca", 0, 0, 0, 5);
        int value = dtab->deleteLast();
        afterOperationFile(dtab, "DTabDeleteAITests.txt", 0, 5);
        std::cout << "Usunieta wartosc: " << value << "\n####\n\n";
    }
}

/**initialize structures with values from file*/
void StructTester::fillStructuresFromFile(std::string filePath) {
    clearStructures();
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

void StructTester::testFindValueAll(int value) {
    preFindFile("listFindTests.txt", value);
    int index = list->findValue(value);
    afterFindFile("listFindTests.txt", index);

    preFindFile("heapFindTests.txt", value);
    index = heap->findValue(value);
    afterFindFile("heapFindTests.txt", index);

    preFindFile("DTabFindTests.txt", value);
    index = dtab->findValue(value);
    afterFindFile("DTabFindTests.txt", index);
}

void StructTester::testFindValueList(int value) {
    preFindFile("listFindTests.txt", value);
    int index = list->findValue(value);
    afterFindFile("listFindTests.txt", index);
}

void StructTester::testFindValueHeap(int value) {
    preFindFile("heapFindTests.txt", value);
    int index = heap->findValue(value);
    afterFindFile("heapFindTests.txt", index);
}

void StructTester::testFindValueDTab(int value) {
    preFindFile("DTabFindTests.txt", value);
    int index = dtab->findValue(value);
    afterFindFile("DTabFindTests.txt", index);
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
    rbtree->print();
}

void StructTester::setStructures(Structure *li, Structure *h, Structure *dt, Structure *rbt) {
    delete(list);
    list = (List*) li;
    delete(heap);
    heap = (Heap*) h;
    delete(dtab);
    dtab = (DynTab*) dt;
    rbtree->DFSRelease(rbtree);
    rbtree = (RBTree*) rbt;
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
        flist << "Testowanie " << where << " struktury.\nStan struktury:\n\n";
        std::cout << "Testowanie " << where << " struktury.\nStan struktury:\n\n";
        for(unsigned int i = begin; i < end; i++) {
            flist << st->get(i) << " ";
            std::cout << st->get(i) << " ";
        }
        flist << "\n\n";
        flist << "Wartosc: " << value << "  index: " << index << "\n\nStan struktury po operacji:\n\n";
        std::cout << "\n\n";
        std::cout << "Wartosc: " << value << "  index: " << index << "\n\nStan struktury po operacji:\n\n";
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

void StructTester::preFindFile(std::string filename, int value) {
    std::ofstream file;
    file.open(filename, std::ios::out | std::ios::app);
    if(file.is_open()) {
        file << "Testowanie szukania wartosci w strukturze.\n";
        std::cout << "Testowanie szukania wartosci w strukturze.\n";
        file << "Szukana wartosc: " << value << "\n\n";
        std::cout << "Szukana wartosc: " << value << "\n\n";
        file << "Indeks szukanej wartoœci: ";
        std::cout << "Indeks szukanej wartoœci: ";
        file.close();
    } else {
        std::cout << "Blad podczas otwierania pliku!" << std::endl;
    }
}

void StructTester::afterFindFile(std::string filename, int index) {
    std::ofstream file;
    file.open(filename, std::ios::out | std::ios::app);
    if(file.is_open()) {
        file << index << "\n\n\n";
        std::cout << index << "\n\nPlik z ta wiadomoscia zostal utworzony w domyslnym katalogu.\n";
        file.close();
    } else {
        std::cout << "Blad podczas otwierania pliku!" << std::endl;
    }
}

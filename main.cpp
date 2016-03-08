#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>

#include "List.h"
#include "DynTab.h"
#include "Heap.h"

using namespace std;

void testujListe();
void testujTablice();

int main()
{
    testujListe();

    testujTablice();

    Heap *heap = new Heap(0);
    for(int i = 0; i < 15; i++) {
        heap->push(i);
    }

    cout << endl << endl;

    heap->printHeap();

    cout << endl << endl;

    for(unsigned int i = 0; i < 5; i++) {
        cout << heap->pop() << " ";
    }

}

void testujTablice() {

    cout << "\n\n\n\nTworze dynamiczna tablice..." << endl;
    DynTab *dt = new DynTab();
    DynTab *dt1 = new DynTab();
    DynTab *dt2 = new DynTab();

    cout << "Dodawianie do tablicy za pomoca adAtBegin.\nStan tablicy to:\t\t\t10 9 8 7 6 5 4 3 2 1";
    for(int i = 0; i < 10; i++) {
        dt->addAtBegin(i+1);
        dt1->addAtBegin(i+1);
        dt2->addAtBegin(i+1);
    }

    cout << "\n\nUsuwanie za pomoca deleteFirst\tzakladane wyjscie: 10 9 8 7 6 5 4 3 2 1\nUsuniete elementy:\t\t\t";

    for(int i = 0; i < 10; i++) {
        cout << dt->deleteFirst() << " ";
    }

    cout << "\n\nUsuwanie za pomoca deleteLast\tZakladane wyjscie: 1 2 3 4 5 6 7 8 9 10\nUsuniete elementy:\t\t\t\t\t";

    for(int i = 0; i < 10; i++) {
        cout << dt1->deleteLast() << " ";
    }

    cout << "\n\nDodawanie za pomoca addAtIndex\tZakladany stan: 10 9 8 7 0 6 5 4 0 3 2 1 0\nStan rzeczywisty:\t\t\t\t";

    dt2->addAtIndex(0, 4);
    dt2->addAtIndex(0, 8);
    dt2->addAtIndex(0, 12);

    for(unsigned int i = 0; i < dt2->getSize(); i++) {
        cout << dt2->getIndex(i) << " ";
    }
}

void testujListe() {
    cout << "Tworze liste..." << endl;
    List *head = new List(0);

    cout << "\n\nDodawanie metoda push\n" << endl;

    cout << "zakladany stan: 0";
    cout << "\t\t\tStan listy: ";
    head->printList();

    head = head->push(-1);

    cout << endl << "zakladany stan: -1 0";
    cout << "\t\t\tStan listy: ";
    head->printList();

    head = head->push(-2);

    cout << endl << "Zakladany stan: -2 -1 0";
    cout << "\t\t\tStan listy: ";
    head->printList();

    head->addToEnd(1);

    cout << "\n\n\n\nDodawanie metoda addToEnd\n" << endl;

    cout << endl << "Zakladany stan: -2 -1 0 1";
    cout << "\t\tStan listy: ";
    head->printList();

    head->addToEnd(2);

    cout << endl << "Zakladany stan: -2 -1 0 1 2";
    cout << "\t\tStan listy: ";
    head->printList();

    head = head->addAtIndex(5, 0);

    cout << "\n\n\n\nDodawanie metoda addAtIndex\n" << endl;

    cout << endl << "Zakladany stan: 5 -2 -1 0 1 2";
    cout << "\t\tStan listy: ";
    head->printList();

    head = head->addAtIndex(5, 3);

    cout << endl << "Zakladany stan: 5 -2 -1 5 0 1 2";
    cout << "\t\tStan listy: ";
    head->printList();

    head = head->addAtIndex(5, 7);

    cout << endl << "Zakladany stan: 5 -2 -1 5 0 1 2 5";
    cout << "\tStan listy: ";
    head->printList();

    cout << "\n\n\n\nUsuwanie metoda pop\n" << endl;

    cout << endl << "Zakladany stan: -2 -1 5 0 1 2 5/ return: 5";
    int a = head->pop(&head);
    cout << "\tStan listy: ";
    head->printList();
    cout << "/ return: " << a;

    cout << endl << "Zakladany stan: -1 5 0 1 2 5/ return: -2 ";
    a = head->pop(&head);
    cout << "\tStan listy: ";
    head->printList();
    cout << "/ return: " << a;

    cout << endl << "Zakladany stan: 5 0 1 2 5/ return: -1";
    a = head->pop(&head);
    cout << "\t\tStan listy: ";
    head->printList();
    cout << "/ return: " << a;

    cout << endl << "Zakladany stan: 0 1 2 5/ return: 5";
    a = head->pop(&head);
    cout << "\t\tStan listy: ";
    head->printList();
    cout << "/ return: " << a;

    cout << "\n\n\n\nUsuwanie metoda deleteFromEnd\n" << endl;

    cout << endl << "Zakladany stan: 0 1 2/ return: 5";
    a = head->deleteFromEnd();
    cout << "\tStan listy: ";
    head->printList();
    cout << "/ return: " << a;

    cout << endl << "Zakladany stan: 0 1/ return: 2";
    a = head->deleteFromEnd();
    cout << "\t\tStan listy: ";
    head->printList();
    cout << "/ return: " << a;

    cout << endl << "Zakladany stan: 0/ return: 1";
    a = head->deleteFromEnd();
    cout << "\t\tStan listy: ";
    head->printList();
    cout << "/ return: " << a << endl;
}

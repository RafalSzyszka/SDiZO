#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
#include <chrono>
#include <windows.h>

#include "List.h"
#include "DynTab.h"
#include "Heap.h"
#include "Structure.h"
#include "StructTester.h"

#include "RBTree.h"

using namespace std;

void stworzplik(int);

int main()
{
    char w;
    bool a,b,c,d,e,f,g;
    a=b=c=d=e=f=g=true;
    StructTester *st = new StructTester();

    //stworzplik(5);

    while (a) {
        b=c=d=e=f=g=true;
        cout << "Witaj! Program ten pozwala na testowanie roznych struktur danych.\nZaleca sie testowanie malych struktur, duze struktury moga sie okazac zbyt trudne do analizowania\n";
        cout << "\nWybierz opcje:\n\t[1]Testuj liste.\n\t[2]Testuj tablice dynamiczna.\n\t[3]Testuj kopiec.\n\t[4]Testuj drzewo RB.\n\t[5]Testuj wszystkie.\n\t[6]Opusc program.\n\n";
        cout << ">>: ";
        cin >> w;
        system("cls");
        switch(w) {
        case '1' : {
            while(b) {
                cout << "\nTESTUJ LISTE!" << endl;
                cout << "\nWybierz opcje:\n\t[1]Wczytaj wartosci z pliku\n\t[2]Dodaj na poczatek\n\t[3]Dodaj na ...\n\t[4]Dodaj na koniec\n\t[5]Szukaj wartosci\n\t[6]Usun z poczatku\n\t[7]Usun z ...\n\t[8]Usun z konca\n\t[9]Pokaz liste\n\t[a]Powrot do opcji\n\n";
                cin >> w;
                system("cls");
                switch(w) {
                case '1' : {
                    string file;
                    cout << "Podaj nazwe pliku: ";
                    cin.ignore();
                    getline(cin, file);
                    st->fillStructuresFromFile(file);
                    st->printList();
                    break;
                } case '2' : {
                    int value;
                    cout << "Podaj wartosc: ";
                    cin.ignore();
                    cin >> value;
                    st->testAddList(value);
                    break;
                } case '3' : {
                    int value, index;
                    cout << "Podaj wartosc: ";
                    cin.ignore();
                    cin >> value;
                    cin.ignore();
                    cout << "Podaj index: ";
                    cin >> index;
                    st->testAddAtIndexList(value, index);
                    break;
                } case '4' : {
                    int value;
                    cout << "Podaj wartosc: ";
                    cin.ignore();
                    cin >> value;
                    st->testAddAtEndList(value);
                    break;
                } case '5' : {
                    int value;
                    cout << "Podaj wartosc: ";
                    cin.ignore();
                    cin >> value;
                    st->testFindValueList(value);
                    break;
                } case '6' : {
                    st->testDeleteFirstList();
                    break;
                } case '7' : {
                    int value;
                    cout << "Podaj index: ";
                    cin.ignore();
                    cin >> value;
                    st->testDeleteAtIndexList(value);
                    break;
                } case '8' : {
                    st->testDeleteLastList();
                    break;
                } case '9' : {
                    st->printList();
                    break;
                } case 'a' : {
                    b = false;
                    break;
                }
                }
            } //while testuj liste
            break;
        } // case 1
        case '2' : {
            while(c) {
                cout << "\nTESTUJ TABLICE DYNAMICZNA!" << endl;
                cout << "\nWybierz opcje:\n\t[1]Wczytaj wartosci z pliku\n\t[2]Dodaj na poczatek\n\t[3]Dodaj na ...\n\t[4]Dodaj na koniec\n\t[5]Szukaj wartosci\n\t[6]Usun z poczatku\n\t[7]Usun z ...\n\t[8]Usun z konca\n\t[9]Pokaz tablice\n\t[a]Powrot do opcji\n\n";
                cin >> w;
                system("cls");
                switch(w) {
                case '1' : {
                    string file;
                    cout << "Podaj nazwe pliku: ";
                    cin.ignore();
                    getline(cin, file);
                    st->fillStructuresFromFile(file);
                    st->printDTab();
                    break;
                } case '2' : {
                    int value;
                    cout << "Podaj wartosc: ";
                    cin.ignore();
                    cin >> value;
                    st->testAddDTab(value);
                    break;
                } case '3' : {
                    int value, index;
                    cout << "Podaj wartosc: ";
                    cin.ignore();
                    cin >> value;
                    cin.ignore();
                    cout << "Podaj index: ";
                    cin >> index;
                    st->testAddAtIndexDTab(value, index);
                    break;
                } case '4' : {
                    int value;
                    cout << "Podaj wartosc: ";
                    cin.ignore();
                    cin >> value;
                    st->testAddAtEndDTab(value);
                    break;
                } case '5' : {
                    int value;
                    cout << "Podaj wartosc: ";
                    cin.ignore();
                    cin >> value;
                    st->testFindValueDTab(value);
                    break;
                } case '6' : {
                    st->testDeleteFirstDTab();
                    break;
                } case '7' : {
                    int value;
                    cout << "Podaj index: ";
                    cin.ignore();
                    cin >> value;
                    st->testDeleteAtIndexDTab(value);
                    break;
                } case '8' : {
                    st->testDeleteLastDTab();
                    break;
                } case '9' : {
                    st->printDTab();
                    break;
                } case 'a' : {
                    c = false;
                    break;
                }
                }
            }//while testuj tablice
            break;
        }//case 2
        case '3' : {
            while(d) {
                cout << "\nTESTUJ KOPIEC!" << endl;
                cout << "\nWybierz opcje:\n\t[1]Wczytaj wartosci z pliku\n\t[2]Dodaj\n\t[3]Szukaj wartosci\n\t[4]Usun\n\t[5]Pokaz kopiec\n\t[6]Powrot do opcji\n\n";
                cin >> w;
                system("cls");
                switch(w) {
                case '1' : {
                    string file;
                    cout << "Podaj nazwe pliku: ";
                    cin.ignore();
                    getline(cin, file);
                    st->fillStructuresFromFile(file);
                    st->printHeap();
                    break;
                } case '2' : {
                    int value;
                    cout << "Podaj wartosc: ";
                    cin.ignore();
                    cin >> value;
                    st->testAddHeap(value);
                    break;
                } case '3' : {
                    int value;
                    cout << "Podaj wartosc: ";
                    cin.ignore();
                    cin >> value;
                    st->testFindValueHeap(value);
                    break;
                } case '4' : {
                    st->testDeleteFirstHeap();
                    break;
                }  case '5' : {
                    st->printHeap();
                    break;
                } case '6' : {
                    d = false;
                    break;
                }
                }
            }//while testuj kopiec
            break;
        }//case 3
        case '4' : {
            while(e) {
                cout << "\nTESTUJ DRZEWO RB!" << endl;
                cout << "\nWybierz opcje:\n\t[1]Wczytaj wartosci z pliku\n\t[2]Dodaj\n\t[3]Szukaj wartosci\n\t[4]Usun\n\t[5]Pokaz drzewo\n\t[6]Powrot do opcji\n\n";
                cin >> w;
                system("cls");
                switch(w) {
                case '1' : {
                    string file;
                    cout << "Podaj nazwe pliku: ";
                    cin.ignore();
                    getline(cin, file);
                    st->fillStructuresFromFile(file);
                    st->printRbTr();
                    break;
                } case '2' : {
                    int value;
                    cout << "Podaj wartosc: ";
                    cin.ignore();
                    cin >> value;
                    st->testAddRBTree(value);
                    break;
                } case '3' : {
                    int value;
                    cout << "Podaj wartosc: ";
                    cin.ignore();
                    cin >> value;
                    st->testFindValueRBTr(value);
                    break;
                } case '4' : {
                    st->testDeleteFirstRBTr();
                    break;
                }  case '5' : {
                    st->printRbTr();
                    break;
                } case '6' : {
                    e = false;
                    break;
                }
                }
            }//while testuj rbtree
            break;
        }//case 4
        case '5' : {
            while(f) {
                cout << "\nTESTUJ WSZYSTKIE!" << endl;
                cout << "\nWybierz opcje:\n\t[1]Wczytaj wartosci z pliku\n\t[2]Dodaj na poczatek\n\t[3]Dodaj na ...\n\t[4]Dodaj na koniec\n\t[5]Szukaj wartosci\n\t[6]Usun z poczatku\n\t[7]Usun z ...\n\t[8]Usun z konca\n\t[9]Pokaz tablice\n\t[a]Powrot do opcji\n\n";
                cin >> w;
                system("cls");
                switch(w) {
                case '1' : {
                    string file;
                    cout << "Podaj nazwe pliku: ";
                    cin.ignore();
                    getline(cin, file);
                    st->fillStructuresFromFile(file);
                    cout << "Tablica:\t";
                    st->printDTab();
                    cout << "\nKopiec:\t";
                    st->printHeap();
                    cout << "\nLista:\t";
                    st->printList();
                    cout << "\nDrzewo:\n";
                    st->printRbTr();
                    break;
                } case '2' : {
                    int value;
                    cout << "Podaj wartosc: ";
                    cin.ignore();
                    cin >> value;
                    st->testAddAll(value);
                    break;
                } case '3' : {
                    int value, index;
                    cout << "Podaj wartosc: ";
                    cin.ignore();
                    cin >> value;
                    cin.ignore();
                    cout << "Podaj index: ";
                    cin >> index;
                    st->testAddAtIndexAll(value, index);
                    break;
                } case '4' : {
                    int value;
                    cout << "Podaj wartosc: ";
                    cin.ignore();
                    cin >> value;
                    st->testAddAtEndAll(value);
                    break;
                } case '5' : {
                    int value;
                    cout << "Podaj wartosc: ";
                    cin.ignore();
                    cin >> value;
                    st->testFindValueAll(value);
                    break;
                } case '6' : {
                    st->testDeleteFirstAll();
                    break;
                } case '7' : {
                    int value;
                    cout << "Podaj index: ";
                    cin.ignore();
                    cin >> value;
                    st->testDeleteAtIndexAll(value);
                    break;
                } case '8' : {
                    st->testDeleteLastAll();
                    break;
                } case '9' : {
                    cout << "Tablica:\t";
                    st->printDTab();
                    cout << "\nKopiec:\t";
                    st->printHeap();
                    cout << "\nLista:\t";
                    st->printList();
                    cout << "\nDrzewo:\n";
                    st->printRbTr();
                    break;
                } case 'a' : {
                    f = false;
                    break;
                }
                }
            }//while testuj tablice
            break;
        }//case 5
        case '6' : {
            a=false;
            break;
        }
        }

    }

}


void stworzplik(int ile) {
    srand(time(NULL));
    ofstream data("values.txt");
    if(data.is_open()) {
        for(int i = 0; i < ile; i++) {
            if(rand() % 5 + 1 == 2) {
                data << (-1)*(rand() % 50000 + 1) << endl;
            } else {
                data << rand() % 50000 + 1 << endl;
            }
        }
    }
    data.close();
}

/**
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
*/

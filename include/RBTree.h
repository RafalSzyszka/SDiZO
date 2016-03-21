#ifndef RBTREE_H
#define RBTREE_H

#include "RBTNode.h"
#include <string>
#include <fstream>

using namespace std;
class RBTree
{
    private:
        RBTNode S;             // W�ze� stra�nika
        RBTNode * root;        // Korze� drzewa czerwono-czarnego
        string cr,cl,cp;       // �a�cuchy do znak�w ramek

        void printRBT(string sp, string sn, RBTNode * p); // Wypisuje drzewo

    public:
        RBTree();             // Konstruktor klasy
        ~RBTree();            // Destruktor klasy
        void DFSRelease(RBTNode * p); // Usuwa rekurencyjnie drzewo
        void print();          // Wypisuje drzewo
        int findRBT(int k); // Wyszukuje w�ze� o kluczu k
        RBTNode * minRBT(RBTNode * p); // Wyszukuje najmniejszy w�ze� w p
        RBTNode * succRBT(RBTNode * p);// Wyszukuje nast�pnik p
        void rot_L(RBTNode * A); // Rotacja w lewo wzgl�dem A
        void rot_R(RBTNode * A); // Rotacja w prawo wzgl�dem A
        void insertRBT(int k);   // Wstawia w�ze� o kluczu k
        void removeRBT(RBTNode * X); // Usuwa w�ze� X
        RBTree* initFromFile(string);
        RBTNode* getRoot();
        void print(ofstream&);
        void printRBTtoFile(string, string, RBTNode*, ofstream&);
};


#endif // RBTREE_H

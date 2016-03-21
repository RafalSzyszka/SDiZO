#ifndef RBTREE_H
#define RBTREE_H

#include "RBTNode.h"
#include <string>
#include <fstream>

using namespace std;
class RBTree
{
    private:
        RBTNode S;             // Wêze³ stra¿nika
        RBTNode * root;        // Korzeñ drzewa czerwono-czarnego
        string cr,cl,cp;       // £añcuchy do znaków ramek

        void printRBT(string sp, string sn, RBTNode * p); // Wypisuje drzewo

    public:
        RBTree();             // Konstruktor klasy
        ~RBTree();            // Destruktor klasy
        void DFSRelease(RBTNode * p); // Usuwa rekurencyjnie drzewo
        void print();          // Wypisuje drzewo
        int findRBT(int k); // Wyszukuje wêze³ o kluczu k
        RBTNode * minRBT(RBTNode * p); // Wyszukuje najmniejszy wêze³ w p
        RBTNode * succRBT(RBTNode * p);// Wyszukuje nastêpnik p
        void rot_L(RBTNode * A); // Rotacja w lewo wzglêdem A
        void rot_R(RBTNode * A); // Rotacja w prawo wzglêdem A
        void insertRBT(int k);   // Wstawia wêze³ o kluczu k
        void removeRBT(RBTNode * X); // Usuwa wêze³ X
        RBTree* initFromFile(string);
        RBTNode* getRoot();
        void print(ofstream&);
        void printRBTtoFile(string, string, RBTNode*, ofstream&);
};


#endif // RBTREE_H

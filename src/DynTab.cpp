#include "DynTab.h"

#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

/**Creating empty table*/
DynTab::DynTab() : size(0), tab() {}

/**Creating array with specific size
*allocating memory for n integers
*filling table with zeros*/
DynTab::DynTab(unsigned int s) : size(s), tab((int *)calloc(s,sizeof(int))) {}

/**adds value at specific index*/
DynTab* DynTab::addAtIndex(int value, unsigned int index) {
    if(index > this->size) {
        throw std::string("Index out of bounds!");  /**checking index*/
    } else {
        if(index == 0) {
            return this->add(value); /**adding at beginning*/
        } else if(index == this->size) {
            return this->addAtEnd(value);   /**adding at end*/
        } else {
            DynTab *dt = this;  /**pointer used to do operations on*/
            int *newTab = (int*)malloc((dt->size+1)*sizeof(int));   /**reserving new memory*/
            for(unsigned int i = 0; i < dt->size+1; i++) {   /**copying old data*/
                if(i < index) { /**first half of array*/
                    newTab[i] = dt->tab[i];
                } else if(i > index) {  /**second half of array*/
                    newTab[i] = dt->tab[i-1];
                } else {
                    newTab[i] = value;  /**adding value at specific index*/
                }
            }
            free(dt->tab); /**freeing old array*/
            dt->tab = newTab;   /**setting new array*/
            dt->size++;     /**increasing array size*/
            return dt;
        }
    }
}
/**adds value at array's beginning*/
DynTab* DynTab::add(int value) {
    DynTab *dt = this;  /**pointer used to do operations*/
    int *newTab = (int*)malloc((dt->size+1)*sizeof(int));   /**allocates new memory block*/
    newTab[0] = value;  /**adding value at the very beginning*/
    for(unsigned int i = 1; i < dt->size+1; i++) { /**Copying old data*/
        newTab[i] = dt->tab[i-1];
    }
    free(dt->tab);  /**deleting old data*/
    dt->tab = newTab;   /**setting new data*/
    dt->size++;     /**increasing array size*/
    return dt;
}

/**Adds value at the end of array, allocates more memory*/
DynTab* DynTab::addAtEnd(int value) {
    DynTab *dt = this;  /**used to do operations*/
    void *tmp;
    /**trying to reallocate memory*/
    if( (tmp = realloc(dt->tab, (dt->size+1)*sizeof(int))) != NULL ) {
        dt->tab = (int*)tmp;    /**previous tab was already freed by realloc, setting copied and enlarged memory block*/
        dt->tab[dt->size] = value;  /**adding value at the end*/
        dt->size++; /**increasing size*/
        return dt;
    } else {    /**throw string if something went wrong*/
        throw std::string("Error occurred while reallocating memory!\nNo changes were done.");
    }
}

void DynTab::print() {
    for(unsigned int i = 0; i < this->size; i++) {
        std::cout << this->tab[i] << " ";
    }
}

/**return value at specific index, does not delete value*/
int DynTab::get(unsigned int index) {
    if(index >= this->size) {
        throw std::string("Index out of bounds!");
    } else {
        return tab[index];
    }
}

int DynTab::deleteAtIndex(unsigned int index, Structure** d) {
    if(index >= this->size){
        throw std::string("Index out of bounds!");
    }
    int value;
    int *tb = (int*)malloc((this->size - 1)*sizeof(int));
    for(unsigned int i = 0; i < index; i++) {
        tb[i] = this->tab[i];
    }
    for(unsigned int i = index+1; i < this->size; i++) {
        tb[i-1] = this->tab[i];
    }
    value = this->tab[index];
    free(this->tab);
    this->tab = tb;
    this->size--;
    return value;
}

/**Deletes and returns array's first value
*resizes table*/
int DynTab::deleteFirst(Structure** d) {
    DynTab *dt = this;  /**pointer used to do operations on object*/
    int value = dt->tab[0];     /**getting value to be returned*/
    int *newTab = (int*)malloc((dt->size-1)*sizeof(int));     /**allocating new memory block*/

    /**copying data from array without first value*/
    for(unsigned int i = 1; i < dt->size; i++) {
        newTab[i-1] = dt->tab[i];
    }
    dt->size--;
    free(dt->tab);  /**freeing memory after old array*/
    dt->tab = newTab;   /**setting new memory block to array*/
    return value;   /**returning value*/
}

/**deletes array's last value
*resizes table*/
int DynTab::deleteLast() {
    DynTab *dt = this;
    if(dt->size >= 1) { /**checking if table is empty*/
        int value = dt->tab[--dt->size];    /**getting last value and decreasing array's size*/
        void *newTab;

        if(dt->size == 0) { /**if it was last element than free memory and return value*/
            free(dt->tab);
            dt->tab = (int *)malloc(0*sizeof(int));
            return value;
        } else {        /**else, try to reallocate memory without last element*/
            if((newTab = realloc(dt->tab, dt->size*sizeof(int)))!= NULL) {
                dt->tab = (int*)newTab;
                return value;
            } else {    /**throws exception if something went wrong*/
                throw std::string("Error occurred while reallocating memory! No changes were done.");
            }
        }
    } else { /**if array is empty throws exception*/
        throw std::string("No elements to be deleted!");
    }
}

/**Searches for value in array*/
int DynTab::findValue(int value) {
    for(unsigned int i = 0; i < this->size; i++) {
        if(this->tab[i] == value) return i;
    }
    return -1;
}

DynTab* DynTab::initFromFile(std::string filename) {
    DynTab* dtab = new DynTab();
    std::ifstream file(filename);
    std::string line;
    if(file.is_open()) {
        while (getline(file, line)) {
            int value;
            std::istringstream iss(line);   //converting string to int
            iss >> value;
            dtab->addAtEnd(value);
        }
        return dtab;
    } else {
        std::cout << "Blad podczas otwierania pliku, struktura pozostaje pusta." << std::endl;
        return new DynTab();
    }
}

DynTab::~DynTab()
{
    free(tab);
}

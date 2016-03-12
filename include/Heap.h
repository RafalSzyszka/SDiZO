#ifndef HEAP_H
#define HEAP_H


class Heap
{
    public:
        Heap() : heap(nullptr), size(0) {}  //default constructor
        Heap(int);      //constructor with initial heap value

        void printHeap();

        void push(int); //adds value to heap
        int pop();      //removes and returns heap's root value

        virtual ~Heap();

    private:
        int *heap;
        unsigned int size;

        void heapFixUpDown(int *);   //fixes heap after pop
        void heapFixDownUp(int *, int);   //fixes heap after push
};

#endif // HEAP_H

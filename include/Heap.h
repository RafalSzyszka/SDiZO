#ifndef HEAP_H
#define HEAP_H


class Heap
{
<<<<<<< HEAD
public:
	Heap() : heap(nullptr), size(0) {}  //default constructor
	Heap(int);      //constructor with initial heap value

	void printHeap();	//prints heap

	void push(int); //adds value to heap
	int pop();      //removes and returns heap's root value
	unsigned int getSize() { return size; }		//returns heap size
	bool findValue(int);	//searchs for value

	virtual ~Heap();

private:
	int *heap;
	unsigned int size;

	void heapFixUpDown(int *);   //fixes heap after pop
	void heapFixDownUp(int *, int);   //fixes heap after push
};

#endif // HEAP_H
=======
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
>>>>>>> 265361da2db65bb3a7b1ebc207616ca923ed703b

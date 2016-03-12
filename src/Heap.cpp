<<<<<<< HEAD
#include "stdafx.h"
#include "Heap.h"
#include <stdlib.h>
#include <iostream>


/**constructor with initial value*/
Heap::Heap(int value) : heap((int*)malloc(sizeof(int))), size(1) {
	heap[0] = value;
}

/**Prints heap content*/
void Heap::printHeap() {
	for (unsigned int i = 0; i < this->size; i++) {
		std::cout << this->heap[i] << " ";
	}
}

/**adds value to heap, fixes it if neccessary*/
void Heap::push(int value) {
	int *newHeap;
	/**copying previous content*/
	if ((newHeap = (int*)realloc(this->heap, (this->size + 1)*sizeof(int))) != NULL) {
		newHeap[this->size] = value; //adding value to the end
		this->heap = newHeap;
		this->size++;
		heapFixDownUp(this->heap, this->size);	//fixing heap
	}
}

/**removing heap's node*/
int Heap::pop() {
	int popValue = this->heap[0];
	int *newHeap = (int*)malloc((this->size - 1)*sizeof(int)); //locating new memory

	newHeap[0] = this->heap[this->size - 1];	//setting last value of heap as new node
	for (unsigned int i = 1; i < this->size - 1; i++) {	//copying rest heap
		newHeap[i] = this->heap[i];
	}

	free(this->heap);	//deleting old heap
	this->heap = newHeap;	//setting new heap
	this->size--;	//resizing

	heapFixUpDown(this->heap);	//fixing heap

	return popValue;	//returning old node's value
}

/**Search for value in heap, returns true if value is in the heap, false if value does not appear in heap*/
bool Heap::findValue(int value) {
	for (int i = 0; i < this->size; i++) {
		if (this->heap[i] == value) {
			return true;
		}
	}
	return false;
}

/**fixing heap after adding value*/
void Heap::heapFixDownUp(int *heap, int size) {
	int parent = (size - 1) / 2;
	int child = size - 1;
	while (heap[parent] < heap[child] && child > 0) { //while parent's value is smaller than it's child
		int tmp = heap[parent];	//swaping values
		heap[parent] = heap[child];
		heap[child] = tmp;
		child = parent;	//child becomes parent
		parent = (child - 1) / 2;	//searching for new parent
	}
}

/**fixing heap after poping node*/
void Heap::heapFixUpDown(int *heap) {
	int node, left, right;
	node = 0;
	
	while ( (left=(2*node+1)) < this->getSize() ) { //while node has at least one child
		if ((right = left+1) < this->getSize()) {	//if node has both children
			if (heap[node] < heap[left] || heap[node] < heap[right]) {	//if node is smaller than one of its child
				if (heap[left] >= heap[right]) { //if left child is greater than right child
					int tmp = heap[node];	//swaping node with left child
					heap[node] = heap[left];	//left child is new node
					heap[left] = tmp;		//old node becomes new child
					node = left;
				}
				else {	//if right child is greater than node
					int tmp = heap[node];	//swaping node with right child
					heap[node] = heap[right];	//right child is new node
					heap[right] = tmp;		//old node becomes new child
					node = right;
				}
			}
			else {
				break;
			}
		}
		else {	//if node has only one child
			if (heap[left] > heap[node]) {	//if left child is greater than node
				int tmp = heap[node];	//swaping node with left child
				heap[node] = heap[left];	//left child is new node
				heap[left] = tmp;		//old node becomes new child
				node = left;
			}
			else {
				break;
			}
		}
	}
}


Heap::~Heap()
{
	free(heap);
}
=======
#include "Heap.h"

#include <stdlib.h>
#include <iostream>

/**constructor with initial value*/
Heap::Heap(int value) : heap((int*)malloc(sizeof(int))), size(1) {
    heap[0] = value;
}

void Heap::printHeap() {
    for(unsigned int i = 0; i < this->size; i++) {
        std::cout << this->heap[i] << " ";
    }
}

void Heap::push(int value) {
    int *newHeap;
    if( (newHeap = (int*)realloc(this->heap, (this->size+1)*sizeof(int))) != NULL) {
        newHeap[this->size] = value;
        this->heap = newHeap;
        this->size++;
        heapFixDownUp(this->heap, this->size);
    }
}

int Heap::pop() {
    int popValue = this->heap[0];
    int *newHeap = (int*)malloc((this->size-1)*sizeof(int));

    newHeap[0] = this->heap[this->size-1];
    for(unsigned int i = 1; i < this->size-1; i++) {
        newHeap[i] = this->heap[i];
    }

    free(this->heap);
    this->heap = newHeap;
    this->size--;

    heapFixUpDown(this->heap);

    return popValue;
}

void Heap::heapFixDownUp(int *heap, int size) {
    int parent = (size-1)/2;
    int child = size-1;
    while(heap[parent] < heap[child] && child > 0) {
        int tmp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = tmp;
        child = parent;
        parent = (child-1)/2;
    }
}

void Heap::heapFixUpDown(int *heap) {
    int left = 1; int right = 2; int node = 0;
    while(heap[node] < heap[left] && heap[node] < heap[right]) {
        if(heap[left] >= heap[right]) {
            int tmp = heap[node];
            heap[node] = heap[left];
            heap[left] = tmp;
            node = left;
            left = 2*node + 1;
            right = 2*node + 2;
        } else {
            int tmp = heap[node];
            heap[node] = heap[right];
            heap[right] = tmp;
            node = right;
            left = 2*node + 1;
            right = 2*node + 2;
        }
    }
}

Heap::~Heap()
{
    free(heap);
}
>>>>>>> 265361da2db65bb3a7b1ebc207616ca923ed703b

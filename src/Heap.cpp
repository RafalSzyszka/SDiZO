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

// SDiZO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Heap.h"

using namespace std;

int main()
{

	Heap *heap = new Heap();
	for (int i = 0; i < 15; i++) {
		heap->push(i);
		heap->push(i);
	}
	
	cout << endl << endl;

	heap->printHeap();

	cout << endl << endl;

	while (heap->getSize() > 0) {
		cout << heap->pop() << " ";
	}

	cout << "\n\n\nGet char: ";
	getchar();
    return 0;
}


/* ========================================================================= *
 * heapSort
 * Implementation of the heapSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include "Sort.h"


void swapHeap(int* a, int* b);
void buildMaxHeap(int* array, size_t length, size_t index);
void HeapSort(int* array , size_t length);

void sort(int* array, size_t length){
	HeapSort(array,length);
}

void HeapSort(int* array , size_t length){
	//Building the maxHeap
	for (int i=(length/2)-1; i>=0; i--){
		buildMaxHeap(array, length, i);
	}

	//Sorting
	for (int i=length-1; i>0; i--){
		swapHeap(&array[0],&array[i]);
		//build the maxHeap to get the highest element to the root again
		buildMaxHeap(array, i, 0);
	}
}

void swapHeap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void buildMaxHeap(int* array, size_t length, size_t index){
	size_t largest = index;
	size_t left = (2*index)+1;
	size_t right= (2*index)+2;

	if(left < length && array[left] > array[largest]){
		largest = left;
	}
	
	if(right < length && array[right] > array[largest]){
		largest = right;
	}
	if(largest != index){
		swapHeap(&array[index], &array[largest]);
		buildMaxHeap(array, length,largest);
	}
}



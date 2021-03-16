/* ========================================================================= *
 * quickSort
 * Implementation of the quickSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include "Sort.h"


//prototypes
void swapQuick(int* a, int* b);
size_t partition (int* array, size_t lowerIndex, size_t length);
void QuickSort(int* array, size_t lowerIndex, size_t length);


void sort(int* array, size_t length){
	QuickSort(array, 0, length);
}

void QuickSort(int* array, size_t lowerIndex, size_t length){
	if(lowerIndex < length){
		size_t pivot = partition(array, lowerIndex, length);
		QuickSort(array, lowerIndex, pivot);
		QuickSort(array, pivot+1, length);
	}
}

size_t partition (int* array, size_t lowerIndex, size_t length){
	size_t higherIndex = length-1;
	size_t pivot = array[higherIndex];
	size_t partitionIndex = lowerIndex;	
	for(size_t i = lowerIndex; i < higherIndex; i++){
		if(array[i] < (int)pivot){
			swapQuick(&array[i],&array[partitionIndex]);
			partitionIndex++;
		}
	}
	swapQuick(&array[partitionIndex],&array[higherIndex]);
	return (partitionIndex);
}
void swapQuick(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

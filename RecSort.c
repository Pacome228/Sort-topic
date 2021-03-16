/* ========================================================================= *
 * recSort
 * Implementation of the recSort algorithm.
 * ========================================================================= */

#include <stdio.h>
#include "Sort.h"

//prototypes
void swapRec(int* a, int* b);
size_t place (int* array, size_t lowerIndex, size_t length, size_t k);
void merge(int* array, size_t lowerIndex, size_t pivot, size_t higerIndex);
void RecSort(int* array ,size_t p, size_t length);

void sort (int* array, size_t length){
	RecSort(array,0,length-1);
}


void RecSort(int* array ,size_t p, size_t length){
	if(p < length){
		size_t pivot = place(array, p, length, length-1);
		RecSort(array, p, pivot);
		RecSort(array, pivot+1, length);
		merge(array, p, pivot, length);
	}
}

void swapRec(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

size_t place (int* array, size_t lowerIndex, size_t length, size_t k){
	size_t count=0;
	for(size_t i=lowerIndex; i < length; i++){
		if(array[i] < array[k]){
			count+=1;
		}
	}
	size_t l=count+lowerIndex;
	swapRec(&array[k], &array[count]);
	return l;
}

void merge(int* array, size_t lowerIndex, size_t pivot, size_t higerIndex){

	size_t lowerLength = pivot - lowerIndex + 1;
	size_t higerLength = higerIndex - pivot;

	size_t l1[lowerLength], l2[higerLength];

	for(size_t i = 0; i < lowerLength; i++){
		l1[i]=array[lowerIndex+i];
	}
	for(size_t j = 0; j < higerLength; j++){
		l2[j]=array[pivot+1+j];
	}

	size_t i=0, j=0, k=lowerIndex;

	while(i < lowerLength && j < higerLength){
		if(l1[i] <= l2[j]){
			array[k]=l1[i];
			i++;
		}
		else{
			array[k]=l2[j];
			j++;
		}
		k++;
	}

	while(i < lowerLength){
		array[k]=l1[i];
		i++;
		k++;
	}
	while(j < higerLength){
		array[k]=l2[j];
		j++;
		k++;
	}
}








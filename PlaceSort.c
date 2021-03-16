/* ========================================================================= *
 * placeSort
 * Implementation of the placeSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include "Sort.h"

void swapPlace(int* a, int* b);
size_t findNewPlace(int* array, size_t index, size_t length);
void PlaceSort(int* array ,size_t index , size_t k, size_t length);

void sort(int* array, size_t length){
	PlaceSort(array,0,0,length);
}


void PlaceSort(int* array ,size_t index , size_t k, size_t length){
	size_t initialIndex = index;
	if (initialIndex == length-1) return;
  	else{
	    do{
    		//find the ideal position of the given index
	      	size_t k = findNewPlace(array,initialIndex,length);
	      	if(initialIndex != k && array[initialIndex] != array[k]){
		      	//swap the position with the ideal position
		        swapPlace(&array[initialIndex], &array[k]);
		    }
		    //If it is palindrome swap with the next element
		    else if (initialIndex != k && array[initialIndex]==array[k] && k==(initialIndex+1)){
	          	swapPlace(&array[initialIndex], &array[k+1]);
	        }
		    
	      	else{
	        	initialIndex=initialIndex+1;
	        	break;
	        }
	    }while(initialIndex != k);
    	PlaceSort(array, initialIndex, k, length);
  	}
}

void swapPlace(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
size_t findNewPlace(int* array, size_t index, size_t length){
  size_t count=0;
  for(size_t j=0 ; j < length; j++){
    if(array[j] < array[index]){
      count++;
    }
  }
  return count;
}





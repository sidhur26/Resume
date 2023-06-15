#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void efficient(const int source[], int val[], int pos[], int size){
	int index_pos = 0;
	int index_val = 0;
	for(int i=0;i<size;i++){
		if (source[i] != 0){                  // checks for non-zero element
			pos[index_pos++] = i;             // puts position of non-zero element into the pos array
			val[index_val++] = source[i];     // puts value of non-zero element into the val array
		}
	}
}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){
	for(int j=0;j<m;j++){
		source[j] = 0;                    // makes source an array of zeros
	}
	for(int i=0;i<n;i++){
		source[pos[i]] = val[i];         // puts non-zero elements into the source array at their corresponding position
	}
}

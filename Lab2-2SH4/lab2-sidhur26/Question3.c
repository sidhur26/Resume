#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr []){
	int index =0;
	for(int i=0;i<N3;i++){
		for(int j=i;j>=0;j--){
			arr[index++] = mat[j][i-j];           // adds the upper half of the matrix into the array in diagonal order
		}
	}
	for(int i = 1; i<N3;i++){
		for(int j=N3-1;j>=i;j--){
			arr[index++] = mat[j][i + N3-1 - j];    // adds the bottom half of the matrix into the array in diagonal order
		}
	}
}

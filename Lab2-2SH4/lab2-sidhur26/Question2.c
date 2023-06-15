#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"


int is_diag_dom(int mat[][N2]){

    //this is the flag that is returned to tell whether the mat is diagonally
	int isDiag=0;
	
	//write your code below
	//Return 1 if the matrix is diagonally dominant and 0 otherwise
	for(int i=0;i<N2;i++){
		int sum =0;                            // initializes sum to equal zero
		for(int j=0;j<N2;j++){
			sum += abs(mat[i][j]);            // adds all of the elements for each row
		}
		sum -= abs(mat[i][i]);                // subtracts the diagonal element from the sum
		if(abs(mat[i][i]) > sum){             // checks if the diagonal element is greater than the sum
			isDiag = 1;
		}
		else{
			break;
		}
	}
	
	


    return isDiag;
}

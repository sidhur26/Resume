
#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

Matrix::Matrix(){
 rowsNum=3;
 colsNum=3;
 matrixData=NULL;
 matrixData = (int**)malloc(rowsNum*sizeof(int*));

    // Allocate rows for fake "2D array":
    for (int i = 0 ; i < rowsNum ; ++i )
    {
       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
    }

    for (int i = 0 ; i < rowsNum ; ++i )
    	for (int j = 0 ; j < colsNum ; ++j )
    		matrixData[i][j]=0;
}

Matrix::Matrix( int row, int col ){

	/*
	* constructs a row-by-col matrix with
	* all elements equal to 0; if row ≤ 0, the number of rows of the matrix is set to
	* 3; likewise, if col ≤ 0 the number of columns of the matrix is set to 3.
	*/
	if (row <= 0){
		rowsNum = 3;                 // sets number of rows to 3 if an invalid input is given
}
	else{
		rowsNum = row;               // sets number of rows to row if it is a valid input
	}
	if (col <= 0){
		colsNum =3;                  // sets number of columns to 3 if an invalid input is given
}
	else{
		colsNum = col;               // sets number of columns to col if it is a valid input
	}
	matrixData = NULL;
	matrixData = (int**)malloc((rowsNum)*sizeof(int*));
	for(int i = 0; i < rowsNum;++i){
		matrixData[i] = (int*)malloc((colsNum)*sizeof(int));
	}
	for(int i =0; i < rowsNum;i++){
		for(int j=0;j<colsNum;j++){
			matrixData[i][j] = 0;                    // initializes all elements to zero
		}
	}
}


Matrix::Matrix(int row, int col, int** table){

	/*
	* constructs a matrix out of the two dimensional array table, with the same number of rows, columns, and the same
	* element in each position as array table.
	*/
	rowsNum = row;                          // initializes rowsNum to number of rows in array table
	colsNum = col;                          // initializes colsNum to number of columns in array table
	matrixData = NULL;
	matrixData = (int**)malloc((rowsNum)*sizeof(int*));
	for(int i = 0; i < rowsNum;++i){
		matrixData[i] = (int*)malloc((colsNum)*sizeof(int));
	}
	for(int i = 0; i < rowsNum;i++){
		for(int j =0;j<colsNum;j++){
			matrixData[i][j] = *( *(table + i) + j);        // initializes elements to the same value as the elements in the table at that position
		}
	}
}

int Matrix::getElement(int i, int j){
	if(i<0 or i>=rowsNum or j<0 or j>=colsNum){            // checks if index is in range
		throw std::out_of_range( "Invalid indexes." );
		return -1;
	}
	else{
		return matrixData[i][j];              // if index is in range returns element at that index
	}


}

bool Matrix::setElement(int x, int i, int j){
	if(i<0 or i>=rowsNum or j<0 or j>=colsNum){       // checks if index is in range
		return false;
	}
	else{
		matrixData[i][j] = x;               // sets element to x if index is in range
		return true;
	}

}


Matrix Matrix::copy(){

	/* fix the code and write your implementation below */

    Matrix copy=  Matrix(rowsNum,colsNum);           // creates a matrix with the same rows and columns as the matrix being copied
    for(int i =0;i<rowsNum;i++){
    	for(int j=0;j<colsNum;j++){
    		copy.setElement(matrixData[i][j],i,j);   // sets each element in the new matrix to the same as the old matrix for each position
    	}
    }


    return  copy;        // returns the copy matrix


}


void Matrix::addTo( Matrix m ){
	if(m.getsizeofrows() == rowsNum and m.getsizeofcols() == colsNum){   // check if matrix addition is defined
		for(int i =0;i<rowsNum;i++){
			for(int j=0;j<colsNum;j++){
				matrixData[i][j] += m.matrixData[i][j];       // adds the two matrices
			}
		}

	}
	else{
		throw std::invalid_argument( "Invalid operation" );   // throws exception if matrix addition is not defined
	}

}


Matrix Matrix::subMatrix(int i, int j){

	/* The exception detail message should read: "Submatrix not defined"*/

	/* fix the code and write your implementation below */

	if(i<0 or i>=rowsNum or j<0 or j>=colsNum){              // checks if i and j are in the range
		throw std::out_of_range( "Submatrix not defined" );
	}
	else{
		Matrix subM = Matrix (i+1,j+1);               // creates a submatrix
		for(int a =0; a<i+1 ;a++){
			for(int b=0; b<j+1 ;b++){
				subM.setElement(matrixData[a][b],a,b);  // sets the elements in the submatrix for rows 0-i and columns 0-j
			}

		}
		return  subM;     // returns the submatrix

	}

}


int Matrix::getsizeofrows(){

	
	/* update below return */

	return rowsNum;       // returns the number of rows

}


int Matrix::getsizeofcols(){



	/* update below return */

    return colsNum;       // returns the number of columns
}


bool Matrix::isUpperTr(){

	/* write your implementation here and update return accordingly */
	for(int i = 1; i< rowsNum; i++){
		for(int j = 0; j<i;j++){
			if(matrixData[i][j] != 0 ){   // checks if any element in the lower part of the matrix is not zero
				return false;             // returns false if not upper triangular
			}
		}
	}
	return true;       // returns true if upper triangular
}


string Matrix::toString(){

	string output;
	for(int i = 0;i<rowsNum;i++){
		for(int j = 0;j<colsNum;j++){
			output += to_string(matrixData[i][j]) + " ";  // converts the element to a string and adds it to the output with a space after it
		}
		output += "\n";    // adds a new line after each row
	}


	//return output;
	 return output;
}

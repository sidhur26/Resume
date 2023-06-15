#include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"



void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
    /*vector3 should store the sum of vector1 and vector2. 
	You may assume that all three arrays have the size equal to n
	*/
	//write your code below
	int n = size;                      // sets the size of the vector equal to n
	for(int i=0;i<n;i++){
		vector3[i] =vector1[i] + vector2[i];      // Adds each component of vector1 and vector2
	}

}

double scalar_prod(double vector1[],double vector2[],int size)
{
	// this is the variable holding the scalar product of the two vectors
    double prod=0;
    double temp;

	//write your code below to calculate the prod value
    for(int i=0;i<size;i++){
    	temp = vector1[i]*vector2[i];      // multiplies vector1 and vector2 and stores the value in temp for each component
    	prod += temp;                      // adds the temp value to prod for each iteration
    }

	
    

	
	// return the result
    return prod;
}

double norm2(double vector1[], int size)
{
	//this is the variable holding the L2 norm of the passed vector
    double L2;
    double L2_squared;
	
    
	//write your code here
	// you should call function scalar_prod().
    L2_squared = scalar_prod(vector1,vector1,size);   //calls scalar_prod
    L2 = sqrt(L2_squared);                            // Gets the square root of the result from scalar_prod

	
	//finally, return the L2 norm 
    return L2;
}

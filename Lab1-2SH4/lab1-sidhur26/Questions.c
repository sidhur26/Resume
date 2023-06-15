
#include "Questions.h"



int Q1_for(){
	int sum=0;
	int i;
	// calculate your sum below..this has to use for loop
	for(i=30;i<=1000;i++)
	{
		if(i%4==0){              // checks if i is a multiple of 4
			sum = sum + i;       // adds i to the sum if its a multiple
		}
	}
	
	// here, we return the calcualted sum:
	return sum;
}
int Q1_while(){
	int sum = 0;
	int i = 30;
	// calculate your sum below..this has to use while loop
	while(i<=1000){
		if(i%4==0){             // checks if i is a multiple of 4
			sum = sum + i;      // adds i to the sum if it is a multiple of 4
		}
		i++;
	}
	
	// here, we return the calcualted sum:
	return sum;
}
int Q1_do(){
	int sum=0;
	int i=30;
	// calculate your sum below..this has to use do-while loop
	do {
		if(i%4==0){               //checks if 4 is a multiple of 4
			sum = sum + i;        // adds i to the sum if it is a multiple of 4
		}
		i++;
	}
	while(i<=1000);

	  
	
	// here, we return the calcualted sum:
	return sum;
}
//===============================================================================================
int Q2(int Q2_input){
	
	// this is the flag that is holding whether the input number is 5-digit or not
	int IsFiveDigit;
	int i = 0;
	// Do your coding below to check
	while(Q2_input!=0){
		Q2_input = Q2_input/10;          // divides by 10 to decrease the digits by 1
		i++;                             // increments i by 1 each time the digits are reduced by 1
	}
	if(i==5){
		IsFiveDigit = 1;
	}
	else{
		IsFiveDigit = 0;
	}
	
	//finally, we must return IsFiveDigit, which must be 1 is the number is five digits and 0 otherwise
	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input){
	
	/* Question 3: 
	Write a program that takes a student's Q3_input as an input, which is a floating point value,
	and returns:
	4 if the Q3_input is in the range 90-100,
	3 if it is in the range 80-89, 
	2 if it is in the range 70-79,
	1 if it is in the range 60-69 and
	0 if the Q3_input is between 0 and 59.
	If the Q3_input is not in the range 0-100, the program shouldreturn -1
*/	
	// this is the varaible that holds the out value to return
	float GPA;
	
	
	// Do your coding below to calculate the GPA variable value
	if(Q3_input>=0 && Q3_input<60){                 // checks if the input is between 0 and 60 not equal to 60
		GPA = 0;
	}
	else if(Q3_input>=60 && Q3_input<70){           // checks if the input is greater than or equal to 60 and less than 70
		GPA = 1;
	}
	else if(Q3_input>=70 && Q3_input<80){           // checks if input is between 70 and 80 but not equal to 80
		GPA = 2;
	}
	else if(Q3_input>=80 && Q3_input<90){           // checks if input is between 80 and 90 but equal to 90
		GPA = 3;
	}
	else if(Q3_input>=90 && Q3_input<=100){         // checks if input is between 90 and 100
		GPA = 4;
	}
	else{
		GPA = -1;
	}
	// finally, we return the GPA
	return GPA;	
}
//===============================================================================================
double Q4(int Q4_input){
	
	// this is the varaible that holds the pi value to return
	double pi=0;
	int i;
	
	// Do your coding below to calculate the pi value
	for(i=1; i <= Q4_input; i++){
		if(i%2==0){                                       // checks if i is even
			pi = pi - (4.0/(2 * i -1));                   // subtracts the next term if i is even
		}
		else{
			pi = pi + (4.0/(2 * i -1));                   // adds the next term if i is odd
		}
	}

	   
	
	// finally, we return the pi value
	return pi;	
}
//===============================================================================================
int Q5(){
	
	// this is the varaible that holds and the total number of triples to return at the end of the function
	int totNumTribles=0;
	/* Do your coding below
		Use a triple-nested for loop that simply tries all possibilities
		and update the total number of triples if needed
	*/
	for(int side1 = 1; side1<=400; side1++){

		for(int side2 = side1; side2<= 400; side2++){        // triple nested for loop to loop through all possibilities of side1, side2, and hyp less than or equal to 400

			for(int hyp = side2; hyp<=400; hyp++){
				if((side1*side1) + (side2*side2) == (hyp*hyp)){          // checks if side1 squared plus side2 squared is equal to the hypotenuse squared
					totNumTribles += 1;                                  // increments the total if the triple satisfies the condition
				}
			}
		}
	}


	
	//finally you should return the total number of tribles.
	return totNumTribles;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[]){
	
	
	
		//counts is teh variable that should hold the total number of found perfect numbers
		//you should update it within your code and return it at the end
	    int counts=0;
        int n,i,sum;
        int index = 0;
		/*
		*
		*perfect is an array that you need to add into it any perfect number you find
		*which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
		*you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will 
		*autmoatically reflect in the main calling function.
		*/
	    for(n=1;n<=Q6_input;n++){
	    	i =1;
	    	sum=0;
	    	while(i<n){
	    		if(n%i==0){                     //checks if i is a factor
	    			sum = sum + i;              // adds i to the sum if it is a factor
	    		}
	    		i++;
	    	}
	    	if(sum==n){                         // checks if the sum is equal to the number being checked
	    		counts += 1;                    // increments the count
	    		perfect[index++]= n;            // puts the number in to the array if it is a perfect number
	    	}
	    }
		

	   return counts;

	
}
//===============================================================================================
int Q7a(int Q7_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	int remainder,i;
	
	
	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//in this part you can assume the knowledge of the number of digits: seven-digit positive integer
	for(i=0;i<7;i++){
		remainder = Q7_input % 10;                           // divides the input by 10 and saves the remainder
		reversedInt = reversedInt * 10 + remainder;          // multiply reversed integer by 10 and adds the remainder
		Q7_input /= 10;                                      // divides input by 10

	}
	
		return reversedInt;
	
}
int Q7b(int Q7b_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	int remainder;
	
	

	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//this part should be generalized for any number of allowed digits
	while(Q7b_input != 0){
		remainder = Q7b_input % 10;                          // divides the input by 10 and saves the remainder
		reversedInt = reversedInt * 10 + remainder;          // multiply reversed integer by 10 and adds the remainder
		Q7b_input /= 10;                                     // divides the input by 10

	}
	
	
	return reversedInt;

	
	
	
}

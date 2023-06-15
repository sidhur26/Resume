#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){
	int count1 = 0;
	int count2 = 0;
	for(int i=0;i<k1;i++){                            // Iterates through pos1 array
		for(int j =0; j<k2;j++){
			if(pos1[i]<pos2[j]){                      // Checks if the position in pos1 is less than the position in pos2
				val3[count1++] = val1[i];             // Adds value from val1
				pos3[count2++] = pos1[i];             // Adds position from pos1
				break;
			}
			else if(pos1[i]==pos2[j]){                // Checks if the positions are equal
				val3[count1++] = val1[i] + val2[j];   // Adds value from val1 and val2
				pos3[count2++] = pos1[i];             // Adds corresponding position
				break;
			}

		}
	}
	for(int h=0; h<k2;h++){                           // Iterates through pos2 array
		for(int s = 0;s<k1;s++){
			if(pos2[h]<pos1[s]){                      // Checks if the position in pos2 is less than the position in pos1
				val3[count1++] = val2[h];             // Adds value from val2
				pos3[count2++] = pos2[h];             // Adds position from pos2
				break;
			}
			else if(pos2[h]==pos1[s]){                // Breaks if positions are equal since they were added earlier
				break;
			}
		}
	}
	if(pos1[k1-1]>pos2[k2-2]){                       // Checks if the highest position is in pos1
		val3[count1++] = val1[k1-1];                 // Adds value corresponding to highest position
		pos3[count2++] = pos1[k1-1];                 // Adds the highest position into pos3
	}
	if(pos2[k2-1]>pos1[k1-1]){                       // Checks if the highest position is in pos2
		val3[count1++] = val2[k2-1];                 // Adds value corresponding to highest position
		pos3[count2++] = pos2[k2-1];                 // Adds the highest position into pos3
	}
	
}

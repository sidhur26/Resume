#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void string_copy(const char source[], char destination[], int n){
	int i =0;
	for(i=0;i<n-1;i++){
		destination[i] = source[i];            // copies string source to string destination depending on size of destination



	}
	destination[i] = '\0';       // adds the null character to the end of the string
}

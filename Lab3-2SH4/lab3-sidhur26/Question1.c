#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL;
	
	/*write your implementation here*/
	int len1,len2,len3;                         // initializes len1, len2, and len3 as integers
	int i = 0;
	len1 = strlen(str1);                        // sets the length of str1 to len1
	len2 = strlen(str2);                        // sets the length of str2 to len2
	len3 = len1 + len2 + 1;                     // adds the length of both strings and adds one for the null character
	z = malloc((size_t) len3);                  // allocates the memory for the new string

	for(i=0;i<len1;i++){
		z[i] = str1[i];                         // adds the first string to the new string
	}
	for(i=0;i<len2;i++){
		z[i+len1] = str2[i];                    // adds the second string after the first string in the new string
	}
	z[len3] = '\0';                             // adds the null character at the end of the list


	/* finally, return the string*/
	return z;

	free(z);                                    // frees the memory previously allocated

}

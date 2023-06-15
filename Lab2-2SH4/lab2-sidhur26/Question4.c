#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]){
	int i = 0;
	int	x;
	while(word[i] != '\0'){
		if(word[i] >= 'a' && word[i] <= 'z'){        // checks if letter is lower case
			x = word[i] - 'a';                       // subtracts the ASCII value of a from the letter's ASCII value
			freq[x]++;
		}
		else if(word[i] >= 'A' && word[i]<= 'Z'){     // checks if letter is upper case
			x = word[i] - 'A';                        // subtracts the ASCII value of A from the letter's ASCII value
			freq[x]++;                                // increments the frequency of the letter
		}
		i++;
}
}

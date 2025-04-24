/* Description: Extra Credit Project to Identify a Blurb
*
* Author: Ben Higginbotham
*
* Duration: 4 hrs
* version: gcc
*/

/* Blurb is a Whoozit followed by between zero or more Whatzits. 
* A Whoozit is the character 'x' followed by between one or more 'y's. 
* A Whatzit is a 'q' followed by either a 'z' or a 'd', followed by a Whoozit.
* <Blurb>   ::- <Whoozit> | <Whoozit> <Whatzit>
* <Whoozit> ::- xy | xy(s)
* <Whatzit> ::- qz <Whoozit> | qd <Whoozit>
* 
* Enter an alien word: qxxyyyy // The word is a mess!
* Enter an alien word: xyyyyqzqd // The word is a mess!
* Enter an alien word: xyyyyyqzxyyy //The word is fine.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 50

int isWhoozit(char[]);
int isWhatzit(char[]);

int main(){
	char blurb[MAX_LEN];
	int result = 1; 

	while(result == 1) {
		printf("Enter an alien word: ");
        	scanf("%s", blurb);
		result = isWhoozit(blurb);
		if (result == 0) {
			printf("\nThe word is fine.\n");
		} else {
			printf("\nThe word is a mess!\n");
		}
	}
	
	return 0;
}

int isWhoozit(char blurb[MAX_LEN]) {
	int i = 2;

	if (blurb[0] != 'x' || blurb[1] != 'y') {
		return 1;
	}

	while(blurb[i] == 'y') {
		i++;
	}
	
	if (blurb[i]) {
		char blurbette[MAX_LEN];
		strcpy(blurbette, blurb + i);
		int result = isWhatzit(blurbette);
		if (result == 1) return 1;			
	}
 
	return 0;
}

int isWhatzit(char blurb[MAX_LEN]) {
        if (blurb[0] == 'q' && (blurb[1] == 'z' || blurb[1] == 'd')) {
		char blurbette[MAX_LEN];
                strcpy(blurbette, blurb + 2);
                int result = isWhoozit(blurbette);
		if (result == 0) return 0;
	}  

	return 1;
}

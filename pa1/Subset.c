//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Author:	Midori Kanuma
// CruzID:	mkanuma
// Class:	CMPS12B/M
// Date:	7/3/2019
// 
// Description:	This file is the main code for
//             	programming assignment 1
//
// compile: gcc -std=c99 -o Hanoi Hanoi.c
//
// File Name: pa1.c
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100	// We will assume that the user will input an integer less than 100
#define USAGE "Usage: Subset n k (n and k are ints satisfying 0<=k<=n<=100)"

// Prints the Sub set of {1,2,3,...,n} where B[] specifies the inclusion/exclusion of the element
void printSet(int B[], int n){
	int j = 1;
	printf("{");
	bool emptySet = true;
	bool firstIdx = true;

	while(j < n+1){

		if(B[j] == 1){

			emptySet = false;

			if(firstIdx){
				printf("%d", j);
				firstIdx = false;
			}else{
				printf(", %d", j);
			}
		}

		j++;
	}

	if(emptySet){
		printf(" }");
	}else{
		printf("}");
	}

	printf("\n");
	return;
}

// This is the recursive element of programming assignment 1. It calls printSet, does nothing, or recurs based on the conditions
void printSubsets(int B[], int n, int k, int i){
	if(k == 0){

		printSet(B, n);

	}else if(k <= n-i+1){

		B[i] = 1;	
		printSubsets(B, n, k-1, i+1);

		B[i] = 0;
		printSubsets(B, n, k, i+1);

	}else{
		return;
	}
}


/*
/This part still needs work, namely the parsing of the command line arguments and printing of the
/error message/the correct output of the script
*/

int main(int argc, char* argv[]){
	int B[MAX_SIZE+1];
	int k;
	int n;
	int i = 1;
	int num;
	int status;
	char ch;

	if(argc != 3){  // Exit and print error message if number of CLA!=2
		printf(USAGE);
		return	EXIT_SUCCESS;
	}

	status = sscanf(argv[1], "%d%c", &num, &ch);  // Exit and print if CLA1 is not an int
    if(status != 1){
    	printf(USAGE);
		return	EXIT_SUCCESS;
    }else{
    	n = num;
    }
	
	status = sscanf(argv[2], "%d%c", &num, &ch);  // Exit and print if CLA2 is not an int
    if(status != 1){
      	printf(USAGE);
		return	EXIT_SUCCESS;
    }else{
    	k = num;
    }

    if(k > n){										// Exit and print if k>n
    	printf(USAGE);
		return	EXIT_SUCCESS;
    }

    printSubsets(B, n, k, i);

	return EXIT_SUCCESS;
}

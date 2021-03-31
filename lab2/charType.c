//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Author:	Midori Kanuma
// CruzID:	mkanuma
// Class:	CMPS12B/M
// Date:	7/14/2019
//
// Description:	This file is the main code for lab2
//				From an input file in, this program reads the characters
//				and prints how many:
//					Alphabets, numeric characters, punctuation characters, and whitespaces.
//				Also prints the string of all those together.
// 
// File Name:	charType.c
// 
// Compile:	gcc -std=c99 -o charType charType.c
//
// Run:		charType in out
// Open:	cat out
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h> 	// Imports the standard I/O
#include <stdlib.h> 	// imports the standard library
#include <stdbool.h>	// imports boolean
#include <ctype.h>	// imports the character type
#include <string.h> 	// imports string operations
#include <assert.h>

#define MX_SRLN 100	// Sets max string length

void extract_chars(char* s, char* a, char* d, char* p, char* w){
	FILE* outPtr;							// Create file pointer to point to 

	outPtr = fopen("out","a");					// Initialize... 
	assert(outPtr!=NULL);							// and make sure it opens

	int sCtr, aCtr = 0, dCtr =0, pCtr = 0, wCtr = 0;		// Initialize counters for string length
	int i = 0;							// Initialize loop counter

	while(*(s+i) != '\0' && i< MX_SRLN){				// This section increments each counter according to the charType
		if(isalnum((int)*(s+i))){
			if(isalpha((int)*(s+i))){
				aCtr++;
			}
			if(isdigit((int)*(s+i))){
				dCtr++;
			}
		}
	
		else if(ispunct((int)*(s+i))){
			pCtr++;
		}
		else if(isspace((int)*(s+i))){
			wCtr++;
		}
		else{
			return;
		}
		i++;
	}

	sCtr = i;							// num of elem in s is i

	a = calloc(aCtr+1,sizeof(char));				// Allocate space for string of length
	d = calloc(dCtr+1,sizeof(char));
	p = calloc(pCtr+1,sizeof(char));
	w = calloc(wCtr+1,sizeof(char));
	
	i = 0;								// Put all of the characters in the pointers
	int j = 0;
	while(i < sCtr && j < aCtr){
		if(isalpha((int)*(s+i))){
			*(a+j) = *(s+i);
			j++;
		}
		i++;
	}
	*(a+aCtr) = '\0';						// Put null terminator

	i = 0;
	j = 0;
	while(i < sCtr && j < dCtr){
		if(isdigit((int)*(s+i))){
			*(d+j) = *(s+i);
			j++;
		}
		i++;
	}
	*(d+dCtr) = '\0';						// Put null terminator

	i = 0;
	j = 0;
	while(i < sCtr && j < pCtr){
		if(ispunct((int)*(s+i))){
			*(p+j) = *(s+i);
			j++;
		}
		i++;
	}
	*(p+pCtr) = '\0';						// Put null terminator

	i = 0;
	j = 0;
	while(i < sCtr && j < wCtr){
		if(isspace((int)*(s+i))){
			*(w+j) = *(s+i);
			j++;
		}
		i++;
	}
	*(w+wCtr) = '\0';						// Put null terminator

	fprintf(outPtr, "%zu alphabetic characters: %s\n", strlen(a), a);	// Print the formatted strings		
	fprintf(outPtr, "%zu numeric characters: %s\n", strlen(d), d);	
	fprintf(outPtr, "%zu punctuation characters: %s\n", strlen(p), p);	
	fprintf(outPtr, "%zu whitespace characters: %s\n", strlen(w), w);	

	fclose(outPtr);							// Close the file
	
		free(a);						// Free up space
		a = NULL;

		free(d);
		d = NULL;

		free(p);
		p = NULL;

		free(w);
		w = NULL;

	return;
}

int main(int argc, char* argv[]){
	assert(argc == 3);  					// Make sure there are only two CLAs

	char in[3], out[4];						// Store the CLAs in arrays to verify string name
	sscanf(argv[1],"%s",in);				// Stores CLA1 in in
	sscanf(argv[2],"%s",out);				// Stores CLA2 in out

	assert(in[0]=='i');						// Make sure that CLA1 is precisely in
	assert(in[1]=='n');
	assert(in[2]=='\0');

	assert(out[0]=='o');					// Make sure that CLA2 is precisely out
	assert(out[1]=='u');
	assert(out[2]=='t');
	assert(out[3]=='\0');

	// Def works

	FILE* inPtr;
	FILE* outPtr;						// Create file pointer to point to in
	
	inPtr = fopen(argv[1],"r");				// Open file and...
	assert(inPtr!=NULL);					// Make sure that it opens


	char* contents;						// Initialize pointer to point to the line being read					
	contents = calloc(MX_SRLN+1,sizeof(char));			// Make sure that the allocated space is not null
	assert(contents!=NULL);

	int i = 0;

	char* a=NULL;						// Initialize char pointers to NULL
	char* d=NULL;
	char* p=NULL;
	char* w=NULL;
	
	while(fgets(contents, MX_SRLN, inPtr) != NULL ){


		//contents contains the line
		i++;						// Counter to keep track of which line we're on

		outPtr = fopen("out","a");			// open file in append mode
		assert(outPtr!=NULL);				// Make sure it opens

		fprintf(outPtr, "line %d contains:\n", i);	// Print formatted string

		fclose(outPtr);					// Close file


		extract_chars(contents, a, d, p, w);		// Run the function to extract characters and 

	}
	
	free(contents);						// Free up the space							
	contents=NULL;
	return EXIT_SUCCESS;    
}

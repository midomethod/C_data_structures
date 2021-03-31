#include <stdio.h> 	// Imports the standard I/O
#include <stdlib.h> 	// imports the standard library
#include <stdbool.h>	// imports boolean
#include <ctype.h>	// imports the character type
#include <string.h> 	// imports string operations
#include <assert.h>

#include"Dictionary.h"

int main(){
	char* ch;

	Dictionary D = newDictionary();

	insert(D, "one", "foo");
	insert(D, "two", "bar");
	insert(D, "three", "blah");
	insert(D, "four", "galumph");

	ch = DictionaryToString(D);
	printf("Contents:\n%s\n\n", ch);
	free(ch);
	//printf("free called on: ch\n\n");
	//printf("\tcheckpoint 0 before lookup\n\n");

	printf("Number of entries: %d\n", size(D));

	printf("Result of lookup(D, \"three\"): %s\n", lookup(D, "three"));

	makeEmpty(D);
	freeDictionary(&D);

	//printf("free called on: D\n\n");

	D = newDictionary();

	//printf("\tCheckpoint 1 after newDictionary\n\n");

	insert(D, "A", "Adobo"); 		// "A Adobo\n" is 8 chars 
	insert(D, "B", "Banana");		// "B Banana\n" is 9 chars
	insert(D, "C", "Chicorita");	// "C Chicorita\n" is 12 chars

	//printf("\tCheckpoint 2 after insert\n\n");

	printf("Number of entries: %d\n", size(D));

	ch = DictionaryToString(D);
	printf("The contents of the dictionary are:\n%s\n", ch);
	free(ch);
	//printf("free called on: ch\n\n");

	//printf("\tCheckpoint 3 after DictionaryToString and size\n\n");

	delete(D, "B");

	//printf("\tCheckpoint 4 after delete\n\n");

	printf("Number of entries: %d\n", size(D));

	ch = DictionaryToString(D);
	printf("The contents of the dictionary are:\n%s\n",ch);
	free(ch);
	//printf("free called on: ch\n\n");

	insert(D, "B", "Burrito");

	printf("Number of entries: %d\n", size(D));

	ch = DictionaryToString(D);
	printf("The contents of the dictionary are:\n%s\n", ch);
	free(ch);
	//printf("free called on: ch\n\n");
	printf("The result of lookup(D, \"B\") is: %s\n", lookup(D, "B"));

	//printf("\n\tCheckpoint 4.1 after lookup(valid)\n\n");

	printf("The result of lookup(D, \"D\") is: %s\n", lookup(D, "D"));

	//printf("\n\tCheckpoint 4.2 after lookup(invalid)\n\n");

	makeEmpty(D);

	//printf("\n\tCheckpoint 5 after makeEmpty\n\n");

	//printf("Number of entries: %d", size(D));

	ch = DictionaryToString(D);
	printf("The contents of the dictionary are:\n%s\n\n\n\n",ch);
	free(ch);
	//printf("free called on: ch\n\n");

	freeDictionary(&D);

	//printf("\tCheckpoint 6 after freeDictionary\n\n");

	printf("Test passed all checkpoints and behaved nominally!!\n");

	return EXIT_SUCCESS;
}
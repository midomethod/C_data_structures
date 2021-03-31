//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Author:	Midori Kanuma
// CruzID:	mkanuma
// Class:	CMPS12B/M
// Date:	7/20/2019
// 
// Description:	This file is the main code for
//             	lab assignment 3
//
// compile: gcc -std=c99 -o Queens Queens.c
//
// File Name: IntegerStack.c
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h> 	// Imports the standard I/O
#include <stdlib.h> 	// imports the standard library
#include <stdbool.h>	// imports boolean
#include <ctype.h>	// imports the character type
#include <string.h> 	// imports string operations
#include <assert.h>

#include"IntegerStack.h"

// Private Types and Functions ------------------------------------------------

// InitialSize
static const int InitialSize = 1;

// IntegerListObj
typedef struct IntegerStackObj{
   int* item;         // array of IntegerList items
   int numItems;      // number of items in this IntegerList
   int cap;
} IntegerStackObj;

// Constructors-Destructors ---------------------------------------------------

// newIntegerList()
// Constructor for the IntegerList ADT
IntegerStack newIntegerStack(){
   IntegerStack S = malloc(sizeof(IntegerStackObj));
   S->item = calloc(InitialSize, sizeof(int));
   S->numItems = 0;
   S->cap = 1;
   return S;
}

// ADT operations ------------------------------------------------------------

// get()
// pre: 1 <= index <= size(L)
// Returns int at position index in L
int peek(IntegerStack S){
   if( S==NULL ){
      fprintf(stderr, "IntegerStack Error: peek() called on NULL IntegerStack reference");
      exit(EXIT_FAILURE);
   }
   if( S->numItems<1 ){
      fprintf(stderr, "IntegerStack Error: peek() called on empty IntegerStack");
      exit(EXIT_FAILURE);
   }

   return S->item[S->numItems-1];
}

// isEmpty
int isEmpty(IntegerStack S){
	if(S->numItems==0){
		return 1;
	}
	else{
		return 0;
	}
}

// push()
// Inserts int x into L at position index
// pre: 1 <= index <= size(L)+1
void push(IntegerStack S, int x){
   	int i;
   	if( S==NULL ){
      	fprintf(stderr, "IntegerStack Error: push() called on NULL IntegerStack reference");
      	exit(EXIT_FAILURE);
   	}

   	if( (S->numItems) == (S->cap) ){
   		
   		S->cap = S->cap*2;

   		int* dummy;
   		dummy = calloc(S->cap, sizeof(int));

   		for(i=0; i <= S->numItems-1 ; i++){
   			dummy[i] = S->item[i];
   		}

   		free(S->item);

   		S->item = dummy;
   	}

   	S->item[S->numItems] = x;

   	S->numItems++;
}  

// delete()
// Deletes int from position index
// pre: 1 <= index <= size(L)
int pop(IntegerStack S){
   int val;

   if( S==NULL ){
      fprintf(stderr, "IntegerStack Error: pop() called on NULL IntegerStack reference");
      exit(EXIT_FAILURE);
   }
   if( S->numItems<1 ){
      fprintf(stderr, "IntegerStack Error: pop() called on empty stack");
      exit(EXIT_FAILURE);
   }

   S->numItems--;
   val = S->item[S->numItems];

   return val;
}

// Prototype for popAll()
// Destructor for the List ADT
void popAll(IntegerStack S){
   int i;

   if( S==NULL ){
     fprintf(stderr, "IntegerStack Error: popAll called on NULL IntegerStack reference");
   }

    for(i=0; i<S->numItems; i++){
      	pop(S);
	}	

	S->cap = 1;

	return;
}

// Other Operations -----------------------------------------------------------

// freeIntegerStack()
// frees the space allocated for the int stack data type
void freeIntegerStack(IntegerStack* S){
	//Integerstack T = *S;
	//printf("checkpoint 1\n");
	free((*S)->item);

	//printf("checkpoint 2\n");
	(*S)->item = NULL;

	//printf("checkpoint 3\n");
	free(*S);

	//printf("checkpoint 4\n");
	*S = NULL;

	return;
}

// printIntegerStack()
// Prints a space separated list of items in S to file stream pointed to by out
void printIntegerStack(FILE* out, IntegerStack S){
   int i;
   if( S==NULL ){
      fprintf(stderr, "IntegerStack Error: printIntegerStack() called on NULL IntegerStack reference");
      exit(EXIT_FAILURE);
   }

   for( i=0; i<(S->numItems); i++){
      fprintf(out, "%d ", S->item[i] );
   }
   fprintf(out, "\n");
}

// equals()
// Returns true (1) if L and R are matching sequences of integers, false (0) 
// otherwise
int equals(IntegerStack S, IntegerStack T){
   int i, eq;
   if( S==NULL || T==NULL ){
      fprintf(stderr, "IntegerStack Error: equals() called on NULL IntegerStack reference");
      exit(EXIT_FAILURE);
   }

   eq = ( (S->numItems)==(T->numItems) );	// Check if number of items are equal
   for( i=0; eq && i<(S->numItems); i++){	
      eq = ( (S->item[i])==(T->item[i]) );
   }
   return eq;
}

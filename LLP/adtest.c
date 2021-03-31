#include <stdio.h> 	// Imports the standard I/O
#include <stdlib.h> 	// imports the standard library
#include <stdbool.h>	// imports boolean
#include <ctype.h>	// imports the character type
#include <string.h> 	// imports string operations
#include <assert.h>

#include"LinkedList.h"

Node top = NULL;

void push(int x){
	if(top==NULL){
		top = newNode(x);
	}	
	else{
		Node N = newNode(x);
		N->next = top;
		top = N;
	}
}

int peek(){
	int x;
	x = top->num;
	return x;
}

int pop(){
	int x;
	Node N;
	if(top==NULL){
		printf("The stack has yet to be initiated\n");
		exit(EXIT_FAILURE);
	}

	N=top;
	top=top->next;

	x = N->item;

	freeNode(&N);

	return x;

}

int main(){

	printf("The beginning of adtest...\n\n");

	push(5);

	printf("\tThe top of stack is: %d\n\n", peek());

	printf("The end of adtest...\n\n");

	return EXIT_SUCCESS;
}
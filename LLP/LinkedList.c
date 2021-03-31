//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Author:	Midori Kanuma
// CruzID:	mkanuma
// Class:	CMPS12B/M
// Date:	7/25/2019
// 
// Description:	This file is the main code for
//             	programming assignment 3
//
// compile:		run make
//
// File Name: Dictionary.c
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h> 	// Imports the standard I/O
#include <stdlib.h> 	// imports the standard library
#include <stdbool.h>	// imports boolean
#include <ctype.h>	// imports the character type
#include <string.h> 	// imports string operations
#include <assert.h>

#include"LinkedList.h"

// Creation of pair structure
typedef struct NodeObj{
	int num;
	Node next;
} NodeObj;

// Destructor for Node
void freeNode(Node* pN){
	if(pN!=NULL && *pN!=NULL){
		free(*pN);
		pN=NULL;
	}	
}

// Constructors-Destructors ---------------------------------------------------

// newDictionary()
// Constructor for the Dictionary ADT.
Node newNode(int x){
	Node N = malloc(sizeof(NodeObj));
	N->num = x;
	N->next = NULL;
}

// Implementation of stack


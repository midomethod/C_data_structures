//-----------------------------------------------------------------------------
// Dictionary.h
// Header file for the Dictionary ADT
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>

#ifndef _LINKEDLIST_H_INCLUDE_
#define _LINKEDLIST_H_INCLUDE_


// Exported type --------------------------------------------------------------

// Dictionary
typedef struct NodeObj* Node;


// Constructors-Destructors ---------------------------------------------------

// newDictionary()
// Constructor for the Dictionary ADT.
Node newNode();

// freeDictionary()
// Destructor for the Dictionary ADT.
void freeNode(Node* pN);


#endif












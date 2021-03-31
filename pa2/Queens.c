//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Author:	Midori Kanuma
// CruzID:	mkanuma
// Class:	CMPS12B/M
// Date:	7/20/2019
// 
// Description:	This file is the main code for
//             	programming assignment 2
//
// compile: gcc -std=c99 -o Queens Queens.c
//
// File Name: Queens.c
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h> 	// Imports the standard I/O
#include <stdlib.h> 	// imports the standard library
#include <stdbool.h>	// imports boolean
#include <ctype.h>	// imports the character type
#include <string.h> 	// imports string operations
#include <assert.h>

#define USAGE "Usage: Queens [-v] number\nOption: -v verbose output, print all solutions\n"

// Places Queen and subtracts 1 from the values of the squares under attack
void placeQueen(int** B, int n, int i, int j){
	if(B[i][0]!=0){
		printf("Error: There is a Queen in row %d\n", i);
		return;
	}

	if(B[i][j]!=0){
		printf("Error: (%d,%d) is either already occupied or under attack\n",i,j);
		return;
	}

	B[i][j]=1;
	B[i][0]=j;
	
	// Begin subtracting downwards
	int y=i+1;
	int x=j;
	while(x<n+1 && x>0 && y<n+1 && y>0){
		B[y][x]=B[y][x]-1;
		y++;
	}

	// Begin subtracting downright
	y=i+1;
	x=j+1;
	while(x<n+1 && x>0 && y<n+1 && y>0){
		B[y][x]=B[y][x]-1;
		y++;
		x++;
	}

	// Begin subtracting downleft
	y=i+1;
	x=j-1;
	while(x<n+1 && x>0 && y<n+1 && y>0){
		B[y][x]=B[y][x]-1;
		y++;
		x--;
	}
}

// Removes queens and adds 1 to the values of the squares previous under attack
void removeQueen(int** B, int n, int i, int j){
	if(B[i][j]!=1){
		printf("Error: (%d,%d) does not contain a Queen to remove\n",i,j);
		return;
	}

	B[i][j]=0;
	B[i][0]=0;
	
	// Begin subtracting downwards
	int y=i+1;
	int x=j;
	while(x<n+1 && x>0 && y<n+1 && y>0){
		B[y][x]=B[y][x]+1;
		y++;
	}

	// Begin subtracting downright
	y=i+1;
	x=j+1;
	while(x<n+1 && x>0 && y<n+1 && y>0){
		B[y][x]=B[y][x]+1;
		y++;
		x++;
	}

	// Begin subtracting downleft
	y=i+1;
	x=j-1;
	while(x<n+1 && x>0 && y<n+1 && y>0){
		B[y][x]=B[y][x]+1;
		y++;
		x--;
	}
}

// Initializes board to all 0s
void initBoard(int** B, int n){
	int i, j;
	for(i=0;i<n+1;i++){
		for(j=0;j<n+1;j++){
			B[i][j]=0;
		}
	}
}

// Helper function I used to display the contents of the board
void showBoard(int** B, int n){
	int i, j;

	for(i=0;i<n+1;i++){
		if(i==1)
			printf("_________________________________________________________________________________________________\n\n");
		for(j=0;j<n+1;j++){
			if(j==0)
				printf("\t%d |",B[i][j]);
			else
				printf("\t%d", B[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// Print the left most column which contain the solution to the current queen placement
void printBoard(int** B, int n){
	int i;
	printf("(");
	for(i=1;i<n+1;i++){
		if(i==1){
			printf("%d",B[i][0]);
		}
		else{
			printf(", %d",B[i][0]);
		}
	}
	printf(")\n");
	return;
}

// Recursive element of this code
int findSolutions(int** B, int n, int i, char* mode){
	int solCt = 0;
	bool verbMode = false;	// Assume it's on normal mode
	int j = 1;

	// If mode = "verbose", set verbMode to true
	if(	mode[0]=='v' &&
		mode[1]=='e' &&
		mode[2]=='r' &&
		mode[3]=='b' &&
		mode[4]=='o' &&
		mode[5]=='s' &&
		mode[6]=='e' &&
		mode[7]=='\0'	){
			verbMode=true;
	}

	// The cpp interpretation of the pseudocode in the pdf
	if(i>n){
		if(verbMode){
			printBoard(B,n);
		}	
		return 1;
	}
	else{
		for(j = 1; j<n+1;j++){
			if(B[i][j]==0){
				placeQueen(B,n,i,j);
				solCt += findSolutions(B,n,i+1,mode);
				removeQueen(B,n,i,j);
			}
		}
	}

	return solCt;
}

int main(int argc, char* argv[]){
	int status;
	int n, i;
	char ch;

	char* opt;
	opt = calloc(3, sizeof(char));	// Allocate enough space to store "-v\0"	
	char* mode;
	mode = calloc(8, sizeof(char));	// Allocate enough space to store "verbose\0"

	// Check if the CLAs are with in spec
	if(argc<2 || argc>3){
		printf(USAGE);
		return EXIT_SUCCESS;
	}
	else if(argc==2){
		status = sscanf(argv[1], "%d%c", &n, &ch);
		if(status!=1){
			printf(USAGE);
			return EXIT_SUCCESS;
		}
		else{
			mode[0]='n';
				mode[1]='o';
					mode[2]='r';
						mode[3]='m';
							mode[4]='a';
								mode[5]='l';
									mode[6]='\0';
		}
	}
	else{
		status = sscanf(argv[2], "%d%c", &n, &ch);
		if(status!=1){
			printf(USAGE);
			return EXIT_SUCCESS;
		}
		else{
			if(strlen(argv[1])>2){
				printf(USAGE);
				return EXIT_SUCCESS;
			}
			else{
				sscanf(argv[1], "%s", opt);
				if(opt[0]!='-'){
					printf(USAGE);
					return(EXIT_SUCCESS);
				}
				else if(opt[1]!='v'){
					printf(USAGE);
					return(EXIT_SUCCESS);
				}
				else if(opt[2]!='\0'){
					printf(USAGE);
					return(EXIT_SUCCESS);
				}
				else{
					mode[0] = 'v';
						mode[1] = 'e';
							mode[2] = 'r';
								mode[3] = 'b';
									mode[4] = 'o';
										mode[5] = 's';
											mode[6] = 'e';
												mode[7] = '\0';
				}
			}	
		}
	}
	// free up the space used for opt
	free(opt);	
	opt = NULL;

	int** B;	// This is a pointer to an int pointer

	//	Allocate enough space for a n+1xn+1 int matrix
	B = calloc(n+1, sizeof(int*));
	for(i=0;i<n+1;i++){
		B[i] = calloc(n+1, sizeof(int));
	}

	initBoard(B, n);	// Initialize board

	// Set row number to 1
	i=1;

	int cumSum;	// Initialize counter
	cumSum = findSolutions(B,n,i,mode);

	printf("%d-Queens has %d solutions\n",n,cumSum);

	// Free memory allocated for B
	for(i=0;i<n+1;i++){
		free(B[i]);
	}
	free(B);



	return EXIT_SUCCESS;
}
#-----------------------------------------------------------------------------------------------
# Author:	Midori Kanuma
# CruzID:	mkanuma
# Class:	CMPS12B/M
# Date:		7/20/2019
# Description:	Makefile for Queens.c with macros
# 
# Macros Usage:	make:		Compiles the files specified Makefile
# 		make clean:	Remove the executable files
# 		make submit:	Submit the files specified in Makefile
#		make check:	List the contents of directory to check the status of submission
#-----------------------------------------------------------------------------------------------

ASSIGNMENT = pa2
EXEBIN     = Queens
SOURCES    = $(EXEBIN).c
OBJECTS    = $(EXEBIN).o
FLAGS      = -std=c99 -Wall
FILES      = Makefile $(SOURCES)
SUBMIT     = submit cmps012b-pt.u19 $(ASSIGNMENT)
CHECK      = ls /afs/cats.ucsc.edu/class/cmps012b-pt.u19/$(ASSIGNMENT)/mkanuma

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS) 

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

memcheck:
	valgrind --leak-check=full $(EXEBIN) 5

clean:
	rm -f $(EXEBIN) $(OBJECTS)

submit: $(FILES)
	$(SUBMIT) $(FILES)

check:			
	$(CHECK)    


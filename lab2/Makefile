#-----------------------------------------------------------------------------------------------
# Author:	Midori Kanuma
# CruzID:	mkanuma
# Class:	CMPS12B/M
# Date:		7/10/2019
# Description:	Makefile for charType.c with macros
# 
# Macros Usage:	make:		Compiles the files specified Makefile
# 		make clean:	Remove the executable files
# 		make submit:	Submit the files specified in Makefile
#		make check:	List the contents of directory to check the status of submission
#-----------------------------------------------------------------------------------------------

ASSIGNMENT = lab2
EXEBIN     = charType
OUT	   = out
SOURCES    = $(EXEBIN).c
OBJECTS    = $(EXEBIN).o
FLAGS      = -std=c99 -Wall
FILES      = README Makefile $(SOURCES)
SUBMIT     = submit cmps012b-pt.u19 $(ASSIGNMENT)
CHECK      = ls /afs/cats.ucsc.edu/class/cmps012b-pt.u19/$(ASSIGNMENT)/mkanuma

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS) 

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean:
	rm -f $(EXEBIN) $(OBJECTS) $(OUT)

memcheck:
	cp in in1;
	cp charType.c in;
	valgrind --leak-check=full $(EXEBIN) in out;
	cp in1 in;
	rm in1

submit: $(FILES)
	$(SUBMIT) $(FILES)

check:			
	$(CHECK)    


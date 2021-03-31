#-----------------------------------------------------------------------------------------------
# Author:	Midori Kanuma
# CruzID:	mkanuma
# Class:	CMPS12B/M
# Date:		7/3/2019
# Description:	Makefile for Subset.c with macros
# 
# Macros Usage:	make:		Compiles the files specified Makefile
# 		make clean:	Remove the executable files
# 		make submit:	Submit the files specified in Makefile
#		make check:	List the contents of directory to check the status of submission
#-----------------------------------------------------------------------------------------------

ASSIGNMENT = pa1
EXEBIN     = Subset
SOURCES    = $(EXEBIN).c
OBJECTS    = $(EXEBIN).o
FLAGS      = -std=c99 -Wall
FILES      = README Makefile $(SOURCES)
SUBMIT     = submit cmps012b-pt.u19 $(ASSIGNMENT)
CHECK      = ls /afs/cats.ucsc.edu/class/cmps012b-pt.u19/$(ASSIGNMENT)/mkanuma

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)

submit: $(FILES)
	$(SUBMIT) $(FILES)

check:
	$(CHECK)    


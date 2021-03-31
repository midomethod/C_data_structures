#-----------------------------------------------------------------------------------------------
# Author:	Midori Kanuma
# CruzID:	mkanuma
# Class:	CMPS12B/M
# Date:		7/20/2019
# Description:	Makefile for Lab3 with macros
# 
# Macros Usage:	make:		Compiles the files specified Makefile
# 		make clean:	Remove the executable files
# 		make submit:	Submit the files specified in Makefile
#		make check:	List the contents of directory to check the status of submission
#-----------------------------------------------------------------------------------------------

ASSIGNMENT  = Lab3
CLIENT		= IntegerStackTest
ADT 		= IntegerStack
SOURCE 		= $(CLIENT).c
OBJECT 		= $(CLIENT).o
ADT_SOURCE 	= $(ADT).c
ADT_OBJECT	= $(ADT).o
ADT_HEADER	= $(ADT).h
COMPILE 	= gcc -c -std=c99 -Wall
LINK  		= gcc -o
REMOVE   	= rm -f
MEMCHECK   	= valgrind --leak-check=full
FILES     	= Makefile $(SOURCE) README $(ADT_HEADER) $(ADT_SOURCE)
SUBMIT     	= submit cmps012b-pt.u19 $(ASSIGNMENT)
CHECK      	= ls /afs/cats.ucsc.edu/class/cmps012b-pt.u19/$(ASSIGNMENT)/mkanuma


$(CLIENT) : $(OBJECT) $(ADT_OBJECT) 
	$(LINK) $(CLIENT) $(OBJECT) $(ADT_OBJECT) 

$(OBJECT) : $(SOURCE) $(ADT_HEADER) 
	$(COMPILE) $(SOURCE)

$(ADT_OBJECT) : $(ADT_SOURCE) $(ADT_HEADER)
	$(COMPILE) $(ADT_SOURCE)

clean :
	$(REMOVE) $(CLIENT) $(OBJECT) $(ADT_OBJECT) 

memcheck : $(CLIENT)
	$(MEMCHECK) $(CLIENT)

submit: $(FILES)
	$(SUBMIT) $(FILES)

check:			
	$(CHECK)    

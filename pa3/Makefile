#------------------------------------------------------------------------------
# Makefile for any client of any ADT in C
#------------------------------------------------------------------------------

ASSIGNMENT	   = pa3
CLIENT         = DictionaryClient2
ADT            = Dictionary
SOURCE         = $(CLIENT).c
OBJECT         = $(CLIENT).o
ADT_SOURCE     = $(ADT).c
ADT_OBJECT     = $(ADT).o
ADT_HEADER     = $(ADT).h
COMPILE        = gcc -c -std=c99 -Wall
LINK           = gcc -o
REMOVE         = rm -f
MEMCHECK       = valgrind --leak-check=full
SUBMIT     	= submit cmps012b-pt.u19 $(ASSIGNMENT)
FILES     	= Makefile $(SOURCE) README $(ADT_HEADER) $(ADT_SOURCE)
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
	$(MEMCHECK) ./$(CLIENT)

submit: $(FILES)
	$(SUBMIT) $(FILES)


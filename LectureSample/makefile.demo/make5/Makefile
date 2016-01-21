#make5

all: myapp

.SUFFIXES:	.cpp

.c.o:
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $<
#  $@ full name of current target
#  $? list of modified dependencies
#  $< each modified dependency 
#  $* name of the target file minus the suffix (.c)

# Which compiler
CC=gcc

# Where to install
INSTDIR=~/local/bin

# Where are include files kept
INCLUDE=.

# Options for development
CFLAGS=-g -Wall -ansi 

# Options for release
# CFLAGS=-O -Wall -ansi


myapp: main.o 2.o 3.o 4.o
#	$(CC) -o $@ $^
	$(CC) -o $@ $?

main.o: main.c a.h
2.o: 2.c a.h b.h
3.o: 3.c b.h c.h

clean:
	-rm -f main.o 2.o 3.o myapp *~

install: myapp
	@if [ -d $(INSTDIR) ]; \
		then \
		cp myapp $(INSTDIR);\
		chmod a+x $(INSTDIR)/myapp;\
		chmod og-w $(INSTDIR)/myapp;\
		echo "Installed in $(INSTDIR)";\
	else \
		echo "Sorry, $(INSTDIR) does not exist";\
	fi






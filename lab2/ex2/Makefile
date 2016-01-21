# Write make file for lab2_ex1

# The ultimate output file.
all: filecopy

# Which complier set (you can change it when using make, default is 'gcc')
CC=gcc

# Options
CFLAGS=-g -Wall

filecopy: filecopy.o
	$(CC) -o filecopy filecopy.o

filecopy.o: filecopy.c
	$(CC) $(CFLAGS) -c filecopy.c

# '*~' is the backup file
clean:
	rm -f filecopy.o filecopy *~


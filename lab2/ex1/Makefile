# Write make file for lab2_ex1

# The ultimate output file.
all: my_stat

# Which complier set (you can change it when using make, default is 'gcc')
CC=gcc

# Options
CFLAGS=-g -Wall

my_stat: my_stat.o
	$(CC) -o my_stat my_stat.o

my_stat.o: my_stat.c
	$(CC) $(CFLAGS) -c my_stat.c

# '*~' is the backup file
clean:
	rm -f my_stat.o my_stat *~


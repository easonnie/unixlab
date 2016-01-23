CC = gcc
LD = gcc

CFLAGS = -Wall -g

#the following is a SUFFIX RULE
%.o: %.c
	$(CC) $(CFLAGS) -c $<

#the following are MACROS
LINKFLAGS = -g -static 
PROG_OBJS = hello.o
RM = rm -rf
PROG = hello
LIBS = -lc -L. -l$(PROG)
LIB_FILES = libhello.a
LIB_OBJS = libhello.o

#the following is a TARGET
all: $(LIB_FILES) $(PROG)
#all: $(LIB_FILES) 

#create the library with this RULE:
libhello.a: libhello.o
	ar rcs $(LIB_FILES) $<

#create the program with this RULE:
$(PROG) : $(PROG_OBJS) $(LIB_FILES)
	$(LD) $(LDFLAGS) $(PROG_OBJS) $(LIBS) -o $(PROG)

#clean up the files with this RULE:
clean:
	$(RM) $(PROG_OBJS) $(PROG) $(LIB_OBJS) $(LIB_FILES) $(PROG_OBJS) 


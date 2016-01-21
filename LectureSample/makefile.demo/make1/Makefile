#make1

myapp: main.o 2.o 3.o 
	gcc -Wall -o myapp main.o 2.o 3.o

2.o: 2.c a.h b.h
	gcc -Wall -c 2.c

3.o: 3.c b.h c.h
	gcc -Wall -c 3.c

main.o: main.c a.h
	gcc -Wall -c main.c






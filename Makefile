CFLAGS = -std=c99 -Wall
CC = gcc

pt2: main.o testfunc.o mede.o
	$(CC) $(CFLAGS) main.o testfunc.o -o pt2

main.o: main.c
	$$(CC) $(CFLAGS) -c main.c

mede.o: mede.c mede.h
	$(CC) $(CFLAGS) -c mede.c

testfunc.o: testfunc.c testfunc.h
	$$(CC) $(CFLAGS) -c testfunc.c

clean:
	rm -f pt2 *.o

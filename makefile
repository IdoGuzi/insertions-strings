CC=gcc
AR=ar
FLAGs = -Wall -g

all: insort isort

isort: main.o insort
	$(CC) $(FLAGS) -o isort main.o libinsertion.a

insort: libinsertion.a
libinsertion.a: insertion.o
	$(AR) -rcs libinsertion.a insertion.o

insertion.o: insertion.c insertion.h
	$(CC) -fPIC $(FLAGS) -c insertion.c

main.o: main.c
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all 

clean:
	-rm -f *.o *.a isort
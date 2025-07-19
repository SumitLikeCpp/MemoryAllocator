flags=-O2 -Wall -std=c11
ldflags=

.PHONY: clean

all: alloc

alloc: alloc.o heap.o
	cc ${flags} $^ -o $@ ${ldflags}

alloc.o: alloc.c alloc.h
	cc ${flags} -c $<

heap.o: heap.s
	as -o $@ $<

clean:
	rm -f *.o alloc

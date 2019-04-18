all: sample

sample: main.o avl.o
	g++ main.o avl.o -o sample

main.o: main.cpp
	g++ -c main.cpp

avl.o: avl.cpp
	g++ -c avl.cpp

clean:
	rm *o sample
all: sample

sample: main.o class.o
	g++ main.o class.o -o sample

main.o: main.cpp
	g++ -c main.cpp

class.o: class.cpp
	g++ -c class.cpp

clean:
	rm *o sample
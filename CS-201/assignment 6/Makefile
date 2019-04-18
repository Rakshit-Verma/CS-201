all: sample

sample: main.o graph.o
	g++ main.o graph.o -o sample

main.o: main.cpp
	g++ -c main.cpp

graph.o: graph.cpp
	g++ -c graph.cpp

clean:
	rm *o sample
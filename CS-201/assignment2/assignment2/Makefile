all: sample

sample: main.o item.o list.o
	g++ main.o item.o list.o -o sample

main.o: main.cpp
	g++ -g -c main.cpp

list.o: list.cpp
	g++ -g -c list.cpp

item.o: item.cpp
	g++ -g -c item.cpp


clean:
	rm *o sample

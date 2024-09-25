DEBUG = -c -std=c++17

run: build
	./out 

build: Comparator.o EightBitAdder.o FullAdder.o main.o 
	g++ -Wall -g -o out Comparator.o EightBitAdder.o FullAdder.o main.o 

Comparator.o: Comparator.h Comparator.cpp 
	g++ $(DEBUG) Comparator.cpp

EightBitAdder.o: EightBitAdder.h EightBitAdder.cpp 
	g++ $(DEBUG) EightBitAdder.cpp

FullAdder.o: FullAdder.h FullAdder.cpp 
	g++ $(DEBUG) FullAdder.cpp

main.o: main.cpp 
	g++ $(DEBUG) main.cpp

.PHONY: clean
clean:
	rm -f *.o out
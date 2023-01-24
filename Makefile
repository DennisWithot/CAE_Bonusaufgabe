all: main

 

main:  main.o
	g++ -o main main.o firma.o

 

main.o: main.cpp
	g++ -c -Wall -o main.o main.cpp

 

firma.o: firma.cpp firma.h
	g++ -c -Wall -o firma.o firma.cpp
	
all: main clean

 

main:   maschfirma.o mitarbeiter.o intervall.o  wartungsplan.o main.o
	g++ -o main main.o mitarbeiter.o intervall.o maschfirma.o wartungsplan.o -std=c++17

 

main.o: main.cpp 
	g++ -c main.cpp 

 
mitarbeiter.o: mitarbeiter.h mitarbeiter.cpp
	g++ -c mitarbeiter.cpp 
	
#firma.o: firma.h firma.cpp
#	g++ -c firma.cpp 

maschfirma.o: maschfirma.h maschfirma.cpp
	g++ -c maschfirma.cpp 
	
intervall.o: intervall.h intervall.cpp
	g++ -c intervall.cpp 

#maschine.o: maschine.h maschine.cpp
#	g++ -c maschine.cpp 


wartungsplan.o: wartungsplan.h wartungsplan.cpp
	g++ -c wartungsplan.cpp 

clean:
	del main.o maschine.o intervall.o firma.o mitarbeiter.o wartungsplan.o
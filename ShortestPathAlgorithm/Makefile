#Makefile for p4
#COSC160

p4: p4.out
	
p4.out: p4.o Graph.o 
	g++ -std=c++11 p4.o Graph.o

p4.o: p4.cpp p4.h Graph.h
	g++ -std=c++11 -c p4.cpp

Graph.o: Graph.cpp Graph.h
	g++ -std=c++11 -c Graph.cpp 
	
submit:
	rm -f submit.zip
	zip submit.zip p4.cpp p4.h Graph.cpp Graph.h Makefile

clean:
	rm -f *.o core p4.out
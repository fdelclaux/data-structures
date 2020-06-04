#Makefile for p2
#COSC160

p2: p2.out
	
p2.out: p2.o BST.o ST.o
	g++ -std=c++11 p2.o BST.o ST.o

p2.o: p2.cpp p2.h BST.h ST.h
	g++ -std=c++11 -c p2.cpp

BST.o: BST.cpp BST.h
	g++ -std=c++11 -c BST.cpp 

ST.o: ST.cpp ST.h
	g++ -std=c++11 -c ST.cpp
	

submit:
	rm -f submit.zip
	zip submit.zip p2.cpp p2.h BST.cpp BST.h ST.cpp ST.h Makefile

clean:
	rm -f *.o core p2.out
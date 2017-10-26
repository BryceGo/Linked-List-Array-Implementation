all: Test

Test: Test.o list.o
	gcc -o Test Test.o list.o
	
Test.o: Test.c list.h
	gcc -o Test.o -c Test.c
	
list.o: list.c list.h
	gcc -o list.o -c list.c

clean: 
	rm -f Test *.o

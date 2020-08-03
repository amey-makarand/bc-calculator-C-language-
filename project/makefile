all: project

project: begin.o oper.o main2.o
	cc begin.o oper.o main2.o -o project

begin.o: begin.c begin.h oper.h 
	cc -c begin.c

oper.o: oper.c oper.h begin.h 
	cc -c oper.c

main2.o: main2.c oper.h begin.h 
	cc -c main2.c

clean:
	rm -rf *.o project

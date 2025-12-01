a.out: main.o addition.o division.o multiplication.o functions.o subtraction.o
	gcc -o a.out main.o addition.o division.o multiplication.o functions.o subtraction.o

main.o: main.c
	gcc -c main.c

addition.o: addition.c
	gcc -c addition.c

division.o: division.c
	gcc -c division.c

multiplication.o: multiplication.c
	gcc -c multiplication.c

functions.o: functions.c
	gcc -c functions.c

subtraction.o: subtraction.c
	gcc -c subtraction.c

clean:
	rm -f *.o a.out

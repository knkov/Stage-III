 OPT = -O4 				

default: bandwidth

bandwidth: bandwidth.o 
	gcc $(OPT) -o bandwidth bandwidth.o

bandwidth.o: bandwidth.c
	gcc $(OPT) -c bandwidth.c


clean:
	rm -f *.o
	rm -f bandwidth


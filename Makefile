all:	lib.o app

lib.o:	lib.h lib.c
	gcc -c lib.c -o lib.o

app:	lib.o main.c
	gcc -o app lib.o main.c

clean:	tsmart-clean
	rm -f *.o app

tsmart-clean:
	rm -f *.ll *.log
	rm -rf bcmake_logs
	rm -rf bcmake_outputs


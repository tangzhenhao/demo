all: app

app: 1.o npd.o double_free.o div_by_zero.o main.o
	$(CC) -o $@ $^

clean: tsmart-clean
	rm -f *.o app

tsmart-clean:
	rm -f *.ll *.log
	rm -rf bcmake_logs
	rm -rf bcmake_outputs


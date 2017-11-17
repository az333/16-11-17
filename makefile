all: fork.c
	gcc fork.c

run: all
	./a.out

clean:
	rm *.out
	rm *~

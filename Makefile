all: compile run

compile:
	gcc -l SDL3 main.c -o HyprBar

run:
	./HyprBar

clean:
	rm HyprBar

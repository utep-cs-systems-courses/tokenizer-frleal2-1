all: files

files: ui.o tokenizer.o history.o
	gcc ui.o tokenizer.o history.o -o program

tokenizer.o: tokenizer.c
	gcc -c tokenizer.c

history.o: history.c
	gcc -c history.c

ui.o: ui.c
	gcc -c ui.c

clean:
	-rm *o program

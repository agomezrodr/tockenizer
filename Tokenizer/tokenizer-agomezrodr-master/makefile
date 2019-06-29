

all: compile

compile: tokenize.o interface.o history.o
	cc tokenize.o interface.o history.o -o compile

history.o: history.c history.h
	cc -c history.c

interface.o: interface.c tokenize.o tokenizer.h
	cc -c interface.c

tokenizer.o: tokenize.c
	cc -c tokenize.c

clear: rm *f compile

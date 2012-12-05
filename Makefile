#build our flex/bison logfile to R converter
.DEFAULT_GOAL = all

strbuilder_test: strbuilder.c strbuilder_test.c strbuilder.h
	gcc -o $@ strbuilder.c strbuilder_test.c

%.yy.c: %.l %.tab.h
	flex -o $@ $<

%.y.DONE: %.y
	bison -d -v $<
	touch $@

%.tab.c: %.y %.y.DONE
	true

%.tab.h: %.tab.c %.y.DONE
	true

%.o: %.c
	gcc -c -o $@ $<

logfile: logfile.yy.c logfile.tab.c strbuilder.o
	gcc -o $@ $^ -lfl

#this produces a tiny test program that just shows the operation of the lexer.
%.lexer: %.yy.c
	gcc -o $@ $^ -lfl -D TOKEN_TEST

all: logfile logfile.lexer strbuilder_test

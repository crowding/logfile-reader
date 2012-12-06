#build our flex/bison logfile to R converter
.DEFAULT_GOAL = all

strbuilder_test: strbuilder.c strbuilder_test.c strbuilder.h
	gcc -o $@ strbuilder.c strbuilder_test.c

%.yy.c: %.l %.tab.h
	flex -o $@ $<

%.y.DONE: %.y
	bison -d -v $<
	touch $@

%.tab.c: %.y %.tab.h %.y.DONE
	true

%.tab.h: %.y.DONE
	true

%.o: %.c
	gcc -c -o $@ $<

logfile: logfile.yy.c logfile.tab.c strbuilder.o
	gcc -o $@ $^ -lfl

#this produces a tiny test program that just shows the operation of the lexer.
%.lexer: %.yy.c
	gcc -o $@ $^ -lfl -D TOKEN_TEST

example.translated: example.data logfile
	./logfile < $< > $@

example.RData: example.data readR.R logfile
	Rscript readR.R $< $@

all: logfile logfile.lexer strbuilder_test example.translated example.RData

clean:
	git clean -dfx

calc: lex.yy.o calc.tab.o
			gcc lex.yy.o calc.tab.o -o calc

lex.yy.c: calc.l calc.tab.h
			flex calc.l

calc.tab.c calc.tab.h: calc.y
			bison -d calc.y

lex.yy.o: lex.yy.c
			gcc -c lex.yy.c
			
calc.tab.o: calc.tab.c
			gcc -c calc.tab.c

clean:
			rm lex.yy.o calc.tab.o calc lex.yy.c calc.tab.c calc.tab.h
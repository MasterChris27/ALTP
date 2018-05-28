compiler: rule.y compiler.l
	/home/boza/bison/bin/bison -d -v rule.y
	./flex compiler.l
	gcc -std=c99 -o compiler rule.tab.c lex.yy.c libfl.a 

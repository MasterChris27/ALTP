compiler: rule.y compiler.l
	/home/boza/bison/bin/bison -d -v rule.y
	./flex compiler.l
	gcc -o compiler rule.tab.c lex.yy.c libfl.a

parser: lex.l parser.y
	bison -d parser.y
	flex lex.l 
	gcc -o bin/$@ parser.tab.c lex.yy.c ast.c -lfl
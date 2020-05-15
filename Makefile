parser: lex.l parser.y
	bison -d parser.y
	flex lex.l 
	gcc -o bin/$@ parser.tab.c utils.c lex.yy.c ast.c -lfl
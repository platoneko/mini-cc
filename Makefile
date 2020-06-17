mini-cc:
	bison -d -v parser.y
	flex lex.l 
	g++ parser.tab.c utils.c lex.yy.c ast.c analysis.cpp tac.cpp genmips.cpp -lfl -o bin/$@ 
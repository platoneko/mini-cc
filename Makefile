mini-cc: lex.l parser.y
	bison -d -v parser.y
	flex lex.l 
	g++ -g parser.tab.c utils.c lex.yy.c ast.c analysis.cpp tac.cpp -lfl -o bin/$@ 
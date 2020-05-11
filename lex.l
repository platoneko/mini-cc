%{
#include "parser.tab.h"

#include <string.h>
#include <unistd.h>
%}

%option yylineno  noyywrap

id   	[A-Za-z_][A-Za-z0-9_]*  
int    	[0-9]+
float  	([0-9]*\.[0-9]+)|([0-9]+\.)

%%
{int}		{ yylval.type_int=atoi(yytext); return INT; }
{float}     { yylval.type_float=atof(yytext); return FLOAT; }
"int"       { strcpy(yylval.type_id, yytext); return TYPE; }
"float"		{ strcpy(yylval.type_id, yytext); return TYPE; }

"return"    { return RETURN; }
"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }

{id}       	{ strcpy(yylval.type_id, yytext); return ID; }
";"			{ return SEMI; }
","			{ return COMMA; }
"=="|"!="|">="|"<="|">"|"<"	{ strcpy(yylval.type_id, yytext); return RELOP; }

"="			{ return ASSIGNOP; }
"+"			{ return PLUS; }
"-"			{ return MINUS; }
"*"			{ return STAR; }
"/"			{ return DIV; }
"%"			{ return MOD; }

"++"		{ return DPLUS; }
"--"		{ return DMINUS; }

"&&"        { return AND; }
"||"        { return OR; }
"!"			{ return NOT; }
"("			{ return LP; }
")"			{ return RP; }
"{"			{ return LC; }
"}"			{ return RC; } 
[ \r\n\t]   {}
.			{ printf("Lex Error: Mysterious character \"%s\" at Line %d\n", yytext, yylineno); }

#ifndef __DEF_H__
#define __DEF_H__
#include "parser.tab.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

//以下对结点属性定义没有考虑存储效率，只是简单地列出要用到的一些属性
struct ASTNode {
	union {
		char type_id[32];                   //由标识符生成的叶结点
		int type_int;                       //由整常数生成的叶结点
		float type_float;                   //由浮点常数生成的叶结点
	};
    struct ASTNode *ptr[3];
	int kind;
	int pos;
	int type;            
};

struct Symbol {
	char name[32];
	int lev;
	int param;
	int type;
	char flag;
};

struct ASTNode *mknode(int num, int kind, int pos, ...);
void display(struct ASTNode *T, int indent);

void analysis(struct ASTNode *T);
#endif
#include "def.h"

#include <vector>
#include <stack>
#include <string>
#include <map>

using namespace std;

extern vector<Symbol *> symbolTab;
extern map<string, int> funcTab;
extern vector<Array *> arrayTab;
static stack<char *> beginStack;        // Warning!
static stack<char *> nextStack;         // Warning!


void displayTAC(TACNode *head) {
    if (head == NULL) return;
    TACNode *node = head;
    char op[3];
    do {
        switch (node->op) {
        case EQ:
            strcpy(op, "=="); break;
        case NEQ:
            strcpy(op, "!="); break;
        case GT:
            strcpy(op, ">"); break;
        case GE:
            strcpy(op, ">="); break;
        case LT:
            strcpy(op, "<"); break;
        case LE:
            strcpy(op, "<="); break;
        case PLUS:
            strcpy(op, "+"); break;
        case MINUS:
            strcpy(op, "-"); break;
        case STAR:
            strcpy(op, "*"); break;
        case DIV:
            strcpy(op, "/"); break;
        case MOD:
            strcpy(op, "%"); break;
        case BITAND:
            strcpy(op, "&"); break;
        case BITOR:
            strcpy(op, "|"); break;
        case BITXOR:
            strcpy(op, "^"); break;
        case BITSHL:
            strcpy(op, "<<"); break;
        case BITSHR:
            strcpy(op, ">>"); break;
        default:
            break;
        }
        switch (node->op) {
        case LABEL:
            printf("label %s:\n", node->result.label);
            break;
        case GOTO:
            printf("  goto %s\n", node->result.label);
            break;
        case ASSIGNOP:
            if (node->opn1.kind == FLOAT)
                printf("  %s := %f\n", symbolTab[node->result.place]->alias, node->opn1.const_float);
            else if (node->opn1.kind == INT)
                printf("  %s := %d\n", symbolTab[node->result.place]->alias, node->opn1.const_int);
            else
                printf("  %s := %s\n", symbolTab[node->result.place]->alias, symbolTab[node->opn1.place]->alias);
            break;
        case FUNC:
            printf("function %s:\n", symbolTab[node->result.place]->name);
            break;
        case PARAM:
            printf("  param %s\n", symbolTab[node->result.place]->alias);
            break;
        case RETURN:
            if (node->result.kind == FLOAT)
                printf("  return %f\n", node->result.const_float);
            else if (node->result.kind == INT)
                printf("  return %d\n", node->result.const_int);
            else if (node->result.kind == VAR)
                printf("  return %s\n", symbolTab[node->result.place]->alias);
            else 
                printf("  return\n");
            break;
        case EQ:
        case NEQ:
        case GT:
        case GE:
        case LT:
        case LE:
            printf("  if ");
            if (node->opn1.kind == INT)
                printf("%d", node->opn1.const_int);
            else if (node->opn1.kind == FLOAT)
                printf("%f", node->opn1.const_float);
            else
                printf("%s", symbolTab[node->opn1.place]->alias);
            printf(" %s ", op);
            if (node->opn2.kind == INT)
                printf("%d", node->opn2.const_int);
            else if (node->opn2.kind == FLOAT)
                printf("%f", node->opn2.const_float);
            else
                printf("%s", symbolTab[node->opn2.place]->alias);
            printf(" goto %s\n", node->result.label);
            break;
        case PLUS:
        case MINUS:
        case STAR:
        case DIV:
            printf("  %s := ", symbolTab[node->result.place]->alias);
            if (node->opn1.kind == INT)
                printf("%d", node->opn1.const_int);
            else if (node->opn1.kind == FLOAT)
                printf("%f", node->opn1.const_float);
            else
                printf("%s", symbolTab[node->opn1.place]->alias);
            printf(" %s ", op);
            if (node->opn2.kind == INT)
                printf("%d\n", node->opn2.const_int);
            else if (node->opn2.kind == FLOAT)
                printf("%f\n", node->opn2.const_float);
            else
                printf("%s\n", symbolTab[node->opn2.place]->alias);
            break;
        case MOD:
        case BITAND:
        case BITOR:
        case BITXOR:
        case BITSHL:
        case BITSHR:
            printf("  %s := ", symbolTab[node->result.place]->alias);
            if (node->opn1.kind == INT)
                printf("%d", node->opn1.const_int);
            else
                printf("%s", symbolTab[node->opn1.place]->alias);
            printf(" %s ", op);
            if (node->opn2.kind == INT)
                printf("%d\n", node->opn2.const_int);
            else
                printf("%s\n", symbolTab[node->opn2.place]->alias);
            break;
        case UMINUS:
            printf("  %s := - ", symbolTab[node->result.place]->alias);
            if (node->opn1.kind == INT)
                printf("%d\n", node->opn1.const_int);
            else if (node->opn1.kind == FLOAT)
                printf("%f\n", node->opn1.const_float);
            else
                printf("%s\n", symbolTab[node->opn1.place]->alias);
            break;
        case FUNC_CALL:
            if (node->result.kind == VAR)
                printf("  %s := call %s\n", symbolTab[node->result.place]->alias, symbolTab[node->opn1.place]->name);
            else
                printf("  call %s\n", symbolTab[node->opn1.place]->name);
            break;
        case ARG:
            if (node->result.kind == INT)
                printf("  arg %d\n", node->result.const_int);
            else if (node->result.kind == FLOAT)
                printf("  arg %f\n", node->result.const_float);
            else
                printf("  arg %s\n", symbolTab[node->result.place]->alias);
            break;
        case RARRAY_REF:
            if (node->opn2.kind == INT)
                printf("  %s := %s[%d]\n", symbolTab[node->result.place]->alias, symbolTab[node->opn1.place]->alias, node->opn2.const_int);
            else
                printf("  %s := %s[%s]\n", symbolTab[node->result.place]->alias, symbolTab[node->opn1.place]->alias, symbolTab[node->opn2.place]->alias);
            break;
        case LARRAY_REF:
            if (node->opn2.kind == INT)
                printf("  %s[%d] := ", symbolTab[node->opn1.place]->alias, node->opn2.const_int);
            else
                printf("  %s[%s] := ", symbolTab[node->opn1.place]->alias, symbolTab[node->opn2.place]->alias);
            if (node->result.kind == INT)
                printf("%d\n", node->result.const_int);
            else if (node->result.kind == FLOAT)
                printf("%f\n", node->result.const_float);
            else
                printf("%s\n", symbolTab[node->result.place]->alias);
            break;
        }
        node = node->next;
    } while (node != head);
}

static TACNode *merge(int num, ...) {
    va_list pArgs;
    va_start(pArgs, num);
    TACNode *head1, *head2, *tail1, *tail2;
    int i = 1;
    while ((head1 = va_arg(pArgs, TACNode *)) == NULL && i < num) ++i;
    for (; i<num; ++i) {
        head2 = va_arg(pArgs, TACNode *);
        if (head2 == NULL)
            continue;
        tail1 = head1->prior;
        tail2 = head2->prior;
        tail1->next = head2;
        tail2->next = head1;
        head1->prior = tail2;
        head2->prior = tail1;
    }
    return head1;
}

static void newLabel(char *label) {
    static int cnt = 0;
    sprintf(label, "L%d", cnt);
    cnt++;
}

static int newTemp(int type) {
    static int cnt = 0;
    Symbol *symbol = new Symbol();
    sprintf(symbol->alias, "T%d", cnt);
    symbol->type = type;
    symbol->flag = 'T';
    symbol->offset = -1;
    symbolTab.push_back(symbol);
    cnt++;
    return symbolTab.size() - 1;
}

static TACNode *gen(int op, Opn opn1, Opn opn2, Opn result) {
    TACNode *node = new TACNode();
    node->op = op;
    node->opn1 = opn1;
    node->opn2 = opn2;
    node->result = result;
    node->next = node->prior = node;
    return node;
}

static TACNode *genLabel(char *label) {
    TACNode *node = new TACNode();
    node->op = LABEL;
    node->result.kind = LABEL;
    strcpy(node->result.label, label);
    node->next = node->prior = node;
    return node;
}

static TACNode *genGoto(char *label) {
    TACNode *node = new TACNode();
    node->op = GOTO;
    node->result.kind = LABEL;
    strcpy(node->result.label, label);
    node->next = node->prior = node;
    return node;
}

static Opn genArrayOffset(ASTNode *T) {
    ASTNode *T0;
    Opn opn1, opn2, result;
    int offset = 0, dim = symbolTab[T->place]->dim;
    T0 = T->ptr[0];
    for (int i = 0; i < dim; ++i) {
        if (T0->ptr[0]->kind == INT) {
            offset += T0->ptr[0]->type_int * arrayTab[symbolTab[T->place]->ref+i]->elsize;
        } else {
            genTAC(T0->ptr[0]);
            T->code = merge(2, T->code, T0->ptr[0]->code);
        }
        T0 = T0->ptr[1];
    }
    T0 = T->ptr[0];
    int temp0 = -1;
    for (int i = 0; i < dim; ++i) {
        if (T0->ptr[0]->kind != INT) {
            TACNode *code1, *code2;
            int temp1, temp2;
            temp1 = newTemp(INT);
            result.kind = VAR;
            result.place = temp1;
            opn1.kind = VAR;
            opn1.place = T0->ptr[0]->place;
            opn2.kind = INT;
            opn2.const_int = arrayTab[symbolTab[T->place]->ref+i]->elsize;
            code1 = gen(STAR, opn1, opn2, result);
            if (temp0 != -1) {
                temp2 = newTemp(INT);
                result.kind = VAR;
                result.place = temp2;
                opn1.kind = VAR;
                opn1.place = temp0;
                opn2.kind = VAR;
                opn2.place = temp1;
                code2 = gen(PLUS, opn1, opn2, result);
                temp0 = temp2;
                T->code = merge(3, T->code, code1, code2);
            } else {
                temp0 = temp1;
                T->code = merge(2, T->code, code1);
            }
        }
        T0 = T0->ptr[1];
    }
    if (temp0 != -1) {
        if (offset != 0) {
            int temp1 = newTemp(INT);
            result.kind = VAR;
            result.place = temp1;
            opn1.kind = VAR;
            opn1.place = temp0;
            opn2.kind = INT;
            opn2.const_int = offset;
            T->code = merge(2, T->code, gen(PLUS, opn1, opn2, result));
            return result;
        } else {
            return result;
        }
    } else {
        result.kind = INT;
        result.const_int = offset;
        return result;
    }
}

static void genVarDec(ASTNode *T) {
    //T->ptr[0] maybe NULL
    if (T->ptr[0]) {            //ID ASSIGNOP EXP
        Opn opn1, result;
        result.kind = VAR;
        result.place = T->place;
        if (T->ptr[0]->kind == T->ptr[0]->type) {
            opn1.kind = T->ptr[0]->type;
            if (T->ptr[0]->type == FLOAT) {
                opn1.const_float = T->ptr[0]->type_float;
            } else {
                opn1.const_int = T->ptr[0]->type_int;
            }
        } else {
            genTAC(T->ptr[0]);  //EXP
            opn1.kind = VAR;
            opn1.place = T->ptr[0]->place;
        }
        T->code = merge(2, T->ptr[0]->code, gen(ASSIGNOP, opn1, {0,0}, result));
    }
}

static void genFuncDef(ASTNode *T) {
    genTAC(T->ptr[1]);          //FUNC_DEC
    genTAC(T->ptr[2]);          //COMP_STM
    T->code = merge(2, T->ptr[1]->code, T->ptr[2]->code);
    if (T->code->prior->op != RETURN) {
        T->code = merge(2, T->code, gen(RETURN, {0,0}, {0,0}, {0,0}));
    }
}

static void genFuncDec(ASTNode *T) {
    //T->ptr[0] maybe NULL
    Opn result;
    result.kind = FUNC;
    result.place = T->place;
    if (T->ptr[0]) {
        genTAC(T->ptr[0]);      //PARAM_LIST
        T->code = merge(2, gen(FUNC, {0,0}, {0,0}, result), T->ptr[0]->code);
    } else {
        T->code = gen(FUNC, {0,0}, {0,0}, result);
    }
}

static void genParamDec(ASTNode *T) {
    Opn result;
    result.kind = PARAM;
    result.place = T->place;
    T->code = gen(PARAM, {0,0}, {0,0}, result);
}

static void genStmList(ASTNode *T) {
    //T->ptr[0], T->ptr[1] maybe NULL
    if (T->ptr[0]) {
        if (T->ptr[1]) {
            genTAC(T->ptr[0]);  //EXP_STMT, RETURN ...
            genTAC(T->ptr[1]);  //STM_LIST
            T->code = merge(2, T->ptr[0]->code, T->ptr[1]->code);
        } else {
            genTAC(T->ptr[0]);  //EXP_STMT, RETURN ...
            T->code = T->ptr[0]->code;
        }
    } else {
        if (T->ptr[1]) {
            genTAC(T->ptr[1]);  //STM_LIST
            T->code = T->ptr[1]->code;
        } else {
            T->code = NULL;
        }
    }
}

static void genReturn(ASTNode *T) {
    //T->ptr[0] maybe NULL
    Opn result;
    if (T->ptr[0]) {
        if (T->ptr[0]->kind == T->ptr[0]->type) {
            result.kind = T->ptr[0]->type;
            if (T->ptr[0]->type == FLOAT) {
                result.const_float = T->ptr[0]->type_float;
            } else {
                result.const_int = T->ptr[0]->type_int;
            }
            T->code = gen(RETURN, {0,0}, {0,0}, result);
        } else if (T->ptr[0]->type == VOID) {
            genTAC(T->ptr[0]);      //EXP
            T->code = merge(2, T->ptr[0]->code, gen(RETURN, {0,0}, {0,0}, {0,0}));
        } else {
            genTAC(T->ptr[0]);      //EXP
            result.kind = VAR;
            result.place = T->ptr[0]->place;
            T->code = merge(2, T->ptr[0]->code, gen(RETURN, {0,0}, {0,0}, result));
        }
    } else {
        T->code = gen(RETURN, {0,0}, {0,0}, {0,0});
    }
}

static void genIfThen(ASTNode *T) {
    //T->ptr[1] maybe NULL
    char next[8];
    newLabel(next);
    newLabel(T->ptr[0]->Etrue);
    strcpy(T->ptr[0]->Efalse, next);
    genTAC(T->ptr[0]);          //EXP
    if (T->ptr[1]) {
        genTAC(T->ptr[1]);          //STMT
        T->code = merge(4, T->ptr[0]->code, 
                        genLabel(T->ptr[0]->Etrue), 
                        T->ptr[1]->code, 
                        genLabel(next));
    } else {
        T->code = merge(3, T->ptr[0]->code, 
                        genLabel(T->ptr[0]->Etrue), 
                        genLabel(next));
    }
}

static void genIfThenElse(ASTNode *T) {
    //T->ptr[1], T->ptr[2] maybe NULL
    char next[8];
    newLabel(next);
    newLabel(T->ptr[0]->Etrue);
    newLabel(T->ptr[0]->Efalse);
    genTAC(T->ptr[0]);          //EXP
    if (T->ptr[1] && T->ptr[2]) {
        genTAC(T->ptr[1]);          //STMT
        genTAC(T->ptr[2]);          //STMT
        T->code = merge(7, T->ptr[0]->code, 
                        genLabel(T->ptr[0]->Etrue),
                        T->ptr[1]->code,
                        genGoto(next),
                        genLabel(T->ptr[0]->Efalse),
                        T->ptr[2]->code,
                        genLabel(next));
    } else if (T->ptr[1]) {
        genTAC(T->ptr[1]);          //STMT
        T->code = merge(6, T->ptr[0]->code, 
                        genLabel(T->ptr[0]->Etrue),
                        T->ptr[1]->code,
                        genGoto(next),
                        genLabel(T->ptr[0]->Efalse),
                        genLabel(next));
    } else if (T->ptr[2]) {
        genTAC(T->ptr[2]);          //STMT
        T->code = merge(6, T->ptr[0]->code, 
                        genLabel(T->ptr[0]->Etrue),
                        genGoto(next),
                        genLabel(T->ptr[0]->Efalse),
                        T->ptr[2]->code,
                        genLabel(next));
    } else {
        T->code = merge(5, T->ptr[0]->code, 
                        genLabel(T->ptr[0]->Etrue),
                        genGoto(next),
                        genLabel(T->ptr[0]->Efalse),
                        genLabel(next));
    }
}

static void genWhile(ASTNode *T) {
    //T->ptr[1] maybe NULL
    char begin[8], next[8];
    newLabel(next);
    newLabel(begin);
    newLabel(T->ptr[0]->Etrue);
    strcpy(T->ptr[0]->Efalse, next);
    genTAC(T->ptr[0]);          //EXP
    if (T->ptr[1]) {
        nextStack.push(next);
        beginStack.push(begin);
        genTAC(T->ptr[1]);          //STMT
        T->code = merge(6, genLabel(begin),
                        T->ptr[0]->code,
                        genLabel(T->ptr[0]->Etrue),
                        T->ptr[1]->code,
                        genGoto(begin),
                        genLabel(next));
        nextStack.pop();
        beginStack.pop();
    } else {
        T->code = merge(5, genLabel(begin),
                        T->ptr[0]->code,
                        genLabel(T->ptr[0]->Etrue),
                        genGoto(begin),
                        genLabel(next));
    }
}

static void genId(ASTNode *T) {
    Opn opn1, opn2, result;
    if (T->Etrue[0]) {
        opn1.kind = VAR;
        opn1.place = T->place;
        opn2.kind = INT;        
        opn2.const_int = 0;
        result.kind = LABEL;
        strcpy(result.label, T->Etrue);
        T->code = merge(2, gen(NEQ, opn1, opn2, result), genGoto(T->Efalse));
    }
}

static void genAssignop(ASTNode *T) {
    Opn opn1, opn2, result, ropn;
    if (T->ptr[1]->kind == T->ptr[1]->type) {
        ropn.kind = T->ptr[1]->type;
        if (T->ptr[1]->type == FLOAT) {
            ropn.const_float = T->ptr[1]->type_float;
        } else {
            ropn.const_int = T->ptr[1]->type_int;
        }
    } else {
        genTAC(T->ptr[1]);      //EXP
        ropn.kind = VAR;
        ropn.place = T->ptr[1]->place;
    }
    if (T->ptr[0]->kind != ARRAY_REF) {
        result.kind = VAR;
        result.place = T->ptr[0]->place;    //T->place == T->ptr[0]->place
        T->code = merge(2, T->ptr[1]->code, gen(ASSIGNOP, ropn, {0,0}, result));
        T->place = result.place;
    } else {
        Opn offset = genArrayOffset(T->ptr[0]);
        opn1.kind = VAR;
        opn1.place = T->ptr[0]->place;
        result.kind = VAR;
        result.place = newTemp(T->type);
        T->code = merge(5, T->code, T->ptr[1]->code, T->ptr[0]->code,
            gen(LARRAY_REF, opn1, offset, ropn),
            gen(RARRAY_REF, opn1, offset, result));
        T->place = result.place;
    }
    if (T->Etrue[0]) {
        opn1.kind = VAR;
        opn1.place = T->place;
        opn2.kind = INT;        
        opn2.const_int = 0;
        result.kind = LABEL;
        strcpy(result.label, T->Etrue);
        T->code = merge(3, T->code, gen(NEQ, opn1, opn2, result), genGoto(T->Efalse));
    }
}

static void genCompAssign(ASTNode *T) {
    Opn opn1, opn2, result, ropn;
    if (T->ptr[1]->kind == T->ptr[1]->type) {
        ropn.kind = T->ptr[1]->type;
        if (T->ptr[1]->type == FLOAT) {
            ropn.const_float = T->ptr[1]->type_float;
        } else {
            ropn.const_int = T->ptr[1]->type_int;
        }
    } else {
        genTAC(T->ptr[1]);      //EXP
        ropn.kind = VAR;
        ropn.place = T->ptr[1]->place;
    }
    if (T->ptr[0]->kind != ARRAY_REF) {
        result.kind = VAR;
        result.place = T->ptr[0]->place;    //T->place == T->ptr[0]->place
        switch (T->type_id[0]) {
        case '+':
            T->code = merge(2, T->ptr[1]->code, gen(PLUS, result, ropn, result));
            break;
        case '-':
            T->code = merge(2, T->ptr[1]->code, gen(MINUS, result, ropn, result));
            break;
        case '*':
            T->code = merge(2, T->ptr[1]->code, gen(STAR, result, ropn, result));
            break;
        case '/':
            T->code = merge(2, T->ptr[1]->code, gen(DIV, result, ropn, result));
            break;
        case '%':
            T->code = merge(2, T->ptr[1]->code, gen(MOD, result, ropn, result));
            break;
        case '&':
            T->code = merge(2, T->ptr[1]->code, gen(BITAND, result, ropn, result));
            break;
        case '|':
            T->code = merge(2, T->ptr[1]->code, gen(BITOR, result, ropn, result));
            break;
        case '^':
            T->code = merge(2, T->ptr[1]->code, gen(BITXOR, result, ropn, result));
            break;
        case '<':
            T->code = merge(2, T->ptr[1]->code, gen(BITSHL, result, ropn, result));
            break;
        case '>':
            T->code = merge(2, T->ptr[1]->code, gen(BITSHR, result, ropn, result));
            break;
        }
        T->place = T->ptr[0]->place;
    } else {
        int temp1, temp2;
        TACNode *code1, *code2;
        temp1 = newTemp(T->type);
        temp2 = newTemp(T->type);
        Opn offset = genArrayOffset(T->ptr[0]);
        result.kind = VAR;
        result.place = temp1;
        opn1.kind = VAR;
        opn1.place = T->ptr[0]->place;
        code1 = gen(RARRAY_REF, opn1, offset, result);      //T1 := A[offset]
        
        result.kind = VAR;
        result.place = temp2;
        opn1.kind = VAR;
        opn1.place = temp1;
        switch (T->type_id[0]) {                            //T2 := T1 op ropn
        case '+':
            code2 = gen(PLUS, opn1, ropn, result);
            break;
        case '-':
            code2 = gen(MINUS, opn1, ropn, result);
            break;
        case '*':
            code2 = gen(STAR, opn1, ropn, result);
            break;
        case '/':
            code2 = gen(DIV, opn1, ropn, result);
            break;
        case '%':
            code2 = gen(MOD, opn1, ropn, result);
            break;
        case '&':
            code2 = gen(BITAND, opn1, ropn, result);
            break;
        case '|':
            code2 = gen(BITOR, opn1, ropn, result);
            break;
        case '^':
            code2 = gen(BITXOR, opn1, ropn, result);
            break;
        case '<':
            code2 = gen(BITSHL, opn1, ropn, result);
            break;
        case '>':
            code2 = gen(BITSHR, opn1, ropn, result);
            break;
        }
        opn1.kind = VAR;
        opn1.place = T->ptr[0]->place;
        T->code = merge(5, T->ptr[1]->code, T->ptr[0]->code, code1, code2, 
            gen(LARRAY_REF, opn1, offset, result));         //A[offset] := T2
        T->place = temp2;
    }
    if (T->Etrue[0]) {
        opn1.kind = VAR;
        opn1.place = T->place;
        opn2.kind = INT;        
        opn2.const_int = 0;
        result.kind = LABEL;
        strcpy(result.label, T->Etrue);
        T->code = merge(3, T->code, gen(NEQ, opn1, opn2, result), genGoto(T->Efalse));
    }
}

static void genAnd(ASTNode *T) {
    if (T->Etrue[0]) {
        newLabel(T->ptr[0]->Etrue);
        strcpy(T->ptr[1]->Etrue, T->Etrue);
        strcpy(T->ptr[0]->Efalse, T->Efalse);
        strcpy(T->ptr[1]->Efalse, T->Efalse);
        genTAC(T->ptr[0]);
        genTAC(T->ptr[1]);
        T->code = merge(3, T->ptr[0]->code, genLabel(T->ptr[0]->Etrue), T->ptr[1]->code);
    } else {
        Opn opn1, opn2, result;
        T->place = newTemp(T->type);
        if (T->ptr[0]->kind == T->ptr[0]->type) {   //1 && EXP
            char label1[8];
            TACNode *code1, *code2, *code3;
            genTAC(T->ptr[1]);      //EXP
            newLabel(label1);
            opn1.kind = INT;
            opn1.const_int = 0;
            result.kind = VAR;
            result.place = T->place;
            code1 = gen(ASSIGNOP, opn1, {0,0}, result);  //t1 := 0
            opn1.const_int = 1;
            code3 = gen(ASSIGNOP, opn1, {0,0}, result);  //t1 := 1
            opn1.kind = VAR;
            opn1.place = T->ptr[1]->place;
            opn2.kind = INT;        
            opn2.const_int = 0;
            result.kind = LABEL;
            strcpy(result.label, label1);
            code2 = gen(EQ, opn1, opn2, result);        //if T2 == 0 goto label1
            T->code = merge(5, code1, T->ptr[1]->code, code2, code3, genLabel(label1));
        } else {                                    //EXP && EXP
            char label1[8];
            TACNode *code1, *code2, *code3, *code4;
            genTAC(T->ptr[0]);  //EXP
            newLabel(label1);
            opn1.kind = INT;
            opn1.const_int = 0;
            result.kind = VAR;
            result.place = T->place;
            code1 = gen(ASSIGNOP, opn1, {0,0}, result);  //t1 := 0
            opn1.const_int = 1;
            code4 = gen(ASSIGNOP, opn1, {0,0}, result);  //t1 := 1
            opn1.kind = VAR;
            opn1.place = T->ptr[0]->place;
            opn2.kind = INT;        
            opn2.const_int = 0;
            result.kind = LABEL;
            strcpy(result.label, label1);
            code2 = gen(EQ, opn1, opn2, result);        //if T1 == 0 goto label1
            if (T->ptr[1]->kind == T->ptr[1]->type) {
                if (T->ptr[1]->type_int) {
                    T->code = merge(5, code1, T->ptr[0]->code, code2, code4, genLabel(label1));
                } else {
                    T->code = merge(2, code1, T->ptr[0]->code);
                }
            } else {
                genTAC(T->ptr[1]);
                opn1.place = T->ptr[1]->place;
                code3 = gen(EQ, opn1, opn2, result);    //if T2 == 0 goto label1
                T->code = merge(7, code1, T->ptr[0]->code, code2, T->ptr[1]->code, code3, code4, genLabel(label1));
            }
        }
    }
}

static void genOr(ASTNode *T) {
    if (T->Etrue[0]) {
                newLabel(T->ptr[0]->Efalse);
                strcpy(T->ptr[0]->Etrue, T->Etrue);
                strcpy(T->ptr[1]->Etrue, T->Etrue);
                strcpy(T->ptr[1]->Efalse, T->Efalse);
                genTAC(T->ptr[0]);
                genTAC(T->ptr[1]);
                T->code = merge(3, T->ptr[0]->code, genLabel(T->ptr[0]->Efalse), T->ptr[1]->code);
    } else {
        Opn opn1, opn2, result;
        T->place = newTemp(T->type);
        if (T->ptr[0]->kind == T->ptr[0]->type) {   //1 && EXP
            char label1[8];
            TACNode *code1, *code2, *code3;
            genTAC(T->ptr[1]);      //EXP
            newLabel(label1);
            opn1.kind = INT;
            opn1.const_int = 0;
            result.kind = VAR;
            result.place = T->place;
            code1 = gen(ASSIGNOP, opn1, {0,0}, result);  //t1 := 0
            opn1.const_int = 1;
            code3 = gen(ASSIGNOP, opn1, {0,0}, result);  //t1 := 1
            opn1.kind = VAR;
            opn1.place = T->ptr[1]->place;
            opn2.kind = INT;        
            opn2.const_int = 0;
            result.kind = LABEL;
            strcpy(result.label, label1);
            code2 = gen(EQ, opn1, opn2, result);        //if T2 == 0 goto label1
            T->code = merge(5, code1, T->ptr[1]->code, code2, code3, genLabel(label1));
        } else {                                    //EXP && EXP
            char label1[8];
            TACNode *code1, *code2, *code3, *code4;
            genTAC(T->ptr[0]);  //EXP
            newLabel(label1);
            opn1.kind = INT;
            opn1.const_int = 1;
            result.kind = VAR;
            result.place = T->place;
            code1 = gen(ASSIGNOP, opn1, {0,0}, result);  //t1 := 1
            opn1.const_int = 0;
            code4 = gen(ASSIGNOP, opn1, {0,0}, result);  //t1 := 0
            opn1.kind = VAR;
            opn1.place = T->ptr[0]->place;
            opn2.kind = INT;        
            opn2.const_int = 0;
            result.kind = LABEL;
            strcpy(result.label, label1);
            code2 = gen(NEQ, opn1, opn2, result);       //if T1 != 0 goto label1
            if (T->ptr[1]->kind == T->ptr[1]->type) {
                if (T->ptr[1]->type_int) {
                    T->code = merge(2, code1, T->ptr[0]->code);
                } else {
                    T->code = merge(5, code1, T->ptr[0]->code, code2, code4, genLabel(label1));
                }
            } else {
                genTAC(T->ptr[1]);
                opn1.place = T->ptr[1]->place;
                code3 = gen(NEQ, opn1, opn2, result);   //if T2 != 0 goto label1
                T->code = merge(7, code1, T->ptr[0]->code, code2, T->ptr[1]->code, code3, code4, genLabel(label1));
            }
        }
    }
}

static void genNot(ASTNode *T) {
    if (T->Etrue[0]) {
        strcpy(T->ptr[0]->Etrue, T->Efalse);
        strcpy(T->ptr[0]->Efalse, T->Etrue);
        genTAC(T->ptr[0]);
        T->code = T->ptr[0]->code;
    } else {
        Opn opn1, opn2, result;
        char label1[8];
        TACNode *code1, *code2, *code3;
        T->place = newTemp(T->type);
        genTAC(T->ptr[0]);
        newLabel(label1);
        opn1.kind = INT;
        opn1.const_int = 1;
        result.kind = VAR;
        result.place = T->place;
        code1 = gen(ASSIGNOP, opn1, {0,0}, result);  //t1 := 1
        opn1.const_int = 0;
        code3 = gen(ASSIGNOP, opn1, {0,0}, result);  //t1 := 0
        opn1.kind = VAR;
        opn1.place = T->ptr[0]->place;
        opn2.kind = INT;        
        opn2.const_int = 0;
        result.kind = LABEL;
        strcpy(result.label, label1);
        code2 = gen(EQ, opn1, opn2, result);       //if T1 == 0 goto label1
        T->code = merge(5, T->ptr[0]->code, code1, code2, code3, genLabel(label1));
    }
}

static void genUminus(ASTNode *T) {
    Opn opn1, opn2, result;
    T->place = newTemp(T->type);
    genTAC(T->ptr[0]);
    opn1.kind = VAR;
    opn1.place = T->ptr[0]->place;
    result.kind = VAR;
    result.place = T->place;
    T->code = merge(2, T->ptr[0]->code, gen(UMINUS, opn1, {0,0}, result));
    if (T->Etrue[0]) {
        opn1.kind = VAR;
        opn1.place = T->place;
        opn2.kind = INT;        
        opn2.const_int = 0;
        result.kind = LABEL;
        strcpy(result.label, T->Etrue);
        T->code = merge(3, T->code, gen(NEQ, opn1, opn2, result), genGoto(T->Efalse));
    }
}

static void genRelop(ASTNode *T) {
    int kind;
    Opn opn1, opn2, result;
    genTAC(T->ptr[0]);
    genTAC(T->ptr[1]);
    if (T->ptr[0]->kind == T->ptr[0]->type) {
        if (T->ptr[0]->kind == FLOAT) {
            opn1.kind = FLOAT;
            opn1.const_float = T->ptr[0]->type_float;
        } else {
            opn1.kind = INT;
            opn1.const_int = T->ptr[0]->type_int;
        }
        opn2.kind = VAR;
        opn2.place = T->ptr[1]->place;
    } else if (T->ptr[1]->kind == T->ptr[1]->type) {
        if (T->ptr[1]->kind == FLOAT) {
            opn2.kind = FLOAT;
            opn2.const_float = T->ptr[1]->type_float;
        } else {
            opn2.kind = INT;
            opn2.const_int = T->ptr[1]->type_int;
        }
        opn1.kind = VAR;
        opn1.place = T->ptr[0]->place;
    } else {
        opn1.kind = VAR;
        opn1.place = T->ptr[0]->place;
        opn2.kind = VAR;
        opn2.place = T->ptr[1]->place;
    }
    switch (T->type_id[0]) {
    case '=':
        kind = EQ;
        break;
    case '!':
        kind = NEQ;
        break;
    case '>':
        if (T->type_id[1]) {
            kind = GE;
        } else {
            kind = GT;
        }
        break;
    case '<':
        if (T->type_id[1]) {
            kind = LE;
        } else {
            kind = LT;
        }
        break;
    }
    if (T->Etrue[0]) {
        result.kind = LABEL;
        strcpy(result.label, T->Etrue);
        T->code = merge(4, T->ptr[0]->code, T->ptr[1]->code, gen(kind, opn1, opn2, result), genGoto(T->Efalse));
    } else {
        char label1[8];
        TACNode *code1, *code2, *code3;
        T->place = newTemp(T->type);
        newLabel(label1);
        result.kind = LABEL;
        strcpy(result.label, label1);
        code2 = gen(kind, opn1, opn2, result);        //if T1 relop T2 goto label1
        opn1.kind = INT;
        opn1.const_int = 1;
        result.kind = VAR;
        result.place = T->place;
        code1 = gen(ASSIGNOP, opn1, {0,0}, result);  //t1 := 1
        opn1.const_int = 0;
        code3 = gen(ASSIGNOP, opn1, {0,0}, result);  //t1 := 0
        T->code = merge(6, T->ptr[0]->code, T->ptr[1]->code, code1, code2, code3, genLabel(label1));
    }
}

static void genArithOp(ASTNode *T) {
    Opn opn1, opn2, result;
    T->place = newTemp(T->type);
    genTAC(T->ptr[0]);
    genTAC(T->ptr[1]);
    if (T->ptr[0]->kind == T->ptr[0]->type) {
        if (T->ptr[0]->kind == FLOAT) {
            opn1.kind = FLOAT;
            opn1.const_float = T->ptr[0]->type_float;
        } else {
            opn1.kind = INT;
            opn1.const_int = T->ptr[0]->type_int;
        }
        opn2.kind = VAR;
        opn2.place = T->ptr[1]->place;
    } else if (T->ptr[1]->kind == T->ptr[1]->type) {
        if (T->ptr[1]->kind == FLOAT) {
            opn2.kind = FLOAT;
            opn2.const_float = T->ptr[1]->type_float;
        } else {
            opn2.kind = INT;
            opn2.const_int = T->ptr[1]->type_int;
        }
        opn1.kind = VAR;
        opn1.place = T->ptr[0]->place;
    } else {
        opn1.kind = VAR;
        opn1.place = T->ptr[0]->place;
        opn2.kind = VAR;
        opn2.place = T->ptr[1]->place;
    }
    result.kind = VAR;
    result.place = T->place;
    T->code = merge(3, T->ptr[0]->code, T->ptr[1]->code, gen(T->kind, opn1, opn2, result));
    if (T->Etrue[0]) {
        opn1.kind = VAR;
        opn1.place = T->place;
        opn2.kind = INT;        
        opn2.const_int = 0;
        result.kind = LABEL;
        strcpy(result.label, T->Etrue);
        T->code = merge(3, T->code, gen(NEQ, opn1, opn2, result), genGoto(T->Efalse));
    }
}

static void genDPLusMinus(ASTNode *T) {
    Opn opn1, opn2, result;
    TACNode *code1, *code2;
    opn2.kind = INT;
    opn2.const_int = 1;
    if (T->ptr[0]->kind != ARRAY_REF) {
        result.kind = VAR;
        result.place = T->ptr[0]->place;
        if (T->kind == DPLUS) {
            code2 = gen(PLUS, result, opn2, result);        //V := V + 1
        } else {
            code2 = gen(MINUS, result, opn2, result);       //V := V - 1   
        }
        if (T->type_id[0] == 'R') {                     //V++|V--
            T->place = newTemp(T->type);
            result.kind = VAR;
            result.place = T->place;
            opn1.kind = VAR;
            opn1.place = T->ptr[0]->place;
            code1 = gen(ASSIGNOP, opn1, {0,0}, result); //T := V
            T->code = merge(2, code1, code2);
        } else {                                        //++V|--V
            T->place = T->ptr[0]->place;
            T->code = code2;
        }
    } else {
        int temp1, temp2;
        temp1 = newTemp(T->type);
        temp2 = newTemp(T->type);
        Opn offset = genArrayOffset(T->ptr[0]);
        opn1.kind = VAR;
        opn1.place = T->ptr[0]->place;
        result.kind = VAR;
        result.place = temp1;
        code1 = gen(RARRAY_REF, opn1, offset, result);      //T1 := A[offset]
        opn1.kind = VAR;
        opn1.place = temp1;
        result.kind = VAR;
        result.place = temp2;
        if (T->kind == DPLUS) {
            code2 = gen(PLUS, opn1, opn2, result);          //T2 := T1 + 1
        } else {
            code2 = gen(MINUS, opn1, opn2, result);         //T2 := T1 - 1   
        }
        opn1.kind = VAR;
        opn1.place = T->ptr[0]->place;
        //A[offset] := T2
        T->code = merge(4, T->ptr[0]->code, code1, code2, gen(LARRAY_REF, opn1, offset, result));
        if (T->type_id[0] == 'R') {
            T->place = temp1;
        } else {
            T->place = temp2;
        }
    }
    if (T->Etrue[0]) {
        opn1.kind = VAR;
        opn1.place = T->place;
        opn2.kind = INT;        
        opn2.const_int = 0;
        result.kind = LABEL;
        strcpy(result.label, T->Etrue);
        T->code = merge(3, T->code, gen(NEQ, opn1, opn2, result), genGoto(T->Efalse));
    }
}

static void genFuncCall(ASTNode *T) {
    //T->ptr[0] maybe NULL
    Opn opn1, opn2, result;
    opn1.kind = FUNC;
    opn1.place = funcTab[T->type_id];
    if (T->type != VOID) {
        T->place = newTemp(T->type);
        result.kind = VAR;
        result.place = T->place;
    } else {
        result = {0,0};
    }
    if (T->ptr[0]) {
        genTAC(T->ptr[0]);          //ARGS
        T->code = merge(2, T->ptr[0]->code, gen(FUNC_CALL, opn1, {0,0}, result));
    } else {
        T->code = gen(FUNC_CALL, opn1, {0,0}, result);
    }
    if (T->Etrue[0]) {
        opn1.kind = VAR;
        opn1.place = T->place;
        opn2.kind = INT;        
        opn2.const_int = 0;
        result.kind = LABEL;
        strcpy(result.label, T->Etrue);
        T->code = merge(3, T->code, gen(NEQ, opn1, opn2, result), genGoto(T->Efalse));
    }
}

static void genArgs(ASTNode *T) {
    //T->ptr[1] maybe NULL
    Opn result;
    genTAC(T->ptr[0]);          //EXP
    if (T->ptr[0]->kind == T->ptr[0]->type) {
        result.kind = T->ptr[0]->type;
        if (T->ptr[0]->type == FLOAT) {
            result.const_float = T->ptr[0]->type_float;
        } else {
            result.const_int = T->ptr[0]->type_int;
        }
    } else {
        result.kind = VAR;
        result.place = T->ptr[0]->place;
    }
    if (T->ptr[1]) {
        genTAC(T->ptr[0]);      //ARGS
        T->code = merge(3, T->ptr[0]->code, gen(ARG, {0,0}, {0,0}, result), T->ptr[1]->code);
    } else {
        T->code = merge(2, T->ptr[0]->code, gen(ARG, {0,0}, {0,0}, result));
    }
}

static void genRArrayRef(ASTNode *T) {
    Opn opn1, offset, result;
    result.kind = VAR;
    result.place = newTemp(T->type);
    opn1.kind = VAR;
    opn1.place = T->place;
    offset = genArrayOffset(T);
    T->code = merge(2, T->code, gen(RARRAY_REF, opn1, offset, result));
    T->place = result.place;
}

static void genArrayDec(ASTNode *T) {
    //T->ptr[1] maybe NULL
    if (T->ptr[1]) {                        //ARRAY_INIT_LIST
        Opn array, offset, ropn;
        ASTNode *T0 = T->ptr[1]->ptr[0];    //ARGS
        int width;
        if (T->type == CHAR)
            width = 1;
        else
            width = 4;
        offset.kind = INT;
        offset.const_int = 0;
        array.kind = VAR;
        array.place = T->place;
        while (T0) {
            if (T0->ptr[0]->kind == T0->ptr[0]->type) {
                ropn.kind = T0->ptr[0]->type;
                if (T0->ptr[0]->type == FLOAT) {
                    ropn.const_float = T0->ptr[0]->type_float;
                } else {
                    ropn.const_int = T0->ptr[0]->type_int;
                }
            } else {
                genTAC(T0->ptr[0]);  //EXP
                ropn.kind = VAR;
                ropn.place = T0->ptr[0]->place;
            }
            T->code = merge(3, T->code, T0->ptr[0]->code, gen(LARRAY_REF, array, offset, ropn));
            T0 = T0->ptr[1];
            offset.const_int += width;
        }
    }
}

void genTAC(ASTNode *T) {
    if (T) {
        switch (T->kind) {              
        case EXT_DEF_LIST:              //T->ptr[1] maybe NULL
            genTAC(T->ptr[0]);          //EXT_VAR_DEF|FUNC_DEF
            if (T->ptr[1]) {
                genTAC(T->ptr[1]);      //EXT_DEF_LIST
                T->code = merge(2, T->ptr[0]->code, T->ptr[1]->code);
            } else {
                T->code = T->ptr[0]->code;
            }
            break;
        case EXT_VAR_DEF:
            genTAC(T->ptr[1]);          //EXT_DEC_LIST
            T->code = T->ptr[1]->code;
            break;
        case EXT_DEC_LIST:              //T->ptr[1] maybe NULL
            genTAC(T->ptr[0]);          //VAR_DEC|ARRAY_DEC
            if (T->ptr[1]) {
                genTAC(T->ptr[1]);      //EXT_DEC_LIST
                T->code = merge(2, T->ptr[0]->code, T->ptr[1]->code);
            } else {
                T->code = T->ptr[0]->code;
            }
            break;
        case VAR_DEC:                   //T->ptr[0] maybe NULL
            genVarDec(T); 
            break;
        case FUNC_DEF:                  
            genFuncDef(T);
            break;
        case FUNC_DEC:                  //T->ptr[0] maybe NULL
            genFuncDec(T);
            break;
        case PARAM_LIST:                //T->ptr[1] maybe NULL
            genTAC(T->ptr[0]);          //PARAM_DEC
            if (T->ptr[1]) {
                genTAC(T->ptr[1]);      //PARAM_LIST
                T->code = merge(2, T->ptr[0]->code, T->ptr[1]->code);
            } else {
                T->code = T->ptr[0]->code;
            }
            break;
        case PARAM_DEC:                 
            genParamDec(T);
            break;
        case COMP_STM:                  //T->ptr[0] maybe NULL
            if (T->ptr[0]) {
                genTAC(T->ptr[0]);      //STM_LIST
                T->code = T->ptr[0]->code;
            }
            break;
        case STM_LIST:                  //T->ptr[0], T->ptr[1] maybe NULL
            genStmList(T);
            break;
        case VAR_DEF:
            genTAC(T->ptr[1]);          //VAR_DEC_LIST
            T->code = T->ptr[1]->code;
            break;
        case VAR_DEC_LIST:              //T->ptr[1] maybe NULL
            genTAC(T->ptr[0]);          //VAR_DEC|ARRAY_DEC
            if (T->ptr[1]) {
                genTAC(T->ptr[1]);      //VAR_DEC_LIST
                T->code = merge(2, T->ptr[0]->code, T->ptr[1]->code);
            } else {
                T->code = T->ptr[0]->code;
            }
            break;
        case EXP_STMT:
            genTAC(T->ptr[0]);          //EXP
            T->code = T->ptr[0]->code;
            break;
        case RETURN:                    //T->ptr[0] maybe NULL
            genReturn(T);
            break;
        case IF_THEN:
            genIfThen(T);
            break;
        case IF_THEN_ELSE:
            genIfThenElse(T);
            break;
        case WHILE:
            genWhile(T);
            break;
        case CONTINUE:
            T->code = genGoto(beginStack.top());
            break;
        case BREAK:
            T->code = genGoto(nextStack.top());
            break;
        case ID:
            genId(T);
            break;
        case INT:
            if (T->Etrue[0]) {
                if (T->type_int) {
                    T->code = genGoto(T->Etrue);
                } else {
                    T->code = genGoto(T->Efalse);
                }
            }
            break;
        case FLOAT:
            if (T->Etrue[0]) {
                if (T->type_float) {
                    T->code = genGoto(T->Etrue);
                } else {
                    T->code = genGoto(T->Efalse);
                }
            }
            break;
        case ASSIGNOP:
            genAssignop(T);
            break;
        case COMP_ASSIGN:
            genCompAssign(T);
            break;
        case AND:
            genAnd(T);
            break;
        case OR:
            genOr(T);
            break;
        case RELOP:
            genRelop(T);
            break;
        case PLUS:
        case MINUS:
        case STAR:
        case DIV:
        case MOD:
        case BITAND:
        case BITOR:
        case BITXOR:
        case BITSHL:
        case BITSHR:
            genArithOp(T);
            break;
        case NOT:
            genNot(T);
            break;
        case UMINUS:
            genUminus(T);
            break;
        case DPLUS:
        case DMINUS:
            genDPLusMinus(T);
            break;
        case FUNC_CALL:
            genFuncCall(T);
            break;
        case ARGS:
            genArgs(T);
            break;
        case ARRAY_DEC:
            genArrayDec(T);
            break;
        case ARRAY_REF:
            genRArrayRef(T);
            break;
        }
    }
}
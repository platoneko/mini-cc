#include "def.h"

#include <vector>
#include <map>
#include <string>

using namespace std;

struct TypeVal {
    int type;
    union {
        float type_float;
        int type_int;
    };
};

static int curLev = 0;
static int curType;
static int funcType;
static int isFuncDef = 0;
static int inLoop = 0;

int hasError = 0;

vector<Symbol *> symbolTab;
map<string, int> funcTab;
vector<Array *> arrayTab;
static vector<int> bTab;


static void newAlias(char *alias) {
    static int cnt = 0;
    sprintf(alias, "V%d", cnt);
    ++cnt;
}

static int newArray(int type, vector<int>::const_iterator begin, vector<int>::const_iterator end) {
    int ref = arrayTab.size();
    Array *array = new Array();
    arrayTab.push_back(array);
    array->type = type;
    array->high = *begin;
    if (begin+1 != end) {
        array->eltype = ARRAY;
        array->elref = newArray(type, begin+1, end);
    } else {
        array->eltype = type;
        array->elref = -1;
    }
    return ref;
}

static TypeVal getTypeVal(ASTNode *lT, ASTNode *rT, int kind, char *relop) {
    TypeVal typeVal;
    switch (kind) {
    case RELOP:
        switch (relop[0]) {
        case '=':
            if (lT->type == FLOAT) {
                if (rT->type == FLOAT)
                    typeVal.type_int = (lT->type_float == rT->type_float);
                else
                    typeVal.type_int = (lT->type_float == rT->type_int);
            } else {
                if (rT->type == FLOAT)
                    typeVal.type_int = (lT->type_int == rT->type_float);
                else
                    typeVal.type_int = (lT->type_int == rT->type_int);
            }
            break;
        case '!':
            if (lT->type == FLOAT) {
                if (rT->type == FLOAT)
                    typeVal.type_int = (lT->type_float != rT->type_float);
                else
                    typeVal.type_int = (lT->type_float != rT->type_int);
            } else {
                if (rT->type == FLOAT)
                    typeVal.type_int = (lT->type_int != rT->type_float);
                else
                    typeVal.type_int = (lT->type_int != rT->type_int);
            }
            break;
        case '>':
            if (relop[1]) {
                if (lT->type == FLOAT) {
                    if (rT->type == FLOAT)
                        typeVal.type_int = (lT->type_float >= rT->type_float);
                    else
                        typeVal.type_int = (lT->type_float >= rT->type_int);
                } else {
                    if (rT->type == FLOAT)
                        typeVal.type_int = (lT->type_int >= rT->type_float);
                    else
                        typeVal.type_int = (lT->type_int >= rT->type_int);
                }
            } else {
                if (lT->type == FLOAT) {
                    if (rT->type == FLOAT)
                        typeVal.type_int = (lT->type_float > rT->type_float);
                    else
                        typeVal.type_int = (lT->type_float > rT->type_int);
                } else {
                    if (rT->type == FLOAT)
                        typeVal.type_int = (lT->type_int > rT->type_float);
                    else
                        typeVal.type_int = (lT->type_int > rT->type_int);
                }
            }
            break;
        case '<':
            if (relop[1]) {
                if (lT->type == FLOAT) {
                    if (rT->type == FLOAT)
                        typeVal.type_int = (lT->type_float <= rT->type_float);
                    else
                        typeVal.type_int = (lT->type_float <= rT->type_int);
                } else {
                    if (rT->type == FLOAT)
                        typeVal.type_int = (lT->type_int <= rT->type_float);
                    else
                        typeVal.type_int = (lT->type_int <= rT->type_int);
                }
            } else {
                if (lT->type == FLOAT) {
                    if (rT->type == FLOAT)
                        typeVal.type_int = (lT->type_float < rT->type_float);
                    else
                        typeVal.type_int = (lT->type_float < rT->type_int);
                } else {
                    if (rT->type == FLOAT)
                        typeVal.type_int = (lT->type_int < rT->type_float);
                    else
                        typeVal.type_int = (lT->type_int < rT->type_int);
                }
            }
            break;
        default: 
            break;
        }
        typeVal.type = INT;
        break;
    case PLUS:
        if (lT->type == FLOAT) {
            if (rT->type == FLOAT)
                typeVal.type_float = (lT->type_float + rT->type_float);
            else
                typeVal.type_float = (lT->type_float + rT->type_int);
            typeVal.type = FLOAT;
        } else {
            if (rT->type == FLOAT) {
                typeVal.type_float = (lT->type_int + rT->type_float);
                typeVal.type = FLOAT;
            }
            else {
                typeVal.type_int = (lT->type_int + rT->type_int);
                typeVal.type = INT;
            }
        }
        break;
    case MINUS:
        if (lT->type == FLOAT) {
            if (rT->type == FLOAT)
                typeVal.type_float = (lT->type_float - rT->type_float);
            else
                typeVal.type_float = (lT->type_float - rT->type_int);
            typeVal.type = FLOAT;
        } else {
            if (rT->type == FLOAT) {
                typeVal.type_float = (lT->type_int - rT->type_float);
                typeVal.type = FLOAT;
            }
            else {
                typeVal.type_int = (lT->type_int - rT->type_int);
                typeVal.type = INT;
            }
        }
        break;
    case STAR:
        if (lT->type == FLOAT) {
            if (rT->type == FLOAT)
                typeVal.type_float = (lT->type_float * rT->type_float);
            else
                typeVal.type_float = (lT->type_float * rT->type_int);
            typeVal.type = FLOAT;
        } else {
            if (rT->type == FLOAT) {
                typeVal.type_float = (lT->type_int * rT->type_float);
                typeVal.type = FLOAT;
            }
            else {
                typeVal.type_int = (lT->type_int * rT->type_int);
                typeVal.type = INT;
            }
        }
        break;
    case DIV:
        if (lT->type == FLOAT) {
            if (rT->type == FLOAT)
                typeVal.type_float = (lT->type_float / rT->type_float);
            else
                typeVal.type_float = (lT->type_float / rT->type_int);
            typeVal.type = FLOAT;
        } else {
            if (rT->type == FLOAT) {
                typeVal.type_float = (lT->type_int / rT->type_float);
                typeVal.type = FLOAT;
            }
            else {
                typeVal.type_int = (lT->type_int / rT->type_int);
                typeVal.type = INT;
            }
        }
        break;
    default:
        break;
    }
    return typeVal;
}

static int getType(char *text) {
    if (strcmp(text, "int") == 0) {
        return INT;
    } else if (strcmp(text, "float") == 0) {
        return FLOAT;
    } else if (strcmp(text, "char") == 0) {
        return CHAR;
    } else {
        return VOID;
    }
}

static string displayType(int type) {
    switch (type) {
    case INT:
        return "int";
    case FLOAT:
        return "float";
    case CHAR:
        return "char";
    case VOID:
        return "void";
    case ARRAY:
        return "array";
    default:
        return "unknown type";
    }
}

static void displayTable() {
    printf("name\talias\tlev\ttype\tflag\tparam\tref\tlink\n");
    for (auto it=symbolTab.cbegin(); it!=symbolTab.cend(); it++) {
        printf("%s\t%s\t%d\t%s\t%c\t%d\t%d\t%d\n", (*it)->name, (*it)->alias, (*it)->lev, displayType((*it)->type).c_str(), (*it)->flag, (*it)->param, (*it)->ref, (*it)->link);
    }
    printf("\n");
    printf("type\teltype\telref\thigh\n");
    for (auto it=arrayTab.cbegin(); it!=arrayTab.cend(); it++) {
        printf("%s\t%s\t%d\t%d\n", displayType((*it)->type).c_str(), displayType((*it)->eltype).c_str(), (*it)->elref, (*it)->high);
    }
    printf("\n");
}

static int checkUndeclaredVar(const char *name, int pos) {
    int lev, index;
    for (lev = curLev; lev >= 0; --lev) {
        index = bTab[lev];
        while (index != -1) {
            if (strcmp(symbolTab[index]->name, name) == 0) {
                if (symbolTab[index]->flag == 'F') {
                    fprintf(stderr, "Semantic Error: illegal usage of function \"%s\" at line %d\n", name, pos);
                    hasError = 1;
                    return -1;
                }
                return index;
            }
            index = symbolTab[index]->link;
        } 
    }
    fprintf(stderr, "Semantic Error: variable \"%s\" undeclared at line %d\n", name, pos);
    hasError = 1;
    return -1;
}

static int checkUndeclaredFunc(const char *name, int pos, int argc) {
    if (funcTab.count(name) == 0) {
        fprintf(stderr, "Semantic Error: function \"%s\" undeclared at line %d\n", name, pos);
        return -1;
    } else {
        int index = funcTab[name];
        if (symbolTab[index]->param > argc) {
            fprintf(stderr, "Semantic Error: too few arguments to function \"%s\" at line %d\n", name, pos);
            hasError = 1;
            return -1;
        } else if (symbolTab[index]->param > argc) {
            fprintf(stderr, "Semantic Error: too many arguments to function \"%s\" at line %d\n", name, pos);
            hasError = 1;
            return -1;
        }
        return index;
    }
}

static int checkRedeclaration(const char *name, int pos) {
    int index = bTab[curLev];
    while (index != -1) {
        if (strcmp(symbolTab[index]->name, name) == 0) {
            fprintf(stderr, "Semantic Error: redeclaration of \"%s\" at line %d\n", name, pos);
            hasError = 1;
            return -1;
        }
        index = symbolTab[index]->link;
    }
    return 0;
}

static void analysisExtVarDef(ASTNode *T) {
    curType = getType(T->ptr[0]->type_id);
    if (curType == VOID) {
        fprintf(stderr, "Semantic Error: variable declared void at line %d\n", T->pos);
        hasError = 1;
    } else {
        analysis(T->ptr[1]);    //EXT_DEC_LIST
    }
}

static void analysisVarDec(ASTNode *T) {
    Symbol *symbol;
    if (checkRedeclaration(T->type_id, T->pos) != -1) {
        symbol = new Symbol();
        strcpy(symbol->name, T->type_id);
        symbol->flag = 'V';
        symbol->type = curType;
        symbol->lev = curLev;
        newAlias(symbol->alias);
        symbol->link = bTab[curLev];
        symbol->ref = -1;
        symbolTab.push_back(symbol);
        bTab[curLev] = symbolTab.size() - 1;
        T->place = bTab[curLev];
    }
    #ifdef DEBUG
    displayTable();
    #endif
    if (T->ptr[0]) {
        analysis(T->ptr[0]);
        if (curLev == 0 && (T->ptr[0]->type != T->ptr[0]->kind)) {
            fprintf(stderr, "Semantic Error: initializer element is not constant at line %d\n", T->pos);
            hasError = 1;
        } else if (T->ptr[0]->type == VOID) {
            fprintf(stderr, "Semantic Error: void value not ignored as it ought to be at line %d\n", T->pos);
            hasError = 1;
        }
    }
}

static void analysisFuncDef(ASTNode *T) {
    funcType = getType(T->ptr[0]->type_id);
    analysis(T->ptr[1]);        //FUNC_DEC
    isFuncDef = 1;
    analysis(T->ptr[2]);        //COMP_STM
}

static void analysisFuncDec(ASTNode *T) {
    Symbol *symbol;
    ASTNode *T0;
    int cnt = 0;
    if (checkRedeclaration(T->type_id, T->pos) != -1) {
        symbol = new Symbol();
        strcpy(symbol->name, T->type_id);
        symbol->flag = 'F';
        symbol->type = funcType;
        symbol->lev = 0;
        T0 = T->ptr[0];
        while (T0) {
            cnt++;
            T0 = T0->ptr[1];
        }
        symbol->param = cnt;
        symbol->link = bTab[curLev];
        symbol->ref = -1;
        symbolTab.push_back(symbol);
        bTab[curLev] = symbolTab.size() - 1;
        T->place = funcTab[T->type_id] = bTab[curLev];
    }
    #ifdef DEBUG
    displayTable();
    #endif
    curLev++;
    if (bTab.size() == curLev) {
        bTab.push_back(-1);
    } else {
        bTab[curLev] = -1;
    }
    analysis(T->ptr[0]);        //PARAM_LIST
}

static void analysisParamList(ASTNode *T) {
    analysis(T->ptr[0]);        //PARAM_DEC
    analysis(T->ptr[1]);        //PARAM_LIST
}

static void analysisParamDec(ASTNode *T) {
    Symbol *symbol;
    if (checkRedeclaration(T->type_id, T->pos) != -1) {
        symbol = new Symbol();
        curType = getType(T->ptr[0]->type_id);
        strcpy(symbol->name, T->type_id);
        symbol->flag = 'P';
        symbol->type = curType;
        symbol->lev = 1;
        newAlias(symbol->alias);
        symbol->link = bTab[curLev];
        symbol->ref = -1;
        symbolTab.push_back(symbol);
        bTab[curLev] = symbolTab.size() - 1;
        T->place = bTab[curLev];
    }
    #ifdef DEBUG
    displayTable();
    #endif
}

static void analysisCompStm(ASTNode *T) {
    if (!isFuncDef) {
        curLev++;
        if (bTab.size() == curLev) {
            bTab.push_back(-1);
        } else {
            bTab[curLev] = -1;
        }
    }
    isFuncDef = 0;
    analysis(T->ptr[0]);        //STM_LIST
    curLev--;
}

static void analysisVarDef(ASTNode *T) {
    curType = getType(T->ptr[0]->type_id);
    if (curType == VOID) {
        fprintf(stderr, "Semantic Error: variable declared void at line %d\n", T->pos);
        hasError = 1;
    } else {
        analysis(T->ptr[1]);    //VAR_DEC_LIST
    }
}

static void analysisReturn(ASTNode *T) {
    if (T->ptr[0]) {
        analysis(T->ptr[0]);    //EXP_STMT
        if (funcType == VOID && T->ptr[0]->type != VOID) {
            fprintf(stderr, "Semantic Error: return with a value, in function returning void at line %d\n", T->pos);
            hasError = 1;
        } else if (funcType != VOID && T->ptr[0]->type == VOID) {
            fprintf(stderr, "Semantic Error: return with no value, in function returning non-void at line %d\n", T->pos);
            hasError = 1;
        }
    } else {
        if (funcType != VOID) {
            fprintf(stderr, "Semantic Error: return with no value, in function returning non-void at line %d\n", T->pos);
            hasError = 1;
        }
    }
}

static void analysisAssignop(ASTNode *T) {
    analysis(T->ptr[0]);
    analysis(T->ptr[1]);
    if (T->ptr[0]->kind != ID && T->ptr[0]->kind != ARRAY_REF) {
        fprintf(stderr, "Semantic Error: lvalue required as left operand of assignment at line %d\n", T->pos);
        hasError = 1;
    } else if (T->ptr[1]->type == VOID) {
        fprintf(stderr, "Semantic Error: void value not ignored as it ought to be at line %d\n", T->pos);
        hasError = 1;
    }
    T->type = T->ptr[0]->type;
}

static void analysisCompAssign(ASTNode *T) {
    analysis(T->ptr[0]);
    analysis(T->ptr[1]);
    if (T->ptr[0]->kind != ID && T->ptr[0]->kind != ARRAY_REF) {
        fprintf(stderr, "Semantic Error: lvalue required as left operand of assignment at line %d\n", T->pos);
        hasError = 1;
    }
    if (T->type_id[0]=='<' || T->type_id[0]=='>' || T->type_id[0]=='^' || T->type_id[0]=='&' || T->type_id[0]=='|') {
        if (T->ptr[0]->type == FLOAT || T->ptr[1]->type == FLOAT) {
            fprintf(stderr, "Semantic Error: invalid operands to binary %s at line %d (have \"%s\" and \"%s\")\n", 
            T->type_id, T->pos, displayType(T->ptr[0]->type).c_str(), displayType(T->ptr[1]->type).c_str());
            hasError = 1;
        }
    } else if (T->ptr[1]->type == VOID) {
        fprintf(stderr, "Semantic Error: void value not ignored as it ought to be at line %d\n", T->pos);
        hasError = 1;
    }
    T->type = T->ptr[0]->type;
}

static void analysisAnd(ASTNode *T) {
    analysis(T->ptr[0]);
    analysis(T->ptr[1]);
    if (T->ptr[0]->kind == T->ptr[0]->type && T->ptr[0]->type_int == 0) {
        T->kind = INT;
        T->type_int = 0;
        free(T->ptr[0]);
        free(T->ptr[1]);
    } else if (T->ptr[0]->kind == T->ptr[0]->type && T->ptr[1]->kind == T->ptr[1]->type) {
        T->kind = INT;
        T->type_int = T->ptr[0]->type_int && T->ptr[1]->type_int;
        free(T->ptr[0]);
        free(T->ptr[1]);
    } else if (T->ptr[0]->type == VOID || T->ptr[1]->type == VOID) {
        fprintf(stderr, "Semantic Error: void value not ignored as it ought to be at line %d\n", T->pos);
        hasError = 1;
    }
    T->type = INT;
}

static void analysisOr(ASTNode *T) {
    analysis(T->ptr[0]);
    analysis(T->ptr[1]);
    if (T->ptr[0]->kind == T->ptr[0]->type && T->ptr[0]->type_int == 1) {
        T->kind = INT;
        T->type_int = 1;
        free(T->ptr[0]);
        free(T->ptr[1]);
    } else if (T->ptr[0]->kind == T->ptr[0]->type && T->ptr[1]->kind == T->ptr[1]->type) {
        T->kind = INT;
        T->type_int = T->ptr[0]->type_int || T->ptr[1]->type_int;
        free(T->ptr[0]);
        free(T->ptr[1]);
    } else if (T->ptr[0]->type == VOID || T->ptr[1]->type == VOID) {
        fprintf(stderr, "Semantic Error: void value not ignored as it ought to be at line %d\n", T->pos);
        hasError = 1;
    }
    T->type = INT;
}

static void analysisRelop(ASTNode *T) {
    analysis(T->ptr[0]);
    analysis(T->ptr[1]);
    if (T->ptr[0]->kind == T->ptr[0]->type && T->ptr[1]->kind == T->ptr[1]->type) {
        T->type_int = getTypeVal(T->ptr[0], T->ptr[1], RELOP, T->type_id).type_int;
        T->kind = INT;
        free(T->ptr[0]);
        free(T->ptr[1]);
    } else if (T->ptr[0]->type == VOID || T->ptr[1]->type == VOID) {
        fprintf(stderr, "Semantic Error: void value not ignored as it ought to be at line %d\n", T->pos);
        hasError = 1;
    }
    T->type = INT;
}

static void analysisArithOp(ASTNode *T) {
    analysis(T->ptr[0]);
    analysis(T->ptr[1]);
    if (T->ptr[0]->kind == T->ptr[0]->type && T->ptr[1]->kind == T->ptr[1]->type) {
        TypeVal typeVal = getTypeVal(T->ptr[0], T->ptr[1], T->kind, NULL);
        T->type = T->kind = typeVal.type;
        if (T->kind == FLOAT) 
            T->type_float = typeVal.type_float;
        else 
            T->type_int = typeVal.type_int;
        free(T->ptr[0]);
        free(T->ptr[1]);
    } else if (T->ptr[0]->type == VOID || T->ptr[1]->type == VOID) {
        fprintf(stderr, "Semantic Error: void value not ignored as it ought to be at line %d\n", T->pos);
        hasError = 1;
    } else {
        if (T->ptr[0]->type == FLOAT || T->ptr[1]->type == FLOAT)
            T->type = FLOAT;
        else
            T->type = INT;
    }
}

static void analysisBinaryOp(ASTNode *T) {
    char op[3];
    switch (T->kind) {
    case MOD:
        strcpy(op, "\%");
        break;
    case BITAND:
        strcpy(op, "&");
        break;
    case BITOR:
        strcpy(op, "|");
        break;
    case BITXOR:
        strcpy(op, "^");
        break;
    case BITSHL:
        strcpy(op, "<<");
        break;
    case BITSHR:
        strcpy(op, ">>");
        break;
    }
    analysis(T->ptr[0]);
    analysis(T->ptr[1]);
    if (T->ptr[0]->type == FLOAT || T->ptr[1]->type == FLOAT) {
        fprintf(stderr, "Semantic Error: invalid operands to binary %s at line %d (have \"%s\" and \"%s\")\n", 
                op, T->pos, displayType(T->ptr[0]->type).c_str(), displayType(T->ptr[1]->type).c_str());
        hasError = 1;
    } else if (T->ptr[0]->type == VOID || T->ptr[1]->type == VOID) {
        fprintf(stderr, "Semantic Error: void value not ignored as it ought to be at line %d\n", T->pos);
        hasError = 1;
    } else {
        if (T->ptr[0]->kind == INT && T->ptr[1]->kind == INT) {
            T->type_int = T->ptr[0]->type_int % T->ptr[1]->type_int;
            T->kind = INT;
            free(T->ptr[0]);
            free(T->ptr[1]);
        }
    }
    T->type = INT;
}



static void analysisNot(ASTNode *T) {
    analysis(T->ptr[0]);
    if (T->ptr[0]->kind == T->ptr[0]->type) {
        T->type_int = !T->ptr[0]->type_int;
        T->kind = INT;
    } else if (T->ptr[0]->type == VOID) {
        fprintf(stderr, "Semantic Error: void value not ignored as it ought to be at line %d\n", T->pos);
        hasError = 1;
    }
    T->type = INT;
}

static void analysisUminus(ASTNode *T) {
    analysis(T->ptr[0]);
    if (T->ptr[0]->kind == INT) {
        T->type_int = -T->ptr[0]->type_int;
        T->kind = INT;
    } else if (T->ptr[0]->kind == FLOAT) {
        T->type_float = -T->ptr[0]->type_float;
        T->kind = FLOAT;
    } else if (T->ptr[0]->type == VOID) {
        fprintf(stderr, "Semantic Error: void value not ignored as it ought to be at line %d\n", T->pos);
        hasError = 1;
    }
    T->type = T->ptr[0]->type;
}

static void analysisDPlusMinus(ASTNode *T) {
    char text[10];
    if (T->kind == DPLUS)
        strcpy(text, "increment");
    else
        strcpy(text, "decrement");
    analysis(T->ptr[0]);
    T->type = T->ptr[0]->type;
    if (T->ptr[0]->kind != ID && T->ptr[0]->kind != ARRAY_REF) {
        fprintf(stderr, "Semantic Error: lvalue required as %s operand at line %d\n", text, T->pos);
        hasError = 1;
    }
}

static void analysisFuncCall(ASTNode *T) {
    ASTNode *T0;
    int cnt = 0;
    T0 = T->ptr[0];
    while (T0) {
        cnt++;
        T0 = T0->ptr[1];
    }
    int place = checkUndeclaredFunc(T->type_id, T->pos, cnt);
    if (place != -1) {
        T->type = symbolTab[place]->type;
    }
    analysis(T->ptr[0]);        //ARGS
}

static void analysisArrayDec(ASTNode *T) {
    Symbol *symbol;
    ASTNode *T0;
    vector<int> subList;
    int cnt = 0;
    subList.push_back(1);
    T0 = T->ptr[0]->ptr[1];                 //ARRAY_SUB_LIST   
    while (T0) {
        if (T0->ptr[0] == NULL) {
            fprintf(stderr, "Semantic Error: declaration of \"%s\" as multidimensional array must have bounds"
                            "for all dimensions except the first at line %d\n", T->type_id, T->pos);
            hasError = 1;
            return;
        }
        analysis(T0->ptr[0]);
        if (T0->ptr[0]->kind != INT) {
            fprintf(stderr, "size of array \"%s\" has non-integer type at line %d\n", T->type_id, T->pos);
            hasError = 1;
            return;
        }
        subList.push_back(T0->ptr[0]->type_int);
        T0 = T0->ptr[1];
    }
    if (T->ptr[0]->ptr[0] == NULL) {        //first dimension
        if (T->ptr[1] == NULL) {
            fprintf(stderr, "Semantic Error: array size missing in \"%s\" at line %d\n", T->type_id, T->pos);
            hasError = 1;
            return;
        } else {
            T0 = T->ptr[1]->ptr[0];         //ARGS
            while (T0) {
                ++cnt;
                T0 = T0->ptr[1];
            }
            if (subList.size() > 1) {
                int size = 1;
                for (auto it=subList.cbegin()+1; it!=subList.cend(); ++it) {
                    size *= *it;
                }
                subList[0] = (cnt+size-1) / size;
            } else {
                subList[0] = cnt;
            }
        }
    } else {
        analysis(T->ptr[0]->ptr[0]);
        if (T->ptr[0]->ptr[0]->kind != INT) {
            fprintf(stderr, "Semantic Error: size of array \"%s\" has non-integer type at line %d\n", T->type_id, T->pos);
            hasError = 1;
            return;
        } else {
            subList[0] = T->ptr[0]->ptr[0]->type_int;
        }
    }
    if (checkRedeclaration(T->type_id, T->pos) != -1) {
        symbol = new Symbol();
        strcpy(symbol->name, T->type_id);
        symbol->flag = 'A';
        symbol->type = curType;
        symbol->lev = curLev;
        newAlias(symbol->alias);
        symbol->link = bTab[curLev];
        symbol->ref = newArray(curType, subList.cbegin(), subList.cend());
        symbol->dim = subList.size();
        symbolTab.push_back(symbol);
        bTab[curLev] = symbolTab.size() - 1;
        T->place = bTab[curLev];
    }
    if (T->ptr[1]) {
        T0 = T->ptr[1]->ptr[0];
        while (T0) {
            analysis(T0->ptr[0]);           //EXP
            if (curLev == 0 && (T0->ptr[0]->type != T0->ptr[0]->kind)) {
                fprintf(stderr, "Semantic Error: initializer element is not constant at line %d\n", T->pos);
                hasError = 1;
            } else if (T0->ptr[0]->type == VOID) {
                fprintf(stderr, "Semantic Error: void value not ignored as it ought to be at line %d\n", T->pos);
                hasError = 1;
            }
            T0 = T0->ptr[1];
        }
    }
    #ifdef DEBUG
    displayTable();
    #endif
}

static void analysisArrayRef(ASTNode *T) {
    int cnt = 0;
    ASTNode *T0;
    int place = checkUndeclaredVar(T->type_id, T->pos);
    if (symbolTab[place]->flag != 'A') {
        fprintf(stderr, "Semantic Error: subscripted value \"%s\" is not array at line %d\n", T->type_id, T->pos);
        hasError = 1;
        return;
    }
    T0 = T->ptr[0];
    while (T0) {
        ++cnt;
        if (T0->ptr[0]) {
            analysis(T0->ptr[0]);
            if (T0->ptr[0]->type != INT) {
                fprintf(stderr, "Semantic Error: subscript of array \"%s\" has non-integer type at line %d\n", T->type_id, T->pos);
                hasError = 1;
                return;
            }
        } else {
            fprintf(stderr, "Semantic Error: array subscript missing in \"%s\" at line %d\n", T->type_id, T->pos);
            hasError = 1;
            return;
        }
        T0 = T0->ptr[1];
    }
    if (symbolTab[place]->dim != cnt) {
        fprintf(stderr, "Semantic Error: dimension not match in \"%s\" at line %d\n", T->type_id, T->pos);
        hasError = 1;
        return;
    }
    T->type = symbolTab[place]->type;
}

void analysis(ASTNode *T) {
    if (T) {
        switch (T->kind) {
        case EXT_DEF_LIST:
            if (bTab.empty()) {
                bTab.push_back(-1);
            }
            analysis(T->ptr[0]);        //EXT_VAR_DEF|FUNC_DEF
            analysis(T->ptr[1]);        //EXT_DEF_LIST
            break;
        case EXT_VAR_DEF:
            analysisExtVarDef(T);
            break;
        case EXT_DEC_LIST:
            analysis(T->ptr[0]);        //VAR_DEC
            analysis(T->ptr[1]);        //EXT_DEC_LIST
            break;
        case VAR_DEC:
            analysisVarDec(T);
            break;
        case FUNC_DEF:
            analysisFuncDef(T);
            break;
        case FUNC_DEC:
            analysisFuncDec(T);
            break;
        case PARAM_LIST:
            analysisParamList(T);
            break;
        case PARAM_DEC:
            analysisParamDec(T);
            break;
        case COMP_STM:
            analysisCompStm(T);
            break;
        case STM_LIST:
            analysis(T->ptr[0]);        //EXP_STMT, RETURN...
            analysis(T->ptr[1]);        //STM_LIST
            break;
        case VAR_DEF:
            analysisVarDef(T);
            break;
        case VAR_DEC_LIST:
            analysis(T->ptr[0]);        //VAR_DEC
            analysis(T->ptr[1]);        //VAR_DEC_LIST
            break;
        case EXP_STMT:
            analysis(T->ptr[0]);
            break;
        case RETURN:
            analysisReturn(T);
            break;
        case IF_THEN:
            analysis(T->ptr[0]);        //EXP
            analysis(T->ptr[1]);        //STMT
            break;
        case IF_THEN_ELSE:
            analysis(T->ptr[0]);        //EXP
            if (T->ptr[0]->type == VOID) {
                fprintf(stderr, "Semantic Error: void value not ignored as it ought to be at line %d\n", T->pos);
                hasError = 1;
            }
            analysis(T->ptr[1]);        //STMT
            analysis(T->ptr[1]);        //STMT
            break;
        case WHILE:
            analysis(T->ptr[0]);        //EXP
            if (T->ptr[0]->type == VOID) {
                fprintf(stderr, "Semantic Error: void value not ignored as it ought to be at line %d\n", T->pos);
                hasError = 1;
            }
            inLoop = 1;
            analysis(T->ptr[1]);        //STMT
            inLoop = 0;
            break;
        case CONTINUE:
            if (!inLoop) {
                fprintf(stderr, "Semantic Error: continue statement not within a loop at line %d\n", T->pos);
                hasError = 1;
            }
            break;
        case BREAK:
            if (!inLoop) {
                fprintf(stderr, "Semantic Error: break statement not within a loop at line %d\n", T->pos);
                hasError = 1;
            }
            break;
        case ID:
            T->place = checkUndeclaredVar(T->type_id, T->pos);
            if (T->place != -1) {
                if (symbolTab[T->place]->flag == 'A') {
                    fprintf(stderr, "Semantic Error: illegal usage of array \"%s\" at line %d\n", T->type_id, T->pos);
                    hasError = 1;
                } else {
                    T->type = symbolTab[T->place]->type;
                }
            }
            break;
        case INT:
            T->type = INT;
            break;
        case FLOAT:
            T->type = FLOAT;
            break;
        case ASSIGNOP:
            analysisAssignop(T);
            break;
        case COMP_ASSIGN:
            analysisCompAssign(T);
            break;
        case AND:
            analysisAnd(T);
            break;
        case OR:
            analysisOr(T);
            break;
        case RELOP:
            analysisRelop(T);
            break;
        case PLUS:
        case MINUS:
        case STAR:
        case DIV:
            analysisArithOp(T);
            break;
        case MOD:
        case BITAND:
        case BITOR:
        case BITXOR:
        case BITSHL:
        case BITSHR:
            analysisBinaryOp(T);
            break;
        case NOT:
            analysisNot(T);
            break;
        case UMINUS:
            analysisUminus(T);
            break;
        case DPLUS:
        case DMINUS:
            analysisDPlusMinus(T);
            break;
        case FUNC_CALL:
            analysisFuncCall(T);
            break;
        case ARGS:
            analysis(T->ptr[0]);        //EXP
            analysis(T->ptr[1]);        //ARGS
            break;
        case ARRAY_DEC:
            analysisArrayDec(T);
            break;
        case ARRAY_REF:
            analysisArrayRef(T);
            break;
        }
    }
}

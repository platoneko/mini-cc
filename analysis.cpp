#include "def.h"

#include <vector>
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
static int isExtVar = 1;
static int isFuncDef = 0;
static int inLoop = 0;
static vector<Symbol *> symbolTab;

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

static void analysis0ArithOp(ASTNode *T) {
    if (T->ptr[0]->kind == T->ptr[0]->type && T->ptr[1]->kind == T->ptr[1]->type) {
        TypeVal typeVal = getTypeVal(T->ptr[0], T->ptr[1], T->kind, NULL);
        T->type = T->kind = typeVal.type;
        if (T->kind == FLOAT) 
            T->type_float = typeVal.type_float;
        else 
            T->type_int = typeVal.type_int;
        free(T->ptr[0]);
        free(T->ptr[1]);
    } else {
        if (T->ptr[0]->type == FLOAT || T->ptr[1]->type == FLOAT)
            T->type = FLOAT;
        else
            T->type = INT;
    }
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
    default:
        return "unknown type";
    }
}

static void displayTable() {
    printf("name\tlev\ttype\tflag\tparam\n");
    for (auto it=symbolTab.cbegin(); it!=symbolTab.cend(); it++) {
        printf("%s\t%d\t%s\t%c\t%d\n", (*it)->name, (*it)->lev, displayType((*it)->type).c_str(), (*it)->flag, (*it)->param);
    }
    printf("\n");
}

static int checkUndeclaredVar(const char *name, int pos) {
    for (auto it=symbolTab.crbegin(); it!=symbolTab.crend(); it++) {
        if (strcmp((*it)->name, name) == 0) {
            if ((*it)->flag == 'F') {
                fprintf(stderr, "Semantic Error: illegal usage of function \"%s\" at line %d\n", name, pos);
                return -1;
            }
            return (*it)->type;
        }
    }
    fprintf(stderr, "Semantic Error: variable \"%s\" undeclared at line %d\n", name, pos);
    return -1;
}

static int checkUndeclaredFunc(const char *name, int pos, int argc) {
    for (auto it=symbolTab.crbegin(); it!=symbolTab.crend(); it++) {
        if (strcmp((*it)->name, name) == 0) {
            if ((*it)->flag != 'F') {
                fprintf(stderr, "Semantic Error: called object \"%s\" is not a function at line %d\n", name, pos);
                return -1;
            }
            if ((*it)->param > argc) {
                fprintf(stderr, "Semantic Error: too few arguments to function \"%s\" at line %d\n", name, pos);
                return -1;
            } else if ((*it)->param < argc) {
                fprintf(stderr, "Semantic Error: too many arguments to function \"%s\" at line %d\n", name, pos);
                return -1;
            }
            return (*it)->type;
        }
    }
    fprintf(stderr, "Semantic Error: function \"%s\" undeclared at line %d\n", name, pos);
    return -1;
}

static int checkRedeclaration(const char *name, int pos) {
    for (auto it=symbolTab.crbegin(); it!=symbolTab.crend(); it++) {
        if ((*it)->lev != curLev) 
            return 0;
        if (strcmp((*it)->name, name) == 0) {
            fprintf(stderr, "Semantic Error: redeclaration of \"%s\" at line %d\n", name, pos);
            return -1;
        }
    }
    return 0;
}

static void analysis0(ASTNode *T) {
    Symbol *symbol;
    ASTNode *T0;
    int cnt = 0;
    if (T) {
        switch (T->kind) {
        case EXT_DEF_LIST:
            analysis0(T->ptr[0]);        //EXT_VAR_DEF|FUNC_DEF
            analysis0(T->ptr[1]);        //EXT_DEF_LIST
            break;
        case EXT_VAR_DEF:
            isExtVar = 1;
            curType = getType(T->ptr[0]->type_id);
            if (curType == VOID) {
                fprintf(stderr, "Semantic Error: variable declared void at line %d\n", T->pos);
            } else {
                analysis0(T->ptr[1]);    //EXT_DEC_LIST
            }
            isExtVar = 0;
            break;
        case EXT_DEC_LIST:
            analysis0(T->ptr[0]);        //VAR_DEC
            analysis0(T->ptr[1]);        //EXT_DEC_LIST
            break;
        case VAR_DEC:
            if (checkRedeclaration(T->type_id, T->pos) != -1) {
                symbol = new Symbol;
                strcpy(symbol->name, T->type_id);
                symbol->flag = 'V';
                symbol->type = curType;
                symbol->lev = curLev;
                symbolTab.push_back(symbol);
            }
            #ifdef DEBUG
            displayTable();
            #endif
            analysis0(T->ptr[0]);
            if (isExtVar && (T->ptr[0]->type != T->ptr[0]->kind)) {
                fprintf(stderr, "Semantic Error: initializer element is not constant at line %d\n", T->pos);
            }
            break;
        case FUNC_DEF:
            funcType = getType(T->ptr[0]->type_id);
            analysis0(T->ptr[1]);        //FUNC_DEC
            isFuncDef = 1;
            analysis0(T->ptr[2]);        //COMP_STM
            break;
        case FUNC_DEC:
            if (checkRedeclaration(T->type_id, T->pos) != -1) {
                symbol = new Symbol;
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
                symbolTab.push_back(symbol);
            }
            #ifdef DEBUG
            displayTable();
            #endif
            curLev++;
            analysis0(T->ptr[0]);        //PARAM_LIST
            break;
        case PARAM_LIST:
            analysis0(T->ptr[0]);        //PARAM_DEC
            analysis0(T->ptr[1]);        //PARAM_LIST
            break;
        case PARAM_DEC:
            if (checkRedeclaration(T->type_id, T->pos) != -1) {
                symbol = new Symbol;
                curType = getType(T->ptr[0]->type_id);
                strcpy(symbol->name, T->type_id);
                symbol->flag = 'P';
                symbol->type = curType;
                symbol->lev = 1;
                symbolTab.push_back(symbol);
            }
            #ifdef DEBUG
            displayTable();
            #endif
            break;
        case COMP_STM:
            if (!isFuncDef) curLev++;
            isFuncDef = 0;
            analysis0(T->ptr[0]);        //STM_LIST
            while (symbolTab.back()->lev == curLev) {
                delete symbolTab.back();
                symbolTab.pop_back();
            }
            #ifdef DEBUG
            displayTable();
            #endif
            curLev--;
            break;
        case STM_LIST:
            analysis0(T->ptr[0]);        //EXP_STMT, RETURN...
            analysis0(T->ptr[1]);        //STM_LIST
            break;
        case VAR_DEF:
            curType = getType(T->ptr[0]->type_id);
            if (curType == VOID) {
                fprintf(stderr, "Semantic Error: variable declared void at line %d\n", T->pos);
            } else {
                analysis0(T->ptr[1]);    //VAR_DEC_LIST
            }
            break;
        case VAR_DEC_LIST:
            analysis0(T->ptr[0]);        //VAR_DEC
            analysis0(T->ptr[1]);        //VAR_DEC_LIST
            break;
        case EXP_STMT:
            analysis0(T->ptr[0]);
            break;
        case RETURN:
            if (T->ptr[0] && funcType == VOID) {
                fprintf(stderr, "Semantic Error: return with a value, in function returning void at line %d\n", T->pos);
            } else if (!T->ptr[0] && funcType != VOID) {
                fprintf(stderr, "Semantic Error: return with no value, in function returning non-void at line %d\n", T->pos);
            }
            analysis0(T->ptr[0]);        //EXP_STMT
            break;
        case IF_THEN:
            analysis0(T->ptr[0]);        //EXP
            analysis0(T->ptr[1]);        //STMT
            break;
        case IF_THEN_ELSE:
            analysis0(T->ptr[0]);        //EXP
            analysis0(T->ptr[1]);        //STMT
            analysis0(T->ptr[1]);        //STMT
            break;
        case WHILE:
            analysis0(T->ptr[0]);        //EXP
            inLoop = 1;
            analysis0(T->ptr[1]);        //STMT
            inLoop = 0;
            break;
        case CONTINUE:
            if (!inLoop) {
                fprintf(stderr, "Semantic Error: continue statement not within a loop at line %d\n", T->pos);
            }
            break;
        case BREAK:
            if (!inLoop) {
                fprintf(stderr, "Semantic Error: break statement not within a loop at line %d\n", T->pos);
            }
            break;
        case ID:
            T->type = checkUndeclaredVar(T->type_id, T->pos);
            break;
        case INT:
            T->type = INT;
            break;
        case FLOAT:
            T->type = FLOAT;
            break;
        case ASSIGNOP:
            analysis0(T->ptr[0]);
            analysis0(T->ptr[1]);
            if (T->ptr[0]->kind != ID) {
                fprintf(stderr, "Semantic Error: lvalue required as left operand of assignment at line %d\n", T->pos);
            }
            T->type = T->ptr[0]->type;
            break;
        case COMP_ASSIGN:
            analysis0(T->ptr[0]);
            analysis0(T->ptr[1]);
            if (T->ptr[0]->kind != ID) {
                fprintf(stderr, "Semantic Error: lvalue required as left operand of assignment at line %d\n", T->pos);
            }
            if (T->type_id[0]=='<' || T->type_id[0]=='>' || T->type_id[0]=='^' || T->type_id[0]=='&' || T->type_id[0]=='|') {
                if (T->ptr[0]->type == FLOAT || T->ptr[1]->type == FLOAT) {
                    fprintf(stderr, "Semantic Error: invalid operands to binary %s at line %d (have \"%s\" and \"%s\")\n", 
                    T->type_id, T->pos, displayType(T->ptr[0]->type).c_str(), displayType(T->ptr[1]->type).c_str());
                }
            }
            T->type = T->ptr[0]->type;
            break;
        case AND:
            analysis0(T->ptr[0]);
            analysis0(T->ptr[1]);
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
            }
            T->type = INT;
            break;
        case OR:
            analysis0(T->ptr[0]);
            analysis0(T->ptr[1]);
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
            }
            T->type = INT;
            break;
        case RELOP:
            analysis0(T->ptr[0]);
            analysis0(T->ptr[1]);
            if (T->ptr[0]->kind == T->ptr[0]->type && T->ptr[1]->kind == T->ptr[1]->type) {
                T->type_int = getTypeVal(T->ptr[0], T->ptr[1], RELOP, T->type_id).type_int;
                T->kind = INT;
                free(T->ptr[0]);
                free(T->ptr[1]);
            }
            T->type = INT;
            break;
        case PLUS:
            analysis0(T->ptr[0]);
            analysis0(T->ptr[1]);
            analysis0ArithOp(T);
            break;
        case MINUS:
            analysis0(T->ptr[0]);
            analysis0(T->ptr[1]);
            analysis0ArithOp(T);
            break;
        case STAR:
            analysis0(T->ptr[0]);
            analysis0(T->ptr[1]);
            analysis0ArithOp(T);
            break;
        case DIV:
            analysis0(T->ptr[0]);
            analysis0(T->ptr[1]);
            analysis0ArithOp(T);
            break;
        case MOD:
            analysis0(T->ptr[0]);
            analysis0(T->ptr[1]);
            if (T->ptr[0]->type == FLOAT || T->ptr[1]->type == FLOAT) {
                fprintf(stderr, "Semantic Error: invalid operands to binary \% at line %d (have \"%s\" and \"%s\")\n", 
                        T->pos, displayType(T->ptr[0]->type).c_str(), displayType(T->ptr[1]->type).c_str());
            } else {
                if (T->ptr[0]->kind == INT && T->ptr[1]->kind == INT) {
                    T->type_int = T->ptr[0]->type_int % T->ptr[1]->type_int;
                    T->kind = INT;
                    free(T->ptr[0]);
                    free(T->ptr[1]);
                }
            }
            T->type = INT;
            break;
        case BITAND:
            analysis0(T->ptr[0]);
            analysis0(T->ptr[1]);
            if (T->ptr[0]->type == FLOAT || T->ptr[1]->type == FLOAT) {
                fprintf(stderr, "Semantic Error: invalid operands to binary & at line %d (have \"%s\" and \"%s\")\n", 
                        T->pos, displayType(T->ptr[0]->type).c_str(), displayType(T->ptr[1]->type).c_str());
            } else {
                if (T->ptr[0]->kind == INT && T->ptr[1]->kind == INT) {
                    T->type_int = T->ptr[0]->type_int & T->ptr[1]->type_int;
                    T->kind = INT;
                    free(T->ptr[0]);
                    free(T->ptr[1]);
                }
            }
            T->type = INT;
            break;
        case BITOR:
            analysis0(T->ptr[0]);
            analysis0(T->ptr[1]);
            if (T->ptr[0]->type == FLOAT || T->ptr[1]->type == FLOAT) {
                fprintf(stderr, "Semantic Error: invalid operands to binary | at line %d (have \"%s\" and \"%s\")\n", 
                        T->pos, displayType(T->ptr[0]->type).c_str(), displayType(T->ptr[1]->type).c_str());
            } else {
                if (T->ptr[0]->kind == INT && T->ptr[1]->kind == INT) {
                    T->type_int = T->ptr[0]->type_int | T->ptr[1]->type_int;
                    T->kind = INT;
                    free(T->ptr[0]);
                    free(T->ptr[1]);
                }
            }
            T->type = INT;
            break;
        case BITXOR:
            analysis0(T->ptr[0]);
            analysis0(T->ptr[1]);
            if (T->ptr[0]->type == FLOAT || T->ptr[1]->type == FLOAT) {
                fprintf(stderr, "Semantic Error: invalid operands to binary ^ at line %d (have \"%s\" and \"%s\")\n", 
                        T->pos, displayType(T->ptr[0]->type).c_str(), displayType(T->ptr[1]->type).c_str());
            } else {
                if (T->ptr[0]->kind == INT && T->ptr[1]->kind == INT) {
                    T->type_int = T->ptr[0]->type_int ^ T->ptr[1]->type_int;
                    T->kind = INT;
                    free(T->ptr[0]);
                    free(T->ptr[1]);
                }
            }
            T->type = INT;
            break;
        case BITSHL:
            analysis0(T->ptr[0]);
            analysis0(T->ptr[1]);
            if (T->ptr[0]->type == FLOAT || T->ptr[1]->type == FLOAT) {
                fprintf(stderr, "Semantic Error: invalid operands to binary << at line %d (have \"%s\" and \"%s\")\n", 
                        T->pos, displayType(T->ptr[0]->type).c_str(), displayType(T->ptr[1]->type).c_str());
            } else {
                if (T->ptr[0]->kind == INT && T->ptr[1]->kind == INT) {
                    T->type_int = T->ptr[0]->type_int << T->ptr[1]->type_int;
                    T->kind = INT;
                    free(T->ptr[0]);
                    free(T->ptr[1]);
                }
            }
            T->type = INT;
            break;
        case BITSHR:
            analysis0(T->ptr[0]);
            analysis0(T->ptr[1]);
            if (T->ptr[0]->type == FLOAT || T->ptr[1]->type == FLOAT) {
                fprintf(stderr, "Semantic Error: invalid operands to binary >> at line %d (have \"%s\" and \"%s\")\n", 
                        T->pos, displayType(T->ptr[0]->type).c_str(), displayType(T->ptr[1]->type).c_str());
            } else {
                if (T->ptr[0]->kind == INT && T->ptr[1]->kind == INT) {
                    T->type_int = T->ptr[0]->type_int >> T->ptr[1]->type_int;
                    T->kind = INT;
                    free(T->ptr[0]);
                    free(T->ptr[1]);
                }
            }
            T->type = INT;
            break;
        case NOT:
            analysis0(T->ptr[0]);
            if (T->ptr[0]->kind == T->ptr[0]->type) {
                T->type_int = !T->ptr[0]->type_int;
                T->kind = INT;
            }
            T->type = INT;
            break;
        case UMINUS:
            analysis0(T->ptr[0]);
            if (T->ptr[0]->kind == INT) {
                T->type_int = -T->ptr[0]->type_int;
                T->kind = INT;
            } else if (T->ptr[0]->kind == FLOAT) {
                T->type_float = -T->ptr[0]->type_float;
                T->kind = FLOAT;
            }
            T->type = T->ptr[0]->type;
            break;
        case DPLUS:
            if (T->ptr[0]->kind != ID) {
                fprintf(stderr, "Semantic Error: lvalue required as increment operand at line %d\n", T->pos);
            }
            break;
        case DMINUS:
            if (T->ptr[0]->kind != ID) {
                fprintf(stderr, "Semantic Error: lvalue required as decrement operand at line %d\n", T->pos);
            }
            break;
        case FUNC_CALL:
            T0 = T->ptr[0];
            while (T0) {
                cnt++;
                T0 = T0->ptr[1];
            }
            T->type = checkUndeclaredFunc(T->type_id, T->pos, cnt);
            analysis0(T->ptr[0]);        //ARGS
            break;
        case ARGS:
            analysis0(T->ptr[0]);        //EXP
            analysis0(T->ptr[1]);        //ARGS
            break;
        }
    }
}

void analysis(ASTNode *T) {
    analysis0(T);
    for (auto it=symbolTab.begin(); it!=symbolTab.end(); it++) {
        delete *it;
    }
    symbolTab.clear();
}
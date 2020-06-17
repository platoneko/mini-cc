#include "def.h"

#include <vector>
#include <string>
#include <map>

using namespace std;


extern vector<Symbol *> symbolTab;
extern map<string, int> funcTab;

static FILE *fp;
static int activeSize, tempSize, paramNum, argCnt = 0, nextActiveSize = -1;


static void getActiveSize(TACNode *code) {
    while (code->op != FUNC_CALL) {
        code = code->next;
    }
    nextActiveSize = symbolTab[code->opn1.place]->offset;
}

static void loadVar(Symbol *var, const char *reg) {
    if (var->flag == 'P') {
        if (var->offset <= 12) {
            fprintf(fp, "  add %s,$a%d,$0\n", reg, var->offset >> 2);
            return;
        } else {
            fprintf(fp, "  lw %s,%d($sp)\n", reg, var->offset);
            return;
        }
    } else if (var->flag == 'V') {
        if (var->lev == 0) {
            fprintf(fp, "  lw %s,%d($gp)\n", reg, var->offset);
            return;
        } else {
            fprintf(fp, "  lw %s,%d($sp)\n", reg, var->offset);
            return;
        }
    } else {
        fprintf(fp, "  lw %s,-%d($sp)\n", reg, var->offset);
        return;
    }
}

static void storeVar(Symbol *var, const char *reg) {
    if (var->flag == 'P') {
        if (var->offset <= 12) {
            fprintf(fp, "  add $a%d,%s,$0\n", var->offset >> 2, reg);
            return;
        } else {
            fprintf(fp, "  sw %s,%d($sp)\n", reg, var->offset);
            return;
        }
    } else if (var->flag == 'V') {
        if (var->lev == 0) {
            fprintf(fp, "  sw %s,%d($gp)\n", reg, var->offset);
            return;
        } else {
            fprintf(fp, "  sw %s,%d($sp)\n", reg, var->offset);
            return;
        }
    } else {
        if (var->offset == -1) {
            var->offset = tempSize;
            tempSize += 4;
        }
        fprintf(fp, "  sw %s,-%d($sp)\n", reg, var->offset);
        return;
    }
}

void genMips(TACNode *head, const char *output) {
    if (funcTab.count("main") == 0) {
        fprintf(stderr, "undefined reference to \"main\"\n");
        exit(-1);
    }
    
    fp = fopen(output, "w");

    fprintf(fp, ".text\n"
                "main0:\n"
                "  jal main\n"
                "  nop\n"
                "  ori $v0,$0,10\n"
                "  syscall\n");

    TACNode *node = head;
    do {
        switch(node->op) {
        case LABEL:
            fprintf(fp, "%s:\n", node->result.label);
            break;
        case GOTO:
            fprintf(fp, "  j %s\n", node->result.label);
            break;
        case ASSIGNOP:
            if (node->opn1.kind == INT) {
                fprintf(fp, "  ori $t0,$0,%d\n", node->opn1.const_int);
            } else {
                loadVar(symbolTab[node->opn1.place], "$t0");
            }
            storeVar(symbolTab[node->result.place], "$t0");
            break;
        case FUNC:
            fprintf(fp, "%s:\n", symbolTab[node->result.place]->name);
            activeSize = symbolTab[node->result.place]->offset;
            fprintf(fp, "  addi $sp,$sp,-%d\n", activeSize);
            tempSize = 0;
            paramNum = symbolTab[node->result.place]->param;
            break;
        case PARAM:
            break;
        case RETURN:
            if (node->result.kind == INT) {
                fprintf(fp, "  ori $v0,$0,%d\n", node->result.const_int);
            } else if (node->result.kind == VAR) {
                loadVar(symbolTab[node->result.place], "$v0");
            }
            fprintf(fp, "  addi $sp,$sp,%d\n", activeSize);
            fprintf(fp, "  jr $ra\n");
            break;
        case EQ:
            if (node->opn1.kind == INT) {
                fprintf(fp, "  ori $t1,$0,%d\n", node->opn1.const_int);
            } else {
                loadVar(symbolTab[node->opn1.place], "$t1");
            }
            if (node->opn2.kind == INT) {
                fprintf(fp, "  ori $t2,$0,%d\n", node->opn1.const_int);
            } else {
                loadVar(symbolTab[node->opn1.place], "$t2");
            }
            fprintf(fp, "  beq $t1,$t2,%s\n", node->result.label);
            break;
        case NEQ:
            if (node->opn1.kind == INT) {
                fprintf(fp, "  ori $t1,$0,%d\n", node->opn1.const_int);
            } else {
                loadVar(symbolTab[node->opn1.place], "$t1");
            }
            if (node->opn2.kind == INT) {
                fprintf(fp, "  ori $t2,$0,%d\n", node->opn1.const_int);
            } else {
                loadVar(symbolTab[node->opn1.place], "$t2");
            }
            fprintf(fp, "  bne $t1,$t2,%s\n", node->result.label);
            break;
        case GT:
            if (node->opn1.kind == INT) {
                if (node->opn1.const_int == 0) {
                    loadVar(symbolTab[node->opn2.place], "$t1");
                    fprintf(fp, "  bltz $t1,%s\n", node->result.label);
                    break;
                } else {
                    loadVar(symbolTab[node->opn2.place], "$t1");
                    fprintf(fp, "  addi $t0,$t1,-%d\n", node->opn1.const_int);
                    fprintf(fp, "  bltz $t0,%s\n", node->result.label);
                    break;
                }
            }
            loadVar(symbolTab[node->opn1.place], "$t1");
            if (node->opn2.kind == INT) {
                if (node->opn2.const_int == 0) {
                    fprintf(fp, "  bgtz $t1,%s\n", node->result.label);
                    break;
                } else {
                    fprintf(fp, "  addi $t0,$t1,-%d\n", node->opn2.const_int);
                    fprintf(fp, "  bgtz $t0,%s\n", node->result.label);
                    break;
                }
            }
            loadVar(symbolTab[node->opn2.place], "$t2");
            fprintf(fp, "  sub $t0,$t1,$t2\n");
            fprintf(fp, "  bgtz $t0,%s\n", node->result.label);
            break;
        case GE:
            if (node->opn1.kind == INT) {
                if (node->opn1.const_int == 0) {
                    loadVar(symbolTab[node->opn2.place], "$t1");
                    fprintf(fp, "  blez $t1,%s\n", node->result.label);
                    break;
                } else {
                    loadVar(symbolTab[node->opn2.place], "$t1");
                    fprintf(fp, "  addi $t0,$t1,-%d\n", node->opn1.const_int);
                    fprintf(fp, "  blez $t0,%s\n", node->result.label);
                    break;
                }
            }
            loadVar(symbolTab[node->opn1.place], "$t1");
            if (node->opn2.kind == INT) {
                if (node->opn2.const_int == 0) {
                    fprintf(fp, "  bgez $t1,%s\n", node->result.label);
                    break;
                } else {
                    fprintf(fp, "  addi $t0,$t1,-%d\n", node->opn2.const_int);
                    fprintf(fp, "  bgez $t0,%s\n", node->result.label);
                    break;
                }
            }
            loadVar(symbolTab[node->opn2.place], "$t2");
            fprintf(fp, "  sub $t0,$t1,$t2\n");
            fprintf(fp, "  bgez $t0,%s\n", node->result.label);
            break;
        case LT:
            if (node->opn1.kind == INT) {
                if (node->opn1.const_int == 0) {
                    loadVar(symbolTab[node->opn2.place], "$t1");
                    fprintf(fp, "  bgtz $t1,%s\n", node->result.label);
                    break;
                } else {
                    loadVar(symbolTab[node->opn2.place], "$t1");
                    fprintf(fp, "  addi $t0,$t1,-%d\n", node->opn1.const_int);
                    fprintf(fp, "  bgtz $t0,%s\n", node->result.label);
                    break;
                }
            }
            loadVar(symbolTab[node->opn1.place], "$t1");
            if (node->opn2.kind == INT) {
                if (node->opn2.const_int == 0) {
                    fprintf(fp, "  bltz $t1,%s\n", node->result.label);
                    break;
                } else {
                    fprintf(fp, "  addi $t0,$t1,-%d\n", node->opn2.const_int);
                    fprintf(fp, "  bltz $t0,%s\n", node->result.label);
                    break;
                }
            }
            loadVar(symbolTab[node->opn2.place], "$t2");
            fprintf(fp, "  sub $t0,$t1,$t2\n");
            fprintf(fp, "  bltz $t0,%s\n", node->result.label);
            break;
        case LE:
            if (node->opn1.kind == INT) {
                if (node->opn1.const_int == 0) {
                    loadVar(symbolTab[node->opn2.place], "$t1");
                    fprintf(fp, "  bgez $t1,%s\n", node->result.label);
                    break;
                } else {
                    loadVar(symbolTab[node->opn2.place], "$t1");
                    fprintf(fp, "  addi $t0,$t1,-%d\n", node->opn1.const_int);
                    fprintf(fp, "  bgez $t0,%s\n", node->result.label);
                    break;
                }
            }
            loadVar(symbolTab[node->opn1.place], "$t1");
            if (node->opn2.kind == INT) {
                if (node->opn2.const_int == 0) {
                    fprintf(fp, "  blez $t1,%s\n", node->result.label);
                    break;
                } else {
                    fprintf(fp, "  addi $t0,$t1,-%d\n", node->opn2.const_int);
                    fprintf(fp, "  blez $t0,%s\n", node->result.label);
                    break;
                }
            }
            loadVar(symbolTab[node->opn2.place], "$t2");
            fprintf(fp, "  sub $t0,$t1,$t2\n");
            fprintf(fp, "  blez $t0,%s\n", node->result.label);
            break;
        case PLUS:
            if (node->opn1.kind == INT) {
                loadVar(symbolTab[node->opn2.place], "$t1");
                fprintf(fp, "  addi $t0,$t1,%d\n", node->opn1.const_int);
                storeVar(symbolTab[node->result.place], "$t0");
                break;
            }
            loadVar(symbolTab[node->opn1.place], "$t1");
            if (node->opn2.kind == INT) {
                fprintf(fp, "  addi $t0,$t1,%d\n", node->opn2.const_int);
            } else {
                loadVar(symbolTab[node->opn2.place], "$t2");
                fprintf(fp, "  add $t0,$t1,$t2\n");
            }
            storeVar(symbolTab[node->result.place], "$t0");
            break;
        case MINUS:
            if (node->opn1.kind == INT) {
                fprintf(fp, "  ori $t1,$0,%d\n", node->opn1.const_int);
            } else {
                loadVar(symbolTab[node->opn1.place], "$t1");
            }
            if (node->opn2.kind == INT) {
                fprintf(fp, "  addi $t0,$t1,-%d\n", node->opn2.const_int);
            } else {
                loadVar(symbolTab[node->opn2.place], "$t2");
                fprintf(fp, "  sub $t0,$t1,$t2\n");
            }
            storeVar(symbolTab[node->result.place], "$t0");
            break;
        case STAR:
            if (node->opn1.kind == INT) {
                fprintf(fp, "  ori $t1,$0,%d\n", node->opn1.const_int);
            } else {
                loadVar(symbolTab[node->opn1.place], "$t1");
            }
            if (node->opn2.kind == INT) {
                fprintf(fp, "  ori $t2,$0,%d\n", node->opn2.const_int);
            } else {
                loadVar(symbolTab[node->opn2.place], "$t2");
            }
            fprintf(fp, "  mul $t0,$t1,$t2\n");
            storeVar(symbolTab[node->result.place], "$t0");
            break;
        case DIV:
            if (node->opn1.kind == INT) {
                fprintf(fp, "  ori $t1,$0,%d\n", node->opn1.const_int);
            } else {
                loadVar(symbolTab[node->opn1.place], "$t1");
            }
            if (node->opn2.kind == INT) {
                fprintf(fp, "  ori $t2,$0,%d\n", node->opn2.const_int);
            } else {
                loadVar(symbolTab[node->opn2.place], "$t2");
            }
            fprintf(fp, "  div $t1,$t2\n");
            storeVar(symbolTab[node->result.place], "$t2");
            break;
        case MOD:
            if (node->opn1.kind == INT) {
                fprintf(fp, "  ori $t1,$0,%d\n", node->opn1.const_int);
            } else {
                loadVar(symbolTab[node->opn1.place], "$t1");
            }
            if (node->opn2.kind == INT) {
                fprintf(fp, "  ori $t2,$0,%d\n", node->opn2.const_int);
            } else {
                loadVar(symbolTab[node->opn2.place], "$t2");
            }
            fprintf(fp, "  div $t1,$t2\n");
            storeVar(symbolTab[node->result.place], "$t1");
            break;
        case BITAND:    
            if (node->opn1.kind == INT) {
                loadVar(symbolTab[node->opn2.place], "$t1");
                fprintf(fp, "  andi $t0,$t1,%d\n", node->opn1.const_int);
                storeVar(symbolTab[node->result.place], "$t0");
                break;
            }
            loadVar(symbolTab[node->opn1.place], "$t1");
            if (node->opn2.kind == INT) {
                fprintf(fp, "  andi $t0,$t1,%d\n", node->opn2.const_int);
            } else {
                loadVar(symbolTab[node->opn2.place], "$t2");
                fprintf(fp, "  and $t0,$t1,$t2\n");
            }
            storeVar(symbolTab[node->result.place], "$t0");
            break;
        case BITOR:
            if (node->opn1.kind == INT) {
                loadVar(symbolTab[node->opn2.place], "$t1");
                fprintf(fp, "  ori $t0,$t1,%d\n", node->opn1.const_int);
                storeVar(symbolTab[node->result.place], "$t0");
                break;
            }
            loadVar(symbolTab[node->opn1.place], "$t1");
            if (node->opn2.kind == INT) {
                fprintf(fp, "  ori $t0,$t1,%d\n", node->opn2.const_int);
            } else {
                loadVar(symbolTab[node->opn2.place], "$t2");
                fprintf(fp, "  or $t0,$t1,$t2\n");
            }
            storeVar(symbolTab[node->result.place], "$t0");
            break;
        case BITXOR:
            if (node->opn1.kind == INT) {
                loadVar(symbolTab[node->opn2.place], "$t1");
                fprintf(fp, "  xori $t0,$t1,%d\n", node->opn1.const_int);
                storeVar(symbolTab[node->result.place], "$t0");
                break;
            }
            loadVar(symbolTab[node->opn1.place], "$t1");
            if (node->opn2.kind == INT) {
                fprintf(fp, "  xori $t0,$t1,%d\n", node->opn2.const_int);
            } else {
                loadVar(symbolTab[node->opn2.place], "$t2");
                fprintf(fp, "  xor $t0,$t1,$t2\n");
            }
            storeVar(symbolTab[node->result.place], "$t0");
            break;
        case BITSHL:
            if (node->opn1.kind == INT) {
                fprintf(fp, "  ori $t1,$0,%d\n", node->opn1.const_int);
            } else {
                loadVar(symbolTab[node->opn1.place], "$t1");
            }
            if (node->opn2.kind == INT) {
                fprintf(fp, "  sll $t0,$t1,%d\n", node->opn2.const_int);
            } else {
                loadVar(symbolTab[node->opn2.place], "$t2");
                fprintf(fp, "  sllv $t0,$t1,$t2\n");
            }
            storeVar(symbolTab[node->result.place], "$t0");
            break;
        case BITSHR:
            if (node->opn1.kind == INT) {
                fprintf(fp, "  ori $t1,$0,%d\n", node->opn1.const_int);
            } else {
                loadVar(symbolTab[node->opn1.place], "$t1");
            }
            if (node->opn2.kind == INT) {
                fprintf(fp, "  sra $t0,$t1,%d\n", node->opn2.const_int);
            } else {
                loadVar(symbolTab[node->opn2.place], "$t2");
                fprintf(fp, "  srav $t0,$t1,$t2\n");
            }
            storeVar(symbolTab[node->result.place], "$t0");
            break;
        case UMINUS:
            if (node->opn1.kind == INT) {
                fprintf(fp, "  addi $t0,$0,-%d\n", node->opn1.const_int);
            } else {
                loadVar(symbolTab[node->opn1.place], "$t1");
                fprintf(fp, "  sub $t0,$0,$t1\n");
            }
            storeVar(symbolTab[node->result.place], "$t0");
            break;
        case FUNC_CALL:
            argCnt = 0;
            nextActiveSize = -1;
            fprintf(fp, "  addi $sp,$sp,-%d\n"
                        "  jal %s\n"
                        "  nop\n"
                        "  addi $sp,$sp,%d\n",
                        tempSize, symbolTab[node->opn1.place]->name, tempSize);
            if (node->result.kind == VAR) {
                storeVar(symbolTab[node->result.place], "$v0");
            }
            for (int i=0; i<paramNum && i<4; ++i) {
                fprintf(fp, "  lw $a%d,%d($sp)\n", i, i<<2);
            }
            break;
        case ARG:
            if (node->result.kind == INT) {
                if (argCnt < 4) {
                    fprintf(fp, "  ori $a%d,$0,%d\n", argCnt, node->result.const_int);
                } else {
                    if (nextActiveSize == -1) {
                        getActiveSize(node->next);
                    }
                    fprintf(fp, "  ori $t0,$0,%d\n"
                                "  sw $t0,%d($sp)\n",
                                node->result.const_int, 
                                -tempSize-nextActiveSize+(argCnt<<2));
                }
            } else {
                loadVar(symbolTab[node->result.place], "$t0");
                if (argCnt < 4) {
                    fprintf(fp, "  or $a%d,$0,$t0\n", argCnt);
                } else {
                    if (nextActiveSize == -1) {
                        getActiveSize(node->next);
                    }
                    fprintf(fp, "  sw $t0,%d($sp)\n",
                                -tempSize-nextActiveSize+(argCnt<<2));
                }
            }
            ++argCnt;
            break;
        case RARRAY_REF:
            if (node->opn2.kind == INT) {
                fprintf(fp, "  lw $t0,%d($sp)\n", 
                            symbolTab[node->opn1.place]->offset + node->opn2.const_int);
            } else {
                loadVar(symbolTab[node->opn2.place], "$t1");
                fprintf(fp, "  add $t1,$sp,$t1\n"
                            "  lw $t0,%d($t1)\n",
                            symbolTab[node->opn1.place]->offset);
            }
            storeVar(symbolTab[node->result.place], "$t0");
            break;
        case LARRAY_REF:
            if (node->result.kind == INT) {
                fprintf(fp, "  ori $t0,$0,%d\n", node->result.const_int);
            } else {
                loadVar(symbolTab[node->result.place], "$t0");
            }
            if (node->opn2.kind == INT) {
                fprintf(fp, "  sw $t0,%d($sp)\n", 
                            symbolTab[node->opn1.place]->offset + node->opn2.const_int);
            } else {
                loadVar(symbolTab[node->opn2.place], "$t1");
                fprintf(fp, "  add $t1,$sp,$t1\n"
                            "  sw $t0,%d($t1)\n",
                            symbolTab[node->opn1.place]->offset);
            }
            break;
        }
        node = node->next;
    } while (node != head);
    fclose(fp);
}
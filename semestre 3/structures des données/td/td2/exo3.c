#include <stdio.h>
#include "LDC.h"

int strToInt(char** s){
    int n = -1;
    while (*s && **s != '\0' && **s - '0' < 10 && **s - '0' >= 0){
        if (n == -1) n = 0;
        n *= 10;
        n += **s - '0';
        (*s)++;
    }
    // avoid skipping the char is it was not converted
    if (n >= 0) (*s)--;
    return n;
}

int algo(char* expr){
    char* c = expr;
    ChainedList* stack = creerListe();
    while (c && *c != '\0'){
        if (*c == ')'){
            int o2 = stack->last->val;
            supprimerFin(stack);
            char op = (char) stack->last->val;
            supprimerFin(stack);
            int o1 = stack->last->val;
            supprimerFin(stack);

            int res = 0;
            if (op == '+'){
                res += o1 + o2;
            } else if (op == '-'){
                res += o1 - o2;
            } else if (op == '*'){
                res += o1 * o2;
            } else if (op == '/'){
                res += o1 / o2;
            }
            insererEnFin(stack, res);
        } else if (*c != '(' && *c != ')'){
            int n = strToInt(&c);
            insererEnFin(stack, n >= 0 ? n : (int) *c);
        }
        c++;
    }
    int res = stack->first->val;
    desalloueListe(stack);
    return res;
}

int main(){
    char* s = "(((4+2)-5)*4)";
    int res = algo(s);
    printf("%s = %d\n", s, res);
    return 0;
}

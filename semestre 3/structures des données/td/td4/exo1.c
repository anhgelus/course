#include <stdio.h>

typedef struct _Cell {
    Formation* val;
    struct _Cell* next;
} Cell;

typedef struct _Formation {
    char* name;
    int hours;
    Cell* formations;
} Formation; 

typedef struct{
    int length;
    int max;
    Formations** formations;
} Catalogue;

void print_formation(Formation* f){
    if (f->hours != 0) {
        printf("Cours %s\n", f->name);
        return;
    }
    printf("%s (%d): ", f->name, f->hours);
    Cell* fms = f->formations;
    while (fms) {
        print_formation(fms->val);
        fms = fms->next;
    }
    printf("\n");
}

void print_catalogue(Catalogue* c){
    for (int i = 0; i < c->lenght; i++) {
        print_formation(c->formations[i]);
    }
}

int sum_formation_hours(Formation* f, int acc){
    acc += f->hours;
    Cell* fms = f->formations;
    while (fms){
        acc += sum_formation_hours(fms, acc);
        fms = fms->next;
    }
    return acc;
}


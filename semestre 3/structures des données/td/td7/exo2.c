// complexite = O(2n) = O(n)
void degre_matrice(int** M, int n, int u, int* deg_e, int* deg_s){
    for (int i = 0; i < n; i++) if (M[u][i]) (*deg_e)++;
    for (int i = 0; i < n; i++) if (M[i][u]) (*deg_s)++;
}

typedef struct Cell{
    int to;
    struct Cell* next;
} Cell;

typedef struct List{
    int val;
    Cell* linked;
} List;

// complexite = O(degre max de n)
int degre_entrant_LA(List** l, int n, int u){
    int acc = 0;
    Cell* c = l[u]->linked;
    while (c){
        acc++;
        c = c->next;
    }
    return acc;
}

// complexite = O(n+(degre max de n))
int degre_sortant_LA(List** l, int n, int u){
    int acc = 0;
    for (int i = 0; i < n; i++){
        Cell* c = l[i]->linked;
        while (c){
            if (c->to == u) acc++;
            c = c->next;
        }
    }
    return acc;
}

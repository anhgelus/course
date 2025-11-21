#include <stdlib.h>
typedef struct cell{
    int val;
    int key;
    struct cell* next;
} Cell;

typedef struct hashMap{
    int size;
    struct cell** map;
} HashMap;

void mapInsert(HashMap* map, int val){
    map->map[g(val)] = val;
}

int mapLen(HashMap* map){
    int len = 0;
    for (int i = 0; i < map->size; i++){
        Cell* v = map->map[i];
        while (v){
            len++;
            v = v->next;
        }
    }
    return len;
}

void mapDel(HashMap* map, int val){
    Cell* f = map->map[g(val)];
    Cell* v = f;
    Cell* b;
    while (v && v->val != val){
        b = v;
        v = v->next;
    }
    if (v->val != val) return;
    if (!b){
        f = v->next;
    } else {
        b = v->next;
    }
    free(v);
}


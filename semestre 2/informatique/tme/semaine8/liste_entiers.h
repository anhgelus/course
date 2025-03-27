typedef struct _cellule_t cellule_t;

struct _cellule_t {
  int donnee;
  cellule_t *suivant;
};

cellule_t * creerListe(int n);

void AfficherListeInt(cellule_t *liste);

int nb_occurences(int val, cellule_t *liste);

int tous_plus_grand(int val, cellule_t *liste);

cellule_t *Maximum(cellule_t *liste);

int Renvoyer_val_element_pos(int pos, cellule_t* liste);

cellule_t *Concatener_it(cellule_t *liste1, cellule_t *liste2);

int nb_maximum(cellule_t *liste);

cellule_t *list(int n, cellule_t *q);

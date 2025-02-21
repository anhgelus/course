#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define PIERRE 0
#define FEUILLE PIERRE+1
#define CISEAUX FEUILLE+1

#define MAX_TRY 3

int choix_ordinateur(){
	return rand()%3;
}

int choix_joueur(){
	int i = 0;
	scanf("%d", &i);
	for (int j = 0; j < MAX_TRY-1 && i < 1 && i > 3; j++) {
		printf("\nCe n'est pas une bonne valeur !\n");
	}
	if (i < 1 && i > 3) return choix_ordinateur();
	return i-1;
}

char* get_name(int coup) {
	char *s;
	if (coup == FEUILLE) s = "feuille";
	else if (coup == PIERRE) s = "pierre";
	else s = "ciseaux";
	char* v = malloc(25 * sizeof(char));
	strcpy(v, s);
	return v;
}

void score(int joueur, int ordinateur, int * score_joueur, int * score_ordinateur){
	printf("\nLe joueur gagnant est...");
	if (joueur > ordinateur || (joueur == PIERRE && ordinateur == CISEAUX)) {
		printf(" vous !\n");
		char* cj = get_name(joueur);
		char* co = get_name(ordinateur);
		printf("Vous avez joué %s ce qui bat son %s", cj, co);
		free(cj);
		free(co);
		(*score_joueur)++;
	} else if (joueur < ordinateur || (ordinateur == PIERRE && joueur == CISEAUX)) {
		printf(" l'ordinateur !\n");
		char* cj = get_name(joueur);
		char* co = get_name(ordinateur);
		printf("Il a joué %s ce qui bat votre %s\n", co, cj);
		free(cj);
		free(co);
		(*score_ordinateur)++;
	} else {
		printf(" oh non, la partie est nulle !");
	}
	printf("\n");
}

void jeu(){
	int score_ordinateur = 0, score_joueur = 0;
	while (score_ordinateur < 3 && score_joueur < 3) {
		printf("Choissez votre coup :\n- 1 pour pierre\n- 2 pour feuille\n- 3 pour ciseaux\n");
		score(choix_joueur(), choix_ordinateur(), &score_joueur, &score_ordinateur);
	}
	printf("Scores finaux:\n- Joueur : %d\n- Ordinateur : %d\n\n", score_joueur, score_ordinateur);
}

int main(){
	srand(time(NULL));
	jeu();
	return 0;
}

#include <stdio.h>
#define MAX 20

int premier(int n){
	if (n < 2) return 0;
	for (int i = 2; i < n;i++){
		if (n%i == 0) return 0; // est une boucle avec sortie anticipée
	}
	return 1;
}

void afficheNombresPremiers(int max){
	for (int i = 2; i <= max; i++){
		if (premier(i)) printf("%d\n", i);
	}
}

int main(){
	printf("Liste des nombres premiers <= %d\n", MAX);
	afficheNombresPremiers(MAX);
	return 0;
}

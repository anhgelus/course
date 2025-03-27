#include <stdio.h>
#define NB_PLANETES 8

typedef struct{
	char name[10];
	float density;
	float distance;
	int satellites;
} planete;

void affichePlanete(planete *p){
	printf(
		"%s:\n- densité : %.02f\n- distance : %.2f\n- nombre de satellites : %d\n\n", 
		p->name,
		p->density,
		p->distance,
		p->satellites
	);
}

void afficheToutesPlanetes(planete ps[]) {
	for (int i = 0; i < NB_PLANETES; i++) affichePlanete((ps+i));
}

void modifieDensite(planete *p, float v){
	p->density = v;
}

int main(){
    planete systemeSolaire[NB_PLANETES] ={{"Mercure", 5.42, 58, 0},{"Venus", 5.25, 108.2, 0},{"Terre", 5.52,149.6,1},{"Mars",3.94,227.9,2},{"Jupiter",1.314,778.3,16},{"Saturne",0.69,1427,17},{"Uranus",1.19,2869,15},{"Neptune",1.6,4496,2}};           
	afficheToutesPlanetes(systemeSolaire);
    return 0;
}

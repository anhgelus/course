#include <cini.h>

void carre(int c, int x, int y){
	for (int i = 0; i<c;i++){
		CINI_draw_pixel(x+i, y, "blue");
		CINI_draw_pixel(x+i, y+c, "green");
		CINI_draw_pixel(x, y+i, "red");
		CINI_draw_pixel(x+c, y+i, "black");
	}
}

void carres_remontant(int c, int x, int y){
	int nx = x, ny = y;
	while (nx >= 0 && ny >= 0){
		carre(c, nx, ny);
		nx -= 20;
		ny -= 20;
	}
}

int main() {
	CINI_open_window(400, 400, "Carre");
	CINI_fill_window("white");
	carres_remontant(100, 50, 100);
	CINI_loop();

	return 0;
}

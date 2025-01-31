#include <cini.h>
#define WIDTH 400
#define HEIGHT 400

int position(int a, int b, int x, int y){
	// t(z) = az+b
	// y(x) = alpha x + beta
	int straight_line_y = a*x+b;
	if (straight_line_y > y) return 1;
	if (straight_line_y < y) return -1;
	return 0;
}

void affiche(int a, int b, int width, int height){
	for (int x = 0; x < width; x++){
		for (int y = 0; y < height; y++){
			int pos = position(a, b, x, y);
			char* color;
			if (pos == 1) color = "red";
			else if (pos == -1) color = "blue";
			else color = "black";	
			CINI_draw_pixel(x, y, color);
		}
	}
}

int main(){
	CINI_open_window(WIDTH, HEIGHT, "Hello");
	CINI_fill_window("white");
	affiche(1, 0, WIDTH, HEIGHT);
	CINI_loop();
	return 0;
}


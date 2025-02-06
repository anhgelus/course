#include <cini.h>
#define WIDTH 1000
#define HEIGHT 1000

int rotate(int v1, int v2) {
	return (5*v2+95*v1)/100; // version avec plus de détails, normalement c'est (v2+9*v1)/10
}

void triangles(int height, int width, int eps){
	int x_a, x_b, x_c;
	int y_a, y_b, y_c;
	x_a = 0; y_a = height-1;
	x_b = width-1; y_b = height-1;
	x_c = (width-1) >> 1; y_c = 0;
	while ( (x_a-x_b)*(x_a-x_b) + (y_a-y_b)*(y_a-y_b) > eps*eps ){
		CINI_draw_line(x_a, y_a, x_b, y_b, "red");
		CINI_draw_line(x_a, y_a, x_c, y_c, "blue");
		CINI_draw_line(x_c, y_c, x_b, y_b, "green");
	
		int old_x[] = {x_a, x_b, x_c};
		int old_y[] = {y_a, y_b, y_c};

		x_a = rotate(old_x[0], old_x[1]); y_a = rotate(old_y[0], old_y[1]);
		x_b = rotate(old_x[1], old_x[2]); y_b = rotate(old_y[1], old_y[2]);
		x_c = rotate(old_x[2], old_x[0]); y_c = rotate(old_y[2], old_y[0]);
	}
}

int main(){
	CINI_open_window(WIDTH, HEIGHT, "Hello");
	CINI_fill_window("white");
	triangles(HEIGHT, WIDTH, 2);
	CINI_loop();
	return 0;
}

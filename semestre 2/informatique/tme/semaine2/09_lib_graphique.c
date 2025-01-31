#include <cini.h>

void diagonale(int x){
	for (int i = 0; i <= x; i++) {
		CINI_draw_pixel(i, i, "orange");
	}
}

int main(){
	CINI_open_window(400, 300, "hello world");
	diagonale(200);
	CINI_loop();

	return 0;
}

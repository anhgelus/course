#include <stdio.h>
int recherche_rec(int* arr, int n, int v){
	if (n == 0) return -1;
	if (arr[n-1] == v) return n-1;
	return recherche_rec(arr, n-1, v);
}

int main() {
	int arr[] = {1, 2, 3, 5, 5};
	printf("%d\n",recherche_rec(arr, 5, 6));
	return 0;
}

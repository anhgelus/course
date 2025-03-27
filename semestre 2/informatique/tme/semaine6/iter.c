#include <stdio.h>
int recherche_iter(int* arr, int n, int v) {
    int i;
    for (i = 0; arr[i] != v && i < n; i++);
    if (i == n) return -1;
    return i;
}

int main() {
	int arr[] = {1, 2, 3};
	printf("%d\n", recherche_iter(arr, 3, 4));
	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void swap2d(int* a[], int* b[]) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int n = 0;
    int **time;
    int h, m, dur;
    int res = 1;
    int i = 0, j = 0;
    bool swapped = false;
    //input n
    scanf("%d", &n);
    if(!(time = (int**)malloc(n * sizeof(int*)))) return -1;
    //input waktu
    for(i = 0; i < n; ++i) {
	scanf("%d:%d %d", &h, &m, &dur);
	time[i] = (int*)malloc(2 * sizeof(int));
	time[i][0] = h * 60 + m;
	time[i][1] = h * 60 + m + dur;
    }
    //urutkan array time berdasarkan total interval tiap matkul
    for(i = 0; i < n - 1; ++i) {
	swapped = false;
	for(j = 0; j < n - 1 - i; ++j) {
	    if(time[j][1] > time[j + 1][1]) {
		swap2d(&time[j], &time[j + 1]);
		swapped = true;
	    }
	}
	if(!swapped) break;
    }
    //menggunakan brute force, maksimalkan hasil
    i = 0, j = 1;
    while(j < n) {
        if(time[i][1] <= time[j][0]) ++res, i = j++;
        else ++j;
    }
    for(i = 0; i < n; ++i)
	free(time[i]);
    free(time);
    printf("%d\n", res);

    return 0;
}

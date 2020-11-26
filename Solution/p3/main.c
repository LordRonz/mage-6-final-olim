#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minDel(char* s) {
    int n = strlen(s), c;
    int l[n][n];
    for(int i = 0; i < n; ++i) l[i][i] = 1;
    for(c = 2; c <= n; ++c) {
	for(int i = 0; i < n - c + 1; ++i) {
	    int j = i + c - 1;
	    if(s[i] == s[j] && c == 2) l[i][j] = 2;
	    else if(s[i] == s[j])
		l[i][j] = l[i + 1][j - 1] + 2;
	    else
		l[i][j] = l[i][j - 1] > l[i + 1][j] ? l[i][j - 1] : l[i + 1][j];
	}
    }
    return n - l[0][n - 1];
}

int main(void) {
    char s[1100];
    int n;
    scanf("%d", &n);
    while(n--) {
	scanf("%s", s);
	printf("%d\n", minDel(s));
    }
    return 0;
}

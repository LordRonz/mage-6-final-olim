#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minDel(char* s) {
    //mencari minimum deletion menggunakan algoritma longest palindromic subsequence
    int n = strlen(s);
    int dp[n][n];
    memset(dp, 0, sizeof(int) * n * n);
    //mengisi dp table, yang nilainya akan terakumulasi di dp[0][n - 1]
    for(int i = n - 1; i >= 0; --i) {
	dp[i][i] = 1;
	for(int j = i + 1; j < n; ++j) {
	    if(s[i] == s[j])
		dp[i][j] = dp[i + 1][j - 1] + 2;
	    else
		dp[i][j] = dp[i + 1][j] > dp[i][j - 1] ? dp[i + 1][j] : dp[i][j - 1]; 
	}
    }
    //untuk mendapatkan minimum deletion, tinggal mengurangi panjang string dengan lps
    return n - dp[0][n - 1];
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

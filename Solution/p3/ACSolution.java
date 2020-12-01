import java.util.*;
import java.io.*;

public class ACSolution {
    static int minDel(char[] s) {
	int n = s.length;
	int[][] dp = new int[n][n];
	for(int i = n - 1; i >= 0; --i) {
	    dp[i][i] = 1;
	    for(int j = i + 1; j < n; ++j) {
		if(s[i] == s[j])
		    dp[i][j] = dp[i + 1][j - 1] + 2;
		else
		    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
	    }
	}
	return n - dp[0][n - 1];
    }

    public static void main(String[] args) {
	Scanner scan = new Scanner(System.in);
	int n = Integer.parseInt(scan.nextLine());
	for(int i = 0; i < n; ++i) {
	    System.out.println(minDel(scan.nextLine().toCharArray()));
	}
    }
}

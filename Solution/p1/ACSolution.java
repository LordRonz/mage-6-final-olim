import java.util.*;
import java.io.*;

public class ACSolution {
    public static void main(String[] args) throws IOException {
	int n, h, m, dur, res = 1;
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	n = Integer.parseInt(br.readLine());
	int[][] time = new int[n][2];
	for(int i = 0; i < n; ++i) {
	    String[] s = br.readLine().trim().split(":|\\s+");
	    h = Integer.parseInt(s[0]);
	    m = Integer.parseInt(s[1]);
	    dur = Integer.parseInt(s[2]);
	    time[i][0] = h * 60 + m;
	    time[i][1] = h * 60 + m + dur;
	}
	Arrays.sort(time, (a, b) -> Integer.compare(a[1], b[1]));
	int i = 0, j = 1;
	while(j < n) {
	    if(time[i][1] <= time[j][0]) {
		++res;
		i = j++;
	    }
	    else j++;
	}
	System.out.println(res);
    }
}

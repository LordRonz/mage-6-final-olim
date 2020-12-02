import java.util.*;
import java.io.*;

public class ACSolution {
    public static void main(String[] args) {
	int i, k, a, i2, k2, a2, day, day2, maxDay = 0, cnt, md;
	Scanner scan = new Scanner(System.in);
	String[] s = scan.nextLine().split(" ");
	i = Integer.parseInt(s[0]);
	k = Integer.parseInt(s[1]);
	a = Integer.parseInt(s[2]);
	md = Math.min(Math.min(i / 3, k / 2), a / 2);
	i -= md * 3;
	k -= md * 2;
	a -= md * 2;
	for(day = 1; day <= 7; ++day) {
	    cnt = 0;
	    day2 = day;
	    i2 = i;
	    k2 = k;
	    a2 = a;
	    while(true) {
		int t = day2 % 7;
		if(t == 1 || t == 4 || t == 0)
		    --i2;
		else if(t == 2 || t == 6)
		    --k2;
		else if(t == 3 || t == 5)
		    --a2;
		if(i2 < 0 || k2 < 0 || a2 < 0) break;
		++day2;
		++cnt;
	    }
	    cnt += 7 * md;
	    maxDay = Math.max(cnt, maxDay);
	}
	System.out.println(maxDay);
    }
}

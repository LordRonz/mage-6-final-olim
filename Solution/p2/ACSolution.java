import java.util.*;
import java.io.*;

public class ACSolution {
    public static void main(String[] args) {
	int[] freq = new int[11];
	int i = 0;
	boolean same = false;
	Scanner scan = new Scanner(System.in);
	int n = scan.nextInt();
	int[] ui = new int[n + 1];
	for(i = 1; i <= n; ++i) { 
	    ui[i] = scan.nextInt();
	    ++freq[ui[i]];
	}
	for(i = n; i > 0; --i) {
	    for(int j = 1; j <= 10 && !same; ++j) {
		if(freq[j] == 0) continue;
		--freq[j];
		int f = -1;
		same = true;
		for(int k = 1; k <= 10; ++k) {
		    if(freq[k] > 0) {
			if(f == -1) f = freq[k];
			else if(f != freq[k]) {
			    same = false;
			    break;
			}
			f = freq[k];
		    }
		}
		++freq[j];
	    }
	    if(same) break;
	    --freq[ui[i]];
	}
	System.out.println(i);
    }
}

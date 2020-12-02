import java.util.*;
import java.io.*;

public class ACSolution {
    static char[][] map;

    static int BFS(int m, int n, int[] start, char target) {
	boolean[][] visited = new boolean[m][n];
	int[][] dist = new int[m][n];
	visited[start[0]][start[1]] = true;
	Queue<int[]> Q = new LinkedList<int[]>();
	Q.add(start);
	while(!Q.isEmpty()) {
	    int[] cur = Q.remove();
	    int i = cur[0], j = cur[1];
	    if(map[i][j] == target) return dist[i][j];
	    if(i + 1 < m && !visited[i + 1][j] && map[i + 1][j] != '#') {
		Q.add(new int[]{i + 1, j});
		visited[i + 1][j] = true;
		dist[i + 1][j] = dist[i][j] + 1;
	    }
	    if(i - 1 >= 0 && !visited[i - 1][j] && map[i - 1][j] != '#') {
		Q.add(new int[]{i - 1, j});
		visited[i - 1][j] = true;
		dist[i - 1][j] = dist[i][j] + 1;
	    }
	    if(j + 1 < n && !visited[i][j + 1] && map[i][j + 1] != '#') {
		Q.add(new int[]{i, j + 1});
		visited[i][j + 1] = true;
		dist[i][j + 1] = dist[i][j] + 1;
	    }
	    if(j - 1 >= 0 && !visited[i][j - 1] && map[i][j - 1] != '#') {
		Q.add(new int[]{i, j - 1});
		visited[i][j - 1] = true;
		dist[i][j - 1] = dist[i][j] + 1;
	    }
	}
	return -1;
    }

    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int[][] t = new int[4][2];
	char[] s = {'M', 'A', 'G', 'E'};
	int minDist = 0;
	String[] strs = br.readLine().trim().split("\\s+");
        int m = Integer.parseInt(strs[0]);
	int n = Integer.parseInt(strs[1]);
	map = new char[m][n];
	for(int i = 0; i < m; ++i) {
	    String temp = br.readLine();
	    for(int j = 0; j < n; ++j) {
		map[i][j] = temp.charAt(j);
		if(map[i][j] == 'J') {
		    t[0][0] = i;
		    t[0][1] = j;
		}
		else if(map[i][j] == 'M') {
		    t[1][0] = i;
		    t[1][1] = j;
		}
		else if(map[i][j] == 'A') {
		    t[2][0] = i;
		    t[2][1] = j;
		}
		else if(map[i][j] == 'G') {
		    t[3][0] = i;
		    t[3][1] = j;
		}
	    }
	}
	for(int i = 0; i < 4; ++i) {
	    int temp = BFS(m, n, t[i], s[i]);
	    if(temp == -1) {
		System.out.println(-1);
		return;
	    }
	    minDist += temp;
	}
	System.out.println(minDist);
    }

}

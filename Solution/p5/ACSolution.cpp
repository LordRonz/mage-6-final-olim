#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <cstdlib>
using namespace std;
typedef pair<int, int> ii;
char map[80][80];

int BFS(int m, int n, ii start, char target);

int main() {
    int m, n;
    ii t[4];
    int minDist = 0;
    int temp = 0;
    char s[] = "MAGE";
    scanf("%d %d", &m, &n);
    scanf("\n");
    //saring input, bila mendapat salah satu dari J, M, A, G taruh di pair t
    for(int i = 0; i < m; ++i) {
	for(int j = 0; j < n; ++j) {
	    scanf("%c", &map[i][j]);
	    if(map[i][j] == 'J')
		t[0] = make_pair(i, j);
	    else if(map[i][j] == 'M')
		t[1] = make_pair(i, j);
	    else if(map[i][j] == 'A')
		t[2] = make_pair(i, j);
	    else if(map[i][j] == 'G')
		t[3] = make_pair(i, j);
	}
	scanf("\n");
    }
    //tiap-tiap checkpoint, lakukan bfs dan jumlahkan jaraknya
    for(int i = 0; i < 4; i++) {
	temp = BFS(m, n, t[i], s[i]);
	if(temp == -1) {
	    printf("-1\n");
	    return 0;
	}
	minDist += temp;
    }
    printf("%d\n", minDist);
    return 0;
}

int BFS(int m, int n, ii start, char target) {
    //inisialisasi vector visited yang diisi dengan false semua dan dist yang diisi 0 semua
    vector<vector<bool>> visited(m, vector<bool>(n));
    vector<vector<int>> dist(m, vector<int>(n));
    //menandai start point sebagai visited agar tidak bolak balik
    visited[start.first][start.second] = true;
    queue<ii> Q;
    Q.push(start);
    //selama queue tidak kosong lakukan iterasi
    while(!Q.empty()) {
	ii cur = Q.front();
	Q.pop();
	int i = cur.first, j = cur.second;
	//jika koordinat map dari pair sama dengan target, di return jaraknya pada tabel dist
	if(map[i][j] == target) return dist[i][j];
	//mengunjungi neighbor-neighbor dari koordinat saat ini yakni atas, bawah, kiri
	//kanan apabila memenuhi syarat ifnya, dan memasukkan dalam queue
	if(i + 1 < m && !visited[i + 1][j] && map[i + 1][j] != '#') {
	    Q.push(make_pair(i + 1, j));
	    visited[i + 1][j] = true;
	    dist[i + 1][j] = dist[i][j] + 1;
	}
	if(i - 1 >= 0 && !visited[i - 1][j] && map[i - 1][j] != '#') {
	    Q.push(make_pair(i - 1, j));
	    visited[i - 1][j] = true;
	    dist[i - 1][j] = dist[i][j] + 1;
	}
	if(j + 1 < n && !visited[i][j + 1] && map[i][j + 1] != '#') {
	    Q.push(make_pair(i, j + 1));
	    visited[i][j + 1] = true;
	    dist[i][j + 1] = dist[i][j] + 1;
	}
	if(j - 1 >= 0 && !visited[i][j - 1] && map[i][j - 1] != '#') {
	    Q.push(make_pair(i, j - 1));
	    visited[i][j - 1] = true;
	    dist[i][j - 1] = dist[i][j] + 1;
	}
    }
    return -1;
}

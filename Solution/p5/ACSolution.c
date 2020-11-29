#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 3000

char map[80][80];

struct queue {
    int items[SIZE][2];
    int front;
    int rear;
};
//                WARNING
//                SEBAIKNYA TIDAK MENGGUNAKAN C SAAT SOAL BFS KARENA TIDAK ADA
//                IMPLEMENTASI QUEUE
//                INI HANYALAH UNTUK MENAMBAH PENGETAHUAN SAJA
//                DISINI MANUAL MENGIMPLEMENTASIKAN QUEUE YANG MANA MEMBUANG WAKTU
struct queue* createQueue();
void enqueue(struct queue* q, int* value);
int* dequeue(struct queue* q);
int isEmpty(struct queue* q);
int BFS(int m, int n, int* start, char target);

int main() {
    int m, n;
    int t[4][2];
    int minDist = 0;
    int temp = 0;
    char s[] = "MAGE";
    scanf("%d %d", &m, &n);
    scanf("\n");
    for(int i = 0; i < m; ++i) {
	for(int j = 0; j < n; ++j) {
	    scanf("%c", &map[i][j]);
	    if(map[i][j] == 'J')
		t[0][0] = i, t[0][1] = j;
	    else if(map[i][j] == 'M')
		t[1][0] = i, t[1][1] = j;
	    else if(map[i][j] == 'A')
		t[2][0] = i, t[2][1] = j;
	    else if(map[i][j] == 'G')
		t[3][0] = i, t[3][1] = j;
	}
	scanf("\n");
    }
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

struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct queue* q) {
    if (q->rear == -1)
	return 1;
    return 0;
}

int* dequeue(struct queue* q) {
    int *item = malloc(2 * sizeof(int));
    if (isEmpty(q)) {
	;
    } else {
	item[0] = q->items[q->front][0];
	item[1] = q->items[q->front][1];
	q->front++;
	if (q->front > q->rear) {
	    q->front = q->rear = -1;
	}
    }
    return item;
}

void enqueue(struct queue* q, int* value) {
    if (q->rear == SIZE - 1)
	;
    else {
	if (q->front == -1)
	    q->front = 0;
	q->rear++;
	q->items[q->rear][0] = value[0];
	q->items[q->rear][1] = value[1];
    }
}

int BFS(int m, int n, int* start, char target) {
    bool visited[m][n];
    memset(visited, 0, m * n * sizeof(bool));
    int dist[m][n];
    memset(dist, 0, m * n * sizeof(int));

    visited[start[0]][start[1]] = true;
    struct queue* Q = createQueue();
    enqueue(Q, start);
    while(!isEmpty(Q)) {
	int *cur = dequeue(Q);
	int i = cur[0], j = cur[1];
	if(map[i][j] == target) { 
	    free(Q);
	    return dist[i][j];
	}
	if(i + 1 < m && !visited[i + 1][j] && map[i + 1][j] != '#') {
	    int temp[2] = {i + 1, j};
	    enqueue(Q, temp);
	    visited[i + 1][j] = true;
	    dist[i + 1][j] = dist[i][j] + 1;
	}
	if(i - 1 >= 0 && !visited[i - 1][j] && map[i - 1][j] != '#') {
	    int temp[2] = {i - 1, j};
	    enqueue(Q, temp);
	    visited[i - 1][j] = true;
	    dist[i - 1][j] = dist[i][j] + 1;
	}
	if(j + 1 < n && !visited[i][j + 1] && map[i][j + 1] != '#') {
	    int temp[2] = {i, j + 1};
	    enqueue(Q, temp);
	    visited[i][j + 1] = true;
	    dist[i][j + 1] = dist[i][j] + 1;
	}
	if(j - 1 >= 0 && !visited[i][j - 1] && map[i][j - 1] != '#') {
	    int temp[2] = {i, j - 1};
	    enqueue(Q, temp);
	    visited[i][j - 1] = true;
	    dist[i][j - 1] = dist[i][j] + 1;
	}
	free(cur);
    }
    free(Q);
    return -1;
}

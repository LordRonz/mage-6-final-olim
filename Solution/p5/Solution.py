#!/usr/bin/env python
from collections import deque

def BFS(mp, m, n, start, target):
    visited = [[False] * n for _ in range(m)]
    dist = [[0] * n for _ in range(m)]

    visited[start[0]][start[1]] = True

    Q = deque([start])

    while Q:
        i, j = Q.popleft()
        
        if mp[i][j] == target: return dist[i][j]

        if i + 1 < m and not visited[i + 1][j] and mp[i + 1][j] != '#':
            Q.append([i + 1, j])
            visited[i + 1][j] = True
            dist[i + 1][j] = dist[i][j] + 1

        if i - 1 >= 0 and not visited[i - 1][j] and mp[i - 1][j] != '#':
            Q.append([i - 1, j])
            visited[i - 1][j] = True
            dist[i - 1][j] = dist[i][j] + 1

        if j + 1 < n and not visited[i][j + 1] and mp[i][j + 1] != '#':
            Q.append([i, j + 1])
            visited[i][j + 1] = True
            dist[i][j + 1] = dist[i][j] + 1

        if j - 1 >= 0 and not visited[i][j - 1] and mp[i][j - 1] != '#':
            Q.append([i, j - 1])
            visited[i][j - 1] = True
            dist[i][j - 1] = dist[i][j] + 1

    return -1

def main():
    t = [[], [], [], []]
    mp = []
    res = 0
    m, n = (int(i) for i in input().split())
    for i in range(m):
        temp = []
        for j, c in enumerate(input()):
            temp.append(c)
            if c == 'J':
                t[0].extend([i, j])
            elif c == 'M':
                t[1].extend([i, j])
            elif c == 'A':
                t[2].extend([i, j])
            elif c == 'G':
                t[3].extend([i, j])
        mp.append(temp)
    for target, c in zip(t, "MAGE"):
        temp = BFS(mp, m, n, target, c)
        if temp == -1:
            print(-1)
            return
        res += temp

    print(res)

if __name__ == "__main__":
    main()

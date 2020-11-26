#!/usr/bin/env python3

def main():
    time = [];
    res = 1
    n = int(input())
    for i in range(n):
        h, m, dur = (int(i) for i in input().replace(':', ' ').split())
        time.append([h * 60 + m, h * 60 + m + dur])

    time.sort(key = lambda x: x[1])

    i, j = 0, 1
    
    while j < n:
        if time[i][1] <= time[j][0]:
            res += 1
            i = j
        j += 1
    
    print(res)

if __name__ == "__main__":
    main()

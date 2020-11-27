#!/usr/bin/env python3

def minDel(s):
    n = len(s)
    dp = [[1 if i == j else 0 for i in range(n)] for j in range(n)]
    #for c in range(2, n + 1):
    #    for i in range(n - c + 1):
    #        j = i + c - 1
    #        if s[i] == s[j] and c == 2: l[i][j] = 2
    #        elif s[i] == s[j]:
    #            l[i][j] = l[i + 1][j - 1] + 2
    #        else:
    #            l[i][j] = max(l[i][j - 1], l[i + 1][j])
    for i in range(n, -1, -1):
        for j in range(i + 1, n):
            if s[i] == s[j]:
                dp[i][j] = dp[i + 1][j - 1] + 2
            else:
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])

    return n - dp[0][-1]

def main():
    for _ in range(int(input())):
        print(minDel(input()))

if __name__ == "__main__":
    main()

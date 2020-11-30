#!/usr/bin/env python3

def minDel(s):
    if(s == s[::-1]): return 0
    n = len(s)
    dp = [1] * n
    for j in range(1, n):
        pre = dp[j]
        for i in reversed(range(0, j)):
            tmp = dp[i]
            if s[i] == s[j]:
                dp[i] = 2 + pre if i + 1 <= j - 1 else 2
            else:
                dp[i] = max(dp[i + 1], dp[i])
            pre = tmp
    return n - dp[0]

def main():
    print('\n'.join(str(minDel(input())) for _ in range(int(input()))))

if __name__ == "__main__":
    main()

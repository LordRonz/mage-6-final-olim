#!/usr/bin/env python3

def main():
    i, k, a, maxDay = *(int(x) for x in input().split()), -1
    print(i, k, a)
    md = min(i // 3, k // 2, a // 2)
    i -= md * 3
    k -= md * 2
    a -= md * 2
    for day in range(1, 8):
        cnt = 0
        day2, i2, k2, a2 = day, i, k, a
        while True:
            t = day2 % 7
            if t == 1 or t == 4 or t == 0:
                i2 -= 1
            elif t == 2 or t == 6:
                k2 -= 1
            elif t == 3 or t == 5:
                a2 -= 1
            if min(i2, k2, a2) < 0:
                break
            day2 += 1
            cnt += 1
        maxDay = max(cnt + 7 * md, maxDay)
    
    print(maxDay)

if __name__ == "__main__":
    main()

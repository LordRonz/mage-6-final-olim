#!/usr/bin/env python3

def main():
    freq = [0 for i in range(15)]
    same = False
    n = int(input())
    ui = [-1]
    i = 0

    for i in map(int, input().split()):
        freq[i] += 1;
        ui.append(i);
        
    for i in range(n, 0, -1):
        for j in range(1, 11):
            if freq[j] == 0: continue
            freq[j] -= 1
            f = -1
            same = True
            for k in range(1, 11):
                if freq[k] > 0:
                    if f == -1: f = freq[k]
                    elif f != freq[k]:
                        same = False
                        break
                    f = freq[k]
            freq[j] += 1
            if same: break
        if same: break
        freq[ui[i]] -= 1

    print(i)

if __name__ == "__main__":
    main()

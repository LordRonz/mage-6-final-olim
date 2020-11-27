#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, k, a, i2, k2, a2, day, day2, maxDay = 0, cnt = 0, md;
    scanf("%d %d %d", &i, &k, &a);
    md = i / 3 < k / 2 ? i / 3 : k / 2;
    md = md < a / 2 ? md : a / 2;
    i -= md * 3;
    k -= md * 2;
    a -= md * 2;
    for(day = 1; day <= 7; ++day) {
	cnt = 0;
	day2 = day;
	i2 = i;
	k2 = k;
	a2 = a;
	while(1) {
	    int t = day2 % 7;
	    if(t == 1 || t == 4 || t == 0)
		--i2;
	    else if(t == 2 || t == 6)
		--k2;
	    else if(t == 3 || t == 5)
		--a2;
	    if(i2 < 0 || k2 < 0 || a2 < 0) break;
	    ++day2;
	    ++cnt;
	}
	cnt += 7 * md;
	maxDay = cnt > maxDay ? cnt : maxDay;
    }
    printf("%d", maxDay);
    return 0;
}

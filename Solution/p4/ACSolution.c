#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, k, a, i2, k2, a2, day, day2, maxDay = 0, cnt = 0, md;
    scanf("%d %d %d", &i, &k, &a);
    //mencari kelipatan 3, 2, 2 minimum dari tiap makanan
    md = i / 3 < k / 2 ? i / 3 : k / 2;
    md = md < a / 2 ? md : a / 2;
    //membuang kelipatan sehingga tersisa maks 2, 1, 1 dari masing-masing makanan
    i -= md * 3;
    k -= md * 2;
    a -= md * 2;
    //cek masing masing start dari senin hingga minggu
    for(day = 1; day <= 7; ++day) {
	cnt = 0;
	day2 = day;
	i2 = i;
	k2 = k;
	a2 = a;
	while(1) {
	    //mengurangi satu persatu makanan hingga salah satu habis
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
	//jumlah hari ditambahkan dengan kelipatan mingguan dan dibandingkan nilai maxnya
	cnt += 7 * md;
	maxDay = cnt > maxDay ? cnt : maxDay;
    }
    printf("%d", maxDay);
    return 0;
}

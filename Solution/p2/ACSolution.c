#include <stdio.h>
#include <stdbool.h>

int main(void) {
    //inisialisasi frekuensi
    int freq[20] = {0};
    int ui[100005], i, n;
    bool same = false;
    scanf("%d", &n);
    //input n
    for(i = 1; i <= n; ++i) {
	scanf("%d", &ui[i]);
	++freq[ui[i]];
    }
    //cek dari streak terbesar
    for(i = n; i > 0; --i) {
	//bruteforce menghilangkan satu persatu
	for(int j = 1; j <= 10 && !same; ++j) {
	    if(freq[j] == 0) continue;
	    --freq[j];
	    int f = -1;
	    same = true;
	    //setelah salah satu frekuensi dikurangi, dicek apakah semua frekuensi sama,
	    //jika ya, maka keluar dari loop dan print streak, jika tidak iterasi dilanjutkan
	    for(int k = 1; k <= 10; ++k) {
		if(freq[k] > 0) {
		    if(f == -1) f = freq[k];
		    else if(f != freq[k]) {
			same = false;
			break;
		    }
		    f = freq[k];
		}
	    }
	    ++freq[j];
	}
	if(same) break;
	//frekuensi dari ui ke i dikurangi apabila tidak dimungkinkan
	--freq[ui[i]];
    }
    printf("%d\n", i);
    return 0;
}

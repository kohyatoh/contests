#include <stdio.h>
#include <stdlib.h>
typedef long long Int;
#define MOD (1000000007LL)

Int a[1024], r[1024];
char buf[1024];

int main() {
    a[1] = 1;
    for (int i = 1; i <= 1000; i++) {
        for (int j = i; j > 0; j--) {
            const Int v = a[j] % MOD;
            r[i] += v;
            a[j+1] += v;
            a[j] += (j-1)*v;
        }
        r[i] %= MOD;
    }
    gets(buf);
    int T = atoi(buf);
    while (T--) {
        gets(buf);
        int n = atoi(buf);
        printf("%d\n", r[n]);
    }
    return 0;
}

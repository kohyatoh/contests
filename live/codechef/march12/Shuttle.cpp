#include <stdio.h>
#include <string.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
inline void cmax(int &a, int b) { if (a < b) a = b; }

int phi[20000], pt[20000];

int main() {
    rep (i, 20000) phi[i] = i;
    for (int i = 2; i < 20000; i++) if (!pt[i]) {
        phi[i] -= phi[i] / i;
        for (int j = i+i; j < 20000; j += i) {
            phi[j] -= phi[j] / i;
            pt[j] = i;
        }
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf(" %d", &n);
        printf("%d\n", phi[n]);
    }
    return 0;
}

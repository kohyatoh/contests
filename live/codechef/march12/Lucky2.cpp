#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;
#define MOD (1000000007LL)

#define N (14)
int luk[N] = { 4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777 };
Int C[1024][1024], p2[1024], p8[1024];
char a[2000], b[2000];

bool is_lucky(const char *p) {
    int c = 0;
    while (*p) {
        if (*p == '4' || *p == '7') c++;
        p++;
    }
    rep (i, N) if (c == luk[i]) return true;
    return false;
}

inline Int f(int n, int c) {
    if (c < 0 || c > n) return 0;
    const int k = n - c;
    return p2[c] * p8[k] % MOD * C[n][k] % MOD;
}

int calc(const char *p) {
    const int n = strlen(p);
    Int ans = 0;
    int c = 0;
    rep (k, n) {
        rep (i, N) {
            int a = 0, b = p[k]-'0';
            if (p[k] > '4') a++, b--;
            if (p[k] > '7') a++, b--;
            ans = (ans + a * f(n-1-k, luk[i]-c-1)) % MOD;
            ans = (ans + b * f(n-1-k, luk[i]-c)) % MOD;
        }
        if (p[k] == '7' || p[k] == '4') c++;
    }
    return ans;
}

int main() {
    p2[0] = p8[0] = 1;
    rep (i, 1023) p2[i+1] = (p2[i] * 2) % MOD;
    rep (i, 1023) p8[i+1] = (p8[i] * 8) % MOD;
    C[0][0] = 1;
    rep (i, 1023) rep (j, 1023) {
        C[i+1][j] = (C[i+1][j] + C[i][j]) % MOD;
        C[i+1][j+1] = (C[i+1][j+1] + C[i][j]) % MOD;
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf(" %s %s", a, b);
        const Int ans = (calc(b) - calc(a) + is_lucky(b) + MOD) % MOD;
        cout << ans << endl;
    }
    return 0;
}

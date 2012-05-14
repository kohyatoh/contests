#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;
#define MOD (1000000007LL)

Int ipow(Int a, Int x) {
    if (x == 0) return 1;
    if (x % 2) return a*ipow(a, x-1)%MOD;
    return ipow(a*a%MOD, x/2);
}

inline Int inv(Int a) { return ipow(a, MOD-2); }

Int B[3000], C[3000][3000];

void prepare() {
    C[0][0] = 1;
    rep (i, 2800) rep (j, 2800) {
        C[i+1][j] = (C[i+1][j]+C[i][j]) % MOD;
        C[i+1][j+1] = (C[i+1][j+1]+C[i][j]) % MOD;
    }
    B[0] = 1;
    for (int k = 1; k < 2800; k++) {
        Int s = 0;
        rep (i, k) {
            Int b = C[k+1][i]*B[i] % MOD;
            if ((k-i)%2 == 0) b = MOD - b;
            s = (s + b) % MOD;
        }
        B[k] = s * inv(C[k+1][k]) % MOD;
    }
}

// 1^k + 2^k + ... + n^k mod MOD
Int powsum(Int n, Int k) {
    Int a = 0;
    rep (i, k+1) {
        a = (a + C[k+1][i]*B[i]%MOD*ipow(n, k+1-i)) % MOD;
    }
    return a * inv(k+1) % MOD;
}

Int solve(Int n, Int k) {
    Int ans = 0;
    ans = (ans + ipow(n*(n+1)/2%MOD, k)) % MOD;
    ans = (ans - powsum(n, k) + MOD) % MOD;
    return ans;
}

int main() {
    prepare();
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        Int n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}

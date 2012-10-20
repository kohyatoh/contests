#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;
#define MOD (1777777777LL)

#define P (1000000)
Int a[P], inv[P], invfct[P];

int main() {
    a[0] = 1;
    a[1] = 0;
    for (int i = 2; i < P; i++) {
        a[i] = (i-1)*(a[i-1]+a[i-2]) % MOD;
    }
    inv[1] = 1;
    for (int i = 2; i < P; i++) inv[i] = inv[MOD%i] * (MOD - MOD/i) % MOD;
    invfct[0] = 1;
    rep (i, P-1) invfct[i+1] = inv[i+1]*invfct[i]%MOD;
    Int N, K;
    cin >> N >> K;
    Int ans = 1;
    rep (i, K) ans = (ans * ((N-i)%MOD)) % MOD;
    ans = (ans * invfct[K]) % MOD;
    ans = (ans * a[K]) % MOD;
    cout << ans << endl;
    return 0;
}

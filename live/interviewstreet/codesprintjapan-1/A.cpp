#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

Int gcd(Int a, Int b) { return b == 0 ? a : gcd(b, a%b); }

int N;
Int K, a[2000000];

bool f(Int c) {
    rep (i, N) if (a[i]%c == 0) return false;
    return true;
}

int main() {
    cin >> N >> K;
    rep (i, N) cin >> a[i];
    rep (i, N) a[i] = gcd(K, a[i]);
    sort(a, a+N);
    N = unique(a, a+N) - a;
    int ans = 0;
    for (Int i = 1; i*i <= K; i++) if (K%i == 0) {
        if (f(i)) ans++;
        if (i*i < K && f(K/i)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}

#include <stdio.h>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

Int gcd(Int a, Int b) { return b == 0 ? a : gcd(b, a%b); }

int n;
Int m, a[32];
double p[32];

double f(Int b) {
    Int x = 1;
    rep (i, n) if (b&(1<<i)) {
        const Int g = gcd(x, a[i]);
        if ((double)x/g*a[i] > 2e18) return 0;
        x = x/g*a[i];
        if (x > m) return 0;
    }
    return m / x;
}

int main() {
    cin >> n >> m;
    rep (i, n) cin >> a[i];
    rep (i, n) cin >> p[i];
    rep (i, n) p[i] /= 100;
    double ans = 0;
    rep (b, 1<<n) if (b) {
        int c = 0;
        double q = 1.0;
        rep (i, n) if (b&(1<<i)) {
            c++;
            q *= p[i];
        }
        ans += q * f(b) * (c%2 ? 1 : -1);
    }
    printf("%.12f\n", ans);
    return 0;
}

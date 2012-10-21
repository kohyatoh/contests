#include <stdio.h>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

int N;
Int x[16], y[16], z[16];

Int solve() {
    rep (i, N) z[i] = x[i] + y[i];
    rep (i, N) if (z[i]%2 != z[0]%2) return -1;
    Int mz = -1;
    rep (i, N) mz = max(mz, z[i]);
    Int t = 0;
    for (int k = 0; ; k++) {
        t += k;
        if (t%2 == mz%2 && t >= mz) return k;
    }
}

int main() {
    cin >> N;
    rep (i, N) cin >> x[i] >> y[i];
    rep (i, N) {
        if (x[i] < 0) x[i] = -x[i];
        if (y[i] < 0) y[i] = -y[i];
    }
    cout << solve() << endl;
    return 0;
}

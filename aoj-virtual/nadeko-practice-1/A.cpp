#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

Int calc(Int a) {
    Int s = 0, r = a;
    r -= min(r, 180000LL);
    s += min(r, 300000LL) * 10;
    r -= min(r, 300000LL);
    s += min(r, 400000LL) * 15;
    r -= min(r, 400000LL);
    s += min(r, 300000LL) * 20;
    r -= min(r, 300000LL);
    s += r * 25;
    if (s > 0 && s < 200000) s = 200000;
    return (s+99)/100;
}

int main() {
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        Int a;
        cin >> a;
        cout << "Case " << _q+1 << ": " << calc(a) << endl;
    }
    return 0;
}

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

struct cow {
    int t, d;
} cows[100000];

bool operator<(const cow& l, const cow& r) {
    return l.t*r.d < r.t*l.d;
}

int main() {
    int n;
    scanf("%d", &n);
    rep(i, n) scanf("%d%d", &cows[i].t, &cows[i].d);
    sort(cows, cows+n);
    Int t=0, ans=0;
    rep(i, n) {
        ans += t*cows[i].d;
        t += cows[i].t*2LL;
    }
    cout << ans << endl;
    return 0;
}

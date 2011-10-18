#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

int x[10000], cnt[10000];

int main() {
    int a[5], w[100];
    rep(i, 50) w[i] = (i+1)*(i+1)*(i+1);
    rep(i, 50) w[i+50] = -w[i];
    rep(i, 5) scanf("%d", a+i);
    rep(i, 100) rep(j, 100) {
        const int v = w[i]*a[3]+w[j]*a[4];
        x[i*100+j] = -v;
    }
    sort(x, x+10000);
    const int n = unique(x, x+10000)-x;
    rep(i, 100) rep(j, 100) {
        const int v = w[i]*a[3]+w[j]*a[4];
        cnt[lower_bound(x, x+n, -v)-x]++;
    }
    Int ans = 0;
    rep(i, 100) rep(j, 100) rep(k, 100) {
        const int v = w[i]*a[0]+w[j]*a[1]+w[k]*a[2];
        const int ix = lower_bound(x, x+n, v)-x;
        if(ix<n && x[ix]==v) ans += cnt[ix];
    }
    cout << ans << endl;
    return 0;
}

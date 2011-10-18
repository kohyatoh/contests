#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

int main() {
    int a[5], w[100];
    rep(i, 50) w[i] = (i+1)*(i+1)*(i+1);
    rep(i, 50) w[i+50] = -w[i];
    rep(i, 5) scanf("%d", a+i);
    map<int, int> cnt;
    rep(i, 100) rep(j, 100) {
        const int v = w[i]*a[3]+w[j]*a[4];
        cnt[v]++;
    }
    Int ans = 0;
    rep(i, 100) rep(j, 100) rep(k, 100) {
        const int v = -w[i]*a[0]-w[j]*a[1]-w[k]*a[2];
        if(cnt.count(v)) ans += cnt[v];
    }
    cout << ans << endl;
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<30)

int n, m, f[20][20], a[20][20], z[20][20];

void flip(int i, int j) {
    z[i][j] = 1;
    a[i][j] = 1-a[i][j];
    if(i>0) a[i-1][j] = 1-a[i-1][j];
    if(j>0) a[i][j-1] = 1-a[i][j-1];
    if(i<n-1) a[i+1][j] = 1-a[i+1][j];
    if(j<m-1) a[i][j+1] = 1-a[i][j+1];
}

int calc(int b) {
    memset(z, 0, sizeof(z));
    memcpy(a, f, sizeof(a));
    int ans = 0;
    rep(i, m) if(b&(1<<i)) flip(0, i), ans++;
    rep(i, n-1) rep(j, m) if(a[i][j]) flip(i+1, j), ans++;
    rep(i, m) if(a[n-1][i]) return INF;
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    rep(i, n) rep(j, m) scanf("%d", f[i]+j);
    const int mm = 1<<m;
    int mv=INF, mb=-1;
    rep(b, mm) {
        const int v = calc(b);
        if(mv>v) mv=v, mb=b;
    }
    if(mb==-1) puts("IMPOSSIBLE");
    else {
        calc(mb);
        rep(i, n) rep(j, m) printf("%d%c", z[i][j], j<m-1 ? ' ' : '\n');
    }
    return 0;
}

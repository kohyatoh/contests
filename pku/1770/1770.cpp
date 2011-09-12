#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, e[200], d[200], g[200][200], memo[200][2];

int calc(int cur, int from, int state) {
    if(memo[cur][state]!=-1) return memo[cur][state];
    int ans=0;
    rep(d, state+1) {
        int s=0;
        rep(i, n) if(i!=from && g[cur][i]) s+=calc(i, cur, !d);
        if(d) s+=e[cur];
        ans=max(ans, s);
    }
    return memo[cur][state]=ans;
}

int main() {
    for(;;) {
        scanf("%d%d", &n, &m);
        if(n==0) return 0;
        rep(i, n) scanf("%d", e+i);
        sort(e, e+n);
        rep(i, m) scanf("%d", d+i);
        sort(d, d+m);
        rep(i, n) rep(j, n) g[i][j]=binary_search(d, d+m, abs(e[j]-e[i]));
        rep(i, n) rep(j, 2) memo[i][j]=-1;
        printf("%d\n", calc(0, -1, 1));
    }
}


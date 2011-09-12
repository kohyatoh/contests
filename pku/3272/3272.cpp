#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, dp1[5000], dp2[5000];
int u[50000], v[50000], next[50000], head[5000], rnext[50000], rhead[5000];

int main() {
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    memset(rhead, -1, sizeof(rhead));
    rep(i, m) {
        scanf("%d%d", u+i, v+i);
        u[i]--, v[i]--;
        if(u[i]>v[i]) swap(u[i], v[i]);
        next[i] = head[u[i]];
        head[u[i]] = i;
        rnext[i] = rhead[v[i]];
        rhead[v[i]] = i;
    }
    rep(i, n) {
        if(dp1[i]==0) dp1[i] = 1;
        for(int x=head[i]; x!=-1; x=next[x]) dp1[v[x]] += dp1[i];
    }
    for(int i=n-1; i>=0; i--) {
        if(dp2[i]==0) dp2[i] = 1;
        for(int x=rhead[i]; x!=-1; x=rnext[x]) dp2[u[x]] += dp2[i];
    }
    int ans = 0;
    rep(i, m) ans = max(ans, dp1[u[i]]*dp2[v[i]]);
    printf("%d\n", ans);
    return 0;
}

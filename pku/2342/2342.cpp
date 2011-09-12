#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[7000], r[7000];
int v[7000], next[7000], head[7000];
int memo[7000][2];

int calc(int at, int can) {
    if(memo[at][can]!=-1) return memo[at][can];
    int ans=0; // no guests
    if(can) {
        int s=a[at];
        for(int x=head[at]; x!=-1; x=next[x]) s+=calc(v[x], 0);
        ans = max(ans, s);
    }
    int ns=0;
    for(int x=head[at]; x!=-1; x=next[x]) ns+=calc(v[x], 1);
    ans = max(ans, ns);
    return memo[at][can] = ans;
}

int main() {
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    memset(memo, -1, sizeof(memo));
    memset(r, -1, sizeof(r));
    rep(i, n) scanf("%d", a+i);
    rep(i, n-1) {
        int _u, _v;
        scanf("%d%d", &_v, &_u);
        _u--, _v--;
        v[i]=_v; next[i]=head[_u]; head[_u]=i;
        r[_v] = _u;
    }
    rep(i, n) if(r[i]==-1) {
        printf("%d\n", calc(i, 1));
    }
    return 0;
}

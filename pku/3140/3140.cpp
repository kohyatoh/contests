#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

int n, m, c[100000];
Int cnt[100000];
int E, u[200000], v[200000], next[200000], head[100000];

Int rec(int cur, int pre) {
    cnt[cur] = c[cur];
    for(int x=head[cur]; x!=-1; x=next[x]) if(v[x]!=pre) {
        cnt[cur] += rec(v[x], cur);
    }
    return cnt[cur];
}

int main() {
    for(int _t=0;; _t++) {
        scanf("%d%d", &n, &m);
        if(n==0 && m==0) return 0;
        rep(i, n) scanf("%d", c+i);
        E = 0;
        memset(head, -1, sizeof(head));
        rep(_, m) {
            int a, b;
            scanf("%d%d", &a, &b);
            a--, b--;
            u[E]=a; v[E]=b; next[E]=head[u[E]]; head[u[E]]=E; E++;
            u[E]=b; v[E]=a; next[E]=head[u[E]]; head[u[E]]=E; E++;
        }
        rec(0, -1);
        const Int s = cnt[0];
        Int ans = s;
        for(int i=1; i<n; i++) {
            ans = min(ans, llabs((s-cnt[i])-cnt[i]));
        }
        cout << "Case " << _t+1 << ": " << ans << endl;
    }
}

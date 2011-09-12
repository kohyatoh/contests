#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, p[100000], cnt[100000], z[100000];
int E, u[100000], v[100000], next[100000], head[50000];

int rec(int cur, int pre) {
    p[cur] = pre;
    cnt[cur] = 1;
    for(int x=head[cur]; x!=-1; x=next[x]) if(v[x]!=pre) {
        cnt[cur] += rec(v[x], cur);
    }
    return cnt[cur];
}

int main() {
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    rep(_, n-1) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        u[E]=a; v[E]=b; next[E]=head[u[E]]; head[u[E]]=E; E++;
        u[E]=b; v[E]=a; next[E]=head[u[E]]; head[u[E]]=E; E++;
    }
    rec(0, -1);
    rep(i, n) {
        z[i] = n-cnt[i];
        for(int x=head[i]; x!=-1; x=next[x]) if(v[x]!=p[i]) {
            z[i] = max(z[i], cnt[v[x]]);
        }
    }
    int ans = n;
    rep(i, n) ans = min(ans, z[i]);
    int c = 0;
    rep(i, n) if(z[i]==ans) {
        if(c++) putchar(' ');
        printf("%d", i+1);
    }
    puts("");
    return 0;
}

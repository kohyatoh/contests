#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
int E, u[50000], v[50000], next[50000], rnext[50000], head[10000], rhead[10000];
bool vis[10000], visr[10000];

int kount(int at) {
    if(vis[at]) return 0;
    vis[at]=true;
    int s=1;
    for(int x=rhead[at]; x!=-1; x=rnext[x]) s+=kount(u[x]);
    return s;
}

int kountr(int at) {
    if(visr[at]) return 0;
    visr[at]=true;
    int s=1;
    for(int x=head[at]; x!=-1; x=next[x]) s+=kountr(v[x]);
    return s;
}

int main() {
    int m, a, b;
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    memset(rhead, -1, sizeof(rhead));
    rep(i, m) {
        scanf("%d%d", &a, &b);
        a--; b--;
        u[E]=a; v[E]=b; next[E]=head[a]; rnext[E]=rhead[b]; head[a]=rhead[b]=E++;
    }
    int ans=0, s=0;
    rep(i, n) if(!vis[i]) {
        s+=kount(i);
        if(s==n) {
            memset(vis, 0, sizeof(vis));
            if(kount(i)==n) ans=kountr(i);
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}

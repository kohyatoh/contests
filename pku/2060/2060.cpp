#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const int NN=1000, MM=100000;
int E, from[MM], to[MM], head[NN], next[MM], H;
int vis[NN], cvis, mat[NN];
void init(int h) { E=0; H=h; memset(head, -1, sizeof(head)); }
void add_edge(int s, int t) {
    t += H;
    from[E]=s; to[E]=t; next[E]=head[s]; head[s]=E; E++;
}
bool rec(int at) {
    if(at<0) return true;
    for(int x=head[at]; x!=-1; x=next[x]) if(vis[to[x]]!=cvis) {
        vis[to[x]] = cvis;
        if(rec(mat[to[x]])) {
            mat[at] = to[x];
            mat[to[x]] = at;
            return true;
        }
    }
    return false;
}
int match() {
    memset(mat, -1, sizeof(mat));
    memset(vis, -1, sizeof(vis));
    int r=0;
    rep(i, H) {
        cvis = i;
        if(rec(i)) r++;
    }
    return r;
}

int T, N;
int st[500], en[500], xs[500], ys[500], xe[500], ye[500];
int dist(int x1, int y1, int x2, int y2) { return abs(x2-x1)+abs(y2-y1); }

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        init(N);
        rep(i, N) {
            int h, m;
            scanf("%d:%d%d%d%d%d", &h, &m, xs+i, ys+i, xe+i, ye+i);
            st[i] = h*60+m;
            en[i] = st[i]+dist(xs[i], ys[i], xe[i], ye[i]);
        }
        rep(i, N) rep(j, N) {
            if(en[i]+dist(xe[i], ye[i], xs[j], ys[j])<st[j]) {
                add_edge(i, j);
            }
        }
        printf("%d\n", N-match());
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const int NN=5000, MM=10000;
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

struct seg {
    int x0, y0, x1, y1;
    seg(int x0, int y0, int x1, int y1) : x0(x0), y0(y0), x1(x1), y1(y1) {}
};

int h, w;
char f[100][100];

int main() {
    scanf("%d%d", &h, &w);
    memset(f, '.', sizeof(f));
    rep(j, h) rep(i, w) scanf(" %c", f[i+1]+j+1);
    vector<seg> xs, ys;
    for(int j=1; j<=h; j++) {
        int st=-1;
        rep(i, w+2) {
            if(f[i][j]=='*' && st==-1) st=i;
            else if(f[i][j]=='.' && st!=-1) {
                xs.push_back(seg(st, j, i-1, j));
                st = -1;
            }
        }
    }
    for(int i=1; i<=w; i++) {
        int st=-1;
        rep(j, h+2) {
            if(f[i][j]=='*' && st==-1) st=j;
            else if(f[i][j]=='.' && st!=-1) {
                ys.push_back(seg(i, st, i, j-1));
                st = -1;
            }
        }
    }
    init(xs.size());
    rep(i, xs.size()) rep(j, ys.size()) {
        if(xs[i].x0<=ys[j].x0 && ys[j].x0<=xs[i].x1
            && ys[j].y0<=xs[i].y0 && xs[i].y0<=ys[j].y1) add_edge(i, j);
    }
    printf("%d\n", match());
    return 0;
}


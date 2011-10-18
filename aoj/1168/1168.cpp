#include <stdio.h>
#include <string.h>
#include <complex>
#include <vector>
#include <set>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef complex<double> P;

struct Edge {
    int u, v, next;
    Edge() {}
    Edge(int _u, int _v) : u(_u), v(_v) {}
};

struct Graph {
    int n, m;
    vector<int> head;
    vector<Edge> es;
    Graph(int _n) : n(_n), m(0), head(_n, -1) {}
    void add(const Edge& e) {
        es.push_back(e);
        es.back().next = head[e.u];
        head[e.u] = m++;
    }
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int H, W, n, col[64][16];
char f[64][16];
int cx[1024], cnt[1024];

void draw(int i, int j, int c) {
    if(col[i][j]!=-1) return;
    col[i][j] = c;
    rep(d, 4) {
        const int x = i+dx[d], y = j+dy[d];
        if(x>=0 && x<H && y>=0 && y<W && f[i][j]==f[x][y]) draw(x, y, c);
    }
}

bool rec(const Graph& g, int ix) {
    cx[ix] = 0;
    cnt[ix] = 0;
    set<int> vis;
    for(int x=g.head[ix]; x!=-1; x=g.es[x].next) {
        const int to = g.es[x].v;
        if(vis.count(to)) continue;
        vis.insert(to);
        if(rec(g, to)==false) return false;
        cx[ix] += cx[to];
        cnt[ix] += cnt[to];
    }
    int minx = 2*W+1, maxx = -1;
    rep(i, H) rep(j, W) if(col[i][j]==ix) {
        cx[ix] += 2*j+1;
        cnt[ix] += 1;
        if(i==H-1 || (col[i+1][j]!=-1 && col[i+1][j]!=ix)) {
            minx = min(minx, 2*j);
            maxx = max(maxx, 2*(j+1));
        }
    }
    return minx*cnt[ix]<cx[ix] && cx[ix]<maxx*cnt[ix];
}

int main() {
    for(;;) {
        scanf("%d%d", &W, &H);
        if(W==0 && H==0) return 0;
        rep(i, H) rep(j, W) scanf(" %c", f[i]+j);
        n = 0;
        memset(col, -1, sizeof(col));
        rep(i, H) rep(j, W) if(f[i][j]!='.' && col[i][j]==-1) draw(i, j, n++);
        Graph g(n);
        rep(i, H-1) rep(j, W) if(col[i][j]!=-1) {
            if(col[i+1][j]!=-1 && col[i+1][j]!=col[i][j]) {
                g.add(Edge(col[i+1][j], col[i][j]));
            }
        }
        rep(i, W) if(col[H-1][i]!=-1) {
            puts(rec(g, col[H-1][i]) ? "STABLE" : "UNSTABLE");
            break;
        }
    }
}

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
inline double sq(double a) { return a*a; }

struct MST {
    typedef double weight;
    static const weight INF = 1e100;
    static const int N = 128;

    int n, r, no[N], prev[N], mark[N], temp[N];
    vector<int> comp[N];
    weight g[N][N], cost, mcost[N];
    
    void init(int _n) {
        n = _n;
        rep(i, n) rep(j, n) g[i][j] = INF;
    }

    void add_edge(int u, int v, weight w) { g[u][v] = w; }

    bool rec(int v, int s) {
        bool found = false;
        if(mark[v]) {
            found = true;
            memcpy(temp, no, sizeof(temp));
            for(;;) {
                cost += mcost[v];
                v = prev[v];
                if(v==s) break;
                while(comp[v].size()) {
                    no[comp[v].back()] = s;
                    comp[s].push_back(comp[v].back());
                    comp[v].pop_back();
                }
            }
            rep(j, n) if(j!=r && no[j]==s) {
                rep(i, n) if(no[i]!=s && g[i][j]<INF) g[i][j] -= mcost[temp[j]];
            }
        }
        mark[v] = 1;
        rep(i, n) if(no[i]!=no[v] && prev[no[i]]==v) {
            if(!mark[no[i]] || i==s) found |= rec(i, s);
        }
        return found;
    }

    weight solve(int _r) {
        r = _r;
        rep(i, n) {
            no[i] = i;
            comp[i].clear();
            comp[i].push_back(i);
        }
        cost = 0;
        for(;;) {
            memset(prev, -1, sizeof(prev));
            rep(i, n) mcost[i] = INF;
            rep(i, n) rep(j, n) if(j!=r && no[i]!=no[j] && g[i][j]<INF) {
                if(g[i][j] < mcost[no[j]]) {
                    mcost[no[j]] = g[i][j];
                    prev[no[j]] = no[i];
                }
            }
            memset(mark, 0, sizeof(mark));
            bool stop = true;
            rep(i, n) if(i!=r && !mark[i] && comp[i].size()) {
                if(rec(i, i)) stop = false;
            }
            if(stop) {
                rep(i, n) if(prev[i]>=0) cost += mcost[i];
                return cost;
            }
        }
    }
} mst;

int N, M;
double v[128][128];

double dot(int a, int b) {
    double s = 0;
    rep(i, N) s += v[a][i]*v[b][i];
    return s;
}

double norm(int a) { return dot(a, a); }

int main() {
    scanf("%d%d", &N, &M);
    rep(i, M) rep(j, N) scanf("%lf", v[i]+j);
    mst.init(M+1);
    rep(i, M) mst.add_edge(M, i, norm(i));
    rep(i, M) rep(j, M) if(i!=j) {
        if(norm(i)==0) mst.add_edge(i, j, norm(j));
        else mst.add_edge(i, j, norm(j)-sq(dot(i, j))/norm(i));
    }
    printf("%.9f\n", mst.solve(M));
    return 0;
}


#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;
#define MOD (1000000007)
inline void up(int &a, int b) { a = (a+b)%MOD; }

template<class W>
struct E {
    int u, v;
    W w;
    E() {}
    E(int u, int v, const W& w) : u(u), v(v), w(w) {}
};
template<class W>
bool less_u(const E<W>& l, const E<W>& r) {
    return l.u!=r.u ? l.u<r.u : l.v!=r.v ? l.v<r.v : l.w<r.w;
}

int N[2], M[2];
int of(int x, int y, int i, int j) {
    return (((x*600)+y)*16+i)*16+j;
}

int main() {
    int T;
    scanf("%d", &T);
    vector<E<string> > g[2];
    map<int, int> dp;
    while(T--) {
        vector<vector<int> > to[2];
        rep(k, 2) {
            scanf("%d%d", N+k, M+k);
            g[k].clear();
            rep(i, M[k]) {
                int a, b;
                char buf[8];
                scanf("%d%d%s", &a, &b, buf);
                g[k].push_back(E<string>(a, b, buf));
            }
            sort(g[k].begin(), g[k].end(), less_u<string>);
            to[k] = vector<vector<int> >(N[k]);
            rep(i, M[k]) {
                const int u = g[k][i].u;
                to[k][u].push_back(i);
            }
            to[k][N[k]-1].push_back(M[k]);
        }
        dp.clear();
        rep(i, to[0][0].size()) rep(j, to[1][0].size()) {
            const int ix = to[0][0][i], jx = to[1][0][j];
            dp[of(ix, jx, 0, 0)] = 1;
        }
        rep(x, M[0]) rep(y, M[1]) {
            const int v0 = g[0][x].v, v1 = g[1][y].v;
            const string &a = g[0][x].w, &b = g[1][y].w;
            rep(i, a.size()) rep(j, b.size()) if(a[i]==b[j]) {
                const int cur = of(x, y, i, j);
                if(dp.count(cur)==0) continue;
                const int val = dp[cur];
                if(i<(int)a.size()-1 && j<(int)b.size()-1) {
                    up(dp[of(x, y, i+1, j+1)], val);
                }
                else if(i<(int)a.size()-1) {
                    rep(p, to[1][v1].size()) {
                        const int ix = to[1][v1][p];
                        up(dp[of(x, ix, i+1, 0)], val);
                    }
                }
                else if(j<(int)b.size()-1) {
                    rep(p, to[0][v0].size()) {
                        const int ix = to[0][v0][p];
                        up(dp[of(ix, y, 0, j+1)], val);
                    }
                }
                else {
                    rep(p, to[0][v0].size()) rep(q, to[1][v1].size()) {
                        const int ix = to[0][v0][p];
                        const int jx = to[1][v1][q];
                        up(dp[of(ix, jx, 0, 0)], val);
                    }
                }
            }
        }
        printf("%d\n", dp[of(M[0], M[1], 0, 0)]);
    }
    return 0;
}

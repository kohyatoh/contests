#include <stdio.h>
#include <vector>
#include <map>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)
#define mp make_pair
inline void cmin(int &a, int b) { if(a>b) a = b; }

int M, N, L, at[40], a[400], g[256][256];
vector<int> con[256];

int main() {
    scanf("%d%d%d", &M, &N, &L);
    rep(i, L) scanf("%d", at+i);
    rep(i, L) at[i]--;
    rep(i, M) rep(j, M) g[i][j] = i==j ? 0 : INF;
    map<pair<int, int>, int> of;
    rep(k, M) {
        int m;
        scanf("%d", &m);
        rep(i, m) scanf("%d", a+i);
        rep(i, m) a[i]--;
        rep(i, m) con[a[i]].push_back(k);
        rep(i, m) {
            const int j = (i+1)%m;
            if(of.count(mp(a[i], a[j]))) {
                const int to = of[mp(a[i], a[j])];
                g[k][to] = g[to][k] = 1;
            }
            of[mp(a[j], a[i])] = k;
        }
    }
    rep(k, M) rep(i, M) rep(j, M) cmin(g[i][j], g[i][k]+g[k][j]);
    int ans = INF;
    rep(k, M) {
        int s = 0;
        rep(i, L) {
            int add = INF;
            rep(j, con[at[i]].size()) cmin(add, g[k][con[at[i]][j]]);
            s += add;
        }
        cmin(ans, s);
    }
    printf("%d\n", ans);
    return 0;
}

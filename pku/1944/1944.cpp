#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int z[1024];
vector<int> g[1024];

int main() {
    int N, P;
    scanf("%d%d", &N, &P);
    rep(i, P) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        z[min(u, v)]++;
        z[max(u, v)]--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = N;
    rep(k, N) if(z[k]) {
        int x = k, a = 0, c = 0;
        rep(_, N) {
            c += z[x];
            if(c) a++;
            if(++x==N) x = 0;
        }
        ans = min(ans, a);
        rep(i, g[k].size()) {
            z[k] -= 2;
            z[g[k][i]] += 2;
        }
    }
    printf("%d\n", ans);
    return 0;
}

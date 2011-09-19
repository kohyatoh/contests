#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct MaxFlow {
    static const int N = 512;
    int n, flow[N][N], capa[N][N], prev[N];
    void init(int _n) {
        n = _n;
        memset(flow, 0, sizeof(flow));
        memset(capa, 0, sizeof(capa));
    }
    void add_edge(int u, int v, int ca) { capa[u][v] = ca; }
    int max(int s, int t, int F=1<<30) {
        int total = 0;
        while(total < F) {
            memset(prev, -1, sizeof(prev));
            queue<int> q;
            prev[s] = s;
            q.push(s);
            while(!q.empty() && prev[t]<0) {
                const int u = q.front();
                q.pop();
                rep(i, n) if(prev[i]<0 && flow[u][i]<capa[u][i]) {
                    prev[i] = u;
                    q.push(i);
                }
            }
            if(prev[t]<0) return total;
            int inc = F-total;
            for(int j=t; prev[j]!=j; j=prev[j]) {
                inc = min(inc, capa[prev[j]][j]-flow[prev[j]][j]);
            }
            for(int j=t; prev[j]!=j; j=prev[j]) {
                flow[prev[j]][j] += inc;
                flow[j][prev[j]] -= inc;
            }
            total += inc;
        }
    return total;
    }
} mf;

int N, M, X[2000], Y[2000], S, T;

int main() {
    scanf("%d%d", &N, &M);
    rep(i, M) scanf("%d%d", X+i, Y+i);
    rep(i, M) X[i]--, Y[i]--;
    scanf("%d%d", &S, &T);
    S--, T--;
    mf.init(N);
    rep(i, M) {
        mf.add_edge(X[i], Y[i], 1);
        mf.add_edge(Y[i], X[i], 1);
    }
    printf("%d\n", mf.max(S, T));
    vector<int> ans;
    rep(i, M) if(mf.flow[X[i]][Y[i]]<0) ans.push_back(i+1);
    printf("%d\n", (int)ans.size());
    rep(i, ans.size()) printf("%d\n", ans[i]);
    return 0;
}


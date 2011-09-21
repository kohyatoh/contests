#include <stdio.h>
#include <string.h>
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
    int pour(int s, int t, int F=1<<30) {
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

int N, E, Q;

int main() {
    scanf("%d%d%d", &N, &E, &Q);
    mf.init(N);
    rep(_, E) {
        int F, T;
        scanf("%d%d", &F, &T);
        F--, T--;
        mf.add_edge(F, T, 1);
        mf.add_edge(T, F, 1);
    }
    int cur = mf.pour(0, N-1);
    rep(_, Q) {
        int M, A, B;
        scanf("%d%d%d", &M, &A, &B);
        A--, B--;
        if(M==1) {
            mf.add_edge(A, B, 1);
            mf.add_edge(B, A, 1);
            cur += mf.pour(0, N-1, 1);
        }
        else {
            if(mf.flow[A][B]==-1) swap(A, B);
            if(mf.flow[A][B] && !mf.pour(A, B, 1)) {
                cur--;
                mf.pour(N-1, B, 1);
                mf.pour(A, 0, 1);
            }
            mf.flow[A][B] = mf.flow[B][A] = 0;
            mf.capa[A][B] = mf.capa[B][A] = 0;
        }
        printf("%d\n", cur);
    }
    return 0;
}

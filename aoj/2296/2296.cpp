#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)
typedef long long Int;

int N, M, W, T;
string S[8];
int V[8], P[8];
int L[8], X[8], Y[8], id[8][8], pf[8][8];

int wdp[1<<8][8], wt[1<<8];
Int wp[1<<8], p[8];

Int knapsack(int m, int n, int *w, Int *v) {
    static Int dp[20000];
    memset(dp, 0, sizeof(dp));
    rep(k, n) rep(i, m-w[k]+1) dp[i+w[k]] = max(dp[i+w[k]], dp[i]+v[k]);
    return *max_element(dp, dp+m+1);
}


int main() {
    cin >> N >> M >> W >> T;
    rep(i, M) cin >> S[i] >> V[i] >> P[i];
    rep(i, N) {
        cin >> L[i] >> X[i] >> Y[i];
        rep(j, L[i]) {
            string r;
            int q;
            cin >> r >> q;
            id[i][j] = find(S, S+M, r)-S;
            pf[i][j] = P[id[i][j]]-q;
        }
    }
    rep(i, 1<<8) rep(j, 8) wdp[i][j] = INF;
    rep(i, N) wdp[1<<i][i] = abs(X[i])+abs(Y[i]);
    const int nn = 1<<N;
    rep(i, nn) rep(j, N) rep(k, N) {
        wdp[i|(1<<k)][k] = min(wdp[i|(1<<k)][k],
                wdp[i][j]+abs(X[j]-X[k])+abs(Y[j]-Y[k]));
    }
    rep(k, nn) {
        wt[k] = INF;
        rep(i, N) wt[k] = min(wt[k], wdp[k][i]+abs(X[i])+abs(Y[i]));
        rep(i, M) p[i] = 0;
        rep(i, N) if(k&(1<<i)) {
            rep(j, L[i]) p[id[i][j]] = max(p[id[i][j]], (Int)pf[i][j]);
        }
        wp[k] = knapsack(W, M, V, p);
    }
    cout << knapsack(T, nn, wt, wp) << endl;
    return 0;
}


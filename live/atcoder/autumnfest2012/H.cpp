#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;

#define NUM (120000)
#define MOD (314159265LL)

struct BIT {
    static const int N=NUM;
    Int x[N];
    void init() { memset(x, 0, sizeof(x)); }
    void add(int k, Int a) {
        for(; k<N; k|=k+1) x[k] = (x[k] + a) % MOD;
    }
    Int sum(int k) {
        Int s = 0;
        for(; k>=0; k=(k&(k+1))-1) s = (s + x[k]) % MOD;
        return s;
    }
    Int rsum(int i, int j) {
        return i==0 ? sum(j) : (sum(j)-sum(i-1)+MOD) % MOD;
    }
} dp[20];

int n, D;
int L[NUM], R[NUM];
vector<int> xs;

int index(int x) {
    return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
}

int main() {
    scanf("%d%d", &n, &D);
    rep (i, n) scanf("%d%d", L+i, R+i);
    rep (i, n) xs.push_back(R[i]);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    vector<pair<int, int> > ps;
    rep (i, n) ps.push_back(mp(L[i], index(R[i])));
    sort(ps.begin(), ps.end());
    dp[0].add(xs.size(), 1);
    rep (i, ps.size()) {
        const int ix = ps[i].second;
        for (int k = D-1; k >= 0; k--) {
            dp[k+1].add(ix, dp[k].rsum(ix+1, xs.size()));
        }
    }
    cout << dp[D].rsum(0, xs.size()) << endl;
    return 0;
}

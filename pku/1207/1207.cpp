#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct RMQ {
    vector<vector<int> > dp;
    RMQ(const vector<int>& a) {
        const int n = a.size();
        dp.push_back(a);
        for(int w=1; w*2<n; w*=2) {
            const int m = n-2*w+1;
            dp.push_back(vector<int>(m));
            vector<int> &cur = dp[dp.size()-2], &nxt = dp.back();
            rep(i, m) nxt[i] = std::min(cur[i], cur[i+w]);
        }
    }
    // return min([a[i] for i in [l, r)])
    int min(int l, int r) {
        int ix=0, w=1;
        while(w*2<r-l) ix++, w*=2;
        return std::min(dp[ix][l], dp[ix][r-w]);
    }
};

map<int, int> memo;

int rec(int n) {
    if(n==1) return 1;
    if(memo.count(n)) return memo[n];
    return memo[n] = 1 + (n%2 ? rec(3*n+1) : rec(n/2));
}

int main() {
    vector<int> a;
    rep(i, 10000) a.push_back(-rec(i+1));
    RMQ rmq(a);
    int l, r;
    while(scanf("%d%d", &l, &r)!=EOF) {
        printf("%d %d %d\n", l, r, -rmq.min(min(l, r)-1, max(l, r)));
    }
    return 0;
}

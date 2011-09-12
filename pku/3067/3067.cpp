#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct BIT {
    static const int N=1000;
    int x[N];
    void init() { memset(x, 0, sizeof(x)); }
    void add(int k, int a) { for(; k<N; k|=k+1) x[k]+=a; }
    int sum(int k) { int s=0; for(; k>=0; k=(k&(k+1))-1) s+=x[k]; return s; }
    int rsum(int i, int j) { return i==0 ? sum(j) : sum(j)-sum(i-1); }
} bit;

vector<int> g[1000];

int main() {
    int T;
    scanf("%d", &T);
    rep(_t, T) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        rep(i, 1000) g[i].clear();
        rep(i, k) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            g[u].push_back(v);
        }
        bit.init();
        long long ans = 0;
        rep(i, n) {
            rep(j, g[i].size()) ans += bit.rsum(g[i][j]+1, m-1);
            rep(j, g[i].size()) bit.add(g[i][j], 1);
        }
        cout << "Test case " << _t+1 << ": " << ans << endl;
    }
    return 0;
}

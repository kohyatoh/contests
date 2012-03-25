#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

int N, K, cnt[60000][512];
Int s[60000];
vector<int> g[60000];

void rec(int at, int pre) {
    cnt[at][0] = 1;
    rep (j, g[at].size()) if (g[at][j] != pre) {
        const int to = g[at][j];
        rec(to, at);
        rep (i, K) cnt[at][i+1] += cnt[to][i];
        rep (i, K+1) if (i>0 && K-i>0) {
            s[at] -= (Int)cnt[to][i-1] * cnt[to][K-i-1];
        }
    }
    rep (i, K+1) {
        s[at] += (Int)cnt[at][i] * cnt[at][K-i];
    }
}

int main() {
    scanf("%d%d", &N, &K);
    rep (i, N-1) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rec(0, -1);
    Int ans = 0;
    rep (i, N) ans += s[i];
    cout << ans/2 << endl;
    return 0;
}

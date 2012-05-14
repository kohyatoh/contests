#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

const int tx[6][4] = {
    {2, 3, 2, 1}, {3, 5, 3, 1},
    {4, 3, 1, 2}, {1, 3, 4, 2},
    {3, 4, 2, 1}, {2, 4, 3, 1},
};
const int ty[6][4] = {
    {1, 3, 5, 3}, {1, 2, 3, 2},
    {1, 3, 4, 2}, {1, 2, 4, 3},
    {1, 3, 4, 2}, {1, 2, 4, 3},
};

int R, C, n, xs[100001], ys[100001];
vector<int> of[100001];

inline bool has(int x, int y) {
    return binary_search(of[x].begin(), of[x].end(), y);
}

Int solve() {
    rep (i, 100001) of[i].clear();
    rep (i, n) of[xs[i]].push_back(ys[i]);
    rep (i, R+1) sort(of[i].begin(), of[i].end());
    Int ans = 0;
    ans += (R-2LL)*(C-4LL);
    ans += (R-4LL)*(C-2LL);
    ans += (R-3LL)*(C-3LL) * 4;
    rep (k, n) rep (t, 6) rep (d, 4) {
        bool is = true;
        rep (i, 4) {
            const int x = xs[k]+(tx[t][i]-tx[t][d]);
            const int y = ys[k]+(ty[t][i]-ty[t][d]);
            if (x <= 0 || x > R || y <= 0 || y > C) {
                is = false;
                break;
            }
        }
        if (!is) continue;
        rep (i, d) {
            const int x = xs[k]+(tx[t][i]-tx[t][d]);
            const int y = ys[k]+(ty[t][i]-ty[t][d]);
            if (has(x, y)) {
                is = false;
                break;
            }
        }
        if (is) ans--;
    }
    return ans * 8;
}

int main() {
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        scanf("%d%d%d", &R, &C, &n);
        rep (i, n) scanf("%d%d", xs+i, ys+i);
        cout << "Case " << _q+1 << ": " << solve() << endl;
    }
    return 0;
}

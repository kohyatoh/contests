#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1<<28)
#define mp make_pair

int n, m;
string b[2048], s;
int idx[2048];
pair<int, int> dp[2048][2048];
vector<int> ps[2048][32];
int suf[2048][32];

int get_pos(int ix, int lo, char ch) {
    const int c = ch - 'a';
    return *lower_bound(ps[ix][c].begin(), ps[ix][c].end(), lo);
}

int get_ix(int lo, char ch) {
    const int c = ch - 'a';
    return suf[lo][c];
}

int main() {
    cin >> n;
    rep (i, n) cin >> b[i];
    cin >> m;
    rep (i, m) cin >> idx[i];
    rep (i, m) idx[i]--;
    cin >> s;
    rep (k, n) {
        rep (i, b[k].size()) {
            const int c = b[k][i] - 'a';
            ps[k][c].push_back(i);
        }
        rep (i, 32) ps[k][i].push_back(INF);
    }
    rep (i, 32) suf[m][i] = INF;
    for (int k = m-1; k >= 0; k--) {
        rep (i, 32) suf[k][i] = suf[k+1][i];
        rep (i, 32) if (ps[idx[k]][i].size() > 1) suf[k][i] = k;
    }
    rep (i, 2048) rep (j, 2048) dp[i][j].first = INF;
    dp[0][0] = mp(0, -1);
    rep (i, 2048) {
        rep (j, s.size()) if (dp[i][j].first < INF) {
            const int cix = dp[i][j].first;
            const int cpos = dp[i][j].second;
            const int sp = get_pos(idx[cix], cpos+1, s[j]);
            if (sp < INF) {
                dp[i+1][j+1] = min(dp[i+1][j+1], mp(cix, sp));
            }
            else {
                const int nix = get_ix(cix+1, s[j]);
                if (nix < INF) {
                    const int npos = get_pos(idx[nix], 0, s[j]);
                    dp[i+1][j+1] = min(dp[i+1][j+1], mp(nix, npos));
                }
            }
            dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
        }
    }
    int ans = 0;
    rep (i, 2048) rep (j, 2048) if (dp[i][j].first < INF) ans = i;
    cout << ans << endl;
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define fst first
#define snd second
#define INF (1LL<<60)
typedef long long Int;
inline void cmax(Int &a, Int b) { if (a < b) a = b; }

int n, m, li[200000], lj[200000];
Int dp[200000][2];

int main() {
    memset(li, -1, sizeof(li));
    memset(lj, -1, sizeof(lj));
    vector<pair<pair<int, int>, int> > sh, cu;
    scanf("%d", &n);
    rep (i, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        sh.push_back(mp(mp(y, x), i));
    }
    scanf("%d", &m);
    rep (i, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        cu.push_back(mp(mp(y, x), i));
    }
    sort(sh.begin(), sh.end());
    sort(cu.begin(), cu.end());
    int ix = 0;
    rep (i, n) {
        while (ix < m && cu[ix].fst.fst < sh[i].fst.fst-1) ix++;
        while (ix < m && cu[ix].fst.fst < sh[i].fst.fst) {
            if (li[i] == -1 && cu[ix].fst.snd >= sh[i].fst.snd) li[i] = ix;
            ix++;
        }
        int jx = ix;
        while (jx < m && cu[jx].fst.fst == sh[i].fst.fst) {
            if (cu[jx].fst.snd >= sh[i].fst.snd) {
                lj[i] = jx;
                break;
            }
            jx++;
        }
    }
    rep (i, n+1) dp[i][0] = dp[i][1] = -INF;
    dp[0][0] = dp[0][1] = 0;
    rep (i, n) {
        const int v = sh[i].fst.snd;
        cmax(dp[i+1][0], max(dp[i][0], dp[i][1]));
        if (li[i] != -1) {
            cmax(dp[i+1][0], dp[i][0] + v);
            if (i == 0 || lj[i-1] != li[i]) {
                cmax(dp[i+1][0], dp[i][1] + v);
            }
            else if (cu[li[i]+1].fst.fst == sh[i].fst.fst-1) {
                cmax(dp[i+1][0], dp[i][1] + v);
            }
        }
        if (lj[i] != -1) cmax(dp[i+1][1], max(dp[i][0], dp[i][1]) + v);
    }
    int ai = dp[n][0] > dp[n][1] ? 0 : 1;
    cout << dp[n][ai] << endl;
    vector<pair<int, int> > as;
    for (int i = n-1; i >= 0; i--) {
        const int v = sh[i].fst.snd;
        if (ai == 0 && dp[i+1][0] == max(dp[i][0], dp[i][1])) {
            ai = dp[i][0] > dp[i][1] ? 0 : 1;
            continue;
        }
        if (li[i] != -1) {
            if (ai == 0 && dp[i+1][0] == dp[i][0] + v) {
                ai = 0;
                as.push_back(mp(cu[li[i]].snd+1, sh[i].snd+1));
                continue;
            }
            if (i == 0 || lj[i-1] != li[i]) {
                if (ai == 0 && dp[i+1][0] == dp[i][1] + v) {
                    ai = 1;
                    as.push_back(mp(cu[li[i]].snd+1, sh[i].snd+1));
                    continue;
                }
            }
            else if (cu[li[i]+1].fst.fst == sh[i].fst.fst-1) {
                if (ai == 0 && dp[i+1][0] == dp[i][1] + v) {
                    ai = 1;
                    as.push_back(mp(cu[li[i]+1].snd+1, sh[i].snd+1));
                    continue;
                }
            }
        }
        if (lj[i] != -1) {
            if (ai == 1 && dp[i+1][1] == max(dp[i][0], dp[i][1]) + v) {
                ai = dp[i][0] > dp[i][1] ? 0 : 1;
                as.push_back(mp(cu[lj[i]].snd+1, sh[i].snd+1));
                continue;
            }
        }
    }
    printf("%d\n", (int)as.size());
    rep (i, as.size()) printf("%d %d\n", as[i].fst, as[i].snd);
    return 0;
}

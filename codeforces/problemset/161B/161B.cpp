#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define fst first
#define snd second

int n, k;
int c[2000], t[2000];
vector<int> as[2000];

int main() {
    scanf("%d%d", &n, &k);
    rep (i, n) scanf("%d%d", c+i, t+i);
    vector<pair<int, int> > xs, ys;
    rep (i, n) {
        if (t[i] == 1) xs.push_back(mp(c[i], i));
        if (t[i] == 2) ys.push_back(mp(c[i], i));
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    rep (i, k) {
        if (xs.size()) {
            if (ys.size() && ys.back().fst > xs.back().fst) {
                if (xs.size()-1 + ys.size()-1 >= k-1-i) {
                    as[i].push_back(ys.back().snd);
                    ys.pop_back();
                }
            }
            as[i].push_back(xs.back().snd);
            xs.pop_back();
        }
        else {
            as[i].push_back(ys.back().snd);
            ys.pop_back();
        }
    }
    rep (i, xs.size()) as[k-1].push_back(xs[i].snd);
    rep (i, ys.size()) as[k-1].push_back(ys[i].snd);
    double ans = 0;
    rep (i, k) {
        rep (j, as[i].size()) ans += c[as[i][j]];
        bool has = false;
        rep (j, as[i].size()) if (t[as[i][j]] == 1) has = true;
        if (has) {
            int mn = c[as[i][0]];
            rep (j, as[i].size()) mn = min(mn, c[as[i][j]]);
            ans -= mn / 2.0;
        }
    }
    printf("%.1f\n", ans);
    rep (i, k) {
        printf("%d", as[i].size());
        rep (j, as[i].size()) printf(" %d", as[i][j]+1);
        printf("\n");
    }
    return 0;
}

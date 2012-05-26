#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;

int N, W, L, r[4000];
int ansx[4000], ansy[4000];
pair<int, int> of[4000];

struct B {
    int x, w, h;
    B() {}
    B(int x, int w, int h) : x(x), w(w), h(h) {}
};

void solve() {
    rep (i, N) of[i] = mp(r[i], i);
    sort(of, of+N);
    reverse(of, of+N);
    int hh = 0;
    int ix = 0;
    while (ix < N && of[ix].first*2 > W) {
        const int x = of[ix].second;
        ansx[x] = 0;
        ansy[x] = hh + r[x];
        if (hh == 0) ansy[x] -= r[x];
        hh = ansy[x] + r[x];
        ix++;
    }
    vector<B> b;
    b.push_back(B(0, W, hh));
    for (int k = 0; ix < N; k++) {
        unsigned ci = b.size();
        int cur = 0;
        B cb = b[k];
        while (ix < N && cur + of[ix].first*2 < cb.w) {
            const int x = of[ix].second;
            ansx[x] = cb.x + cur + r[x];
            ansy[x] = cb.h + r[x];
            if (cb.h == 0) ansy[x] -= r[x];
            b.push_back(B(ansx[x]-r[x], r[x]*2, ansy[x]+r[x]));
            cur += r[x]*2;
            ix++;
        }
        if (ci < b.size()) b.back().w += cb.w - cur;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        scanf("%d%d%d", &N, &W, &L);
        rep (i, N) scanf("%d", r+i);
        solve();
        printf("Case #%d:", _q+1);
        rep (i, N) printf(" %d %d", ansx[i], ansy[i]);
        printf("\n");
    }
    return 0;
}

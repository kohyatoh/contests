#include <stdio.h>
#include <tr1/unordered_set>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long P;

P enc(int x, int y) { return P(x)<<32|y; }

int n;
P ps[200000];
tr1::unordered_set<P> vis;

void rec(const P& p) {
    if (vis.count(p)) return ;
    vis.insert(p);
    int x = p>>32;
    int y = p;
    rep (i, 3) rep (j, 3) {
        const P np = enc(x+i-1, y+j-1);
        if (binary_search(ps, ps+n, np)) rec(np);
    }
}

int main() {
    double R;
    scanf("%d%lf", &n, &R);
    R *= 1.05;
    rep (i, n) {
        double x, y;
        scanf("%lf%lf", &x, &y);
        x += 1e7, y += 1e7;
        ps[i] = enc(int(x/R), int(y/R));
    }
    sort(ps, ps+n);
    n = unique(ps, ps+n) - ps;
    int ans = 0;
    rep (i, n) if (!vis.count(ps[i])) rec(ps[i]), ans++;
    printf("%d\n", ans);
    return 0;
}

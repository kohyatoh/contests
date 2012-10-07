#include <stdio.h>
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef complex<double> P;
#define EPS (1e-6)

P readP() {
    double x, y;
    scanf("%lf%lf", &x, &y);
    return P(x, y);
}

double radius(const vector<P>& ps) {
    P p = P(0, 0);
    double cur = 1.0;
    rep (dep, 30) {
        rep (_, 20) {
            double mx = norm(ps[0]-p);
            int ix = 0;
            rep (i, ps.size()) {
                const double d = norm(ps[i]-p);
                if (mx < d) mx = d, ix = i;
            }
            p += cur*(ps[ix]-p);
        }
        cur *= 0.5;
    }
    double ans = 0;
    rep (i, ps.size()) ans = max(ans, abs(ps[i]-p));
    return ans;
}

int n, m;
double rs[128], ts[128];
bool used[128];

bool can(int k) {
    vector<double> a, b;
    rep (i, n) if (!used[i]) a.push_back(rs[i]);
    rep (i, m) if (i >= k) b.push_back(ts[i]);
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    rep (i, b.size()) if (b[i] > a[i]+EPS) return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    rep (i, n) scanf("%lf", rs+i);
    rep (i, m) {
        int K;
        scanf("%d", &K);
        vector<P> ps;
        rep (_, K) ps.push_back(readP());
        ts[i] = radius(ps);
    }
    if (!can(0)) puts("NG");
    else {
        rep (k, m) rep (i, n) if (!used[i] && ts[k] <= rs[i]+EPS) {
            used[i] = 1;
            if (can(k+1)) { printf("%d\n", i+1); break; }
            used[i] = 0;
        }
    }
    return 0;
}

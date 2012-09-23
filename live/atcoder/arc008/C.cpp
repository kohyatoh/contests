#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;
inline double sq(double a) { return a*a; }

int N;
double x[1024], y[1024], t[1024], r[1024];
int vis[1024];
double g[1024][1024];

int main() {
    scanf("%d", &N);
    rep (i, N) scanf("%lf%lf%lf%lf", x+i, y+i, t+i, r+i);
    rep (i, N) rep (j, N) if (i != j) {
        const double s = min(t[i], r[j]);
//        const double dist = sqrt(sq(x[i]-x[j]) + sq(y[i]-y[j]));
        const double dist = hypot(fabs(x[i]-x[j]), fabs(y[i]-y[j]));
        assert(dist > 0);
        assert(s >= 3);
        g[i][j] = dist / s;
    }
    priority_queue<pair<double, int> > q;
    q.push(mp(0, 0));
    vector<double> ts;
    while (!q.empty()) {
        pair<double, int> vv = q.top();
        q.pop();
        const int at = vv.second;
        if (vis[at]) continue;
        vis[at] = 1;
        ts.push_back(fabs(vv.first));
        rep (i, N) if (i != at && vis[i] == 0) {
            q.push(mp(vv.first-g[at][i], i));
        }
    }
    sort(ts.begin(), ts.end());
    assert(ts[0] == 0);
    reverse(ts.begin(), ts.end());
    double ans = 0;
    rep (i, N-1) ans = max(ans, i + ts[i]);
    printf("%.9f\n", ans);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <complex>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define EPS (1e-13)
inline double sq(double a) { return a*a; }
typedef complex<double> P;

int n;
double x[200], y[200], r[200], d[200][200];
int cross[200][200];
P ps[200], cp[200][200][2];

bool canSeePoint(P p, int ix) {
    for(int i=ix+1; i<n; i++) if(abs(p-ps[i])<r[i]-EPS) return false;
    return true;
}

bool canSee(int ix) {
    vector<int> ids;
    ids.push_back(ix);
    for(int i=ix+1; i<n; i++) {
        if(d[ix][i]+r[ix]<r[i]) return false;
        if(d[ix][i]<r[i]+r[ix]) ids.push_back(i);
    }
    if(ids.size()<3) return true;
    rep(i, ids.size()) rep(j, i) if(cross[ids[i]][ids[j]]) rep(k, 2) {
        const P p(cp[ids[i]][ids[j]][k]);
        if(abs(p-ps[ix])<=r[ix]+EPS && canSeePoint(p, ix)) return true;
    }
    return false;
}

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%lf%lf%lf", x+i, y+i, r+i);
        rep(i, n) ps[i] = P(x[i], y[i]);
        rep(i, n) rep(j, n) d[i][j] = abs(ps[j]-ps[i]);
        memset(cross, 0, sizeof(cross));
        rep(i, n) rep(j, n) if(d[i][j]>0) {
            cross[i][j] = abs(r[j]-r[i])<d[i][j] && d[i][j]<r[i]+r[j];
            if(cross[i][j]) {
                const double a = (sq(d[i][j])+sq(r[i])-sq(r[j]))/d[i][j]/2;
                const double b = sqrt(sq(r[i])-sq(a));
                const P dir(1/d[i][j]*(ps[j]-ps[i]));
                const P mid(ps[i]+dir*a);
                cp[i][j][0] = mid + b*dir*P(0, 1);
                cp[i][j][1] = mid - b*dir*P(0, 1);
            }
        }
        int ans = 0;
        rep(i, n) if(canSee(i)) ans++;
        printf("%d\n", ans);
    }
}

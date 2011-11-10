#include <stdio.h>
#include <string.h>
#include <complex>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef complex<double> P;
const double pi = atan2(0.0, -1.0);

inline P unit(double a) { return P(cos(a), sin(a)); }

int n, m, c;
double w[20000], ang[20000], aof[200];
double cs[128], ca[128], cc[20000];
P ps[128], pa[128], pp[20000];

void rebuild(int k) {
    const int b = k/m;
    const int l = b*m, r = min((b+1)*m, n);
    for(int i=k; i<r; i++) {
        cc[i] = ang[i];
        if(i>l) cc[i] += cc[i-1];
        pp[i] = w[i]*unit(cc[i]);
        if(i>l) pp[i] += pp[i-1];
    }
    ca[b] = cc[r-1];
    pa[b] = pp[r-1];
    for(int i=b; i<c; i++) {
        cs[i] = ca[i];
        if(i>0) cs[i] += cs[i-1];
        ps[i] = i>0 ? pa[i]*unit(cs[i-1]) : pa[i];
        if(i>0) ps[i] += ps[i-1];
    }
}

int main() {
    bool first = true;
    int Q;
    while(scanf("%d%d", &n, &Q)!=EOF) {
        if(!first) puts("");
        first = false;
        rep(i, n) scanf("%lf", w+i);
        m = max(20, (int)sqrt((double)n));
        c = (n+m-1)/m;
        memset(ang, 0, sizeof(ang));
        memset(cs, 0, sizeof(cs));
        memset(ca, 0, sizeof(ca));
        memset(cc, 0, sizeof(cc));
        rep(k, c) {
            const int l = k*m, r = min((k+1)*m, n);
            pp[l] = P(w[l], 0);
            for(int i=l+1; i<r; i++) pp[i] = pp[i-1]+P(w[i], 0);
            pa[k] = pp[r-1];
            ps[k] = pa[k];
            if(k>0) ps[k] += ps[k-1];
        }
        rep(_, Q) {
            int x, a;
            scanf("%d%d", &x, &a);
            ang[x] = (a-180)/180.0*pi;
            rebuild(x);
            const P p(ps[c-1]*P(0, 1));
            printf("%.2f %.2f\n", p.real(), p.imag());
        }
    }
    return 0;
}

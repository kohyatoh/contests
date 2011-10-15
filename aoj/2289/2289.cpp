#include <stdio.h>
#include <iostream>
#include <complex>
#include <vector>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define EPS (1e-12)
typedef complex<double> P;
inline double sq(double a) { return a*a; }
const double pi = atan2(0.0, -1.0);

inline double cross(const P& a, const P& b) { return imag(conj(a)*b); }
inline P unit(const P& p) { return 1/abs(p)*p; }
inline P unit(double t) { return P(cos(t), sin(t)); }

bool intersectLL(const P& l0, const P& l1, const P& m0, const P& m1) {
    return abs(cross(l1-l0, m1-m0)) > EPS  // non-parallel
        || abs(cross(l1-l0, m0-l0)) < EPS; // same line
}
P crosspoint(const P& l0, const P& l1, const P& m0, const P& m1) {
    const double A = cross(l1-l0, m1-m0);
    const double B = cross(l1-l0, l1-m0);
    if(abs(A)<EPS && abs(B)<EPS) return m0;
//    if(abs(A)<EPS) throw 0;
    return m0+B/A*(m1-m0);
}

vector<P> crosspointsCL(const P& p, double r, const P& l0, const P& l1) {
    vector<P> v;
    const P cp(crosspoint(p, p+(l1-l0)*P(0, 1), l0, l1));
    if(abs(cp-p)<r+EPS) {
        const double a = sqrt(sq(r)-norm(p-cp));
        const P dir(a*unit(l1-l0));
        v.push_back(cp+dir);
        v.push_back(cp-dir);
    }
    return v;
}

vector<P> crosspointsCC(const P& p1, double r1, const P& p2, double r2) {
    const double d = abs(p1-p2);
    if(d+min(r1, r2)<max(r1, r2)-EPS || r1+r2<d-EPS) return vector<P>();
    const double a = (r1*r1-r2*r2+d*d)/(2*d);
    const double b = sqrt(r1*r1-a*a);
    const P m(p1+a*unit(p2-p1));
    const P dir(b*unit(p2-p1)*P(0, 1));
    vector<P> rs;
    rs.push_back(m+dir);
    rs.push_back(m-dir);
    return rs;
}

struct Arc {
    P p;
    double r, t0, t1;
    Arc(const P& p, double r, double t0, double t1)
    : p(p), r(r), t0(t0), t1(t1) {}
};

bool in_arc(const Arc& a, const P& p) {
    if(abs(p-a.p)<EPS) return true;
    if(abs(p-a.p)>a.r+EPS) return false;
    const double t = arg(p-a.p);
    if(a.t0>a.t1) return t < a.t1+EPS || a.t0-EPS < t;
    else return a.t0-EPS < t && t < a.t1+EPS;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        vector<Arc> as;
        rep(i, n) {
            int x, y, r, s, t;
            scanf("%d%d%d%d%d", &x, &y, &r, &s, &t);
            if(s>180) s -= 360;
            if(t>180) t -= 360;
            as.push_back(Arc(P(x, y), r, pi*s/180, pi*t/180));
        }
        vector<pair<P, P> > ls;
        rep(i, n) {
            ls.push_back(mp(as[i].p, as[i].p+as[i].r*unit(as[i].t0)));
            ls.push_back(mp(as[i].p, as[i].p+as[i].r*unit(as[i].t1)));
        }
        vector<P> cs;
        rep(i, n) cs.push_back(as[i].p);
        rep(i, n) rep(j, i) {
            vector<P> v(crosspointsCC(as[i].p, as[i].r, as[j].p, as[j].r));
            rep(k, v.size()) cs.push_back(v[k]);
        }
        rep(i, n) rep(j, ls.size()) {
            vector<P> v(crosspointsCL(as[i].p, as[i].r,
                        ls[j].first, ls[j].second));
            rep(k, v.size()) cs.push_back(v[k]);
        }
        rep(i, ls.size()) rep(j, i) {
            if(intersectLL(ls[i].first, ls[i].second,
                        ls[j].first, ls[j].second)) {
                cs.push_back(crosspoint(ls[i].first, ls[i].second,
                            ls[j].first, ls[j].second));
            }
        }
        int ans = 0;
        rep(k, cs.size()) {
            int c = 0;
            rep(i, n) if(in_arc(as[i], cs[k])) c++;
            ans = max(ans, c);
        }
        printf("%d\n", ans);
    }
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <complex>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef complex<double> P;
#define EPS (1e-12)
const double pi = atan2(0.0, -1.0);

P unit(const P& p) { return 1/abs(p)*p; }
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

Arc reflect(const Arc& a) {
    const double nt0 = a.t0>=0 ? pi-a.t0 : -pi-a.t0;
    const double nt1 = a.t1>=0 ? pi-a.t1 : -pi-a.t1;
    return Arc(P(-a.p.real(), a.p.imag()), a.r, nt0, nt1);
}

double abs(const Arc& a) { return fabs(a.t1-a.t0)*a.r; }

ostream& operator<<(ostream& os, const Arc& a) {
    os << a.p << ", " << a.r << ", " << a.t0 << " to " << a.t1;
    return os;
}

vector<P> crosspointsAA(const Arc& a, const Arc& b) {
    vector<P> ps(crosspointsCC(a.p, a.r, b.p, b.r));
    vector<P> ans;
    rep(i, ps.size()) {
        const double ta = arg(ps[i]-a.p);
        const double tb = arg(ps[i]-b.p);
        if(min(a.t0, a.t1)-EPS <= ta && ta <= max(a.t0, a.t1)+EPS
                && min(b.t0, b.t1)-EPS <= tb && tb <= max(b.t0, b.t1)+EPS) {
            ans.push_back(ps[i]);
        }
    }
    return ans;
}

int L, X1, Y1, X2, Y2;

vector<Arc> make() {
    vector<Arc> v;
    v.push_back(Arc(P(0, 0), L, -pi/2, -pi));
    if(X1<0 && L<abs(P(X1, Y1))) {
        const double x = sqrt(L*L-Y1*Y1);
        v.push_back(Arc(P(0, 0), L, pi, arg(P(-x, Y1))));
        return v;
    }
    if(X1>=0 && L<abs(P(X1, Y2))) {
        const double y = sqrt(L*L-X1*X1);
        v.push_back(Arc(P(0, 0), L, pi, arg(P(X1, y))));
        return v;
    }
    vector<P> ps;
    if(X1<0) ps.push_back(P(X1, Y1));
    ps.push_back(P(X1, Y2));
    ps.push_back(P(X2, Y2));
    ps.push_back(P(X2, Y1));
    double r = L, t = pi;
    P p(0, 0);
    rep(i, ps.size()) {
        v.push_back(Arc(p, r, t, arg(ps[i]-p)));
        r -= abs(ps[i]-p);
        t = arg(ps[i]-p);
        p = ps[i];
        if(r<=EPS) break;
    }
    return v;
}

double solve() {
    if(L<=Y1 || (X1>=0 && L<=abs(P(X1, Y1))+EPS)) return 2*pi*L;
    vector<Arc> lv(make());
    swap(X1, X2); X1 = -X1; X2 = -X2;
    vector<Arc> rv(make());
    rep(i, rv.size()) rv[i] = reflect(rv[i]);
//    rep(i, lv.size()) cerr << lv[i] << endl;
//    rep(i, rv.size()) cerr << rv[i] << endl;
    double ans = 0;
    rep(i, lv.size()) ans += abs(lv[i]);
    rep(i, rv.size()) ans += abs(rv[i]);
    rep(i, lv.size()) rep(j, rv.size()) {
        if(abs(rv[j].p-lv[i].p)<EPS) continue;
        vector<P> ps = crosspointsAA(lv[i], rv[j]);
        rep(k, ps.size()) {
            double a = 0;
            rep(x, i) a += abs(lv[x]);
            rep(x, j) a += abs(rv[x]);
            a += lv[i].r * fabs(arg(ps[k]-lv[i].p)-lv[i].t0);
            a += rv[j].r * fabs(arg(ps[k]-rv[j].p)-rv[j].t0);
            ans = min(ans, a);
        }
    }
    return ans;
}

int main() {
    for(;;) {
        scanf("%d%d%d%d%d", &L, &X1, &Y1, &X2, &Y2);
        if(L==0) return 0;
        if(Y2<=0) { swap(Y1, Y2); Y1 = -Y1; Y2 = -Y2; }
        if(Y1<=0 && Y2>0) {
            const int y1 = X1, y2 = X2;
            X1 = Y1, X2 = Y2;
            Y1 = y1, Y2 = y2;
        }
        if(X2<=0) { swap(X1, X2); X1 = -X1; X2 = -X2; }
        if(Y2<=0) { swap(Y1, Y2); Y1 = -Y1; Y2 = -Y2; }
        printf("%.8f\n", solve());
    }
}

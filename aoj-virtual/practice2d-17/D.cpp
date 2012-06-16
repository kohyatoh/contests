#include <stdio.h>
#include <math.h>
#include <iostream>
#include <complex>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
const double EPS = 1e-12;
const double pi = atan2(0.0, -1.0);
typedef complex<double> P;

double norma(double t) {
    while (t < -pi) t += 2*pi;
    while (t > pi) t -= 2*pi;
    return t;
}

double cross(const P& a, const P& b) { return imag(conj(a)*b); }
double dot(const P& a, const P& b) { return real(conj(a)*b); }
P unit(const P& p) { return 1/abs(p)*p; }
P unit(double a) { return P(cos(a), sin(a)); }
P rot90(const P& p) { return p * P(0, 1); }

int ccw(const P& a, P b, P c) {
    b -= a, c -= a;
    if (cross(b, c) > 0) return 1;
    if (cross(b, c) < 0) return -1;
    if (dot(b, c) < 0) return 2;
    if (norm(b) < norm(c)) return -2;
    return 0;
}

bool intersectLL(const P& l0, const P& l1, const P& m0, const P& m1) {
    return abs(cross(l1-l0, m1-m0)) > EPS;
}

P crosspoint(const P& l0, const P& l1, const P& m0, const P& m1) {
    const double a = cross(l1-l0, m1-m0);
    const double b = cross(l1-l0, l1-m0);
    if (abs(a) < EPS && abs(b) < EPS) return m0;
    if (abs(a) < EPS) throw 0;
    return m0 + b/a * (m1-m0);
}

struct C {
    double R;
    vector<pair<double, double> > as;
    vector<pair<P, P> > es;
    C(double R) : R(R) {}
};

C empty(double R) {
    C c(R);
    c.as.push_back(mp(-pi, pi));
    return c;
}

double size(const C& c) {
    double t = 0;
    rep (i, c.as.size()) t += c.as[i].second - c.as[i].first;
    double s = c.R*c.R*(2*pi-t);
    rep (i, c.es.size()) s += cross(c.es[i].first, c.es[i].second);
    return s / 2;
}

C cut(const C& c, double dt, double t) {
    if (fabs(dt-pi) < EPS) return empty(c.R);
    C nc(c);
    const P p0 = c.R*unit(t-dt);
    const P p1 = c.R*unit(t+dt);
    const double a0 = norma(t-dt), a1 = norma(t+dt);
    if (a0 <= a1) nc.as.push_back(mp(a0, a1));
    else {
        nc.as.push_back(mp(-pi, a1));
        nc.as.push_back(mp(a0, pi));
    }
    sort(nc.as.begin(), nc.as.end());
    int m = 0;
    rep (i, nc.as.size()) {
        if (!m || nc.as[m-1].second < nc.as[i].first) nc.as[m++] = nc.as[i];
        else nc.as[m-1].second = max(nc.as[m-1].second, nc.as[i].second);
    }
    nc.as.resize(m);
    P s0 = p0, s1 = p1;
    rep (i, nc.es.size()) {
        if (!intersectLL(nc.es[i].first, nc.es[i].second, p0, p1)) {
            const int cc = ccw(nc.es[i].first, nc.es[i].second, p0);
            if (cc == -1) s0 = s1 = P(0, 0);
            else if (abs(cc) != 1) {
                if (dot(p1-p0, nc.es[i].second-nc.es[i].first) < -EPS) {
                    return empty(c.R);
                }
            }
            continue;
        }
        const P cp = crosspoint(nc.es[i].first, nc.es[i].second, p0, p1);
        if (ccw(nc.es[i].first, nc.es[i].second, s0) == -1) s0 = cp;
        if (ccw(nc.es[i].first, nc.es[i].second, s1) == -1) s1 = cp;
    }
    rep (i, nc.es.size()) {
        if (!intersectLL(nc.es[i].first, nc.es[i].second, p0, p1)) {
            const int cc = ccw(p0, p1, nc.es[i].first);
            if (cc == -1) nc.es[i].first = nc.es[i].second = P(0, 0);
            else if (abs(cc) != 1) {
                if (dot(p1-p0, nc.es[i].second-nc.es[i].first) < -EPS) {
                    return empty(c.R);
                }
            }
            continue;
        }
        const P cp = crosspoint(nc.es[i].first, nc.es[i].second, p0, p1);
        if (ccw(p0, p1, nc.es[i].first) == -1) nc.es[i].first = cp;
        if (ccw(p0, p1, nc.es[i].second) == -1) nc.es[i].second = cp;
    }
    nc.es.push_back(mp(s0, s1));
    m = 0;
    rep (i, nc.es.size()) {
        if (abs(nc.es[i].first - nc.es[i].second) > EPS) nc.es[m++] = nc.es[i];
    }
    nc.es.resize(m);
    return nc;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        double R, L;
        scanf("%lf%lf", &R, &L);
        int n;
        scanf("%d", &n);
        C c(R);
        rep (i, n) {
            double t, V;
            scanf("%lf%lf", &t, &V);
            t = norma(t/180*pi);
            const double s = size(c) - V/L;
            double l = 0, r = pi;
            rep (_, 100) {
                const double mid = (l+r) / 2;
                if (size(cut(c, mid, t)) < s) r = mid;
                else l = mid;
            }
            c = cut(c, l, t);
        }
        double ansT = 0;
        rep (i, c.as.size()) ansT += c.as[i].second - c.as[i].first;
        double ansE = 0;
        rep (i, c.es.size()) ansE += abs(c.es[i].second - c.es[i].first);
        printf("%.9f %.9f\n", ansE, R*(2*pi-ansT));
    }
    return 0;
}

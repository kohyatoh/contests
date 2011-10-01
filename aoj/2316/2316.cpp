#include <stdio.h>
#include <math.h>
#include <iostream>
#include <complex>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define EPS (1e-5)
typedef complex<double> P;
inline double sq(double a) { return a*a; }

const char names[4][8] = {"Red", "Green", "Blue", "White"};
int N, A, B, xs[50], ys[50];
P ps[50];

inline double cross(const P& a, const P& b) { return imag(conj(a)*b); }
inline P unit(const P& p) { return 1/abs(p)*p; }

inline bool intersectSP(const P& s0, const P& s1, const P& p) {
    return abs(s0-p)+abs(s1-p)-abs(s1-s0) < EPS;
}

P crosspoint(const P& l0, const P& l1, const P& m0, const P& m1) {
    const double A = cross(l1-l0, m1-m0);
    const double B = cross(l1-l0, l1-m0);
    if(abs(A)<EPS && abs(B)<EPS) return m0;
    return m0+B/A*(m1-m0);
}

vector<P> crosspointsCL(const P& p, double r, const P& l0, const P& l1) {
    vector<P> v;
    const P cp(crosspoint(p, p+(l1-l0)*P(0, 1), l0, l1));
    if(abs(cp-p)<EPS) {
        const P dir(r*unit(l1-l0));
        v.push_back(p+dir); v.push_back(p-dir);
    }
    else if(abs(cp-p)<r+EPS) {
        const double a = sqrt(sq(r)-norm(p-cp));
        const P dir(a*unit(cp-p)*P(0, 1));
        v.push_back(cp+dir); v.push_back(cp-dir);
    }
    return v;
}

double angle(P p, double L) {
    double a = -1e100;
    rep(i, N-1) {
        vector<P> v(crosspointsCL(p, L, ps[i], ps[i+1]));
        rep(j, v.size()) {
            if(real(p)<real(v[j]) && intersectSP(ps[i], ps[i+1], v[j])) {
                a = max(a, arg(v[j]-p));
            }
        }
    }
    return a;
}

int main() {
    const double sqrt2 = sqrt(2);
    const double arg45 = arg(P(1, 1));
    const double pi = atan2(0.0, -1.0);
    scanf("%d%d%d", &N, &A, &B);
    rep(i, N) scanf("%d%d", xs+i, ys+i);
    rep(i, N) ps[i] = P(xs[i], ys[i]);
    int rp = 0;
    P cur(A, ys[0]+(double)(A-xs[0])*(ys[1]-ys[0])/(xs[1]-xs[0]));
    cur += unit(ps[1]-ps[0]);
    while(cur.real()<B-EPS) {
        const double a = angle(cur, 1), b = angle(cur, sqrt2);
        if(a>b-arg45-EPS) cur += P(cos(a), sin(a)), rp += 1;
        else cur += P(cos(b), sin(b))*sqrt2, rp += 2;
    }
    puts(names[rp%4]);
    return 0;
}

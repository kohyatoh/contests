#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define EPS (1e-12)
inline double sq(double a) { return a*a; }

struct P {
    double x, y, z;
    P() {}
    P(double x, double y, double z) : x(x), y(y), z(z) {}
};
P operator*(double k, const P& p) { return P(p.x*k, p.y*k, p.z*k); }
P operator+(const P& l, const P& r) { return P(l.x+r.x, l.y+r.y, l.z+r.z); }
P operator-(const P& l, const P& r) { return P(l.x-r.x, l.y-r.y, l.z-r.z); }
double abs(const P& p) { return sqrt(sq(p.x)+sq(p.y)+sq(p.z)); }
ostream &operator<<(ostream& os, const P& p) {
    return os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
}
P unit(const P& p) { return 1/abs(p)*p; }

int R[2], S[2], K[2], X[2][128], Y[2][128], Z[2][128];
P ps[2][128];
double tm[2][128];

P at(int k, int ix, double t) {
    if(ix==K[k]-1) return ps[k][ix];
    return ps[k][ix] + (t-tm[k][ix])*S[k]*unit(ps[k][ix+1]-ps[k][ix]);
}

int solve() {
    rep(k, 2) rep(i, K[k]) ps[k][i] = P(X[k][i], Y[k][i], Z[k][i]);
    rep(k, 2) {
        double t = 0;
        rep(i, K[k]) {
            tm[k][i] = t;
            if(i<K[k]-1) t += abs(ps[k][i+1]-ps[k][i]) / S[k];
        }
    }
    vector<double> ts;
    rep(k, 2) rep(i, K[k]) ts.push_back(tm[k][i]);
    sort(ts.begin(), ts.end());
    vector<P> pt[2];
    rep(k, 2) rep(i, ts.size()) {
        if(ts[i]>tm[k][K[k]-1]+EPS) break;
        const int ix = upper_bound(tm[k], tm[k]+K[k], ts[i])-tm[k]-1;
        pt[k].push_back(at(k, ix, ts[i]));
    }
    vector<int> is;
    rep(i, min(pt[0].size(), pt[1].size())) {
        is.push_back(abs(pt[0][i]-pt[1][i])<=R[0]+R[1]+EPS);
    }
    int c = 0;
    if(is.size() && is[0]==1) c++;
    rep(i, is.size()-1) {
        if(is[i]==0 && is[i+1]==1) c++;
        if(is[i]==0 && is[i+1]==0) {
            const P p0(pt[0][i]), q0(pt[0][i+1]);
            const P p1(pt[1][i]), q1(pt[1][i+1]);
            const double t = ts[i];
            double l = ts[i], r = ts[i+1];
            rep(_, 100) {
                const double m1 = (2*l+r)/3, m2 = (l+r*2)/3;
                const double a =
                    abs((p0+(m1-t)*S[0]*unit(q0-p0)) - (p1+(m1-t)*S[1]*unit(q1-p1)));
                const double b =
                    abs((p0+(m2-t)*S[0]*unit(q0-p0)) - (p1+(m2-t)*S[1]*unit(q1-p1)));
                if(a<b) r = m2;
                else l = m1;
            }
            const double d = abs((p0+(l-t)*S[0]*unit(q0-p0))-(p1+(l-t)*S[1]*unit(q1-p1)));
            if(d<=R[0]+R[1]+EPS) c++;
        }
    }
    return c;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        rep(k, 2) {
            scanf("%d%d%d", R+k, S+k, K+k);
            rep(i, K[k]) scanf("%d%d%d", X[k]+i, Y[k]+i, Z[k]+i);
            X[k][K[k]] = 0; Y[k][K[k]] = 0; Z[k][K[k]] = 0;
            K[k]++;
        }
//printf("%d, %d\n", K[0]-1, K[1]-1);
        printf("%d\n", solve());
    }
    return 0;
}


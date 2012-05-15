#include <stdio.h>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define EPS (1e-8)

struct P {
    double x, y, z;
    P() {}
    P(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
};

inline P operator+(const P& l, const P& r) {
    return P(l.x+r.x, l.y+r.y, l.z+r.z);
}
inline P operator-(const P& l, const P& r) {
    return P(l.x-r.x, l.y-r.y, l.z-r.z);
}
inline P operator*(double x, const P& r) {
    return P(x*r.x, x*r.y, x*r.z);
}
inline double dot(const P& l, const P& r) {
    return l.x*r.x + l.y*r.y + l.z*r.z;
}
inline double norm(const P& p) { return dot(p, p); }
inline double abs(const P& p) { return sqrt(norm(p)); }
inline P unit(const P& p) { return 1/abs(p)*p; }

P readP() {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    return P(u, v, w);
}

void dump(const P& p) {
    printf("(%.9f, %.9f, %.9f)\n", p.x, p.y, p.z);
}

P projection(const P& l0, const P& l1, const P& p) {
    return l0 + dot(p-l0, l1-l0) / norm(l1-l0) * (l1-l0);
}

vector<P> crosspoint(const P& p, double r, const P& s, const P& t) {
    const P q = projection(s, t, p);
    const double dd = norm(q-p);
    if (dd > r*r) return vector<P>();
    else if (fabs(r*r-dd) < EPS) return vector<P>(1, q);
    else {
        vector<P> rs;
        const double x = sqrt(r*r-dd);
        rs.push_back(q+x*unit(t-s));
        rs.push_back(q-x*unit(t-s));
        return rs;
    }
}

int N;
P ps[200];
double rs[200];

P solve(P s, P t) {
    vector<pair<P, P> > cs;
    rep (i, N) {
        const vector<P> a = crosspoint(ps[i], rs[i], s, t);
        rep (j, a.size()) {
            if (dot(t-s, a[j]-s) > EPS) cs.push_back(mp(a[j], ps[i]));
        }
    }
    if (cs.size() == 0) return s;
    int ix = 0;
    rep (i, cs.size()) {
        if (norm(cs[ix].first-s) > norm(cs[i].first-s)) ix = i;
    }
    const P q = cs[ix].first, z = cs[ix].second;
    const P m = projection(z, q, s);
    return solve(q, s+2*(m-s));
}

int main() {
    for (;;) {
        scanf("%d", &N);
        if (N == 0) return 0;
        P p = readP();
        rep (i, N) {
            ps[i] = readP();
            scanf("%lf", rs+i);
        }
        P ans = solve(P(0, 0, 0), p);
        printf("%.9f %.9f %.9f\n", ans.x, ans.y, ans.z);
    }
}

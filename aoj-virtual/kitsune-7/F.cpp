#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <complex>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef complex<double> P;
#define EPS (1e-9)
#define INF (1e100)

double dot(const P& a, const P& b) { return real(conj(a)*b); }
double cross(const P& a, const P& b) { return imag(conj(a)*b); }
int ccw(const P& a, P b, P c) {
    b -= a, c -= a;
    if (cross(b, c) > 0) return 1;
    if (cross(b, c) < 0) return -1;
    if (dot(b, c) < 0) return 2;
    if (norm(b) < norm(c)) return -2;
    return 0;
}
bool intersectLS(const P& l0, const P& l1, const P& s0, const P& s1) {
    return cross(l1-l0, s0-l0) * cross(l1-l0, s1-l0) < EPS;
}
bool onlineLS(const P& l0, const P& l1, const P& s0, const P& s1) {
    return intersectLS(l0, l1, s0, s1) && fabs(cross(l1-l0, s1-s0)) < EPS;
}
double crosspoint(const P& l0, const P& l1, const P& m0, const P& m1) {
    const double A = cross(l1-l0, m1-m0);
    const double B = cross(l1-l0, l1-m0);
//    if (abs(A) < EPS && abs(B) < EPS) return m0;
    if (abs(A) < EPS && abs(B) < EPS) assert(false);
    if (abs(A) < EPS) assert(false);
    // return m0 + B/A * (m1-m0);
    return B/A;
}

double strict_in(double x, double y, double w, double h) {
    return 0 < x && x < w && 0 < y && y < h;
}
double inner(double x, double y, double w, double h) {
    return 0 <= x && x <= w && 0 <= y && y <= h;
}

int n, w, h;
P ps[200000], vs[200000];
bool use[200000];
double t1[200000], t2[200000];
P rc[4];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &w, &h);
        scanf("%d", &n);
        rep (i, n) {
            double x, y, a, b;
            scanf("%lf%lf%lf%lf", &x, &y, &a, &b);
            ps[i] = P(x, y);
            vs[i] = P(a, b);
        }
        rc[0] = P(0, 0);
        rc[1] = P(w, 0);
        rc[2] = P(w, h);
        rc[3] = P(0, h);
        rep (k, n) {
            use[k] = true;
            rep (i, 4) {
                if (onlineLS(ps[k], ps[k]+vs[k], rc[i], rc[(i+1)%4])) {
                    use[k] = false;
                    break;
                }
            }
            if (!use[k]) continue;
            t1[k] = INF, t2[k] = -INF;
            if (strict_in(ps[k].real(), ps[k].imag(), w, h)) t1[k] = -1;
            else if (inner(ps[k].real(), ps[k].imag(), w, h)) t1[k] = 0;
            rep (i, 4) {
                if (intersectLS(ps[k], ps[k]+vs[k], rc[i], rc[(i+1)%4])) {
                    double t = crosspoint(
                            rc[i], rc[(i+1)%4],
                            ps[k], ps[k]+vs[k]
                            );
                    if (t < 0) continue;
                    t1[k] = min(t1[k], t);
                    t2[k] = max(t2[k], t);
                }
            }
            if (t1[k] >= t2[k]) use[k] = false;
        }
        vector<pair<double, int> > ev;
//        printf("----\n");
        rep (k, n) {
//            printf("%d, %f, %f\n", (int)use[k], t1[k], t2[k]);
            if (use[k]) {
                ev.push_back(mp(t1[k], 1));
                ev.push_back(mp(t2[k], 0));
            }
        }
        sort(ev.begin(), ev.end());
        int ans = 0, cur = 0;
        rep (i, ev.size()) {
            if (ev[i].second) cur++; else cur--;
            ans = max(ans, cur);
        }
        printf("%d\n", ans);
    }
    return 0;
}

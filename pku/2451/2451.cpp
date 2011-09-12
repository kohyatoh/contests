#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define DBG(...) (__VA_ARGS__)
#else
#define LOG(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF MY_INFINITY

#include <complex>
const double EPS=1e-8;
typedef complex<double> P;
#define X(p) real(p)
#define Y(p) imag(p)
namespace std {
    bool operator<(const P& a, const P& b) {
        return X(a)!=X(b) ? X(a)<X(b) : Y(a)<Y(b);
    }
}
double cross(const P& a, const P& b) { return imag(conj(a)*b); }
double dot(const P& a, const P& b) { return real(conj(a)*b); }
int ccw(const P& a, P b, P c) {
    b-=a, c-=a;
    if(cross(b, c)>0) return 1;
    if(cross(b, c)<0) return -1;
    if(dot(b, c)<0) return 2;
    if(norm(b)<norm(c)) return -2;
    return 0;
}
P crosspoint(const P& l0, const P& l1, const P& m0, const P& m1) {
    const double a = cross(l1-l0, m1-m0);
    const double b = cross(l1-l0, l1-m0);
    if(abs(a)<EPS && abs(b)<EPS) return m0; // same line
    if(abs(a)<EPS) throw 0; // not crossing
    return m0 + b/a*(m1-m0);
}
double polygon_size(const vector<P>& v) {
    double s = 0;
    rep(i, v.size()-2) s += cross(v[i+1]-v[0], v[i+2]-v[0]);
    return fabs(s)/2;
}
vector<P> convex_cut(const vector<P>& v, const P& l0, const P& l1) {
    vector<P> r;
    rep(i, v.size()) {
        const P& a(v[i]), b(v[(i+1)%v.size()]);
        if(ccw(l0, l1, a)!=-1) r.push_back(a);
        if(ccw(l0, l1, a)*ccw(l0, l1, b)<0) {
            r.push_back(crosspoint(l0, l1, a, b));
        }
    }
    return r;
}

int main() {
    vector<P> v;
    v.push_back(P(0, 0));
    v.push_back(P(10000, 0));
    v.push_back(P(10000, 10000));
    v.push_back(P(0, 10000));
    int n;
    scanf("%d", &n);
    rep(i, n) {
        double x1, y1, x2, y2;
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        v = convex_cut(v, P(x1, y1), P(x2, y2));
        LOG(polygon_size(v));
    }
    printf("%.1f\n", polygon_size(v));
    return 0;
}


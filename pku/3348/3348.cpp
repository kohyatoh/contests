#include <stdio.h>
#include <math.h>
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef complex<double> P;
#define EPS (1e-9)

namespace std {
    bool operator<(const P& a, const P& b) {
        return real(a)!=real(b) ? real(a)<real(b) : imag(a)<imag(b);
    }
}

inline double cross(const P& a, const P& b) { return imag(conj(a)*b); }
inline double dot(const P& a, const P& b) { return real(conj(a)*b); }

int ccw(const P& a, P b, P c) {
    b -= a; c -= a;
    if(cross(b, c)>0) return 1;
    if(cross(b, c)<0) return -1;
    if(dot(b, c)<0) return 2;
    if(norm(b)<norm(c)) return -2;
    return 0;
}

vector<P> convex_hull(vector<P> ps) {
    sort(ps.begin(), ps.end());
    const int n = ps.size();
    int k = 0;
    vector<P> rs(2*n);
    for(int i=0; i<n; rs[k++]=ps[i++]) {
        while(k>=2 && ccw(rs[k-2], rs[k-1], ps[i])<=0) k--;
    }
    for(int i=n-2, t=k+1; i>=0; rs[k++]=ps[i--]) {
        while(k>=t && ccw(rs[k-2], rs[k-1], ps[i])<=0) k--;
    }
    rs.resize(k-1);
    return rs;
}

double polygon_size(const vector<P>& ps) {
    double a = 0;
    rep(i, ps.size()-2) a += cross(ps[i+1]-ps[0], ps[i+2]-ps[0]);
    return fabs(a)/2;
}

P scanP() {
    double x, y;
    scanf(" %lf%lf", &x, &y);
    return P(x, y);
}

int main() {
    int n;
    scanf("%d", &n);
    vector<P> ps;
    rep(i, n) ps.push_back(scanP());
    ps = convex_hull(ps);
    printf("%d\n", (int)(polygon_size(ps)/50));
    return 0;
}

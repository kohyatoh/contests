#include <stdio.h>
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef complex<double> P;
const double pi = atan2(0.0, -1.0);

namespace std {
    bool operator<(const P& a, const P& b) {
        return real(a)!=real(b) ? real(a)<real(b) : imag(a)<imag(b);
    }
}
double cross(const P& a, const P& b) { return imag(conj(a)*b); }
double dot(const P& a, const P& b) { return real(conj(a)*b); }
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
    vector<P> v(2*n);
    for(int i=0; i<n; v[k++]=ps[i++]) {
        while(k>1 && ccw(v[k-2], v[k-1], ps[i])<=0) k--;
    }
    for(int i=n-2, t=k; i>=0; v[k++]=ps[i--]) {
        while(k>t && ccw(v[k-2], v[k-1], ps[i])<=0) k--;
    }
    v.resize(k-1);
    return v;
}

P scanP() {
    double x, y;
    scanf("%lf%lf", &x, &y);
    return P(x, y);
}

double calc(int L, const vector<P>& ps) {
    double ans = L*2*pi;
    rep(i, ps.size()) {
        const int j = (i+1)%ps.size();
        ans += abs(ps[j]-ps[i]);
    }
    return ans;
}

int main() {
    int N, L;
    scanf("%d%d", &N, &L);
    vector<P> ps;
    while(N--) ps.push_back(scanP());
    ps = convex_hull(ps);
    printf("%.0f\n", calc(L, ps));
    return 0;
}
